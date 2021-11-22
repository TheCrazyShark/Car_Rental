#include "global.h"
#include <ctime>

/*****************************
	Log is called after every "action" that is made. The function recieves
	the user_id that made the action as well as what the action was. It will then
	push to a file that holds that information as well as the date/time that it occured
****************************/
void log(string user_id, string action_type) {
	string date, time; // GET CURRENT DATE

	time_t t = time(0);   // get time now
	tm* now = localtime(&t);
	cout << (now->tm_year + 1900) << '-'
		<< (now->tm_mon + 1) << '-'
		<< now->tm_mday
		<< "\n";
}