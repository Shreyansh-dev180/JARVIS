#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<filesystem>
#include<algorithm>
#include<fstream>
#include<thread>
#include<chrono>

//local .h files include
//.. means first go to jarvis(one level back) then search for files
#include"../browser_modules/user_browser_detection.h"
#include"../browser_modules/user_browser_launch.h"
#include"../browser_modules/fallback_function.h"

using namespace std;
namespace fs = filesystem;




void Youtube_Command_Executer(string filtered_command){
    string user_primary_browser = "";

    fs::path folder = "Jarvis_Data";
    
    fs::path p = folder/"User_Main_Browser.txt";

    //check if file not exists then call to detection module and extract data directly
    if(!fs::exists(p)){
        Browser_Detection_Module();

        /*if user entered empty response and detection module returned without 
        creating the file then return from here if file still not exits      */

        if(!fs::exists(p)){
            cout<<"[SIR]: User_Main_Browser.txt not found\nTry Again\n";
            return;
        }
    }

    //checking if User_Main_Browser.txt is empty
    if(fs::is_empty(p)){
        cout<<"[SIR]: It seems like You Have'nt Entered A Valid Browser Name\n";
        cout<<"There is No Data In the Jarvis_Data Module\n";
        cout<<"Please Try Again\n";
        return;
    }

    //Reading the Jarvis_Data/ User_Main_Browser.txt 
    fstream browser_data_file(p);

    if(browser_data_file.is_open()){
        getline(browser_data_file, user_primary_browser);

        browser_data_file.close();
    }
    else{
        cout<<"Failed to Open user_main_browser.txt file\n";
        return;
    }

    //starting the right Browser
    Browser_Launch(user_primary_browser);

    this_thread::sleep_for(chrono::seconds(5));


    string base_url = "https://www.youtube.com/results?search_query=";

    string query = filtered_command;

    replace(query.begin(),query.end() ,' ', '+');

    string final_search_text = base_url + query;
    
    if(user_primary_browser.find("brave") != string::npos){

        int is_browser_opened = system("winapp ui list-windows | findstr /i \"Brave\" > nul");

        //if 0 then opened - continue else if 1 means still browser is not opened even after 5 sec

        if(is_browser_opened != 0){
            cout<<"[SIR]: Your Browser is Taking Too long to Launch\n"
                  "Please Try Again\n";
            return;
        }


        system("winapp ui send-keys \"Ctrl+l\" -a brave");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a brave");
        system("winapp ui send-keys \"Backspace\" -a brave");

        string command = "winapp ui send-keys \"" + final_search_text + "\" -a brave";

        system(command.c_str()); //system expects a C format string thats why c_str;

        system("winapp ui send-keys \"Enter\" -a brave");
        
        return;

    }

    //if user_browser is chrome then-:
    else if(user_primary_browser.find("chrome") != string::npos){

        int is_browser_opened = system("winapp ui list-windows | findstr /i \"Chrome\" > nul");

        //if 0 then opened - continue else if 1 means still browser is not opened even after 5 sec

        if(is_browser_opened != 0){
            cout<<"[SIR]: Your Browser is Taking Too long to Launch\n"
                  "Please Try Again\n";
            return;
        }


        system("winapp ui send-keys \"Ctrl+l\" -a chrome");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a chrome");
        system("winapp ui send-keys \"Backspace\" -a chrome");

        string command = "winapp ui send-keys \"" + final_search_text + "\" -a chrome";

        system(command.c_str()); //system expects a C format string thats why c_str;

        system("winapp ui send-keys \"Enter\" -a chrome");
        
        return;

    }

    //if msedge
    else if(user_primary_browser.find("msedge") != string::npos){

        int is_browser_opened = system("winapp ui list-windows | findstr /i \"Edge\" > nul");

        //if 0 then opened - continue else if 1 means still browser is not opened even after 5 sec

        if(is_browser_opened != 0){
            cout<<"[SIR]: Your Browser is Taking Too long to Launch\n"
                  "Please Try Again\n";
            return;
        }


        system("winapp ui send-keys \"Ctrl+l\" -a msedge");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a msedge");
        system("winapp ui send-keys \"Backspace\" -a msedge");

        string command = "winapp ui send-keys \"" + final_search_text + "\" -a msedge";

        system(command.c_str()); //system expects a C format string thats why c_str;

        system("winapp ui send-keys \"Enter\" -a msedge");
        
        return;

    }

    //if firefox
    else if(user_primary_browser.find("firefox") != string::npos){

        int is_browser_opened = system("winapp ui list-windows | findstr /i \"Firefox\" > nul");

        //if 0 then opened - continue else if 1 means still browser is not opened even after 5 sec

        if(is_browser_opened != 0){
            cout<<"[SIR]: Your Browser is Taking Too long to Launch\n"
                  "Please Try Again\n";
            return;
        }


        system("winapp ui send-keys \"Ctrl+l\" -a firefox");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a firefox");
        system("winapp ui send-keys \"Backspace\" -a firefox");

        string command = "winapp ui send-keys \"" + final_search_text + "\" -a firefox";

        system(command.c_str()); //system expects a C format string thats why c_str;

        system("winapp ui send-keys \"Enter\" -a firefox");
        
        return;

    }

    else{
        cout<<"[SIR]: Due to Configuration Issues Browser Automation Failed\n"
              "You can try Checking whether You Have Entered a Valid Browser Name\n";
        
        //before returning Call to Fallback module for updating the txt file data
        Fallback_Module(p);

        return;
    }

    
    
  

}


