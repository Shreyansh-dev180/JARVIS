#include<iostream>
#include<windows.h>


using namespace std;


void Memory_info() {
	//Ram-memory details
	MEMORYSTATUSEX memory{}; //container with name memory having some fields

	//window require us to fill the dwlength field with size of container 
	memory.dwLength = sizeof(memory);

	//GlobalMemoryStatusEx() function fills all fields with data but if 
	//it was successfull then return 1 else 0 so 

	if (GlobalMemoryStatusEx(&memory)) {
		//Memory Info;
		cout << "Memory Info is As: " << '\n';

		//Total Memory.
		cout << "Total Ram: " << memory.ullTotalPhys / (1024 * 1024) << " MB" << '\n';
		//Free Ram.
		cout << "Free Ram: " << memory.ullAvailPhys / (1024 * 1024) << " MB" << '\n';
		//Ram in use in %
		cout << "Ram in Use: " << memory.dwMemoryLoad << " %" << '\n';

	}

	else {
		cout << "[SIR]: Memory Status Failed\nPlease Try Again\n";
	}
}


void Cpu_info() {
	SYSTEM_INFO sys{}; //made a container for storing the cpu details 
						// in different fields 
	//telling the window to fill the data in container's field.

	GetSystemInfo(&sys); //this func dont return any true or false on success
						// or failure so no need to check with if else;

	cout << "[SIR]: Cpu Details Are As: \n";
	cout << "Logical Units (Cores) : " << sys.dwNumberOfProcessors << '\n';
	
	//Processor architecture AMD64(x64) || INTEL(x86) || ARM64(xARM64);
	if (sys.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_AMD64) {
		cout << "Processor Architecture: x64 \n";
	}
	else if (sys.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_INTEL) {
		cout << "Processor Architecture: x86 \n";
	}
	else if (sys.wProcessorArchitecture == PROCESSOR_ARCHITECTURE_ARM64) {
		cout << "Processor Architecture: xARM64 \n";
	}
	else {
		cout << "Processor Architecture Could'nt be recognised\n";
	}
}

