#include "global.h"

string convertToASCII(string password) {
	string result = "";
	int_fast64_t convert;
	for (int i = 0; i < password.length(); i++)
	{
		convert = int(password[i]);
		convert = convert % 7;
		string  inter = to_string(convert);
		result = result + inter;
	}
	return result;
}

/************************* 
	HASHING - Can't do more than 9 characters
/***********************************/
string hash_password(string password) {
	uint_fast64_t toss = 1;
	int64_t  passkey_to_asci;
	int64_t salt = 97;
	int64_t mod = 7;
	int64_t hash_num;

	while (toss) {
		passkey_to_asci = stoi(convertToASCII(password));
		hash_num = passkey_to_asci % 7;
		hash_num = hash_num + int32_t(salt);
		toss = toss - 1;
	}
	//cout << hash_num;
	return to_string(hash_num);
}

/*----------------
	!!!!NEED TO ADD MAX 3 TIMES LOGIN!!!!!
----------------*/
bool login(User& user) {
	string username, clear_pass, hash_pass, user_id, user_type, text;
	vector<string>usernames;
	vector<string>passwords;
	vector<string>user_ids;
	vector<string>user_types;
	encdec enc;
	int userIndex = 0;
	int loginCount = 0;

		cout << "Please enter your username:" << endl;
		cin >> username;
		cout << "Please enter your password:" << endl;
		cin >> clear_pass;

		enc.decrypt("users"); // Decrypt File before opening
		ifstream users("users.txt"); // Opening the file.
		if (users.is_open()) { // If the file is open
			// Ignore first line for column names
			string line;
			getline(users, line);

			while (!users.eof()) { // While the end of file is NOT reached
				getline(users, text, ',');
				user_ids.push_back(text);
				getline(users, text, ',');
				usernames.push_back(text);
				getline(users, text, ',');
				passwords.push_back(text);
				getline(users, text, '\n'); // New line after password
				user_types.push_back(text);
			}
			users.close(); //closing the file
		}
		else {
			cout << "ERROR: Unable to open file"; // Error if file can't open
		}
		enc.encrypt("users"); // Re-encrypt File before opening

		// Check if username entered matches with any username and if so returns their user_id
		vector<string>::iterator it;
		it = find(usernames.begin(), usernames.end(), username);

		if (it != usernames.end()) { // If it doesn't make to end then username is in vector
			userIndex = it - usernames.begin();	// finds user_id

			//Hashing the password that was just entered.
			hash_pass = hash_password(clear_pass);

			// Test if hashed password is the equal to the password retreived from file
			if (hash_pass == passwords[userIndex]) {
				cout << endl << "Login successful" << endl;

				// Set up user object
				user.setUserId(to_string(userIndex + 1));
				user.setUsername(username);
				user.setUserType(user_types[userIndex]);

				log(user, "Login"); // Log which user has logged in

				return true; // Show menu that user logged in
			}
			else {
				cout << "ERROR: Password did not match." << endl << endl;

				user.setUserId("0");
				log(user, "Failed Login"); // Log which user failed a login
				return false; // Show menu that user did not log in
			}
		}
		else {
			// Show menu that user did not log in
			cout << "ERROR: Username not found." << endl << endl;
			
			user.setUserId("0");
			log(user, "Failed Login"); // Log which user failed a login
			return false;
		}
}

void create_account(User& user) {
	string username, password_first, password_second, user_id, inputPassword, inputUsername, hash_pass;
	encdec enc;

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
	enc.decrypt("users"); // Decrypt File before opening
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

	// Set up user object
	user.setUserId(to_string(stoi(user_id) + 1));
	user.setUsername(username);
	user.setUserType("customer");

	// Hash password
	hash_pass = hash_password(password_first);

	// Adds new user to users.txt
	ofstream usersOut("users.txt", fstream::app);
	if (usersOut.is_open()) { // If the file is open
		usersOut << "\n" << stoi(user_id) + 1 << "," << username << "," << hash_pass << "," << "customer"; // Add whole line
		usersOut.close(); //closing the file
	}
	else 
		cout << "Unable to open file"; // Error if file can't open
	enc.encrypt("users"); // Re-encrypt File before opening
}