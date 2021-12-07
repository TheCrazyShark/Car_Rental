#include "global.h"

/*-----------------
	Class to store user information to be used in logs and permissions
-----------------*/
User::User() {
	username = "";
	pass_hash = "";
	user_id = "";
	user_type = "";
}
// Set User class variables
void User::setUsername(string username_i) {
	username = username_i;
}
void User::setUserId(string user_id_i) {
	user_id = user_id_i;
}
void User::setUserType(string user_type_i) {
	user_type = user_type_i;
}
// Get User class variables
string User::getUsername() {
	return username;
}
string User::getUserId() {
	return user_id;
}
string User::getUserType() {
	return user_type;
}

/*****************************
	Lists available options for the admin
****************************/
void admin_menu(User& user) {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	do {
		cout << "1 - View Car Requests" << endl;
		cout << "2 - View Car Returns" << endl;
		cout << "3 - View Logs" << endl;
		cout << "4 - Exit" << endl;

		cin >> user_input;
		if (user_input == "1") { // View Requests
			view_requests();
			log(user, "Viewed Requests"); // Log which admin viewed requests
			cout << endl;
		}
		else if (user_input == "2") { // View Car Return Submission
			view_returns();
			log(user, "Viewed Returns"); // Log which admin viewed returns
			cout << endl;
		}
		else if (user_input == "3") { // View Logs
			view_logs();
			log(user, "Viewed Logs"); // Log which admin viewed logs
			cout << endl;
		}
		else if (user_input == "4") { // Exits from program
			exit(0);
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2" || user_input != "3" || user_input != "4");
}

/*****************************
	Lists available options for the customer
****************************/
void customer_menu(User& user) {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	do {
		cout << "1 - Request Car" << endl;
		cout << "2 - Return Car" << endl;
		cout << "3 - Exit" << endl;

		cin >> user_input;
		cin.ignore();
		if (user_input == "1") { // Request Car
			request_car();
			log(user, "Requested Car"); // Log which user requested car
			cout << endl;
		}
		else if (user_input == "2") { // Return Car
			return_car();
			log(user, "Returned Car"); // Log which user returned car
			cout << endl;
		}
		else if (user_input == "3") { // Exits from program
			exit(0);
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2" || user_input != "3");
}

/*****************************
	Lists available options for the mechanic
****************************/
void mech_menu(User& user) {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	do {
		cout << "1 - View Repair Reports" << endl;
		cout << "2 - Exit" << endl;

		cin >> user_input;
		if (user_input == "1") { // View Repair Reports
			// List repair reports
			log(user, "Viewed Repair Reports"); // Log which mech viewed repair reports
			cout << endl;
		}
		else if (user_input == "2") { // Exits from program
			exit(0);
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1");
}

void main_menu() {
	string user_input;
	User user;

	do {
		cout << "Welcome to the car rental service! Enter 1 if you already have an account, otherwise enter 2 to create an account." << endl;
		cout << "1 - Login" << endl;
		cout << "2 - Create Account" << endl;
		cout << "3 - Exit" << endl;

		cin >> user_input;
		if (user_input == "1") { // Login
			if (login(user)) {
				// Give menu based on user level
				if (user.getUserType() == "customer") {
					customer_menu(user);
				}
				else if (user.getUserType() == "admin") {
					admin_menu(user);
				}
				else if (user.getUserType() == "mechanic") {
					mech_menu(user);
				}
			}
		}
		else if (user_input == "2") { // Create account
			create_account(user);
			customer_menu(user);
		}
		else if (user_input == "3") { // Exits from program
			exit(0);
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2" || user_input != "3");
}