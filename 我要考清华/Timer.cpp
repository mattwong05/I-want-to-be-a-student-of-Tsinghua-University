#include "functionTest.h"
#include <sstream>


//	modIt(double a, int b)	对double求mod
double modIt(double a, int b)
{
	while (a > b)
	{
		a -= b;
	}
	return a;
}


//	printTime(double consumeTime)	输出间隔时间
void printTime(double consumeTime)
{
	bool hourFlag = false;
	if (consumeTime > 3600) {
		cout << int(consumeTime / 3600) << "h ";
		consumeTime = modIt(consumeTime, 3600);
		hourFlag = true;
	}
	if (consumeTime > 60 || hourFlag == true) {
		cout << int(consumeTime / 60) << "min ";
		consumeTime = modIt(consumeTime, 60);
	}
	cout << consumeTime << "s\n";
}


string printTime_t(double consumTime) {
	int consumSec = int(consumTime + 0.5);
	string timeBuf;
	stringstream ss;
	ss << consumSec / 3600 << "小时" << consumSec % 3600 / 60 << "分钟" << consumSec % 60 << "秒";
	ss >> timeBuf;
	return timeBuf;
}


//	getTime()	格式化输出时间
void getTime(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d\t星期%1d\t%02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, sys.wDayOfWeek, sys.wHour, sys.wMinute, sys.wSecond);
}


string getTime_t(void)
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	stringstream ss;
	string localTime;
	ss << sys.wYear << "年" << sys.wMonth << "月" << sys.wDay << "日-" << sys.wHour<< "时"<< sys.wMinute << "分" << sys.wSecond << "秒";
	ss >> localTime;
	return localTime;
}