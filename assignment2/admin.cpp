#pragma once
#include"admin.h"
#include"menu.h"
#include"file.h"
void admin::sign_in(){
	menu m;
	m.loading();
	system("cls");
//	cin.ignore();
	cout << "-------------------------SIGN IN (as ADMIN)----------------------" << endl;
	int size = 0;
	file f;
	string username, pass, st;
	fstream admin_read("admin_data.txt", ios::in | ios::out);
	size = f.size(admin_read);
	cout << "Number of account: " << size << endl;
	account *arrayaccount = new account[size];
	f.read_admin(arrayaccount, size);

	cout << "Enter your username: ";
	fflush(stdin);
	getline(cin, username);
	cout << "Enter your password: ";
	fflush(stdin);
	pass = getpass();
	//	fflush(stdin);
	int verify = 2;
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
		cout << "This user doesn't exist" << endl << "1. Try different account" << endl << "0. Back to main menu" << endl;
		int choice = 0;
		fflush(stdin);
		choice = getchoice(0, 1);
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
		cout << "1. Try to sign in again" << endl << "0. Back to main menu" << endl;
		int choice = 0;
		fflush(stdin);
		choice = getchoice(0, 1);
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
void admin::user_menu() {
	system("cls");
	file f;
	cout << "------------------------LIBRO (admin)------------------------" << endl;
	cout << "1. Edit profile" << endl << "2. Display all reader" << endl << "3. Add/Active/Block reader" << endl << "4. Search book" << endl << "5. Notification" << endl << "6. View book's list" << endl << "0. Log out" << endl;
	int choice;
	fflush(stdin);
	choice = getchoice(0, 6);
	switch (choice)
	{
	case 0: {menu m; m.mainmenu(); }break;
	case 1: edit_profile(); break;
	case 2:{
			   show_all_reader();
			   system("pause>nul");
			   user_menu();
	}
	case 3: {
				system("cls");
				cout << "----------------------Add/Active/Block reader---------------------" << endl;
				cout << "1. Add user" << endl<<"2. Active user"<<endl << "3. Block user" << endl << "0. Back";
				int choice;
				fflush(stdin);
				choice = getchoice(0,3);
				switch (choice){
				case 1: {				
					menu m;
					m.signup_menu();
					user_menu(); 
				}
					break;
				case 2: {
							show_all_reader();
							cout << "Enter user ID you need to active: ";
							string id;
							getline(cin, id);
							file f;
							fstream rdr_data("reader_data.txt", ios::in | ios::out);
							int size = f.size(rdr_data);
							rdr_data.close();
							account *acc = new account[size];
							f.read_reader(acc, size);
							bool exist = false;
							int position = -1;
							for (int i = 0; i < size; i++){
								if (acc[i].get_id() == id){
									acc[i].set_active(1);
									position = i;
									exist = true;
									break;
								}
							}
							f.write_reader(acc, size);							
							if (exist){
								cout << acc[position].get_username()<< " has been actived!" << endl;
							}
							delete[] acc;
							system("pause>nul");
							user_menu();
				}
					break;
				case 3: {
							show_all_reader();
							cout << "Enter user ID you need to block: ";
							string id;
							getline(cin, id);
							file f;
							fstream rdr_data("reader_data.txt", ios::in | ios::out);
							int size = f.size(rdr_data);
							rdr_data.close();
							account *acc = new account[size];
							f.read_reader(acc, size);
							bool exist = false;
							int position;
							for (int i = 0; i < size; i++){
								if (acc[i].get_id() == id){
									acc[i].set_active(0);
									position = i;
									exist = true;
									break;
								}
							}
							f.write_reader(acc, size);
							if (exist){
								cout << acc[position].get_username() << " has been blocked!" << endl;
							}
							delete[] acc;
							system("pause>nul");
							user_menu();
				}
					break;
				}

	}
		break;
	case 4: {
				book b;
				b.Display_all_book();
				b.Find_book();
				system("pause>nul");
				user_menu();
	}
		break;
	case 5: {notification(); user_menu(); } break;
	case 6:{
			   book b;
			   b.Display_all_book();
			   system("pause>nul");
			   user_menu();
	}
		break;
	default:
		break;
	}
}
void admin::edit_profile() {
	fstream read_data("admin_data.txt", ios::in);
	file f;
	int size, position;
	size = f.size(read_data);
	read_data.close();
	account *a = new account[size];
	f.read_admin(a, size);
	for (int i = 0; i < size; i++) {
		if (a[i].get_id() == id_signed_in) {
			position = i;
			break;
		}
	}
	system("cls");
	cout << "Kind of informaion you want to change: " << endl << "1. User name" << endl << "2. Password" << endl << "3. Full name" << endl << "4. Birthday" << endl << "5. Phone number" << endl << "0. Back" << endl;
	int choice = 0;
	fflush(stdin);
	choice = getchoice(0, 5);
	switch (choice)
	{
	case 0: {user_menu(); } break;
	case 1: {
				cout << endl;
				cout << "Sorry, you can't change your username, press any key to return" << endl;
				system("pause>nul");
				edit_profile();
	} break;
	case 2: {
				system("cls");
				cout << "----------------- CHANGE PASSWORD -----------------" << endl;
				cout << "Current password: ";
				string pass, newpass;
				fflush(stdin);
				pass = getpass();
				unsigned int numOfwrong = 0;
				while (pass != a[position].get_password()) {
					numOfwrong++;
					if (numOfwrong > 2){
						cout << "\nYou entered more than 3 times incorrectly!.\nExit in 3 second ...";
						Sleep(3000);
						edit_profile();
					}
					cout << "Invalid password" << endl << "Enter your current password again: ";
					fflush(stdin);
					pass = getpass();
				}
				cout << "Enter new password: ";
				fflush(stdin);
				newpass = getpass();
				menu m;
				while (m.verify_semicolon(newpass) == 1) {
					cout << "Your password word mustn't content char \';\', retype it: ";
					fflush(stdin);
					newpass = getpass();
				}
				if (m.verify_semicolon(newpass) == 0) {
					a[position].set_password(newpass);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_admin(a, size);
					user_menu();
				}
	} break;
	case 3: {
				system("cls");
				cout << "----------------CHANGE YOUR NAME---------------------"<<endl;
				cout << "Your current name: " << a[position].get_name() << endl;
				cout << "Enter your new name: ";
				string newname;
				fflush(stdin);
				getline(cin, newname);
				menu m;
				while (m.verify_semicolon(newname) == 1) {
					cout << "Your name mustn't content char \';\', retype it: ";
					fflush(stdin);
					getline(cin, newname);
				}
				if (m.verify_semicolon(newname) == 0) {
					a[position].set_name(newname);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_admin(a, size);
					user_menu();
				}
	}
		break;
	case 4: {
				system("cls");
				cout << "----------------CHANGE BIRTHDAY---------------------"<<endl;
				cout << "Your current birthday: " << a[position].get_birthday() << endl;
				cout << "Enter new birthday: ";
				string newbirth;
				fflush(stdin);
				getline(cin, newbirth);
				menu m;
				while (m.verify_semicolon(newbirth) == 1) {
					cout << "Your birthday mustn't content char \';\', retype it: ";
					fflush(stdin);
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
				cout << "----------------CHANGE PHONE---------------------"<<endl;
				cout << "Your current phone: " << a[position].get_phone() << endl;
				cout << "Enter new phone: ";
				string newphone;
				fflush(stdin);
				getline(cin, newphone);
				menu m;
				while (m.verify_semicolon(newphone) == 1) {
					cout << "Your phone mustn't content char \';\', retype it: ";
					fflush(stdin);
					getline(cin, newphone);
				}
				if (m.verify_semicolon(newphone) == 0) {
					a[position].set_phone(newphone);
					cout << "Success!!!" << endl;
					system("pause>nul");
					file w;
					w.write_admin(a, size);
					user_menu();
				}
	}
		break;
	default:
		break;
	}
	delete[] a;
}
void admin::notification(){
	system("cls");
	cout << "------------------------------NOTIFICATION-----------------------------------" << endl;
	fstream ad_noti("admin_noti.txt", ios::in | ios::out);
	int size;
	file f;

	size = f.size(ad_noti);
	string *line = new string[size];
	if (size == 0) { cout << "Empty!!!" << endl; }
	else{
		for (int i = 0; i < size; i++){
			getline(ad_noti, line[i]);
		}
	}
	for (int i = size - 1; i >= 0; i--){
		cout << line[i] << endl;
	}
	ad_noti.close();
	cout << "1. Clear all notification" << endl << "0. Back" << endl;
	int choice;
	choice = getchoice(0, 1);
	switch (choice)
	{
	case 0: user_menu(); break;
	case 1: {
				system("del admin_noti.txt");
				fstream noti("admin_noti.txt");
				noti << "" << endl;
				noti.close();
	}
		break;
	default:
		break;
	}
	//system("pause>nul");
}
admin::admin()
{
}


admin::~admin()
{
}
