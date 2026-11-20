#include<iostream>
#include<sodium.h>
#include<string>
#include<algorithm>

//Local Includes
#include "new_account_creation.h"
#include "login_module.h"

using namespace std;



string Authenticate_The_User() {
	//initialize libsodium once for all subagents.
	if (sodium_init() < 0) {
		cout << "[SIR]: Authentication Initialization Failed!";
		cout << "[SIR]: libsodium Initialization Failed\n";
		return "failure";
	}

	//ask user to choose login or create new account
	string user_choice = "";

	cout << "[SIR]: 1.Login\n2.Create New Account\nEither (1,2) or Name: ";

	getline(cin, user_choice);

	//if name input then convert to lowercase;
	transform(user_choice.begin(), user_choice.end(),
		user_choice.begin(), ::tolower);

	//if user_choice = login either 1
	if (user_choice == "1" || user_choice == "login") {
		string login_module_result = login_module();

		return login_module_result;

	}

	else if (user_choice == "2" || user_choice == "create new account"
		|| user_choice == "createnewaccount") {

		string login_module_result = create_new_account();

		return login_module_result;
	}

	else {
		cout << "[SIR]: Invalid Input Provided!\n";
		cout << "[SIR]: Please Give Input In Correct Structure\n";
		return "error";
	}




}