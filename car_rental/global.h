#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma once


/*-----------------
	Class to store user information to be used in logs and permissions
-----------------*/
class User {
private:
	string username, pass_hash, user_id, user_type;
public:
	User();

	// Set User class variables
	void setUsername(string username_i);
	void setUserId(string user_id_i);
	void setUserType(string user_type_i);

	// Get User class variables
	string getUsername();
	string getUserId();
	string getUserType();
};

/**************** menus.cpp ****************/
void main_menu();
void admin_menu(User& user);
void customer_menu(User& user);
void mech_menu(User& user);

/**************** login.cpp ****************/
void login(User& user);
void create_account(User& user);
string hash_password(string password);

/**************** main.cpp ****************/
// Customer Functions
void request_car();
void return_car();

// Admin Functions
void issue_repair();
bool issue_or_deny();
void view_requests();

// Mech Functions

/**************** logs.cpp ****************/
void log(string user_id, string action_type);