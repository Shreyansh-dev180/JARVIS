#include<iostream>
#include<algorithm>
#include<filesystem>
#include<sodium.h>
#include<fstream>
#include<string>

using namespace std;
namespace fs = std::filesystem;


string create_new_account() {

	fs::path passwordHash_str_path = "Jarvis_Data/user_password.txt";

	//someone calls create account by mistake but 
	// if account already exists so return

	if (fs::exists(passwordHash_str_path)) {
		cout << "[SIR]: User Account Already Exists!\n";
		return "failure";
	}


	//ask user for account details 
	string password = ""; 
	string passwordHash_str = "";

	/*c style char array(writable buffer)
		of constant size
		stores every byte in buffer*/

	char passwordHash[crypto_pwhash_STRBYTES];



	cout << "[SIR]: Create a Strong Password: ";
	getline(cin, password);

	
	if (password.empty()) {
		cout << "[SIR]: Empty Password!\n";
		return "failure";
	}
	

	//hashing the entered password

	//the function return: 0 hash generated , -1 failed.

	int hash_generation_result =
		crypto_pwhash_str(
			passwordHash,
			password.c_str(),
			password.size(),
			crypto_pwhash_OPSLIMIT_INTERACTIVE,
			crypto_pwhash_MEMLIMIT_INTERACTIVE
		);

	//extracting passwordHash c-style string in passwordHash_str(c++ string);

	if (hash_generation_result == 0) {
		/*c-style array has '\0' at end 
		The std::string constructor reads characters 
		until it encounters the null terminator.
		
		No manual iteration required.*/

		passwordHash_str = passwordHash; //Done.


		//saving the hashed file
		ofstream file(passwordHash_str_path);

		if (file.is_open()) {
			file << passwordHash_str;

			if (!file.good()) {
				cout << "[SIR]: Failed to Save Password\n";
				return "failure";

			}

			cout << "[SIR]: Password Saved Successfully\n";

			file.close();

			if (file.fail()) {
				cout << "[SIR]: Failed To Close The File\n";
				return "failure";
			}

			return "success";
		}

		else {
			cout << "[SIR]: Failed To Open File!\n";
			cout << "[SIR]: Please Try Again\n";

			return "failure";
		}


	}

	else {
		//if hash_generation failed then return
		cout << "[SIR]: Hash Generation Failed\n";
		return "failure";
	}





}