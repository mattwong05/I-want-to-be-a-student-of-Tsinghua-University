#include "functionTest.h"
#include "TimeIt.h"

void insertLog(void) {
	TimeIt timeIt;
	int year, month, day, beginHour, beginMin, beginSec, finishHour, finishMin, finishSec;
	string beginTime, finishTime, spendTime, others;
	char insertCheck;

	cout << "现在是插入模式！\n";
	string log = contentEnter_sub();
	cout << "请输入日期： YYYY MM DD(以空格间隔，回车结束输入):";
	cin >> year >> month >> day;
	cout << "请输入开始时间： HH MM SS(以空格间隔，回车结束输入):";
	cin >> beginHour >> beginMin >> beginSec;
	beginTime = timeIt.toStd(year, month, day, beginHour, beginMin, beginSec);
	cout << "请输入结束时间： HH MM SS(以空格间隔，回车结束输入):";
	cin >> finishHour >> finishMin >> finishSec;
	finishTime = timeIt.toStd(year, month, day, finishHour, finishMin, finishSec);
	
	changeColor(深红色, 深黄色);
	cout << "请检查时间输入是否正确！\n开始时间:" << beginTime << "\n结束时间:" << finishTime << endl;
	changeColor();
	
INSERTCHECK:
	cout << "(1)没问题\t(0)重新输入\n";
	insertCheck = _getch();
	switch (insertCheck) {
	case '1':
		spendTime = timeIt.stdSubtract(finishTime, beginTime);
		if (spendTime == "Error") return;
		log += beginTime + ',' + finishTime + ',' + spendTime + ',';
		cout << "请留下备注:";
		cin >> others;
		log += others + ',' + timeIt.getTime_t() + "插入";
		addLog(log);
		break;
	case '0':
		return insertLog();
		break;
	default:
		cout << "输入错误,请重试！";
		goto INSERTCHECK;
		break;
	}
	
}