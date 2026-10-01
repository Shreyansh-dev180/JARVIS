//standard includes: 
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

//.h includes: 
#include "temp_cleaner.h"
#include "command_parser.h"
#include "youtube_agent.h"

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


    //1. Youtube automation- Call to Youtube_Command_Executer(string filtered_command, vector<string> task_target);
    if(task_target[0] == "play" && task_target[1] == "youtube"){
        Youtube_Command_Executer(filtered_command, task_target);
    }



    

    


    return 0;
}