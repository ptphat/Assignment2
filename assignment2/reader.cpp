#pragma once
#include"reader.h"
#include"menu.h"
#include"book.h"
#include"file.h"
void reader::user_menu() {
	system("cls");
	cout << "------------------------LIBRO (USER)------------------------" << endl;
	cout << "1. Edit profile" << endl << "2. Book request" << endl << "3. Notification"<<endl<<"4. Search book" << endl << "0. Log out" << endl;
	int choice;
	fflush(stdin);
	choice = getchoice(0, 4);
	switch (choice)
	{
	case 0: {menu m; m.mainmenu(); }break;
	case 1: edit_profile(); break;
	case 2: bookrequest(); break;
	case 3: notification(); break;
	case 4: {
				book b; 
				b.Display_all_book(); 
				b.Find_book(); 
				int choice;
				cout << "Would you like to find again?"<<endl;
				cout << "1. Yes" << endl;
				cout << "2. No" << endl;
				fflush(stdin);
				choice = getchoice(1, 2);
				switch (choice){
				case 1: b.Find_book(); break;
				case 2: user_menu(); break;
				}
	}
	default:
		break;
	}
}
void reader::sign_in() {
	menu m;
	m.loading();
	system("cls");
//	cin.ignore();
	cout << "----------------------SIGN IN (as reader)----------------------" << endl;
	int size = 0;
	string username, pass, st;
	fstream reader_read("reader_data.txt", ios::in | ios::out);
	while (getline(reader_read, st)) { size++; }
	cout << "Number of account: " << size << endl;
	account *arrayaccount = new account[size];
	reader_read.clear();
	reader_read.seekg(0, 0);
	for (int i = 0; i < size; i++) {
		getline(reader_read, st, ';');
		arrayaccount[i].set_id(st);
		getline(reader_read, st, ';');
		arrayaccount[i].set_date(st);
		getline(reader_read, st, ';');
		arrayaccount[i].set_username(st);
		getline(reader_read, st, ';');
		arrayaccount[i].set_password(st);
		getline(reader_read, st);
	}
	reader_read.close();

	cout << "Enter your username: ";
	fflush(stdin);
	getline(cin, username);
	cout << "Enter your password: ";
	fflush(stdin);
	pass = getpass();
	//	fflush(stdin);
	int verify = 0;
	for (int i = 0; i < size; i++) {
		if (username == arrayaccount[i].get_username()) {
			if (pass == arrayaccount[i].get_password()) {
				verify = 0; // Dang nhap thanh cong
				id_signed_in=arrayaccount[i].get_id();
				usrname_signed_in = arrayaccount[i].get_username();
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
		cout << "-------------------------------------------------------------------" << endl;
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
void reader::edit_profile() {
	fstream read_data("reader_data.txt", ios::in);
	file f;
	int size, position;
	size = f.size(read_data);
	read_data.close();
	account *a = new account[size];
	f.read_reader(a, size);
	for (int i = 0; i < size; i++) {
		if (a[i].get_id() == id_signed_in) {
			position = i;
			break;
		}
	}
	system("cls");
	cout << "Kind of informaion you want to change: " << endl << "1. User name" << endl << "2. Password" << endl << "3. Full name" << endl << "4. Birthday" << endl << "5. Phone number" << endl << "0. Back"<<endl;
	int choice = 0;
	fflush(stdin);
	choice = getchoice(0, 5);
	switch (choice)
	{
	case 0: user_menu(); break;
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
		pass = getpass();
		while (pass != a[position].get_password()) {
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
			w.write_reader(a, size);
			user_menu();
		}
	} break;
	case 3: {
		system("cls");
		cout << "----------------CHANGE YOUR NAME---------------------" << endl;
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
			w.write_reader(a, size);
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
		cout << "----------------CHANGE PHONE---------------------" << endl;
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
			w.write_reader(a, size);
			user_menu();
		}
	}
			break;
	default:
		break;
	}
	delete[] a;
}
void reader::bookrequest(){
	system("cls");
	cout << "-----------------------------------BOOK REQUEST---------------------------------" << endl;
	cout << "List book: " << endl;
	file f;
	fstream u("book.txt", ios::in | ios::out);
	int size;
	size = f.size(u);
	u.close();
	book *b = new book[size];
	f.read_book(b, size);
	cout << setw(30) << "Title" << setw(20) << "Author"<<setw(15)<<"Date" << setw(15) << "Quantity" << endl;
	for (int i = 0; i < 80; i++) cout << "-";
	cout << endl;
	for (int i = 0; i < size; i++){
		cout << setw(30) << b[i].title << setw(20) << b[i].author << setw(15) << b[i].date << setw(15) << b[i].num << endl;
	}
	int position = -1;
	string title;
	cout<<endl << "Enter exactly the name of book you want to borrow: ";
	fflush(stdin);
	getline(cin, title);
	for (int i = 0; i < size; i++){
		if (b[i].title == title){
			position = i;
			break;
		}
	}
	if (position == -1){
		cout << "Sorry that book doesn't exist or you have typed incorrect the name" << endl;
		cout << "1. Retry" << endl << "0. Exit" << endl;
		int choice;
		fflush(stdin);
		choice = getchoice(0, 1);
		switch (choice)
		{
		case 1: bookrequest(); break;
		case 0: user_menu(); break;
		default:
			break;
		}
	}
	else {
		int quantity;
		do{
			cout << "How many book do you want: ";
			cin >> quantity;
		} while (quantity <0 || quantity > b[position].num);
		b[position].num -= quantity;
		f.write_list_book(b, size);
		fstream request("request.txt", ios::out | ios::app);
		request << currentDateTime() << ';' << usrname_signed_in << ';' << b[position].title << ';' << quantity << ';' << "1" << ';' << "1" << ';' << endl;
		// 1 chưa được accept ; 1 chưa đi mượn
		cout << "Success!!!" << endl;
		system("pause>nul");
		request.close();
		delete[] b;
		user_menu();
	}
}
void reader::notification(){
	system("cls");
	cout << "---------------------------NOTIFICATION---------------------------" << endl;
	file f;
	fstream rdr_data("request.txt", ios::in | ios::out);
	int size;
	size = f.size(rdr_data);
	rdr_data.close();
	request_manager *arr = new request_manager[size];
	f.read_request(arr, size);

	int position = -1;
	bool exist = false; //Kiem tra su ton tai cua thong bao
	for (int i = 0; i < size; i++){
		if (arr[i].usrname == usrname_signed_in){
			if (arr[i].accept == 0) {
				cout << "Book request of " << arr[i].quantity << " \"" << arr[i].title << "\" has been accepted." << endl; 
				exist = true;
			}
			else if (arr[i].accept == 2) {
				cout << "Book request of " << arr[i].quantity << " \"" << arr[i].title << "\" has been denied." << endl;
			}
			else if (arr[i].accept==1) {
				cout << "You have requested " << arr[i].quantity << " book(s) named \"" << arr[i].title << "\"." << endl;
			}
		}
	}
	if (exist == false){
		cout << "Empty!!!";
	}
	system("pause>nul");
	user_menu();
}

