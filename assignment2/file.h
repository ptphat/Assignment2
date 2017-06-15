#pragma once
#include"account.h"
#include"menu.h"
#include"reader.h"
using namespace std;

class file
{
public:
	int size(fstream &file);
	void read_account(account *arrayacc, int size);
	void write_account(account *arryacc, int size);
};

