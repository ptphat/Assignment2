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
		file >> arrayacc[i].role;
		getline(file, st);
	}
	file.close();
}
void file::write_reader( account *arryacc, int size) {
	fstream file("reader_data.txt", ios::in | ios::out);
	for (int i = 0; i < size; i++) {
		file << arryacc[i].get_id() << ";" << arryacc[i].get_username() << ";" << arryacc[i].get_password() << ";" << arryacc[i].get_name() << ";" << arryacc[i].get_birthday() << ";" << arryacc[i].get_phone() << ";"<< endl;
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
		file >> arrayacc[i].role;
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
		file >> arrayacc[i].role;
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
