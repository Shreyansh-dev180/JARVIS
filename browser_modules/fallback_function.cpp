#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;
namespace fs = filesystem;


void Fallback_Module(fs::path User_Main_Browser_file_path){
    fs::path file_path = User_Main_Browser_file_path;

    string new_user_command = "";

    string filtered_new_user_command = "";

    //Asking for correct Browser Name;
    cout<<"[SIR]: Enter The Name Of Your Primary Browser[One Time]\n"
        <<"1.Brave\n"
        <<"2.Chrome\n"
        <<"3.Edge\n"
        <<"4.Firefox\n"
        <<"5.Other\n"
        <<"6.Your Choice: ";

    getline(cin, new_user_command);

    if(new_user_command.empty()){
        cout<<"[SIR]: Empty Commands Are Invalid\nTry Again\n"; 
        return;
    }

    transform(new_user_command.begin(), new_user_command.end(),
              new_user_command.begin(), ::tolower);

    if(new_user_command.find("other") != string::npos){
        cout<<"[SIR]: Jarvis Don't Support Any Other Browser\n";
        cout<<"[SIR]: Sorry For The Inconvinience\n";
        return;
    }

    if(new_user_command.find("brave") != string::npos) filtered_new_user_command = "brave";

    else if(new_user_command.find("chrome") != string::npos) filtered_new_user_command = "chrome";

    else if(new_user_command.find("edge") != string::npos) filtered_new_user_command = "msedge";

    else if(new_user_command.find("firefox") != string::npos) filtered_new_user_command = "firefox";

    else {
        cout<<"[SIR]: You Made an Invalid Choice\n"
               "Try Entering The Exact Browser Name Listed\n";
        return;
    }


    if(!filtered_new_user_command.empty()){
        ofstream file(file_path);

        if(file.is_open()){
            file<<filtered_new_user_command;
            file.close();
            cout<<"[SIR]: Your Old Incorrect Browser Name is Replaced with: "<<filtered_new_user_command<<'\n';
            cout<<"[SIR]: Try Youtube Play Feature Once Again\n";
            return;
        }

        else{
            cout << "[SIR]: Failed to Update Browser Configuration\n";
        }
        
    }


}