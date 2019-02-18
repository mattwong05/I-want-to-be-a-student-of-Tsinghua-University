#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>
#include <iomanip>

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

void TimeIt::reset(void) {
	consumeTime = consumeTime_buf = 0;
}

void TimeIt::start(void) {
	begin = clock();
}

void TimeIt::pause(void) {
	finish = clock();
	consumeTime_buf = (int)(finish - begin) / CLOCKS_PER_SEC;
	consumeTime += consumeTime_buf;
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
		consumeTime %= 3600;
	}
	if (consumeTime >= 60) {
		ss << consumeTime / 60 << "分钟";
		consumeTime %= 60;
	}
	ss << consumeTime << "秒";
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
	return string();
}
