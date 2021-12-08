#include "global.h"

/******************
THINGS TO ADD:
Exit program if login fails 3 times
Make hashing better
Add ability to view/edit user information as Admin user
Make it so Mech can view the repair requests --> Mark specific requests as complete
Make it so Admin can accept or deny a current request after viewing requets
Make it so Customer can view their current requests
issue_repair needs the fix that is in the comments of the file
*******************/

/*********************************************** CUSTOMER FUNCTIONS *****************************************************/

/*****************************
	Request car will be called if the user wants to request a car.
	The user can request to view the available cars. Which will be printed into the console.
	It will ask what kind of car they want long with some other info and then pass the info on to the admin.
	Im thinking pass the user input into a text file that the admin can access then delete.
	Error statement if car type not available.
****************************/
void request_car() {
	string request_id, firstName, lastName, address, carType, rentalUse, rentalTime;
	encdec enc;

	cout << "Enter first name: ";
	getline(cin, firstName);
	cout << "Enter last name: ";
	getline(cin, lastName);
	cout << "Enter your address: ";
	getline(cin, address);
	cout << "Enter preferred rental type(Car, Truck, Suv, Van): ";
	getline(cin, carType);
	cout << "Enter why you want to rent: ";
	getline(cin, rentalUse);
	cout << "How long are you expecting to rent: ";
	getline(cin, rentalTime);
	//need to figure out how to store the request

	enc.decrypt("requests"); // Decrypt File before opening
	ifstream requestsIn("requests.txt");
	if (requestsIn.is_open()) { // If the file is open
		// Ignore first line for column names
		string line;
		getline(requestsIn, line);

		while (!requestsIn.eof()) { // While the end of file is NOT reached
			string line;
			getline(requestsIn, request_id, ',');
			getline(requestsIn, line, '\n'); // IGNORE THIS INPUT - Only needed to get to end of line
		}
		requestsIn.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open

	ofstream requestsOut("requests.txt", fstream::app);
	if (requestsOut.is_open()) { // If the file is open
		requestsOut << "\n" << stoi(request_id) + 1 << "," << firstName << "," << lastName << "," << address << "," << carType << "," << rentalUse
			<< "," << rentalTime; // Add whole line
		requestsOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
	enc.encrypt("returns"); // Re-encrypt File before opening
}

/*****************************
	Return car will be called when a user wants to return a car.
	The user will fill out the return form.
	The form will then be viewable by the admin.
	Admin will either decide to issue a repair ticket or return the car to the database.
****************************/
void return_car() {
	string damage, damages, dateReturned, milesDriven;
	encdec enc;

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
	getline(cin, dateReturned);
	cout << "How many miles have you driven:  ";
	getline(cin, milesDriven);

	enc.decrypt("returns"); // Decrypt File before opening
	ofstream returnsOut("returns.txt", fstream::app);
	if (returnsOut.is_open()) { // If the file is open
		returnsOut << "\n" << damage << "," << damages << "," << dateReturned << "," << milesDriven; // Add whole line
		returnsOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
	enc.encrypt("returns"); // Re-encrypt File before opening
}

/*********************************************** ADMIN FUNCTIONS *****************************************************/

/*****************************
	After the car is returned this fuction is called if the car needs repaired.
	The admin will fill out a form of the cars information and will attach the damages or
	suspected problems that the customer decribed.
****************************/
void issue_repair() {
	string carPlate, damages;
	encdec enc;

	cout << "What were the damages or problems: ";
	getline(cin, damages);
	//cin.ignore();
	cout << "What is the car's plate number: ";
	getline(cin, carPlate);
	
	/*****************************************************
		DON'T GET INFORMATION ABOUT CAR, ASK FOR PLATE, THEN SEARCH CARS FILE FOR CAR & GET INFORMATION, THEN SEARCH RETURNS THEN WRITE TO REPAIRS FILE
	******************************************************/ 

	enc.decrypt("repairs"); // Decrypt File before opening
	ofstream repairsOut("repairs.txt", fstream::app);
	if (repairsOut.is_open()) { // If the file is open
		repairsOut << "\n" << damages << "," << carPlate; // Add whole line
		repairsOut.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
	enc.encrypt("repairs"); // Re-encrypt File before opening
}

/*****************************
	Called by view_requests after an admin selects a specific request
	and allows the admin to accept or deny the request
****************************/
bool issue_or_deny() {
	bool decision;
	decision = false;

	return decision;
}

/****************************
	Outputs all requests and lets an admin select 
	and view the specific information of a request.
***************************/
void view_requests() {
	encdec enc;

	enc.decrypt("requests"); // Decrypt File before opening
	ifstream requestsIn("requests.txt");
	if (requestsIn.is_open()) { // If the file is open
		string line;
		cout << endl;

		/*------------------------
			will show column names for reference
		------------------------*/
		while (getline(requestsIn, line)) { // While the end of file is NOT reached
			cout << line << endl;
		}
		requestsIn.close(); //closing the file
	}
	else cout << "Unable to open file" << endl; // Error if file can't open
	enc.encrypt("requests"); // Re-encrypt File before opening
}

/****************************
	Outputs all returns and lets an admin select
	and view the specific information of a return.
***************************/
void view_returns() {
	encdec enc;

	enc.decrypt("returns"); // Decrypt File before opening
	ifstream requestsIn("returns.txt");
	if (requestsIn.is_open()) { // If the file is open
		string line;
		cout << endl;

		/*------------------------
			will show column names for reference
		------------------------*/
		while (getline(requestsIn, line)) { // While the end of file is NOT reached
			cout << line << endl;
		}
		requestsIn.close(); //closing the file
	}
	else cout << "Unable to open file" << endl; // Error if file can't open
	enc.encrypt("returns"); // Re-encrypt File before opening
}



/*********************************************** MECH FUNCTIONS *****************************************************/
void view_repairs() {
	encdec enc;

	enc.decrypt("repairs"); // Decrypt File before opening
	ifstream reapirsIn("repairs.txt");
	if (reapirsIn.is_open()) { // If the file is open
		string line;
		cout << endl;

		/*------------------------
			will show column names for reference
		------------------------*/
		while (getline(reapirsIn, line)) { // While the end of file is NOT reached
			cout << line << endl;
		}
		reapirsIn.close(); //closing the file
	}
	else cout << "Unable to open file" << endl; // Error if file can't open
	enc.encrypt("repairs"); // Re-encrypt File before opening
}

int main() {
	// Manually decrypt files
	//encdec enc;

	//enc.decrypt("repairs");
	//enc.encrypt("repairs");
	
	main_menu();

	return 0;
}
