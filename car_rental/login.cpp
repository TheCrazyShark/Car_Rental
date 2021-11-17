#include "global.h"
//#include "bcrypt.h"

/*----------------
	Might be worthwhile to create an object to merge the login() and create_account() functions since their initial layout is similar

	!!!!NEED TO ADD MAX 3 TIMES LOGIN!!!!!
----------------*/
void login(User& user) {
	string username, clear_pass, hash_pass, user_id, user_type;
	string Hash_function(string);
	vector<string>usernames;
	vector<string>passwords;
	vector<string>user_ids;
	int loginCount = 0;

	cout << "Please enter your username:" << endl;
	cin >> username;
	cout << "Please enter your password:" << endl;
	cin >> clear_pass;

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
			getline(users, hash_pass, '\n'); // New line after password
			passwords.push_back(hash_pass);
		}
		users.close(); //closing the file
	}
	else cout << "ERROR: Unable to open file"; // Error if file can't open

	// Check if username entered matches with any username and if so returns their user_id
	vector<string>::iterator it;
	it = find(usernames.begin(), usernames.end(), username);
	int userIndex;

	if (it != usernames.end()) { // If it doesn't make to end then username is in vector
		userIndex = distance(usernames.begin(), it) - 1; // Find distance in order to calculate user_id
		cout << "Username found. User id is: " << userIndex << endl;
	}
	else {
		cout << "ERROR: Username not found." << endl;
	}

	//Hashing the password that was just entered.
	//hash_pass = Hash_function(clear_pass);
	//cout << hash_pass << endl; //Debugging

	// Test if hashed password is the equal to the password retreived from file
	if (clear_pass == passwords[userIndex]) {
		cout << "Login successful" << endl;
	}
	else {
		cout << "ERROR: Password did not match." << endl;
	}
	
	// Set up user object
	user.setUserId(user_id);
	user.setUsername(username);
	user.setUserType(user_type);

	/******************************************
	1. Hash the password that was just entered
	2. Select the password (Should be hashed) from the database by matching the usernames
	3. Test the newly hashed password against the pulled password and test if they are the same
		ERROR: Provide same error message no matter if account isn't found or password doesn't match "Account not found or password is incorrect"
	******************************************/
}

void create_account(User& user) {
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
		}
		usersIn.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open

	/********************************************
	HASH PASSWORD BEFORE WRITING PASSWORD TO FILE
	********************************************/

	// Set up user object
	user.setUserId(user_id);
	user.setUsername(username);
	user.setUserType("customer");

	// Adds new user to users.txt
	ofstream usersOut("users.txt", fstream::app);
	if (usersOut.is_open()) { // If the file is open
		usersOut << "\n" << stoi(user_id) + 1 << ", " << username << ", " << password_first << ", " << "customer"; // Add whole line
		usersOut.close(); //closing the file
	}
	else 
		cout << "Unable to open file"; // Error if file can't open
}

/********************
	Called by create_account() and login() to get a hash of passwords for testing.
********************/
/*string hash_function(string password) {
	string password_1, hash;
	password_1 = password;
	//Will Add GenerateHash and GenerateSALT by the next phase.
	hash = bcrypt::GenerateHash(password_1);
	//cout << "Hash: " << Hash << endl; // DEBUGGING

	return hash;
}*/