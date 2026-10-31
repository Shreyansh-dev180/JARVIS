#include<iostream>
#include<windows.h>
#include<string>

using namespace std;

string ram_monitor_module() {
	MEMORYSTATUSEX mem{};

	mem.dwLength = sizeof(mem);

	if (GlobalMemoryStatusEx(&mem)) {
		if (mem.dwMemoryLoad >= 90) {
			return "warning";
		}
		else {
			return "safe";
		}

	}
	else {
		cout << "[SIR]: Failed to Access Memory Details\n";
		cout << "[SIR]: Please Try Again\n";
		return "error";
	}
}