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

