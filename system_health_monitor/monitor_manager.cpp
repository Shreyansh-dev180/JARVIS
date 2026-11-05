#include<iostream>
#include<thread>
#include<chrono>
#include<string>

//local includes
#include "ram_health.h"

using namespace std;

//Global Variables Declaration: 

int ram_health_warning_count = 0;

void system_health_monitor_manager(stop_token token) {
	//run while loop while stop request not called
	while (!token.stop_requested()) {
		//ram health checkup;

		string ram_health_result = ram_monitor_module();

		//update warning count based on result.
		if (ram_health_result == "warning") {
			ram_health_warning_count++;
		}
		//if safe result then reset warning count.
		else {
			ram_health_warning_count = 0;
		}

		//check if ram_health_warning_count > 5 then warn user

		if (ram_health_warning_count >= 5) {
			cout << "[SIR]: Warning! Ram Bottle-necking\n";
			cout << "[SIR]: High Uses of Ram Detected\n";
			//set ram health monitor again to 0 
			//to avoid spamming warning messages.
			ram_health_warning_count = 0;
		}

		//cpu health checkup;



		this_thread::sleep_for(chrono::seconds(5));
	}

	cout << "System Health Monitor Stopped\n";

}