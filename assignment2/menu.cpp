#pragma once
#include"menu.h"
#include"file.h"

void menu::signup_menu() {
	loading();
	system("cls");
	cout << "----------------------SIGN UP (as reader)----------------------" << endl;
//	cin.ignore();
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
		arrayaccount[i].set_date(st);
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
	delete[] arrayaccount;
	if (verify == 0) {
		cout << "Enter your password: ";
		fflush(stdin);
		getline(cin, pass);
		while (verify_semicolon(pass) == 1) {
			cout << "Your password mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, pass);
		}
		cout << "Full name: ";
		fflush(stdin); 
		getline(cin, name);
		while (verify_semicolon(name) == 1) {
			cout << "Your full name mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, name);
		}
		cout << "Birthday: ";
		fflush(stdin); 
		getline(cin, birthday);
		while (verify_semicolon(birthday) == 1) {
			cout << "Your date of birth mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, birthday);
		}
		cout << "Phone number: "; 
		fflush(stdin);
		getline(cin, phone);
		while (verify_semicolon(phone) == 1) {
			cout << "Your phone number mustn't content char \';\', please retype it: ";
			fflush(stdin);
			getline(cin, phone);
		}
		user_write << size << ';' << currentDateTime() << ';' << username << ';' << pass << ';' << name << ';' << birthday << ';' << phone << ';' << endl;
		user_write.close();
		cout << "Successful !!!" << endl;
		fstream ad_noti("admin_noti.txt", ios::out | ios::app); //Ghi vao file thong bao cua admin
		ad_noti.clear();
		ad_noti.seekg(0, 0);
		ad_noti << "User \"" << username << "\" has registered on "<< currentDateTime()<<"." << endl;
		ad_noti.close();
		system("pause>nul");
//		mainmenu();
	}
}
void menu::mainmenu() {
	loading();
	system("cls"); 
	file f;
	cout << "-------------- LIBRO (designed by Phat) --------------" << endl;
	cout << setw(17) << "" << "https://github.com/ptphat/assignment2" << endl << endl;
	cout << "1. Sign in" << endl << "2. Sign up" << endl << "3. Change color" << endl << "4. About" << endl << "0. Exit" << endl;
	int choice = 0;
	choice = f.getchoice(0, 4);
	switch (choice)
	{
	case 1: as_role();	break;
	case 2: {signup_menu();	mainmenu(); }break;
	case 3: {loading(); change_theme_menu(); };	break;
	case 4: {
		system("cls");
		cout << "Cheking for update: No update is available" << endl;
		cout << "Version: 2.2 (25, July, 2017)" << endl;
		cout << "Member:" << endl;
		cout << left << setw(30) << "Tran Nhan Vu (leader)" << setw(15) << "161xxxx" << endl;
		cout << left << setw(30) << "Pham Thanh Phat" << setw(15) << "1612537" << endl;
		cout << left << setw(30) << "Ung Van Duy" << setw(15) << "1610512" << endl;
		cout << left << setw(30) << "Phan Ngoc Thinh" << setw(15) << "1613361" << endl;
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
