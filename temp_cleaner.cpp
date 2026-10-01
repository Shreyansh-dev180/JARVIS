#include<iostream>
#include<filesystem>
#include<cstdlib>
#include<system_error>

/*ec or error_code is like a container which stores the window error and 
keeps running the program without crashing it so we check if ec have any error then
instead of crashing cout some message and continue .  */

std::error_code ec;

using namespace std;
namespace fs = filesystem;

void temp_clean(){
    int errors = 0;
    int skipped = 0;
    int success = 0;


    
    /*task is to access the temp path and then clean it.*/

    fs::path p = getenv("TEMP");

    for(auto entry : fs::directory_iterator(p)){
        //if directory then use remove all for erasing whole tree: 
        if(entry.is_directory()){

            fs::remove_all(entry, ec);

            if(ec){ //if ec contain any error then
                //there is error; and we are skipping it.
                errors++;
                skipped++;
            }
            else{ //if not
                //successful;
                success++;
            }
        }

        //if file then use simple remove function: 
        else if(entry.is_regular_file()){

            fs::remove(entry, ec);

            if(ec){ //if ec contain any error

                errors++;
                skipped++;
            
            }
            else{ //if not then successful
                success++;
            }
        }

        ec.clear(); //clearing the ec container for next iteration

        
    }

    //giving report of operation
    cout<<"[SIR]: "<<errors<<" errors encountered\n";
    cout<<"[SIR]: "<<skipped<<" Files and Folders Skipped\n";
    cout<<"[SIR]: "<<success<<" Files and Folders are Deleted Successfully\n";

    

}