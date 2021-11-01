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

	ifstream users("users.txt"); // Opening the file.
	if (users.is_open()) { // If the file is open
		// Ignore first line for column names
		string line;
		getline(users, line);

		//int i = 0; // Counter for file

		while (!users.eof()) { // While the end of file is NOT reached
			getline(users, user_id, ',');
			user_ids.push_back(user_id); // NEEDS TO BE INT
			getline(users, username, ',');
			usernames.push_back(username);
			getline(users, password, '\n'); // New line after password
			passwords.push_back(password);

			//i += 1; // Increment number of lines
		}
		users.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open

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

	/******************************************
	1. Hash the password that was just entered
	2. Select the password (Should be hashed) from the database by matching the usernames
	3. Test the newly hashed password against the pulled password and test if they are the same
		ERROR: Provide same error message no matter if account isn't found or password doesn't match "Account not found or password is incorrect"
	******************************************/
}

void create_account() {
	string username, password_first, password_second, user_id, inputPassword, inputUsername;
	
	// User input for username/password
	cout << "Create your username: " << endl;
	cin >> username;
	do { // Repeat if the two passwords do not match ------ Will probably change this in order to clear up wording
		cout << "Create your password: " << endl;
		cin >> password_first;
		cout << "Please re-enter your password: " << endl;
		cin >> password_second;
		if (password_first != password_second) {
			cout << "Passwords do not match, please re-enter.";
		}
	} while (password_first != password_second);

	// Counts the number of users in order to calculate the next available user_id
	ifstream usersIn("users.txt");
	if (usersIn.is_open()) { // If the file is open
		// Ignore first line for column names
		string line;
		getline(usersIn, line);

		while (!usersIn.eof()) { // While the end of file is NOT reached
			string line;
			getline(usersIn, user_id, ',');
			getline(usersIn, line, '\n'); // IGNORE THIS INPUT - Only needed to get to end of line

			//cout << "User ID: " << user_id << ". Username: " << inputUsername << ". Password: " << inputPassword << endl;

			//getline(usersIn, line, '\n').ignore();
		}
		usersIn.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open

	/********************************************
	HASH PASSWORD BEFORE WRITING PASSWORD TO FILE
	********************************************/

	// Adds new user to users.txt
	ofstream usersOut("users.txt", fstream::app);
	if (usersOut.is_open()) { // If the file is open
		usersOut << "\n" << stoi(user_id) + 1 << ", " << username << ", " << password_first; // Add whole line
		usersOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
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
	//
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

/******************
	Return car will be called when a user wants to return a car.
	The user will fill out the return form.
	The form will then be viewable by the admin.
	Admin will either decide to issue a repair ticket or return the car to the database.
******************/
void return_car() {
	string damages, dateReturned;
	int milesDriven;

	cout << "Are there any damages: " << "\n";
	cin >> damages;
	cout << "When did you return the car: " << "\n";
	cin >> dateReturned;
	cout << "How many miles have you driven:  " << "\n";
	cin >> milesDriven;
}

/******************
	After the car is returned this fuction is called if the car needs repaired.
	The admin will fill out a form of the cars information and will attach the damages or
	suspected problems that the customer decribed.
******************/
void repair_car() {
	string carType, carPlate, carColor, damages;
	cout << "What were the damages or problems: " << "\n";
	cin >> damages;
	cout << "What is the car's plate number: " << "\n";
	cin >> carPlate;
	cout << "What tpye of car is it: " << "\n";
	cin >> carType;
	cout << "What is the car's color:  " << "\n";
	cin >> carColor;
}

int main() {
	main_menu();

	return 0;
}
