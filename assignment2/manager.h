#pragma once
#include"account.h"
#include"reader.h"
#include"request_manager.h"
class manager : public reader{
public:
	string usrname;
	string book;
	int quantity;
public:
	void sign_in();
	void user_menu();
	void edit_profile();
	void notification();
	void accept(request_manager *rq, int size);
public:
	manager();
	~manager();
};

