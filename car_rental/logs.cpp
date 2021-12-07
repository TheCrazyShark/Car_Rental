#include "global.h"
#include <ctime>   // localtime

/*****************************
	Get string of current date/time
****************************/
string getCurrDateTime() {
	time_t now = time(0);
	char str[26]; // Enable Buffer
	ctime_s(str, sizeof str, &now); // convert now to string form

	return str;
}

/*****************************
	Log is called after every "action" that is made. The function recieves
	the user_id that made the action as well as what the action was. It will then
	push to a file that holds that information as well as the date/time that it occured
****************************/
void log(User& user, string action_type) {
	string date_time;
	encdec enc;

	date_time = getCurrDateTime(); // Get current date

	enc.decrypt("log");
	ofstream logOut("log.txt", fstream::app);
	if (logOut.is_open()) { // If the file is open
		logOut << user.getUserId() << "," << action_type << "," << date_time; // Add whole line
		logOut.close(); //closing the file
	}
	enc.encrypt("log");
}

/****************************
	Called by admins in order to view a list of all the logs
****************************/
void view_logs() {
	encdec enc;

	enc.decrypt("log"); // Decrypt File before opening
	ifstream logIn("log.txt");
	if (logIn.is_open()) { // If the file is open
		string line;
		cout << endl;

		/*------------------------
			will show column names for reference
		------------------------*/
		cout << "User ID, Action Taken, Date & Time" << endl;
		while (getline(logIn, line)) { // While the end of file is NOT reached
			cout << line << endl;
		}
		logIn.close(); //closing the file
	}
	else cout << "Unable to open file" << endl; // Error if file can't open
	enc.encrypt("log"); // Re-encrypt File before opening
}