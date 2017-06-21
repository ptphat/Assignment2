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
void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
	SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
	SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
void main() {
	//CONSOLE_CURSOR_INFO Info;
	//Info.bVisible = FALSE;
	//Info.dwSize = 20;
	//SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
	
//	SetWindow(800, 600);

	
	menu mn0;
	mn0.welcome();
	system("color 0F");
	mn0.mainmenu();
	mn0.goodbye();
	//admin ad;
	//ad.user_menu();
}