#include<iostream>
#include<filesystem>
#include<string>
#include<algorithm>
#include<fstream>
#include<thread>

//files include cd ..  to return to root jarvis dir first
#include "../browser_modules/fallback_function.h"
#include "../browser_modules/user_browser_detection.h"
#include "../browser_modules/user_browser_launch.h"

using namespace std;

using namespace std;
namespace fs = filesystem;

void Google_Search_Module(string& filtered_command){
    string browser_name = "";

    fs::path p = "Jarvis_Data/User_Main_Browser.txt";

    //if User_Main_Browser.txt file not exists 
    //Then call to browser_detection_module create it.
    if(!fs::exists(p)){
        Browser_Detection_Module();
        
        //if still file not exists then return back.
        if(!fs::exists(p)){
            cout<<"[SIR]: User_Main_Browser.txt Not Found\nTry Again\n";
            return;
        }
    }

    //Reading the Jarvis_Data/ User_Main_Browser.txt

    fstream user_main_browser_txt_file(p);

    if(user_main_browser_txt_file.is_open()){
        getline(user_main_browser_txt_file, browser_name);

        user_main_browser_txt_file.close();
    }

    else{
        cout<<"Failed to Open user_main_browser.txt file\n";
        return;
    }

    //launching the user primary browser;
    if(!browser_name.empty()){
        Browser_Launch(browser_name);
    }


    //wait for 5 seconds ,let the browser be stable;
    this_thread::sleep_for(chrono::seconds(5));

    if(browser_name.find("brave") != string::npos){
        //check if browser is opened or not
        int browser_open_or_close = system("winapp ui list-windows | findstr /i \"Brave\" > nul");

        //if browser_open_or_close == 0 means opened else not open
        if(browser_open_or_close != 0){
            cout<<"[SIR]: Your Browser is Taking Too Long To Open\n";
            cout<<"Please Try Again\n";
            return;
        }

        system("winapp ui send-keys \"Ctrl+l\" -a brave");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a brave");
        system("winapp ui send-keys \"Backspace\" -a brave");

        //searching the filtered_command means users-query.
        string user_query = "winapp ui send-keys \""+ filtered_command + "\" -a brave";

        system(user_query.c_str()); //system expects a c style string so c_str();

        //On pressing enter it search the auto suggested results so we do one space to 
        //avoid searching auto suggested result and search what we have typed.

        system("winapp ui send-keys \"Space\" -a brave");
        system("winapp ui send-keys \"Space\" -a brave");

        system("winapp ui send-keys \"Enter\" -a brave");

        return;
    }

    
    else if(browser_name.find("chrome") != string::npos){
        //check if browser is opened or not
        int browser_open_or_close = system("winapp ui list-windows | findstr /i \"Chrome\" > nul");

        //if browser_open_or_close == 0 means opened else not open
        if(browser_open_or_close != 0){
            cout<<"[SIR]: Your Browser is Taking Too Long To Open\n";
            cout<<"Please Try Again\n";
            return;
        }

        system("winapp ui send-keys \"Ctrl+l\" -a chrome");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a chrome");
        system("winapp ui send-keys \"Backspace\" -a chrome");

        //searching the filtered_command means users-query.
        string user_query = "winapp ui send-keys \""+ filtered_command + "\" -a chrome";

        system(user_query.c_str()); //system expects a c style string so c_str();

        system("winapp ui send-keys \"Enter\" -a chrome");

        return;
    }

    
    else if(browser_name.find("msedge") != string::npos){
        //check if browser is opened or not
        int browser_open_or_close = system("winapp ui list-windows | findstr /i \"Edge\" > nul");

        //if browser_open_or_close == 0 means opened else not open
        if(browser_open_or_close != 0){
            cout<<"[SIR]: Your Browser is Taking Too Long To Open\n";
            cout<<"Please Try Again\n";
            return;
        }

        system("winapp ui send-keys \"Ctrl+l\" -a msedge");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a msedge");
        system("winapp ui send-keys \"Backspace\" -a msedge");

        //searching the filtered_command means users-query.
        string user_query = "winapp ui send-keys \""+ filtered_command + "\" -a msedge";

        system(user_query.c_str()); //system expects a c style string so c_str();

        system("winapp ui send-keys \"Enter\" -a msedge");

        return;
    }


    else if(browser_name.find("firefox") != string::npos){
        //check if browser is opened or not
        int browser_open_or_close = system("winapp ui list-windows | findstr /i \"Firefox\" > nul");

        //if browser_open_or_close == 0 means opened else not open
        if(browser_open_or_close != 0){
            cout<<"[SIR]: Your Browser is Taking Too Long To Open\n";
            cout<<"Please Try Again\n";
            return;
        }

        system("winapp ui send-keys \"Ctrl+l\" -a firefox");

        //l is typed in search bar so delete it first
        system("winapp ui send-keys \"Backspace\" -a firefox");
        system("winapp ui send-keys \"Backspace\" -a firefox");

        //searching the filtered_command means users-query.
        string user_query = "winapp ui send-keys \""+ filtered_command + "\" -a firefox";

        system(user_query.c_str()); //system expects a c style string so c_str();

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