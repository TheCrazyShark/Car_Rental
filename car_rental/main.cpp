#include <iostream>
#include <string>
using namespace std;

void main_menu() {
	string username, password;
	int user_input;

	cout << "Welcome to the car rental service! Enter 1 if you already have an account, otherwise enter 2 to create an account.";
//login: add 3 iterations and then end program
	do {
		cin >> user_input;
		if (user_input == 1) {
			cout << "Please enter your username";
			cin >> username;
			cout << "Please enter your password";
			cin >> password;

			login();
		}
		else if (user_input == 2) {
			create_account();
		}
		else {
			cout << "Invalid input, please try again.";
		}
	} while (user_input != 1 || user_input != 2);
}

void login(){
	
}

void create_account() {

}

int main() {
	main_menu();

	return 0;
}
