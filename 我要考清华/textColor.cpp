#include "functionTest.h"

void changeColor(int word, int background)
{
	//	word
	//	1   深蓝色
	//	2   深绿色
	//	3   深青色
	//	4   深红色
	//	5   深粉色
	//	6   黄色
	//	7   深白色
	//	8   灰色
	//	9   浅蓝色
	//	10  浅绿色
	//	11  浅青色
	//	12  浅红色
	//	13  浅粉色
	//	14  浅黄色
	//	15  浅白色

	//	background
	//	1~15        黑色
	//	16~31       深蓝色
	//	32~47       深绿色
	//	48~63       深青色
	//	64~79       深红色
	//	80~95       深粉色
	//	96~111      深黄色
	//	112~127     深白色
	//	128~143     灰色
	//	144~159     浅蓝色
	//	160~175     浅绿色
	//	176~191     浅青色
	//	192~207     浅红色
	//	208~223     浅粉色
	//	224~239     浅黄色
	//	240~255     浅白色
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//句柄
	SetConsoleTextAttribute(hout, word + background * 16);
}


//	样例
	//HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);//句柄
	//cout << "原色" << endl;
	//SetConsoleTextAttribute(hout, 7);//没有添加颜色，原色
	//cout << "原色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);//三色相加，白色
	//cout << "白色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED);//红色
	//cout << "红色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN);//绿色
	//cout << "绿色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_BLUE);//蓝色
	//cout << "蓝色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);//红色和绿色相加，黄色
	//cout << "黄色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);//红色和蓝色相加，粉色
	//cout << "粉色" << endl;
	//SetConsoleTextAttribute(hout, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);//绿色和蓝色相加，青色
	//cout << "青色" << endl;
	//SetConsoleTextAttribute(hout, 64 + 15);
	//cout << "深红色背景颜色，浅白色字体颜色" << endl;
	//SetConsoleTextAttribute(hout, 79);
	//cout << "深红色背景颜色，浅白色字体颜色" << endl;