#pragma once
#include"account.h"

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
};

