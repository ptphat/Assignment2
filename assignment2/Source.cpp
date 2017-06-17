#include<iostream>
#include"account.h"
#include"file.h"
#include"menu.h"
#include"reader.h"
#include<string>
#include<iomanip>
#include<fstream>
#include<Windows.h>
using namespace std;

void main() {
	//CONSOLE_CURSOR_INFO Info;
	//Info.bVisible = FALSE;
	//Info.dwSize = 20;
	//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
	menu mn0;
	mn0.welcome();
	mn0.mainmenu();
	mn0.goodbye();
}