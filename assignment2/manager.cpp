#pragma once
#include"manager.h"
#include"menu.h"
#include"file.h"
void manager::sign_in(){
	menu m;
	m.loading();
	system("cls");
	cin.ignore();
	cout << "-------------------------SIGN IN (as manager)----------------------" << endl;
	int size = 0;
	string username, pass, st;
	fstream manager_read("manager_data.txt", ios::in | ios::out);
	while (getline(manager_read, st)) { size++; }
	cout << "Number of account: " << size << endl;
	account *arrayaccount = new account[size];
	manager_read.clear();
	manager_read.seekg(0, 0);
	for (int i = 0; i < size; i++) {
		getline(manager_read, st, ';');
		arrayaccount[i].set_id(st);
		getline(manager_read, st, ';');
		arrayaccount[i].set_username(st);
		getline(manager_read, st, ';');
		arrayaccount[i].set_password(st);
		getline(manager_read, st);
	}
	manager_read.close();

	cout << "Enter your username: ";
	fflush(stdin);
	getline(cin, username);
	cout << "Enter your password: ";
	fflush(stdin);
	getline(cin, pass);
	//	fflush(stdin);
	int verify = 0;
	for (int i = 0; i < size; i++) {
		if (username == arrayaccount[i].get_username()) {
			if (pass == arrayaccount[i].get_password()) {
				verify = 0; // Dang nhap thanh cong
				id_signed_in = arrayaccount[i].get_id();
				break;
			}
			else {
				verify = 1; // Sai mat khau
				break;
			}
		}
		else verify = 2; //Chua tim duoc username trong file
	}
	if (verify == 2) {
		cout << "-----------------------------------------------------------------" << endl;
		cout << "This user doesn't exist" << endl << "0. Try different account" << endl << "2. Back to main menu" << endl;
		int choice = 0;
		do {
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice < 0 || choice >1);
		switch (choice)
		{
		case 1: sign_in(); break;
		case 0: m.mainmenu();
		default:
			break;
		}
	}
	else if (verify == 1) {
		cout << "-----------------------------------------------------------------" << endl;
		cout << "Password is invalid" << endl;
		cout << "1. Try to sign in again" << endl << "2. Back to main menu" << endl;
		int choice = 0;
		do {
			cout << "Enter your choice: ";
			fflush(stdin);
			cin >> choice;
		} while (choice < 0 || choice >1);
		switch (choice)
		{
		case 1: sign_in(); break;
		case 0: m.mainmenu();
		default:
			break;
		}
	}
	else if (verify == 0) {
		user_menu();
	}
}
void manager::user_menu() {
	system("cls");
	int size;
	file f;
	fstream file_request("request.txt", ios::in | ios::out);
	size = f.size(file_request);
	request_manager *rm = new request_manager[size];
	f.read_request(rm, size);
	int num_of_noti = 0;
	for (int i = 0; i < size; i++){
		if (rm[i].verify == 1){
			num_of_noti++;
		}
	}
	delete[] rm;
	cout << "------------------------LIBRO (MANAGER)------------------------" << endl;
	cout << "1. Edit profile" << endl << "2. Notification(" << num_of_noti << ")" << endl << "3. Add/remove book" << endl << "0. Log out" << endl;
	int choice;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice < 0 || choice >3);
	switch (choice)
	{
	case 0: {menu m; m.mainmenu(); }break;
	case 1: edit_profile(); break;
	case 2: notification(); break;
	case 3: break;
	default:
		break;
	}
}
void manager::edit_profile() {
	fstream read_data("manager_data.txt", ios::in);
	file f;
	int size, position;
	size = f.size(read_data);
	read_data.close();
	account *a = new account[size];
	f.read_manager(a, size);
	for (int i = 0; i < size; i++) {
		if (a[i].get_id() == id_signed_in) {
			position = i;
			break;
		}
	}
	system("cls");
	cout << "Kind of informaion you want to change: " << endl << "1. User name" << endl << "2. Password" << endl << "3. Full name" << endl << "4. Birthday" << endl << "5. Phone number" << endl << "0. Back" << endl;
	int choice = 0;
	do {
		cout << "Enter your choice: ";
		cin >> choice;
	} while (choice < 0 || choice > 5);
	switch (choice)
	{
	case 0: {user_menu(); } break;
	case 1: {cout << "Sorry, you can't change your username, press any key to return" << endl;
		system("pause>nul");
		edit_profile();
	} break;
	case 2: {
				system("cls");
				cout << "----------------- CHANGE PASSWORD -----------------" << endl;
				cout << "Current password: ";
				string pass, newpass;
				fflush(stdin);
				getline(cin, pass);
				while (pass != a[position].get_password()) {
					cout << "Invalid password" << endl << "Enter your current password again: ";
					fflush(stdin);
					getline(cin, pass);
				}
				cout << "Enter new password: ";
				fflush(stdin);
				getline(cin, newpass);
				menu m;
				while (m.verify_semicolon(newpass) == 1) {
					cout << "Your password word mustn't content char \';\', retype it: ";
					fflush(stdin);
					getline(cin, newpass);
				}
				if (m.verify_semicolon(newpass) == 0) {
					a[position].set_password(newpass);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_manager(a, size);
					user_menu();
				}
	} break;
	case 3: {
				system("cls");
				cout << "----------------CHANGE YOUR NAME---------------------";
				cout << "Your current name: " << a[position].get_name() << endl;
				cout << "Enter your new name: ";
				string newname;
				cin >> newname;
				menu m;
				while (m.verify_semicolon(newname) == 1) {
					cout << "Your name mustn't content char \';\', retype it: ";
					cin >> newname;
				}
				if (m.verify_semicolon(newname) == 0) {
					a[position].set_name(newname);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_manager(a, size);
					user_menu();
				}
	}
		break;
	case 4: {
				system("cls");
				cout << "----------------CHANGE BIRTHDAY---------------------";
				cout << "Your current birthday: " << a[position].get_birthday() << endl;
				cout << "Enter new birthday: ";
				string newbirth;
				getline(cin, newbirth);
				menu m;
				while (m.verify_semicolon(newbirth) == 1) {
					cout << "Your birthday mustn't content char \';\', retype it: ";
					getline(cin, newbirth);
				}
				if (m.verify_semicolon(newbirth) == 0) {
					a[position].set_birthday(newbirth);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_reader(a, size);
					user_menu();
				}
	}
		break;
	case 5: {
				system("cls");
				cout << "----------------CHANGE PHONE---------------------";
				cout << "Your current birthday: " << a[position].get_phone() << endl;
				cout << "Enter new birthday: ";
				string newphone;
				fflush(stdin);
				getline(cin, newphone);
				menu m;
				while (m.verify_semicolon(newphone) == 1) {
					cout << "Your birthday mustn't content char \';\', retype it: ";
					fflush(stdin);
					getline(cin, newphone);
				}
				if (m.verify_semicolon(newphone) == 0) {
					a[position].set_phone(newphone);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_manager(a, size);
					user_menu();
				}
	}
		break;
	default:
		break;
	}
	delete[] a;
}
void manager::notification(){
	system("cls");
	int size;
	file f;
	fstream file_request("request.txt", ios::in | ios::out);
	size = f.size(file_request);
	request_manager *rm = new request_manager[size];
	f.read_request(rm, size);
	int *p = new int[size];
	bool exist = false; //Kiểm tra sự tồn tại của các thông báo
	cout << "----------------------NOTIFICATION---------------------" << endl;
	int j = 0; // Bien danh so thu tu notification
	for (int i = 0; i < size; i++){
		if (rm[i].verify == 1){
			j++;
			p[j] = i;
			cout << j << ". User \"" << rm[i].usrname << "\" want to borrow " << rm[i].quantity << " book(s) named \"" << rm[i].title << "\" on: " << rm[i].date << endl;
			exist = true;
		}
	}
	if (exist == false) { 
		delete[] p, rm;
		cout << "Empty!!!" << endl;
		system("pause>nul");
		user_menu();
	}
	else{
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "1. Accept request" << endl << "0. Back" << endl;
		int choice;
		do {
			cout << "Enter your choice: ";
			cin >> choice;
		} while (choice<0 || choice>1);
		switch (choice){
		case 0: user_menu(); break;
		case 1: {
					int choice;
					do{
						cout << "Choose which request you want to accept: ";
						fflush(stdin);
						cin >> choice;
					} while (choice <1 || choice >j);
					rm[p[choice]].verify = 0; //Yeu cau duoc chap nhan
					file f;
					f.write_request(rm, size);
					delete[] p, rm;
					cout << "Success!!!" << endl;
					system("pause>nul");
					notification();
		}
		}
	}

}

manager::manager()
{
}


manager::~manager()
{
}
