#include<iostream>
#include<string>
#include<filesystem>
#include<algorithm>
#include<fstream>

using namespace std;
namespace fs = filesystem;


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
        <<"5.Other\n"
        <<"6.Your Choice: ";

        getline(cin, user_response);

        //if Empty Response 

        if(user_response.empty()){
            cout<<"[SIR]: Please Enter a Valid Choice\n";
            cout<<"[SIR]: Empty Commands are Invalid\n";
            return;
        }

        transform(user_response.begin(), user_response.end(),
                user_response.begin(), ::tolower);

        //check if user uses other browser out of the 4 ;
        if(user_response.find("other") != string::npos){

            cout<<"[SIR]: Jarvis Don't Support Any Other Browser\n";
            cout<<"[SIR]: Sorry For The Inconvinience\n";
            return;

        }

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

        else {
            cout<<"[SIR]: You Made an Invalid Choice\n"
                  "Try Entering The Exact Browser Name Listed\n";
            return;
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