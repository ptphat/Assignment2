#include"account.h"
#include"file.h"
#include"menu.h"
#include"reader.h"

int file::size(fstream &file) {
	string st;
	int size = 0;
	while (getline(file, st)) size++;
	file.clear();
	file.seekg(0, 0);
	return size;
	
};
void file::read_account(account *arrayacc,int size) {
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
		file >> arrayacc[i].role;
		getline(file, st);
	}
	file.close();
}
void file::write_account( account *arryacc, int size) {
	fstream file("reader_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ";" << arryacc[i].get_username() << ";" << arryacc[i].get_password() << ";" << arryacc[i].get_name() << ";" << arryacc[i].get_birthday() << ";" << arryacc[i].get_phone() << ";"<< endl;
	}
	file.close();
}
