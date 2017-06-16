#pragma once
#include"menu.h"

void menu::welcome() {
	system("cls");
	cout << endl << endl << endl;
	cout << setw(36) << right << "W" << endl;
	cout << setw(34) << "__" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(38) << right << "WEL" << endl;
	cout << setw(38) << "______" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(40) << right << "WELCO" << endl;
	cout << setw(42) << "__________" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(42) << right << "WELCOME" << endl;
	cout << setw(45) << "_____________" << endl;
	Sleep(200);
}
void menu::loading() {
	system("cls");
	cout << endl << endl << endl;
	cout << setw(43) << right << "LOADING.";
	Sleep(50);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(44) << right << "LOADING..";
	Sleep(50);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(45) << right << "LOADING...";
	Sleep(50);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(46) << right << "LOADING....";
	Sleep(90);
}
void menu::goodbye() {
	system("cls");
	cout << endl << endl << endl;
	cout << setw(36) << right << "G" << endl;
	cout << setw(34) << "__" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(38) << right << "GOO" << endl;
	cout << setw(38) << "______" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(40) << right << "GOODB" << endl;
	cout << setw(42) << "__________" << endl;
	Sleep(100);
	system("cls");
	cout << endl << endl << endl;
	cout << setw(42) << right << "GOODBYE" << endl;
	cout << setw(45) << "_____________" << endl;
	Sleep(200);
}
void menu::signup_menu() {
	loading();
	system("cls");
	cout << "----------------------SIGN UP (as reader)----------------------" << endl;
	cin.ignore();
	string st;
	int size = 0;

	fstream user_read("reader_data.txt", ios::in | ios::out);
	while (getline(user_read, st)) { size++; }
	cout << "Number of account: " << size << endl;
	account *arrayaccount = new account[size];
	user_read.clear();
	user_read.seekg(0, 0);
	for (int i = 0; i < size; i++) {
		getline(user_read, st, ';');
		arrayaccount[i].set_id(st);
		getline(user_read, st, ';');
		arrayaccount[i].set_username(st);
		getline(user_read, st);
	}
	user_read.close();

	string username, pass, name, birthday, email, phone;
	int verify = 0; // Bien xac thuc cho username
	fstream user_write("reader_data.txt", ios::out | ios::app);
	cout << "Enter your username: ";
	fflush(stdin);
	getline(cin, username);
	while (verify_semicolon(username) == 1) {
		cout << "Your username mustn't content char \';\', please retype it: ";
		fflush(stdin);
		getline(cin, username);
	}

	for (int i = 0; i < size; i++) {
		if (username == arrayaccount[i].get_username()) {
			verify = 1; // Trung username
			break;
		}
		else verify = 0; //Chua bi trung username
	}
	while (verify == 1) {
		cout << "Someone has used this username, retype your username: ";
		fflush(stdin);
		getline(cin, username);
		for (int i = 0; i < size; i++) {
			if (username == arrayaccount[i].get_username()) {
				verify = 1;
				break;
			}
			else verify = 0;
		}
	}
	if (verify == 0) {
		cout << "Enter your password: ";
		fflush(stdin);
		getline(cin, pass);
		while (verify_semicolon(pass) == 1) {
			cout << "Your password mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, pass);
		}
		cout << "Full name: "; getline(cin, name);
		while (verify_semicolon(name) == 1) {
			cout << "Your full name mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, name);
		}
		cout << "Birthday: "; getline(cin, birthday);
		while (verify_semicolon(birthday) == 1) {
			cout << "Your date of birth mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, birthday);
		}
		cout << "Phone number: "; getline(cin, phone);
		while (verify_semicolon(phone) == 1) {
			cout << "Your phone number mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, phone);
		}
		user_write << size << ";" << username << ";" << pass << ";" << name << ";" << birthday << ";" << phone << ";" << endl;
		user_write.close();
		cout << "Successful !!! Please press Enter and sign in again :)" << endl;
		system("pause>nul");
		mainmenu();
	}
}
void menu::mainmenu() {
	loading();
	system("cls");
	cout << "-------------- LIBRO (designed by Phat) --------------" << endl;
	cout << "1. Sign in" << endl << "2. Sign up" << endl << "3. Change color" << endl << "4. About" << endl << "0. Exit" << endl;
	int choice = 0;
	do {
		cout << "Enter your choice: ";
		fflush(stdin);
		cin >> choice;
	} while (choice < 0 || choice >4);

	switch (choice)
	{
	case 1: as_role();	break;
	case 2: signup_menu();	break;
	case 3: {loading(); change_theme_menu(); };	break;
	case 4: {
		system("cls");
		cout << "Cheking for update: No update is available" << endl;
		cout << "Version: 1.0.0 (15, July, 2017)" << endl;
		cout << "Member:" << endl;
		cout << "Tran Nhan Vu (leader)"<< endl << "Pham Thanh Phat" << endl << "Ung Van Duy"<< endl << "Phan Ngoc Thinh" << endl;
		system("pause>nul");
		mainmenu();
	}
	case 0: system("exit");
	default:
		break;
	}
}
void menu::change_theme_menu() {
	system("cls");
	cout << "Font color: " << endl;
	cout << left;
	cout << setw(20) << "1. BLue" << setw(20) << "8. Light Blue" << endl;
	cout << setw(20) << "2. Green" << setw(20) << "9. Ligth Green" << endl;
	cout << setw(20) << "3. Aqua" << setw(20) << "10. Light Aqua" << endl;
	cout << setw(20) << "4. Red" << setw(20) << "11. Light red" << endl;
	cout << setw(20) << "5. Purple" << setw(20) << "12. Light purple" << endl;
	cout << setw(20) << "6. Yellow" << setw(20) << "13. Light yellow" << endl;
	cout << setw(20) << "7. White" << setw(20) << "14. Bright white" << endl;
	cout << "0. Agree and return to main menu" << endl;
	cout << "Enter your choice: ";
	int choice = 0;
	cin >> choice;
	while (choice < 0 || choice >14) {
		change_theme_menu();
	}
	switch (choice)
	{
	case 0: mainmenu(); break;
	case 1: {system("color 01"); change_theme_menu(); } break;
	case 2: {system("color 02"); change_theme_menu(); } break;
	case 3: {system("color 03"); change_theme_menu(); } break;
	case 4: {system("color 04"); change_theme_menu(); } break;
	case 5: {system("color 05"); change_theme_menu(); } break;
	case 6: {system("color 06"); change_theme_menu(); } break;
	case 7: {system("color 07"); change_theme_menu(); } break;
	case 8: {system("color 09"); change_theme_menu(); } break;
	case 9: {system("color 0A"); change_theme_menu(); } break;
	case 10: {system("color 0B"); change_theme_menu(); } break;
	case 11: {system("color 0C"); change_theme_menu(); } break;
	case 12: {system("color 0D"); change_theme_menu(); } break;
	case 13: {system("color 0E"); change_theme_menu(); } break;
	case 14: {system("color 0F"); change_theme_menu(); }break;
	default: mainmenu(); break;
	}
}
