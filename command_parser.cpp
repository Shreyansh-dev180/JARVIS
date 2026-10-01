#include<iostream>
#include<string>
#include<vector>
#include<string>
using namespace std;

//function references --

//1.play_youtube_parsing 
void play_youtube_parsing(string& user_command , vector<string>& task_target , string& filtered_cmd);



//MAIN FUNCTION 

void cmd_parser(string& user_command , vector<string>& task_target, string& filtered_cmd){
    //For command type - play <text> on youtube;

    if(user_command.find("play") != string::npos && user_command.find("youtube") != string::npos){

        play_youtube_parsing(user_command, task_target, filtered_cmd);
    }



}










void play_youtube_parsing(string& user_command , vector<string>& task_target , string& filtered_cmd){
    size_t start = user_command.find("play"); //first occurance of play's p index
    //store the index value of o in on youtube.
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
        string song = user_command.substr(start+5, end - (start+5)); //starting, after how many char to stop 
        filtered_cmd = song;


       }

}
