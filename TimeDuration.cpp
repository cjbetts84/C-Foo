/*TimeDuration.cpp
Problem 3 - Time Duration
Compute the duration in time between a start time and a finish time. The start and 
finish time will include hours, minutes, seconds, and either AM or PM. Your time 
difference will always be nonnegative and less thatn 24 hours. You must accept the 
input with a colon between the numbers followed by a space and either AM or PM as 
indicated below. For a 20 minute time penalty, you may choose your own input format.

Sample data:
Start		Finish		Duration
3:52:02 AM	4:15:01 PM	12:22:59
10:35:18 AM	7:28:05 AM	20:52:47
*/

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main(void){

	string startTime, stopTime;
	int startH, startM, startS, stopH, stopM, stopS = 0;
	int durS, durM, durH = 0;

	cout << "Enter start time: ";
	getline(cin, startTime);

	cout << "Enter finish time: ";
	getline(cin, stopTime);

	//Parse out hours, minutes, seconds from startTime
	startH = stoi(startTime.substr(0, startTime.find(":")));
	startM = stoi(startTime.substr(startTime.find(":") + 1, startTime.find(":") + 2));
	startS = stoi(startTime.substr(startTime.rfind(":") + 1, startTime.rfind(":") + 2));

	//Convert to military time
	if (startTime.find("P") != string::npos){
		startH += 12;
	}

	//Parse out hours, minutes, seconds from stopTime
	stopH = stoi(stopTime.substr(0, stopTime.find(":")));
	stopM = stoi(stopTime.substr(stopTime.find(":") + 1, stopTime.find(":") + 2));
	stopS = stoi(stopTime.substr(stopTime.rfind(":") + 1, stopTime.rfind(":") + 2));

	//Convert to military time
	if (stopTime.find("P") != string::npos){
		stopH += 12;
	}

	//Figure out duration of seconds
	if (stopS >= startS){
		durS = stopS - startS;
	}
	else{	//borrow if necessary
		stopM -= 1;
		stopS += 60;
		durS = stopS - startS;
	}

	//Figure out duration of minutes
	if (stopM >= startM){
		durM = stopM - startM;
	}
	else{
		stopH -= 1;
		stopM += 60;
		durM = stopM - startM;
	}

	//Figure out duration of hours
	durH = stopH - startH;
	if (durH < 0){
		durH += 24;
	}

	//Output
	cout << "Start\t\tFinish\t\tDuration\n"
		<< startTime << "\t" << stopTime << "\t" 
		<< durH << ":" << setfill('0') << setw(2) << durM << ":" 
		<< setfill('0') << setw(2) << durS << endl;

	return 0;
}//end main(void)
