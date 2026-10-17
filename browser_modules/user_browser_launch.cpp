#include<iostream>
#include<string>

using namespace std;

void Browser_Launch(string& user_primary_browser){

    if(user_primary_browser.find("brave") != string::npos) system("Start brave");

    else if(user_primary_browser.find("chrome") != string::npos) system("Start chrome");

    else if(user_primary_browser.find("firefox") != string::npos) system("Start firefox");

    else if(user_primary_browser.find("msedge") != string::npos) system("Start msedge");

    else cout<<"[SIR]: Failed to Start appropriate Browser\n Please Try Again\n";
   

}