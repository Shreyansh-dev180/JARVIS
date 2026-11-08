#include<iostream>
#include<Windows.h>
#include<pdh.h>
#include<string>

using namespace std;


string cpu_monitor_module() {

	string result = "";


	PDH_HQUERY query;
	PDH_HCOUNTER counter;

	//opening query;
	PdhOpenQueryW(NULL, 0, &query);

	//adding counter to query
	PdhAddEnglishCounterW(
		query,
		L"\\Processor(_Total)\\% Processor Time",
		0,
		&counter
	);

	//collecting data
	PdhCollectQueryData(query);

	Sleep(1000);

	PdhCollectQueryData(query);

	//get counter's result in formatted form as double

	PDH_FMT_COUNTERVALUE value;

	PdhGetFormattedCounterValue(
		counter,
		PDH_FMT_DOUBLE,
		NULL,
		&value
	);

	

	if (value.doubleValue >= 90) {
		result = "warning";
	}
	else {
		result = "safe";
	}

	PdhCloseQuery(query);

	return result;
	

}