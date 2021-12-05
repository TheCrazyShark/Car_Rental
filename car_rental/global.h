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

/*----------------------
	Class to encrypt and decrypt files using simple cesear cipher
----------------------*/
class encdec {
private:
	int key = 20; // Key to encrypt/decrypt
	string file; // File name to be encrypt
	string fileEncrypt;
	char c;
public:
	void encrypt(string filename) {
		file = filename + ".txt";
		fileEncrypt = filename + "Encrypt.txt";
		fstream fin, fout;

		fin.open(file, fstream::in);
		fout.open(fileEncrypt, fstream::out);

		if (fin.is_open() && fout.is_open()) {
			// Read file till end
			while (fin >> noskipws >> c) {
				int temp = (c + key); // Make encrypted char

				fout << (char)temp; // Write temp as char in output
			}

			// Close files
			fin.close();
			fout.close();

			// Delete cleartext file
			if (remove(file.c_str()) != 0)
				perror("Error deleting file");
		}
		else {
			cout << "Error opening file while encrypting" << endl;
			exit;
		}
	}
	void decrypt(string filename) {
		file = filename + ".txt";
		fileEncrypt = filename + "Encrypt.txt";
		fstream fin, fout;

		fin.open(fileEncrypt, fstream::in);
		fout.open(file, fstream::out);

		if (fin.is_open() && fout.is_open()) {
			// Read file till end
			while (fin >> noskipws >> c) {
				int temp = (c - key); // Make decrypted char

				fout << (char)temp; // Write temp as char in output
			}

			// Close files
			fin.close();
			fout.close();
		}
		else {
			cout << "Error opening file while decrypting" << endl;
			exit;
		}
	}
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
void view_returns();

// Mech Functions

/**************** logs.cpp ****************/
//void log(User& user, string action_type);