#pragma once
#include"file.h"



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
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
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
		fflush(stdin);
		getline(file, st);
	}
	file.close();
}
void file::write_reader( account *arryacc, int size) {
	fstream file("reader_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ";" << arryacc[i].get_username() << ";" << arryacc[i].get_password() << ";" << arryacc[i].get_name() << ";" << arryacc[i].get_birthday() << ";" << arryacc[i].get_phone() << ";"<<endl;
	}
	file.close();
}
void file::read_manager(account *arrayacc, int size) {
	fstream file("manager_data.txt", ios::in | ios::out);
	string st;
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
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
		fflush(stdin);
		getline(file, st);
	}
	file.close();
}
void file::write_manager(account *arryacc, int size) {
	fstream file("manager_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ";" << arryacc[i].get_username() << ";" << arryacc[i].get_password() << ";" << arryacc[i].get_name() << ";" << arryacc[i].get_birthday() << ";" << arryacc[i].get_phone() << ";" << endl;
	}
	file.close();
}
void file::read_admin(account *arrayacc, int size) {
	fstream file("admin_data.txt", ios::in | ios::out);
	string st;
	for (int i = 0; i < size; i++) {
		fflush(stdin);
		getline(file, st, ';');
		arrayacc[i].set_id(st);
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
		fflush(stdin);
		getline(file, st);
	}
	file.close();
}
void file::write_admin(account *arryacc, int size) {
	fstream file("admin_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ";" << arryacc[i].get_username() << ";" << arryacc[i].get_password() << ";" << arryacc[i].get_name() << ";" << arryacc[i].get_birthday() << ";" << arryacc[i].get_phone() << ";" << endl;
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
		file >> arrrq[i].verify;
		getline(file, st);
	}
	file.close();
}
void file::write_request(request_manager *arrrq, int size){
	fstream file("request.txt", ios::in | ios::out);
	string st;
	file.seekg(0, 0);
	for (int i = 0; i < size; i++){
		file << arrrq[i].date << ';' << arrrq[i].usrname << ';' << arrrq[i].title << ';' << arrrq[i].quantity << ';' << arrrq[i].verify << ';' << endl;
	}
	file.close();
}