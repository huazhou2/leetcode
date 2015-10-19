#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <ncurses.h>
#include <windows.h>
using namespace std;
 
int main()
{
	int a=1;
	int count;
	while (GetAsyncKeyState(VK_UP) & 0x8000) {
	//cin>>a;
	system("clear");
	cout<<setw(++count);
	cout<<"-";
	}
	cout<<"Done"<<endl;

	
}
