#include <iostream>
#include <string>
using namespace std;

void main_menu() {
	int user_input;

	cout << "Welcome to the car rental service! Enter 1 if you already have an account, otherwise enter 2 to create an account." << endl;
	cout << "1 - Login" << endl;
	cout << "2 - Create Account" << endl;

	do {
		cin >> user_input;
		if (user_input == 1) { // Login
			login();
		}
		else if (user_input == 2) { // Create account
			create_account();
		}
		else {
			cout << "Invalid input, please try again.";
		}
	} while (user_input != 1 || user_input != 2);
}

void login() {
	//login: add 3 iterations and then end program
	string username, password;

	cout << "Please enter your username";
	cin >> username;
	cout << "Please enter your password";
	cin >> password;
}

void create_account() {

}

int main() {
	main_menu();

	return 0;
}