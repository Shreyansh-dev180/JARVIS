#include<iostream>
#include<thread>
#include<chrono>
#include<string>

//local includes
#include "ram_health.h"

using namespace std;


void system_health_monitor_manager(stop_token token) {
	//run while loop while stop request not called
	while (!token.stop_requested()) {
		//ram health checkup;
		int ram_health_warning_count = 0;
		string ram_health_result = ram_monitor_module();

		if (ram_health_result == "warning") {
			ram_health_warning_count++;
		}
		else {
			ram_health_warning_count = 0;
		}

		//cpu health checkup;

		this_thread::sleep_for(chrono::seconds(5));
	}

	cout << "System Health Monitor Stopped\n";

}