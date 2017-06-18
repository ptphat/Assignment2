#pragma once
#include"account.h"

class book
{
public:
	string id;
	string author;
	string date;
	string title;
	int num;
	string describe;

public:
	book();
	void Add_book();
	void Modify_book();
	bool Find_book();
	void Display_book_info();
	void Display_all_book();
	friend bool CheckSubstring(string, string);
	string Get_book_id(){ return id; }
	string Get_author(){ return author; }
	string Get_date(){ return date; }
	string Get_title(){ return title; }
	string Get_describe(){ return describe; }
	int Get_num_of_book(){ return num; }

	void Set_id(string s){ id = s; }
	void Set_author(string s){ author = s; }
	void Set_date(string s){ date = s; }
	void Set_title(string s){ title = s; }
	void Set_describe(string s){ describe = s; }
	void Set_num_of_book(int x){ num = x; }
};

