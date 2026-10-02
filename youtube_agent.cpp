#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<filesystem>
#include<algorithm>
#include<fstream>

using namespace std;
namespace fs = filesystem;

//1. Browser_Detection_Module reference
void Browser_Detection_Module(string& user_primary_browser);


void Youtube_Command_Executer(string filtered_command, vector<string> task_target){
    string user_primary_browser = "";

    fs::path folder = "Jarvis_Data";
    
    fs::path p = folder/"User_Main_Browser.txt";

    //check if file not exists then call to detection module and extract data directly
    if(!fs::exists(p)){
        Browser_Detection_Module(user_primary_browser);
    }

    //Reading the Jarvis_Data/ User_Main_Browser.txt 
    fstream browser_data_file(p);

    if(browser_data_file.is_open()){
        getline(browser_data_file, user_primary_browser);

        browser_data_file.close();
    }
    
    

}





void Browser_Detection_Module(){
    string user_primary_browser = "";

    fs::path folder = "Jarvis_Data";
    
    fs::path p = folder/"User_Main_Browser.txt";

    //if files dont exists.
    if(!fs::exists(p)){

        string user_response = "";
        cout<<"[SIR]: Enter The Name Of Your Primary Browser[One Time]\n"
        <<"1.Brave\n"
        <<"2.Chrome\n"
        <<"3.Edge\n"
        <<"4.Firefox\n"
        <<"5.Your Choice: ";

        getline(cin, user_response);

        //if Empty Response 

        if(user_response.empty()){
            cout<<"[SIR]: Please Enter a Valid Choice\n";
            return;
        }

        transform(user_response.begin(), user_response.end(),
                user_response.begin(), ::tolower);

        if(user_response.find("brave") != string::npos){
            user_primary_browser = "brave";
            
        }

        else if(user_response.find("chrome") != string::npos){
            user_primary_browser = "chrome";
            
        }

        else if(user_response.find("edge") != string::npos){
            user_primary_browser = "msedge";
            
        }

        else if(user_response.find("firefox") != string::npos){
            user_primary_browser = "firefox";

        }

        //Saving the User Browser in Jarvis_Data/User_Main_Browser.txt;
        //if folder and file inside it both dont exists
        if(!fs::exists(folder)){
            fs::create_directory(folder);

            ofstream file(p);

            if(file.is_open()){
                file<< user_primary_browser;
                file.close();
            }
        }
        //if only file inside the folder is missing
        else{
            ofstream file(p);

            if(file.is_open()){
                file<< user_primary_browser;
                file.close();
            }
        }

    }

}