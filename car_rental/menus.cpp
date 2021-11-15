#include "global.h"

/******************
	Lists available options for the admin
******************/
void admin_menu() {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	cout << "1 - View Requests" << endl;
	cout << "2 - View Car Return Submission" << endl;

	do {
		cin >> user_input;
		if (user_input == "1") { // View Requests
			// List requests
		}
		else if (user_input == "2") { // View Car Return Submission
			// List car return subimssions
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2");
}

/******************
	Lists available options for the customer
******************/
void customer_menu() {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	cout << "1 - Request Car" << endl;
	cout << "2 - Return Car" << endl;

	do {
		cin >> user_input;
		if (user_input == "1") { // Request Car
			request_car();
		}
		else if (user_input == "2") { // Return Car
			return_car();
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2");
}

/******************
	Lists available options for the mechanic
******************/
void mech_menu() {
	string user_input;

	cout << "Welcome. Please select what you would like to do!" << endl;
	cout << "1 - View Repair Reports" << endl;

	do {
		cin >> user_input;
		if (user_input == "1") { // View Repair Reports
			// List repair reports
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1");
}

void main_menu() {
	string user_input;

	cout << "Welcome to the car rental service! Enter 1 if you already have an account, otherwise enter 2 to create an account." << endl;
	cout << "1 - Login" << endl;
	cout << "2 - Create Account" << endl;

	do {
		cin >> user_input;
		if (user_input == "1") { // Login
			//user = login();
			// IF LOGIN SUCCSESSFUL PULL TYPE
		}
		else if (user_input == "2") { // Create account
			create_account();
		}
		else {
			cout << "Invalid input, please try again." << endl;
		}
	} while (user_input != "1" || user_input != "2");
}