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
void peppaPig(void);
void familyWithChildren(void);


void changeColor(int word = 7, int background = 0);

void addLog(string logData);
void contentEnter(void);
string contentEnter_sub(void);
void insertLog(void);

enum color {
	黑色, 深蓝色, 深绿色, 深青色,深红色, 深粉色, 深黄色, 深白色,
	灰色, 浅蓝色, 浅绿色, 浅青色,浅红色, 浅粉色, 浅黄色, 浅白色,
};