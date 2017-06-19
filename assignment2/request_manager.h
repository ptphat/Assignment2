#pragma once
#include"independent_function.h"


class request_manager : public independent_function
{
public:
	string date;
	string usrname;
	string title;
	int quantity;
	int verify; // Xac thuc su chap nhan cua manager
};

