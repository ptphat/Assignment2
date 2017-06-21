#pragma once
#include"file.h"
#include"account.h"


int file::size(fstream &file) {
	string st;
	int size = 0;
	while (getline(file, st)) size++;
	file.clear();
	file.seekg(0, 0);
	return size;
	
};
void file::read_reader(account *arrayacc,int size) {
	fstream file("reader_data.txt", ios::in | ios::out);
	string st;
	bool s;
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_date(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_username(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_password(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_name(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_birthday(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_phone(st);
		file >> s;
		arrayacc[i].set_active(s);
		getline(file, st);
	}
	file.close();
}
void file::write_reader( account *arryacc, int size) {
	fstream file("reader_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ';' << arryacc[i].get_date() << ';' << arryacc[i].get_username() << ';' << arryacc[i].get_password() << ';' << arryacc[i].get_name() << ';' << arryacc[i].get_birthday() << ';' << arryacc[i].get_phone() << ';' << arryacc[i].get_active() << ';' << endl;
	}
	file.close();
}
void file::read_manager(account *arrayacc, int size) {
	fstream file("manager_data.txt", ios::in | ios::out);
	string st;
	bool s;
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_date(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_username(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_password(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_name(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_birthday(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_phone(st);
		file >> s;
		arrayacc[i].set_active(s);
		getline(file, st);
	}
	file.close();
}
void file::write_manager(account *arryacc, int size) {
	fstream file("manager_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ';' << arryacc[i].get_date() << ';' << arryacc[i].get_username() << ';' << arryacc[i].get_password() << ';' << arryacc[i].get_name() << ';' << arryacc[i].get_birthday() << ';' << arryacc[i].get_phone() << ';' << arryacc[i].get_active() << ';' << endl;
	}
	file.close();
}
void file::read_admin(account *arrayacc, int size) {
	fstream file("admin_data.txt", ios::in | ios::out);
	string st;
	bool s;
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_date(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_username(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_password(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_name(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_birthday(st);
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_phone(st);
		file >> s;
		arrayacc[i].set_active(s);
		getline(file, st);
	}
	file.close();
}
void file::write_admin(account *arryacc, int size) {
	fstream file("admin_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ';' << arryacc[i].get_date() << ';' << arryacc[i].get_username() << ';' << arryacc[i].get_password() << ';' << arryacc[i].get_name() << ';' << arryacc[i].get_birthday() << ';' << arryacc[i].get_phone() << ';' << arryacc[i].get_active() << ';' << endl;
	}
	file.close();
}
void file::read_book(book *arraybk, int size){
	fstream file("book.txt", ios::in | ios::out);
	string st;
	for (int i = 0; i < size; i++){
		fflush(stdin);
		getline(file, arraybk[i].id, ';');
		fflush(stdin);
		getline(file, arraybk[i].title, ';');
		fflush(stdin);
		getline(file, arraybk[i].author, ';');
		fflush(stdin);
		getline(file, arraybk[i].date, ';');
		file >> arraybk[i].num;
		file.seekg(1, 1);
		getline(file, arraybk[i].describe, ';');
		getline(file, st);
	}
}
void file::read_request(request_manager *arrrq, int size){
	fstream file("request.txt", ios::in | ios::out);
	string st;
	for (int i = 0; i < size; i++){
		fflush(stdin);
		getline(file, arrrq[i].date, ';');
		fflush(stdin);
		getline(file, arrrq[i].usrname, ';');
		fflush(stdin);
		getline(file, arrrq[i].title, ';');
		file >> arrrq[i].quantity;
		file.seekg(1, 1);
		file >> arrrq[i].accept;
		file.seekg(1, 1);
		file >> arrrq[i].borow;
		file.seekg(1, 1);
		file >> arrrq[i].give_back;
		getline(file, st);
	}
	file.close();
}
void file::write_request(request_manager *arrrq, int size){
	fstream file("request.txt", ios::in | ios::out);
	string st;
	file.seekg(0, 0);
	for (int i = 0; i < size; i++){
		file << arrrq[i].date << ';' << arrrq[i].usrname << ';' << arrrq[i].title << ';' << arrrq[i].quantity << ';' << arrrq[i].accept << ';' << arrrq[i].borow << ';' << arrrq[i].give_back << ';' << endl;
	}
	file.close();
}
// Ham duoi tuong duong ham read_book()
void file::read_list_book(book* list, int size)
{
	fstream f0("book.txt", ios::in);
	string s;
	for (int i = 0; i < size; i++){
		getline(f0, s, ';');
		list[i].Set_id(s);
		getline(f0, s, ';');
		list[i].Set_title(s);
		getline(f0, s, ';');
		list[i].Set_author(s);
		getline(f0, s, ';');
		list[i].Set_date(s);
		int x;
		f0 >> x;
		list[i].Set_num_of_book(x);
		getline(f0, s, ';');
		getline(f0, s);
		list[i].Set_describe(s);
	}
	f0.close();
}
void file::write_list_book(book* list, int size)
{
	fstream file("book.txt", ios::trunc | ios::out);
	for (int i = 0; i < size; i++) {
		file << list[i].Get_book_id() << ";" << list[i].Get_title() << ";" << list[i].Get_author() << ";" << list[i].Get_date() << ";" << list[i].Get_num_of_book() << ";" << list[i].Get_describe() << ";" << endl;
	}
	file.close();
}