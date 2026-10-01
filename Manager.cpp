//standard includes: 
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<vector>

//.h includes: 
#include"temp_cleaner.h"
#include"command_parser.h"

//namespaces used: 
using namespace std;

//function to take user input in user_command: 
void user_input(string &user_command){
    cout<<"[Sir]: How Can I Help You Today\n";
    getline(cin, user_command);
}

int main(){
    string user_command = "";
    string filtered_command = "";

    //task example - search , play, clean etc;
    //target example - on youtube, on google, on brave, etc;
    vector<string> task_target;

    //Call to take user input;
    user_input(user_command);

    //call to command parser
    cmd_parser(user_command, task_target, filtered_command);

    cout<<"Filtered_command is: "<<filtered_command<<'\n';


    

    


    return 0;
}