#pragma once
#include"account.h"
#include"file.h"
#include"menu.h"

using namespace std;
class reader : public account {
public:
	string id_signed_in;
	string usrname_signed_in;
	string pass_signed_in;
	string name_signed_in;
	string birth_signed_in;
	string phone_signed_in;
public:
	void sign_in();
	void reader_menu();
	void edit_profile();
	void muonsach();
	void notification();
};
