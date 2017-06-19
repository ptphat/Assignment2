#include<iostream>
#include"independent_function.h"
#include"account.h"
#include"file.h"
#include"menu.h"
#include"reader.h"
#include"book.h"
#include"request_manager.h"
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
#include<ctime>
using namespace std;

void main() {
	//CONSOLE_CURSOR_INFO Info;
	//Info.bVisible = FALSE;
	//Info.dwSize = 20;
	//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
	menu mn0;
	mn0.welcome();
	system("color 0F");
	mn0.mainmenu();
	mn0.goodbye();
}