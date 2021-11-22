#include "global.h"
#include <ctime>

/*****************************
	Log is called after every "action" that is made. The function recieves
	the user_id that made the action as well as what the action was. It will then
	push to a file that holds that information as well as the date/time that it occured
****************************/
void log(User& user, string action_type) {
	string date, time; // GET CURRENT DATE
	string user_id;

	user_id = user.getUserId();

	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< "\n";

	ofstream requestsOut("log.txt", fstream::app);
	if (requestsOut.is_open()) { // If the file is open
		requestsOut << "\n" << user_id << "," << action_type << "," << date << "," << time; // Add whole line
		requestsOut.close(); //closing the file
	}
}