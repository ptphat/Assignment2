#pragma once
#include"independent_function.h"
#include"account.h"



class reader : public account {
public:
	string id_signed_in;
	string usrname_signed_in;
	//string pass_signed_in;
	//string name_signed_in;
	//string birth_signed_in;
	//string phone_signed_in;
public:
	virtual void sign_in();
	virtual void user_menu();
	virtual void edit_profile();
	void bookrequest();
	void notification();
	void show_all_reader();
};
