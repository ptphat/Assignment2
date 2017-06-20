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
	string getid_rdr(int size){ // Ham tao ID tu dong
		string ID, s = currentDateTime();
		ID = ID + s[2] + s[3];
		if (size >= 1000){
			char ng = size / 1000 + 48;
			char tr = (size % 1000) / 100 + 48;
			char ch = (size % 100) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 1000 && size >= 100){
			char ng = '0';
			char tr = (size) / 100 + 48;
			char ch = (size % 100) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 100 && size >= 10){
			char ng = '0';
			char tr = '0';
			char ch = (size) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 10 && size >= 0){
			char ng = '0';
			char tr = '0';
			char ch = '0';
			char dv = (size)+48;
			ID = ID + ng + tr + ch + dv;
		}
		return ID;
	}
	string getid_book(int size){ // Ham tao ID tu dong
		string ID, s = currentDateTime();
		ID = ID + s[2] + s[3];
		if (size >= 1000){
			char ng = size / 1000 + 48;
			char tr = (size % 1000) / 100 + 48;
			char ch = (size % 100) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 1000 && size >= 100){
			char ng = '0';
			char tr = (size) / 100 + 48;
			char ch = (size % 100) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 100 && size >= 10){
			char ng = '0';
			char tr = '0';
			char ch = (size) / 10 + 48;
			char dv = (size % 10) + 48;
			ID = ID + ng + tr + ch + dv;
		}
		else if (size < 10 && size >= 0){
			char ng = '0';
			char tr = '0';
			char ch = '0';
			char dv = (size)+48;
			ID = ID + ng + tr + ch + dv;
		}
		return 'B'+ ID;
	}
	string getpass(){

		char ch;
		string pass;
		int count = 0;

		while (((ch = _getch()) != 13) || pass.empty()){ // 13: phim Enter
			if (ch == 13 || ch == '\t'){
				cout << endl << "Your password is empty.\nPlease Enter your password again: ";
				continue;
			}
			else if (ch <= 126 && ch >= 32) {//go ki tu in duoc
				cout << "*";
				pass.push_back(ch);
				count++;
			}
			else if (ch == 8){ // phim backspaces
				if (count > 0){
					cout << "\b \b";
					count--;
					pass.erase(pass.end() - 1);
				}
			}
			else{// bo qua phim mui ten len, xuong, qua, lai,...
				cout << endl << "Mat khau khong gom ki tu la! " << endl;
				_getch();//bo qua ki tu la
				cout << "Enter your password: ";
				pass = "";
				continue;
			}
		}
		cout << endl;
		return pass;
	}
	int clean_stdin() {
		while (getchar() != '\n') {
		}
		return 1;
	}
	int getchoice(int begin, int end){
		int choice;
		char c;
		do{
			cout << "Enter your choice: ";
			fflush(stdin);
		} while (((scanf_s("%d%c", &choice, &c) != 2 || c != '\n') && clean_stdin()) || choice < begin || choice > end);
		return choice;
	}
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
		system("color 0C");
		cout << endl << endl << endl;
		cout << setw(36) << right << "W" << endl;
		cout << setw(34) << "__" << endl;
		Sleep(100);
		system("cls");
		system("color 0D");
		cout << endl << endl << endl;
		cout << setw(38) << right << "WEL" << endl;
		cout << setw(38) << "______" << endl;
		Sleep(100);
		system("cls");
		system("color 0E");
		cout << endl << endl << endl;
		cout << setw(40) << right << "WELCO" << endl;
		cout << setw(42) << "__________" << endl;
		Sleep(100);
		system("cls");
		system("color 0B");
		cout << endl << endl << endl;
		cout << setw(42) << right << "WELCOME" << endl;
		cout << setw(45) << "_____________" << endl;
		Sleep(160);
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
		system("color 0C");
		cout << endl << endl << endl;
		cout << setw(36) << right << "G" << endl;
		cout << setw(34) << "__" << endl;
		Sleep(60);
		system("cls");
		system("color 0D");
		cout << endl << endl << endl;
		cout << setw(38) << right << "GOO" << endl;
		cout << setw(38) << "______" << endl;
		Sleep(60);
		system("cls");
		system("color 0E");
		cout << endl << endl << endl;
		cout << setw(40) << right << "GOODB" << endl;
		cout << setw(42) << "__________" << endl;
		Sleep(60);
		system("cls");
		system("color 0B");
		cout << endl << endl << endl;
		cout << setw(42) << right << "GOODBYE" << endl;
		cout << setw(45) << "_____________" << endl;
		Sleep(100);
	}

public:
	independent_function();
	~independent_function();
};

