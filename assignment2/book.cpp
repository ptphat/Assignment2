#include"book.h"
#include"file.h"

book::book(){
	id = "#";
	author = "NO INFORMATION";
	date = "NO INFORMATION";
	title = "NO INFORMATION";
	describe = "NO INFORMATION";
	num = 0;
}

void book::Add_book(){
	int size;
	cout << "\n-Enter the number of book you want to add: ";
	cin >> size;
	string s;
	book *list = new book[size];
	for (int i = 0; i < size; i++){
		cout << "\n\n-BOOK " << i + 1 << ":";
		cout << "\n-Enter book id: ";
		fflush(stdin);
		getline(cin, s);
		list[i].Set_id(s);
		cout << "-Enter book name: ";
		fflush(stdin);
		getline(cin, s);
		list[i].Set_title(s);
		cout << "-Enter book's author: ";
		fflush(stdin);
		getline(cin, s);
		list[i].Set_author(s);
		cout << "-Enter date publish: ";
		fflush(stdin);
		getline(cin, s);
		list[i].Set_date(s);
		cout << "-Enter describe about book: ";
		fflush(stdin);
		getline(cin, s);
		list[i].Set_describe(s);
		cout << "-Enter number of book available: ";
		int n0;
		cin >> n0;
		list[i].Set_num_of_book(n0);

	}

	// save number of book to file
	fstream f("book.txt", ios::out | ios::app);
	for (int i = 0; i < size; i++){
		f << list[i].Get_book_id() << ";" << list[i].Get_author() << ";" << list[i].Get_date() << ";" << list[i].Get_title() << ";" << list[i].Get_num_of_book() << ";" << list[i].Get_describe() << endl;
	}
	f.close();

	cout << "\n----- Add book successful ------";
	Sleep(1000);
	// delete pointer
	delete[] list;
	list = NULL;
}

void book::Modify_book(){
	system("cls");
	// Load data from file
	fstream f0("book.txt", ios::in);
	file f;
	int size = f.size(f0);
	f0.close();
	book *list = new book[size];
	f.read_list_book(list, size);

	cout << "\n---------------- MIDIFY BOOK INFORMATION ----------------\n";

	cout << "\nEnter ID of book you want to modify ";
	cout << "\nIf you don't remember, let find it and come back";
	cout << "\n-ID: ";
	string s;
	bool found = false;
	fflush(stdin);
	getline(cin, s);
	// find ID in list book
	for (int i = 0; i < size; i++){
		if (s.compare(list[i].Get_book_id()) == 0){
			found = true;
			list[i].Display_book_info();
			cout << endl;
			int option;
			do
			{
				cout << "\nChoose info you want to modify: ";
				cout << "\n1. ID";
				cout << "\n2. Name";
				cout << "\n3. Author";
				cout << "\n4. Date publish";
				cout << "\n5. Number of book available";		// consider ....
				cout << "\n6. Describe";
				cout << "\n0. Return";
				cout << "\nYour choose: ";
				cin >> option;
				if (option == 0) break;
				switch (option)
				{
				case 1:{
						   cout << "-Book id: " << id << endl;
						   cout << "\nSorry! You can't modify book ID...";
						   break;
				}
				case 2:{
						   cout << "-Enter new book name: ";
						   fflush(stdin);
						   getline(cin, s);
						   list[i].Set_title(s);
						   break;
				}
				case 3:{
						   cout << "-Enter new book's author: ";
						   fflush(stdin);
						   getline(cin, s);
						   list[i].Set_author(s);
						   break;
				}
				case 4:{
						   cout << "\n-Enter new date publish: ";
						   fflush(stdin);
						   getline(cin, s);
						   list[i].Set_date(s);
						   break;
				}
				case 5:{
						   cout << "\n-Enter new number of book: ";
						   int n;
						   cin >> n;
						   list[i].Set_num_of_book(n);
						   break;
				}
				case 6:{
						   cout << "\n-Enter new describe about book: ";
						   fflush(stdin);
						   getline(cin, s);
						   list[i].Set_describe(s);
						   break;
				}
				default:
					break;
				}

				// SAVE CHANGE TO FILE
				f.write_list_book(list, size);
				cout << "\n---- Update successful -----";
				Sleep(1500);
				cout << "\nDo you want to modify again (y/n)?_";
				cin >> s;
				if (s != "y" || s != "Y"){ break; }
			} while (option != 0);
		}
	}
	if (!found){
		cout << "\nNot found the book you want to modify !!!";
		system("pause>nul");
	}
}

//===================================================================
bool CheckSubstring(std::string firstString, std::string secondString){

	if (secondString.size() > firstString.size())
		return false;
	for (int i = 0; i < firstString.size(); i++){
		firstString[i] = toupper(firstString[i]);
	}
	for (int i = 0; i < secondString.size(); i++){
		secondString[i] = toupper(secondString[i]);
	}
	// important
	for (int i = 0; i < firstString.size(); i++){
		int j = 0;
		if (firstString[i] == secondString[j]){
			while (firstString[i] == secondString[j] && j < secondString.size()){
				j++;
				i++;
			}
			if (j == secondString.size())
				return true;
		}
	}
	return false;
}

//===================================================
bool book::Find_book(){
	// Load data from file
	fstream f0("book.txt", ios::in);
	file f;
	int size = f.size(f0);
	f0.close();
	book *list = new book[size];
	f.read_list_book(list, size);
	string s;

	bool found = false;
	cout << "\n-Enter the book you want to find: ";
	fflush(stdin);
	getline(cin, s);
	for (int i = 0; i < size; i++){
		if (CheckSubstring(list[i].Get_book_id(), s) || CheckSubstring(list[i].Get_title(), s) || CheckSubstring(list[i].Get_author(), s) || CheckSubstring(list[i].Get_date(), s) || CheckSubstring(list[i].Get_describe(), s)){
			list[i].Display_book_info();
			cout << endl;
			found = true;
		}
	}
	if (!found){
		cout << "\nNot found!";
		Sleep(1000);
	}
	return found;
}

void book::Display_book_info(){
	cout << "\n-Book ID: " << id;
	cout << "\n-Book name: " << title;
	cout << "\n-Author: " << author;
	cout << "\n-Date publish: " << date;
	cout << "\n-Number of book available: " << num;
	cout << "\n-More describe: " << describe;
}

void book::Display_all_book(){
	system("cls");
	fstream f0("book.txt", ios::in);
	file f;
	int size = f.size(f0);
	f0.close();
	book* list = new book[size];
	f.read_list_book(list, size);
//	cout << "\nALL LIST BOOK\n";
	cout << "-------------------------------------------------ALL LIST BOOK-------------------------------------------------\n";
	cout << setw(6) << left << "ID" << setw(50) << left << "TITLE" << setw(40) << left << "AUTHOR" << setw(7) << left << "NUMBER" << endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++){
		cout << setw(6) << left << list[i].Get_book_id() << setw(50) << left << list[i].Get_title() << setw(40) << left << list[i].Get_author() << setw(7) << left << list[i].Get_num_of_book() << endl;
	}
//	system("pause>nul");
}
