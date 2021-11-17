#include "global.h"

/******************
	Request car will be called if the user wants to request a car.
	The user can request to view the available cars. Which will be printed into the console.
	It will ask what kind of car they want long with some other info and then pass the info on to the admin.
	Im thinking pass the user input into a text file that the admin can access then delete.
	Error statement if car type not available.
******************/
void request_car() {
	string request_id, firstName, lastName, address, carType, rentalUse, rentalTime;

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

	ifstream requestsIn("users.txt");
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
	getline(cin, dateReturned);
	cout << "How many miles have you driven:  ";
	getline(cin, milesDriven);

	ofstream returnsOut("returns.txt", fstream::app);
	if (returnsOut.is_open()) { // If the file is open
		returnsOut << "\n" << damage << "," << damages << "," << dateReturned << "," << milesDriven; // Add whole line
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
	ifstream requestsIn("requests.txt");
	if (requestsIn.is_open()) { // If the file is open
		string line;
		cout << endl;

		//will show column names for reference
		while (getline(requestsIn, line)) { // While the end of file is NOT reached
			cout << line << endl;
		}
		requestsIn.close(); //closing the file
	}
	else cout << "Unable to open file"; // Error if file can't open
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
	request_car();
	//return_car();
	//view_requests();

	return 0;
}