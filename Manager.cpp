//standard includes: 
#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include <thread>

//local.h includes: 
#include "system_automation/temp_cleaner.h"
#include "system_automation/system_info.h"
#include "command_parser/command_parser.h"
#include "browser_automation/youtube_agent.h"
#include "browser_automation/google_search.h"
#include "system_health_monitor/monitor_manager.h"

//liberal sessions

//namespaces used: 
using namespace std;

//function to take user input in user_command: 
void user_input(string &user_command){
    cout<<"[Sir]: How Can I Help You Today\n";
    getline(cin, user_command);
}

int main(){
    //create a thread obj whose lifetime is till main's lifetime
    jthread system_health_monitor_thread;

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

        //Incase of unrecognize command the cmd_parser show error message
        // and returns without filling anything in task_target vector
        //so we need to check if task_target is empty then stop further execution;

        if (task_target.empty()) {
            cout << "[SIR]: Invalid Command Structure\n";
        }

        //1. Youtube automation- Call to Youtube_Command_Executer(string filtered_command, vector<string> task_target);
        else if(task_target[0] == "play" && task_target[1] == "youtube"){
            Youtube_Command_Executer(filtered_command);
        }

        //google search automation: call to 
        else if(task_target[0] == "search" && task_target[1] == "google"){
            Google_Search_Module(filtered_command);
        }

        //for command structure: clean temp 
        //task = clean , target = temp files; filtered command not needed.

        else if(task_target[0] == "clean" && task_target[1] == "temp"){
            temp_clean();
        }

        else if (task_target[0] == "system" && task_target[1] == "info") {
            Memory_info();
            Cpu_info();
        }

        else if (task_target[0] == "start" && task_target[1] == "system monitor") {
            /*we check if the jthread obj is not joinable means 
            it is not holding a working thread so our system health 
            monitor is not running already so we can start safely else
            cout that system health monitor is already running*/

            if (!system_health_monitor_thread.joinable()) {
                /*create a jthread and give its ownership to our
                system_health_monitor_thread so that its lifetime
                stay throughout the main program*/
                //SHMT-> system_health_monitor_thread;
                jthread temp_SHMT(system_health_monitor_manager);

                //pass temp_SHMT ownership to SHMT thread
                system_health_monitor_thread = move(temp_SHMT);

                cout << "[SIR]: System Monitoring Has Been Started\n";
            }
            else {
                cout << "[SIR]: System Monitoring is Already Running\n";
            }

        }

        else if (task_target[0] == "stop" && task_target[1] == "system monitor") {
            /*for stopping the system monitoring we check if it is 
            joinable then it means system monitoring was running so
            we need to stop it else cout system monitoring is not 
            running*/
            if (system_health_monitor_thread.joinable()) {
                system_health_monitor_thread.request_stop();
                system_health_monitor_thread.join();
                cout << "[SIR]: System Monitor has been stopped\n";
            }
            else {
                cout << "[SIR]: System Monitor is not Running\n";
            }
        }

        else{
            cout<<"[SIR]: Possibly due to Wrong Command Structure\nOr Empty Query\n";
            cout<<"The Error Occured\nTry Again with Correct Command Structure and query\n";
        }


    }



    

    


    return 0;
}