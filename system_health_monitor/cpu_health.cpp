#include<iostream>
#include<Windows.h>
#include<pdh.h>
#include<string>

using namespace std;


string cpu_monitor_module() {

	string result = "";
	
	PDH_STATUS status;

	PDH_HQUERY query = nullptr;
	PDH_HCOUNTER counter = nullptr;

	//opening query;
	status = PdhOpenQueryW(NULL, 0, &query);

	if (status != ERROR_SUCCESS) {
		return "error";
	}

	//adding counter to query
	status = PdhAddEnglishCounterW(
		query,
		L"\\Processor(_Total)\\% Processor Time",
		0,
		&counter
	);

	if (status != ERROR_SUCCESS) {
		PdhCloseQuery(query);
		return "error";
	}

	//collecting data
	status = PdhCollectQueryData(query);

	if (status != ERROR_SUCCESS) {
		PdhCloseQuery(query);
		return "error";
	}

	Sleep(1000);

	status = PdhCollectQueryData(query);

	if (status != ERROR_SUCCESS) {
		PdhCloseQuery(query);
		return "error";
	}

	//get counter's result in formatted form as double

	PDH_FMT_COUNTERVALUE value;

	status = PdhGetFormattedCounterValue(
		counter,
		PDH_FMT_DOUBLE,
		NULL,
		&value
	);

	if (status != ERROR_SUCCESS) {
		PdhCloseQuery(query);
		return "error";
	}

	

	if (value.doubleValue >= 90) {
		result = "warning";
	}
	else {
		result = "safe";
	}

	PdhCloseQuery(query);

	return result;
	

}