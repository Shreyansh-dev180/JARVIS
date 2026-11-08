#include<iostream>
#include<thread>
#include<chrono>
#include<string>

//local includes
#include "ram_health.h"
#include "cpu_health.h"

using namespace std;

//Global Variables Declaration: 

int ram_health_warning_count = 0;
int cpu_health_warning_count = 0;

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
		
		string cpu_health_result = cpu_monitor_module();
		
		if (cpu_health_result == "warning") {
			cpu_health_warning_count++;
		}

		else if (cpu_health_result == "safe") {
			cpu_health_warning_count = 0;
		}
		
		if (cpu_health_warning_count >= 5) {
			cout << "[SIR]: Warning! CPU Bottle-necking\n";
			cout << "[SIR]: High CPU Uses Detected\n";

			//reset warning count to 0 to avoid spamming;

			cpu_health_warning_count = 0;

		}
		


		this_thread::sleep_for(chrono::seconds(5));
	}

	cout << "System Health Monitor Stopped\n";

}