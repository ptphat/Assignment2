#pragma once

#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<iostream>

using namespace std;

class account {
public:
	string id;
	string username;
	string name;
	string birthday;
	string email;
	string phonenumber;
	string password;
	int role; //Xác định vai trò của tài khoản 0:admin, 1:manager, 2:reader
public:
	string get_id() { return id; }
	string get_username() { return username; }
	string get_name() { return name; }
	string get_birthday() { return birthday; }
	string get_password() { return password; }
	string get_phone() { return phonenumber; }

	void set_id(string s) { id = s; }
	void set_username(string s) { username = s; }
	void set_name(string s) { name = s; }
	void set_birthday(string s) { birthday = s; }
	void set_password(string s) { password = s; }
	void set_phone(string s) { phonenumber = s; }

};

