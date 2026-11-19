#include<iostream>
#include<fstream>
#include<string>
#include<filesystem>
#include<sodium.h>

using namespace std;
namespace fs = std::filesystem;


string login_module() {
	//stored hash password path:
	
	fs::path stored_password_path = "Jarvis_Data/user_password.txt";

	//Ask user for password
	string entered_password = "";
	string stored_password = "";

	cout << "[SIR]: Enter Your Passsword: ";
	getline(cin, entered_password);

	//read the stored hash password;

	//check if txt file not exists
	if (!fs::exists(stored_password_path)) {
		cout << "[SIR]: Account Details Not Found\n";
		cout << "[SIR]: Try Creating New Account\n";
		return "failure";
	}

	//Read the stored hash
	ifstream stored_password_file(stored_password_path);

	if (stored_password_file.is_open()) {
		
		//check if reading succeeded.
		if (!getline(stored_password_file, stored_password)) {
			cout << "[SIR]: Failed To Read Password Hash\n";
			cout << "[SIR]: Please Try Again\n";
			return "failure";
		}

		stored_password_file.close();

		if (stored_password_file.fail()) {
			cout << "[SIR]: Failed to Close File\n";
			cout << "[SIR]: Please Try Again\n";
			return "failure";
		}

		if (stored_password.empty() ||
			entered_password.size() > stored_password.size()) {
			cout << "[SIR]: Account Details Are Invalid\n";
			cout << "[SIR]: Try Creating a New Account\n";
			return "failure";
		}

		int password_verification_result =
			crypto_pwhash_str_verify(
				stored_password.c_str(),
				entered_password.c_str(),
				entered_password.size()
			);

		if (password_verification_result != 0) {
			cout << "[SIR]: Incorrect Password!\n";
			cout << "[SIR]: Try Again Please\n";
			return "failure";
		}

		cout << "[SIR]: Password Matched!\n";
		return "success";

	}

	else {
		cout << "[SIR]: Failed To Read Password Hash File\n";
		return "failure";
	}

	

}
