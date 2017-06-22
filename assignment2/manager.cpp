#pragma once
#include"manager.h"
#include"menu.h"
#include"file.h"
void manager::sign_in(){
	menu m;
	m.loading();
	system("cls");
//	cin.ignore();
	cout << "-------------------------SIGN IN (as manager)----------------------" << endl;
	file f;
	int size = 0;
	string username, pass, st;
	fstream manager_read("manager_data.txt", ios::in | ios::out);
	size = f.size(manager_read);
	cout << "Number of account: " << size << endl;
	account *arrayaccount = new account[size];
	f.read_manager(arrayaccount, size);

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
		if (rm[i].accept == 1){
			num_of_noti++;
		}
	}
	cout << "------------------------LIBPRO (manager)------------------------" << endl;
	cout << "1. Edit profile" << endl << "2. Notification (" << num_of_noti << ")" << endl << "3. Modify book" << endl << "4. Verify" << endl << "5. Add or remove book" << endl << "6. View book's list"<<endl<<"7. Search book" << endl << "0. Log out" << endl;
	int choice;
	book b;
	fflush(stdin);
	choice = getchoice(0, 7);
	switch (choice)
	{
	case 0: {menu m; m.mainmenu(); }break;
	case 1: edit_profile(); break;
	case 2: notification(); break;
	case 3: {
				system("cls");
				b.Modify_book();
				cout << endl << "Do you want to modify again?" << endl << "1. Yes" << endl << "2. No" << endl;
				int choice;
				fflush(stdin);
				choice = getchoice(1, 2);
				switch (choice){
				case 1: b.Modify_book(); break;
				case 2: user_menu(); break;
				}

	} break;
	case 4:{
			   cout << "---------------------------Verify-------------------------" << endl;
			   cout << "1. Verify user borrows book(s) completely" << endl;
			   cout << "2. Verify user gives book(s) back completely" << endl;
			   cout << "0. Back" << endl;
			   int choice;
			   fflush(stdin);
			   choice = getchoice(0, 2);
			   switch (choice){
			   case 0: user_menu(); break;
			   case 1:{
						  cout << "-----Verify user borrow book(s) completely-----" << endl;
						  string usr, title;
						  int quantity;
						  fflush(stdin);
						  cout << "Enter this user: "; getline(cin, usr);
						  fflush(stdin);
						  cout << "Enter title: "; getline(cin, title);
						  cout << "Enter quantity: "; cin >> quantity;
						  for (int i = 0; i < size; i++){
							  if (usr == rm[i].usrname && title == rm[i].title && quantity == rm[i].quantity && rm[i].accept==0){
								  rm[i].borow = 0;
								  break;
							  }
						  }
						  f.write_request(rm, size);
						  user_menu();
			   }
				   break;
			   case 2:{
						  cout << "-----Verify user give book(s) back completely----" << endl;
						  string usr, title;
						  int quantity;
						  fflush(stdin);
						  cout << "Enter this user: "; getline(cin, usr);
						  fflush(stdin);
						  cout << "Enter title: "; getline(cin, title);
						  cout << "Enter quantity: "; cin >> quantity;
						  for (int i = 0; i < size; i++){
							  if (usr == rm[i].usrname && title == rm[i].title && quantity == rm[i].quantity && rm[i].borow==0 ){
								  rm[i].give_back = 0;
								  fstream bk("book.txt", ios::in | ios::out);
								  int size = f.size(bk);
								  bk.close();
								  book *b=new book[size];
								  f.read_book(b, size);
								  for (int i = 0; i < size; i++){
									  if (b[i].title == title){
										  b[i].num += rm[i].quantity;
										  break;
									  }
								  }
								  f.write_book(b, size);
								  break;
							  }
						  }
						  f.write_request(rm, size);
						  user_menu();
			   }
				   break;
			   } 
	}
		break;
	case 5: {
				system("cls");
				cout << "-----------------------------------------------------------" << endl;
				cout << "1. Add book" << endl << "2. Remove book" << endl << "0. Back" << endl;
				int choice;
				fflush(stdin);
				choice = getchoice(0, 2);
				switch (choice)
				{
				case 1: {
							b.Add_book();
							 user_menu();
				}
					break;
				case 2:{
						   b.Delete_book();
						   user_menu();
				}
				default:
					break;
				}
	}
		break;
	case 6:{
			   b.Display_all_book();
			   system("pause>nul");
			   user_menu();
	}
		break;
	case 7:{
			   book b;
			   b.Display_all_book();
			   b.Find_book();
			   system("pause>nul");
			   user_menu();
	}
		break;
	default:
		break;
	}
	delete[] rm;
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
					w.write_manager(a, size);
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
					w.write_manager(a, size);
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
	cout << "---------------------------------NOTIFICATION-------------------------------" << endl;
	int j = 0; // Bien danh so thu tu notification
	for (int i = 0; i < size; i++){
		if (rm[i].accept == 1){
			j++;
			p[j] = i;
			cout << j << ". User \"" << rm[i].usrname << "\" wants to borrow " << rm[i].quantity << " book(s) named \"" << rm[i].title << "\" on: " << rm[i].date << endl;
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
		cout << "1. Accept request" << endl << "2. Deny request" << endl << "0. Back" << endl;
		int choice;
		cout << "Enter your choice: ";
		cin >> choice;
		while (choice<0 || choice>2 || cin.fail()){
			cout << "Please retype: ";
			cin.clear();
			cin.ignore(1000, '\n');
			cin >> choice;
		} 
		switch (choice){
		case 0: user_menu(); break;
		case 1: {
					int choice;
					cin.clear();
					cin.ignore(1000, '\n');
					cout << "Choose which request you want to accept: ";
					cin >> choice;
					while (choice <1 || choice >j || cin.fail()){
						cout << "Please retype: ";
						cin.clear();
						cin.ignore(1000, '\n');
						cin >> choice;
					}
					rm[p[choice]].accept = 0; //Yeu cau duoc chap nhan
					file f;
					f.write_request(rm, size);
					delete[] rm;
					cout << "------------ Successful ------------" << endl;
					Sleep(1000);
					notification();
		}
		case 2:{
				   int choice;
				   cout << "Choose which request you want to deny: ";
				   cin >> choice;
				   while (choice <1 || choice >j || cin.fail()){
					   cout << "Please retype: ";
					   cin.clear();
					   cin.ignore(1000, '\n');
					   cin >> choice;
				   }
				   rm[p[choice]].accept = 2; //Yeu cau khong duoc chap nhan
				   f.write_request(rm, size);
				   file f;
				   fstream bk("book.txt", ios::in | ios::out);
				   int _size;
				   _size = f.size(bk);
				   bk.close();
				   book *b = new book[_size];
				   f.read_book(b, _size);
				   for (int i = 0; i < _size; i++) {
					   if (b[i].title == rm[p[choice]].title) {
						   b[i].num += rm[p[choice]].quantity;
					   }
				   }
				   f.write_book(b, _size);
				   delete[] rm;
				   delete[] p;
				   cout << "------------ Successful ------------" << endl;
				   Sleep(1000);
				   notification();
		}
		}
	}
	delete[] p;
}

manager::manager()
{
}


manager::~manager()
{
}
