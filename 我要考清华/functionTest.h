#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <conio.h>	//	getch();
#include <Windows.h>
using namespace std;
void sendOff(void);
void songOfJoy(void);
void countDown(int hh, int mm, int ss = 0);
void printTime(double consumeTime);
string printTime_t(double consumeTime);
void getTime(void);
string getTime_t(int x = 0);
void changeColor(int word = 7, int background = 0);
void addLog(string logData);