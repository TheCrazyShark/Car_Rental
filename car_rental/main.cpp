#include "global.h"

/*----------------
Might be worthwhile to create an object to merge the login() and create_account() functions since their initial layout is similar
----------------*/
void login() {
	//login: add 3 iterations and then end program
	string username, password, user_id;
	vector<string>usernames;
	vector<string>passwords;
	vector<string>user_ids;

	cout << "Please enter your username:" << endl;
	cin >> username;
	cout << "Please enter your password:" << endl;
	cin >> password;

	int i = 0;

	ifstream users("users.txt"); //opening the file.
	if (users.is_open()) //if the file is open
	{
		//ignore first line
		string line;
		getline(users, line);

		while (!users.eof()) //while the end of file is NOT reached
		{
			//I have 3 sets {user_id, username, password} so use 3 getlines
			getline(users, user_id, ',');
			user_ids.push_back(user_id);
			getline(users, username, ',');
			usernames.push_back(username);
			getline(users, password, '\n'); //new line after password
			passwords.push_back(password);

			i += 1; //increment number of lines
		}
		users.close(); //closing the file
		cout << "Number of entries: " << i - 1 << endl;
	}
	else cout << "Unable to open file"; //if the file is not open output

	/*----------------
	1. Hash the password that was just entered
	2. Select the password (Should be hashed) from the database by matching the usernames
	3. Test the newly hashed password against the pulled password and test if they are the same
		ERROR: Provide same error message no matter if account isn't found or password doesn't match "Account not found or password is incorrect"
	----------------*/
}

void create_account() {
	string username, password_first, password_second;
	
	cout << "Create your username." << endl;
	cin >> username;
	do { // Repeat if the two passwords do not match ------ Will probably change this in order to clear up wording
		cout << "Create your password." << endl;
		cin >> password_first;
		cout << "Please re-enter your password." << endl;
		cin >> password_second;
		if (password_first != password_second) {
			cout << "Passwords do not match, please re-enter.";
		}
	} while (password_first != password_second);


}

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

void request_car(){

}

int main() {
	main_menu();

	return 0;
}