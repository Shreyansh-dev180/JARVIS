//standard includes: 
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

//.h includes: 
#include "system_automation/temp_cleaner.h"
#include "command_parser/command_parser.h"
#include "browser_automation/youtube_agent.h"

//namespaces used: 
using namespace std;

//function to take user input in user_command: 
void user_input(string &user_command){
    cout<<"[Sir]: How Can I Help You Today\n";
    getline(cin, user_command);
}

int main(){

    while(true){
        string user_command = "";
        string filtered_command = "";

        //task example - search , play, clean etc;
        //target example - on youtube, on google, on brave, etc;
        vector<string> task_target;

        //Call to take user input;
        user_input(user_command);

        transform(user_command.begin(),
                  user_command.end(),
                  user_command.begin(),
                  ::tolower);

        if(user_command == "exit"){
            cout<<"[SIR]: Signing Off For Now\n";
            break;
        }

        //call to command parser
        cmd_parser(user_command, task_target, filtered_command);


        //1. Youtube automation- Call to Youtube_Command_Executer(string filtered_command, vector<string> task_target);
        if(task_target[0] == "play" && task_target[1] == "youtube"){
            Youtube_Command_Executer(filtered_command);
        }

        //for command structure: clean temp 
        //task = clean , target = temp files; filtered command not needed.

        if(task_target[0] == "clean" && task_target[1] == "temp"){
            temp_clean();
        }


    }



    

    


    return 0;
}