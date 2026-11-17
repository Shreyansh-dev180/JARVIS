#include<iostream>
#include<sodium.h>
#include<string>

using namespace std;


string Authenticate_The_User() {
	//initialize libsodium once for all subagents.
	if (sodium_init() < 0) {
		cout << "[SIR]: Authentication Initialization Failed!";
		cout << "[SIR]: libsodium Initialization Failed\n";
		return "failure";
	}




}