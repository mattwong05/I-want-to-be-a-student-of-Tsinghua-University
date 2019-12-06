#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>
#include <iomanip>
using namespace std;


void TimeIt::getTime(void) {
	char dayOfWeek[7][4] {
		"日", "一", "二", "三", "四", "五", "六"
	};
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	printf("%4d/%02d/%02d 星期%s %02d:%02d:%02d\n", sys.wYear, sys.wMonth, sys.wDay, dayOfWeek[sys.wDayOfWeek], sys.wHour, sys.wMinute, sys.wSecond);
}

string TimeIt::getTime_t(void) {
	stringstream ss;
	string getTimeIt;
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	ss << setw(4) <<sys.wYear << '/' << setw(2) << setfill('0') <<sys.wMonth << '/' 
		<< setw(2) << setfill('0') << sys.wDay << '-' 
		<< setw(2) << setfill('0') << sys.wHour << ':' 
		<< setw(2) << setfill('0') << sys.wMinute << ':' 
		<< setw(2) << setfill('0') << sys.wSecond;
	ss >> getTimeIt;
	return getTimeIt;
}

void TimeIt::countDown(void) {
	int countDownHH, countDownMM, countDownSS;
	cout << "请输入所需倒计时的时间 (hours minutes seconds)并以换行结束输入:";
	cin >> countDownHH >> countDownMM >> countDownSS;
	countDownSS += countDownHH * 3600 + countDownMM * 60;
	countDownSS *= 1000;
	Sleep(countDownSS);
	cout << "时间到！！！" << endl;
	countDownHH > 0 || countDownMM >= 1 ? songOfJoy() : familyWithChildren();
}


void TimeIt::newCountDown(void) {
	/*
		思路：
			do{
				获取当前时间，
				计算当前时间和目标时间的差值，
				显示当前剩余时间，
			}while（当前时间小于目标时间）
	*/
}


void TimeIt::reset(void) {
	consumeTime_buf = consumeTime = 0;
}

void TimeIt::start(void) {
	begin = clock();
}

void TimeIt::pause(void) {
	finish = clock();
	consumeTime_buf = (double)(finish - begin) / CLOCKS_PER_SEC;
	consumeTime += int(consumeTime_buf+0.5) ;
	show();
}

void TimeIt::stop(void) {
	system("cls");
	timerFlag = false;
}

string TimeIt::show(void) {
	stringstream ss;
	string consumeTimePrint;
	if (consumeTime >= 3600) {
		ss << consumeTime / 3600 << "小时";
	}
	if (consumeTime >= 60) {
		ss << consumeTime % 3600 / 60 << "分钟";
	}
	ss << consumeTime % 60 << "秒";
	ss >> consumeTimePrint;
	cout << consumeTimePrint << endl;
	return consumeTimePrint;
}

string TimeIt::Timer(void) {
	reset();
	system("title 计时器");
	timerFlag = true;
	cout << "摁下任意按键以开始计时\n";
	_getch();
	start();
	while (timerFlag) {
		system("cls");
		cout << "********************************************************计时器********************************************************\n";
		cout << "摁下任意按键以暂停计时\n";
		_getch();
		system("cls");
		cout << "********************************************************计时器********************************************************\n";
		pause();
		cout << "停止请按0，其余按键继续\n";
		char timerControler = _getch();
		if (timerControler == '0') {
			stop();
			return show();
		}
		else {
			start();
		}
	}
	_getch();
	return "";
}


string TimeIt::toStd(int year, int month, int day, int hour, int minute, int second) {
	stringstream ss;
	string stdTime;
	ss << setw(4) << year << '/' 
		<< setw(2) << setfill('0') << month << '/'
		<< setw(2) << setfill('0') << day << '-'
		<< setw(2) << setfill('0') << hour << ':'
		<< setw(2) << setfill('0') << minute << ':'
		<< setw(2) << setfill('0') << second;
	ss >> stdTime;
	return stdTime;
}

string TimeIt::stdSubtract(string a, string b)
{
	int yearA, yearB, monthA, monthB, dayA, dayB, hourA, hourB, minA, minB, secA, secB;
	char buf;
	stringstream ss;
	ss << a;
	ss >> yearA >> buf >> monthA >> buf >> dayA >> buf >> hourA >> buf >> minA >> buf >> secA;
	ss.clear();
	ss << b;
	ss >> yearB >> buf >> monthB >> buf >> dayB >> buf >> hourB >> buf >> minB >> buf >> secB;
	//printf("%d/%d/%d %d:%d:%d\n", yearA, monthA, dayA, hourA, minA, secA);
	//printf("%d/%d/%d %d:%d:%d\n", yearB, monthB, dayB, hourB, minB, secB);
	if (yearA == yearB && monthA == monthB && dayA == dayB) {
		return TimeSub(hourA, minA, secA, hourB, minB, secB);
	}
	//	其实并没有机会运行到这，哈哈
	cout << "暂未支持不在同一天的时间计算！！！\n";
	return string();
}

string TimeIt::TimeSub(int h1, int m1, int s1, int h2, int m2, int s2) {
	int sec, min, hour;
	string spendTime;
	stringstream ss;
	if (h1 > h2 || (h1 == h2 && m1 > m2) || (h1 == h2 && m1 == m2 && s1 > s2)) {
		s1 >= s2 ? sec = s1 - s2 : (sec = s1 + 60 - s2, m1--);
		m1 >= m2 ? min = m1 - m2 : (min = m1 + 60 - m2, h1--);
		hour = h1 - h2;
		if (hour) {
			ss << hour << "小时" << min << "分钟" << sec << "秒";
		}
		else if (min) {
			ss << min << "分钟" << sec << "秒";
		}
		else {
			ss << sec << "秒";
		}
		ss >> spendTime;
		return spendTime;
	}
	else {
		cout << "错误的时间，相减为负数！！！\n";
		return "Error";
	}
}