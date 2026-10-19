#include<iostream>
#include<string>
#include<vector>
#include<string>
using namespace std;

//function references --

//1.play_youtube_parsing 
void play_youtube_parsing(string& user_command , vector<string>& task_target , string& filtered_cmd);

//2. search_google_parsing
void search_google_parsing(string user_command, vector<string>& task_target, string& filtered_command);


//MAIN FUNCTION 

void cmd_parser(string& user_command , vector<string>& task_target, string& filtered_cmd){
    //For command type - play <text> on youtube;

    if(user_command.find("play") != string::npos && user_command.find("youtube") != string::npos){

        play_youtube_parsing(user_command, task_target, filtered_cmd);
    }

    else if(user_command.find("clean") != string::npos && user_command.find("temp") != string::npos){

        //command structure : clean temp (any case);
        //no need of filtered command because Task = clean target = temp files;
        task_target.push_back("clean");
        task_target.push_back("temp");

    }

    else if(user_command.find("search") != string::npos && user_command.find("google") != string::npos){
        search_google_parsing(user_command, task_target, filtered_cmd);
    }



}










void play_youtube_parsing(string& user_command , vector<string>& task_target , string& filtered_cmd){
    size_t start = user_command.find("play"); //first occurance of play's p index
    //store the index value of space(" ") before on youtube.
    size_t end = user_command.find(" on youtube"); 

    //logic checking

    //example- play believer on youtube; 

    /*1. if we found both and there is some text between play and on youtube
         for the text part we start is p's index so start+5 means at 'b' of believer
         now end is already at o now end should be greater than start+5 means any 
         text inbetween now we get that text using substr and end - start+5*/

    if(user_command.find("play") != string::npos
       && user_command.find(" on youtube") != string::npos && end > start+5)
       {
        //Extracting Task and Target

        task_target.push_back("play");
        task_target.push_back("youtube");


        //end - start+5 for getting total length of area to keep 
        //example start 5 and end 10 then 10-5 is keep rest 5 words between  
        string to_be_searched = user_command.substr(start+5, end - (start+5)); //starting, after how many char to stop 
        filtered_cmd = to_be_searched;


       }
    else{
        cout<<"[SIR]: Empty or Unstructured Commands are not Accepted\n";
        cout<<"[SIR]: play **Empty** on youtube\n";
        cout<<"Make sure to Add Some Query and structure your command\n";
        return;
    }

}


void search_google_parsing(string user_command, vector<string>& task_target, string& filtered_command){
    size_t start = user_command.find("search");  // s is the starting index
    size_t end = user_command.find(" on google"); // " " is the ending index


    if(user_command.find("search") != string::npos 
       && user_command.find(" on google") != string::npos
       && end > (start+7)){

        task_target.push_back("search");
        task_target.push_back("google");

        string search_query = user_command.substr(start+7, end - (start+7));
        filtered_command = search_query;

       }

    else{
        cout<<"[SIR]: Empty or Unstructured Commands are not Accepted\n";
        cout<<"[SIR]: search **Empty** on google\n";
        cout<<"Make sure to Add Some Query and structure your command\n";
        return;
    }

       /*condition check here if start+6 then if search on google then start + 6 is always less than 
       end so always true but it should be start + 7 so there should be atleast one char*/

       /*example  = search xyz on google
       start = s means 0;
       end = " " spaec just after z so 10
       
       now we say search length is 5 (0 indexed) now we want to avoid that space after h so 
       start will be start + 7 
       same if we have end = 10 ranging from s to " " 
       so we also want to exclude that space so we subtract search length + 1 means end - start+7*/
}