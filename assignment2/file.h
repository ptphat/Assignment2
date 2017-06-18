#pragma once
#include"account.h"
#include"request_manager.h"
#include"book.h"

class file
{
public:
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

