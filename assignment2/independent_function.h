#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<ctime>
#include<conio.h>
using namespace std;

class independent_function
{
public:
	string getid_rdr(int size); // Ham tao ID tu dong
	string getid_book(int size); // Ham tao ID tu dong
	string getpass();	
	int clean_stdin();
	int getchoice(int begin, int end);
	const string currentDateTime();
	void welcome();
	void loading();
	void goodbye();
};

