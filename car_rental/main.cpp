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

	int i = 0; // Counter for file
	ifstream users("users.txt"); // Opening the file.
	if (users.is_open()) { // If the file is open
		// Ignore first line for column names
		string line;
		getline(users, line);

		while (!users.eof()) { // While the end of file is NOT reached
			getline(users, user_id, ',');
			user_ids.push_back(user_id); // NEEDS TO BE INT
			getline(users, username, ',');
			usernames.push_back(username);
			getline(users, password, '\n'); // New line after password
			passwords.push_back(password);

			i += 1; // Increment number of lines
		}
		users.close(); //closing the file
	}
	else cout << "Unable to open file"; //if the file is not open output

	// Check if username entered matches with any username and if so returns their user_id
	vector<string>::iterator it;
	it = find(usernames.begin(), usernames.end(), username);
	int userIndex;

	if (it != usernames.end()) { // If it doesn't make to end then username is in vector
		userIndex = distance(usernames.begin(), it) - 1; // Find distance in order to calculate user_id
		cout << "Username found. User id is: " << userIndex << endl;
	}
	else
		cout << "Username not found" << endl;

	if (password == passwords[userIndex]) {
		cout << "Login successful" << endl;
	}
	else
		cout << "Password did not match" << endl;

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

/******************
	Request car will be called if the user wants to request a car.
	The user can request to view the available cars. Which will be printed into the console.
	It will ask what kind of car they want long with some other info and then pass the info on to the admin.
	Im thinking pass the user input into a text file that the admin can access then delete.
	Error statement if car type not available.
******************/
void request_car() {
	string firstName, lastName, address, carType, rentalUse;

	cout << "Enter first name: " << "\n";
	cin >> firstName;
	cout << "Enter last name: " << "\n";
	cin >> lastName;
	cout << "Enter you address: " << "\n";
	cin >> address;
	cout << "Enter preferred rental type(Car, Truck, Suv, Van): " << "\n";
	cin >> carType;
	cout << "Enter why you want to rent: " << "\n";
	//need to figure out how to store the request
}

int main() {
	main_menu();

	return 0;
}