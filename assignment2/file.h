#pragma once
#include"independent_function.h"
#include"request_manager.h"
#include"book.h"
#include"account.h"
class file : public independent_function
{
public:
	int clean_stdin() {
		while (getchar() != '\n') {
		}
		return 1;
	}
	int getchoice(int begin, int end){
		int choice;
		char c;
		do{
			cout << "Enter your choice: ";
			fflush(stdin);
		} while (((scanf_s("%d%c", &choice, &c) != 2 || c != '\n') && clean_stdin()) || choice < begin || choice > end);
		return choice;
	}
	int size(fstream &file);
	void read_reader(account *arrayacc, int size);
	void write_reader(account *arryacc, int size);
	void read_manager(account *arrayacc, int size);
	void write_manager(account *arrayacc, int size);
	void read_admin(account *arrayacc, int size);
	void write_admin(account *arrayacc, int size);
	void read_book(book *arraybk, int size);
	void read_request(request_manager *arrrq, int size);
	void write_request(request_manager *arrrq, int size);
	void read_list_book(book*, int);
	void write_list_book(book*, int);
};

