#pragma once
#include"account.h"
#include"file.h"
#include"reader.h"

class menu
{

public:
	int verify_semicolon(string st) { //Xac thuc dau ';'
		int verify = 0;
		for (int i = 0; i < st.length(); i++) {
			if (st[i] == ';') {
				verify = 1; // Trong chuoi co dau ';'
				break;
			}
			else verify = 0; // Trong chuoi chua co dau ';'
		}
		return verify;
	}
	void welcome();
	void loading();
	void goodbye();
	void signup_menu();
	void as_role(){
		system("cls");
		cout << "-------------------------SIGN IN-------------------------" << endl;
		cout << "Sign in as: " << endl << "1. Reader" << endl << "2. Manager" << endl << "3. Admin"<< endl << "0. Back" << endl;
		int choice = 0;
		do {
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice < 0 || choice >3);
		switch (choice)
		{
		case 1: {reader r; r.sign_in(); } break;
		case 2:  break;
		case 3: //to be continue
			break;
		case 0: mainmenu(); break;
		default:
			break;
		}
	}
	void change_theme_menu();
	void mainmenu();
};

