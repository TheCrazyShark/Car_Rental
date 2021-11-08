#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma once

void login();
void create_account();
//string hash_function(string password);
void main_menu();
void request_car();
void return_car();
void repair_car();
bool issue_or_deny();
void view_requests();
void log(string user_id, string action_type);