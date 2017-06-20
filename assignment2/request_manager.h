#pragma once
#include"independent_function.h"


class request_manager : public independent_function
{
public:
	string date;
	string usrname;
	string title;
	int quantity;
	// Xac thuc su chap nhan cua manager 0: request duoc chap nhan, 1: Chua duoc chap nhan, 2: bị tu choi
	int accept;
	//Xac thuc da di muon 0: da muon, 1: Chua di muon 
	int borow;
	// Xac thu da tra 0: da tra; 1: chua tra
	int give_back;
	
};

