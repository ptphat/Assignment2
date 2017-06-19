#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<ctime>
using namespace std;

class independent_function
{
public:
	const string currentDateTime() {
		time_t     now = time(0);
		struct tm  tstruct;
		char       buf[80];
		tstruct = *localtime(&now);
		strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

		return buf;
	}
	void welcome() {
		system("cls");
		cout << endl << endl << endl;
		cout << setw(36) << right << "W" << endl;
		cout << setw(34) << "__" << endl;
		Sleep(80);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(38) << right << "WEL" << endl;
		cout << setw(38) << "______" << endl;
		Sleep(80);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(40) << right << "WELCO" << endl;
		cout << setw(42) << "__________" << endl;
		Sleep(80);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(42) << right << "WELCOME" << endl;
		cout << setw(45) << "_____________" << endl;
		Sleep(150);
	}
	void loading() {
		system("cls");
		cout << endl << endl << endl;
		cout << setw(43) << right << "LOADING.";
		Sleep(30);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(44) << right << "LOADING..";
		Sleep(30);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(45) << right << "LOADING...";
		Sleep(30);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(46) << right << "LOADING....";
		Sleep(60);
	}
	void goodbye() {
		system("cls");
		cout << endl << endl << endl;
		cout << setw(36) << right << "G" << endl;
		cout << setw(34) << "__" << endl;
		Sleep(60);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(38) << right << "GOO" << endl;
		cout << setw(38) << "______" << endl;
		Sleep(60);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(40) << right << "GOODB" << endl;
		cout << setw(42) << "__________" << endl;
		Sleep(60);
		system("cls");
		cout << endl << endl << endl;
		cout << setw(42) << right << "GOODBYE" << endl;
		cout << setw(45) << "_____________" << endl;
		Sleep(100);
	}

public:
	independent_function();
	~independent_function();
};

