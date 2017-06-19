#pragma once
#include"independent_function.h"
#include"reader.h"

class admin : public reader{
public:
	void sign_in();
	void user_menu();
	void edit_profile();
	void notification();
public:
	admin();
	~admin();
};

