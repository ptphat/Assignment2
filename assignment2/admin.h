#pragma once
#include"reader.h"

class admin : public reader{
public:
	void sign_in();
	void user_menu();
	void edit_profile();
public:
	admin();
	~admin();
};

