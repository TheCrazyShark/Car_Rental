#include "global.h"
//#include "bcrypt.h"

/*----------------
	Might be worthwhile to create an object to merge the login() and create_account() functions since their initial layout is similar

	!!!!NEED TO ADD MAX 3 TIMES LOGIN!!!!!
----------------*/
void login() {
	// 
	string username, password, hashed_password, user_id;
	string Hash_function(string);
	vector<string>usernames;
	vector<string>passwords;
	vector<string>user_ids;
	int loginCount = 0;

	cout << "Please enter your username:" << endl;
	cin >> username;
	cout << "Please enter your password:" << endl;
	cin >> password;

	//Hashing the password that was just entered.
	//hashed_password = Hash_function(password);
	//cout << hashed_password << endl; //Debugging

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

/******************
	Request car will be called if the user wants to request a car.
	The user can request to view the available cars. Which will be printed into the console.
	It will ask what kind of car they want long with some other info and then pass the info on to the admin.
	Im thinking pass the user input into a text file that the admin can access then delete.
	Error statement if car type not available.
******************/
void request_car() {
	string firstName, lastName, address, carType, rentalUse, rentalTime;
	//
	cout << "Enter first name: ";
	getline(cin, firstName);
	cout << "Enter last name: ";
	getline(cin, lastName);
	cout << "Enter you address: ";
	getline(cin, address);
	cout << "Enter preferred rental type(Car, Truck, Suv, Van): ";
	getline(cin, carType);
	cout << "Enter why you want to rent: ";
	getline(cin, rentalUse);
	cout << "How long are you expecting to rent: ";
	getline(cin, rentalTime);
	//need to figure out how to store the request

	ofstream requestsOut("requests.txt", fstream::app);
	if (requestsOut.is_open()) { // If the file is open
		requestsOut << "\n" << firstName << ", " << lastName << ", " << address << ", " << carType << ", " << rentalUse
			<< ", " << rentalTime; // Add whole line
		requestsOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
}

/******************
	Return car will be called when a user wants to return a car.
	The user will fill out the return form.
	The form will then be viewable by the admin.
	Admin will either decide to issue a repair ticket or return the car to the database.
******************/
void return_car() {
	string damage, damages, dateReturned, milesDriven;

	cout << "Are there any damages (yes/no): ";
	getline(cin,damage);
	if (damage == "yes") {
		cout << "What are the damages: ";
		getline(cin, damages);
	}
	else {
		damages = "none";
	}
	cout << "When did you return the car: ";
	getline(cin, dateReturned);;
	cout << "How many miles have you driven:  ";
	getline(cin, milesDriven);;

	ofstream returnsOut("returns.txt", fstream::app);
	if (returnsOut.is_open()) { // If the file is open
		returnsOut << "\n" << damage << ", " << damages << ", " << dateReturned << ", " << milesDriven; // Add whole line
		returnsOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
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

/******************
	Called by view_requests after an admin selects a specific request
	and allows the admin to accept or deny the request
******************/
bool issue_or_deny() {
	bool decision;
	decision = false;

	return decision;
}

/*****************
	Outputs all requests and lets an admin select 
	and view the specific information of a request.
*****************/
void view_requests() {

}

/******************
	Log is called after every "action" that is made. The function recieves
	the user_id that made the action as well as what the action was. It will then
	push to a file that holds that information as well as the date/time that it occured
******************/
void log(string user_id, string action_type) {
	string date, time; // GET CURRENT DATE
}

int main() {
	//main_menu();
	//request_car();
	return_car();
	return 0;
}