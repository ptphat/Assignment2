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


//================ MAIN ===================
void main() {
	menu mn0;
	mn0.welcome();
	mn0.mainmenu();
	mn0.goodbye();
}