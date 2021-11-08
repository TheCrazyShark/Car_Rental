#include "global.h"
void admin_menu();
void customer_menu();
void mech_menu();


void admin_menu() {

}

void customer_menu() {

}

void mech_menu() {

}

void main_menu() {
	string user_input;

	cout << "Welcome to the car rental service! Enter 1 if you already have an account, otherwise enter 2 to create an account." << endl;
	cout << "1 - Login" << endl;
	cout << "2 - Create Account" << endl;

	do {
		cin >> user_input;
		if (user_input == "1") { // Login
			login();
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