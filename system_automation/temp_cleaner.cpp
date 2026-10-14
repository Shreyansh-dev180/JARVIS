#include<iostream>
#include<cstdlib>
#include<thread>
#include<chrono>




using namespace std;
namespace fs = filesystem;

void temp_clean(){
    system("winapp ui send-keys \"Win+R\" -a \"Program Manager\" --via send-input --allow-system-keys");
    this_thread::sleep_for(chrono::seconds(1));

    system("winapp ui send-keys \"Backspace\" -a \"Run\"");

    system("winapp ui send-keys \"Temp\" -a \"Run\"");

    system("winapp ui send-keys \"Enter\" -a \"Run\"");

    this_thread::sleep_for(chrono::seconds(3));

    //not functioning : Under Development...

    system("winapp ui send-keys \"Ctrl+A\" -a \"Temp\"");

    system("winapp ui send-keys \"delete\" -a \"Temp\"");
}