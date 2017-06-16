#pragma once
#include"reader.h"
#include"account.h"

class manager : public reader{
public:
	void sign_in();
	void user_menu();
	void edit_profile();
public:
	manager();
	~manager();
};

