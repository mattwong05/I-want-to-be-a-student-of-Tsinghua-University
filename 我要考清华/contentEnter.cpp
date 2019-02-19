#include "functionTest.h"
#include "TimeIt.h"
#include <sstream>


string contentEnter_sub(void) {
	TimeIt nowTime;
	string log, classifyName, tagName, contentName;
	char contentCheck;
	cout << "欢迎记录你的时间！\n请输入你即将进行的内容的大分类:";
	cin >> classifyName;
	cout << "请输入你要学习的子分类：";
	cin >> tagName;
	cout << "请输入你要学习的内容：";
	cin >> contentName;

	changeColor(深黄色);
	cout << "请确认你的输入，检查无误后我们就要进行啦!!!\n";
	cout << "大分类:" << classifyName << "\t子分类:" << tagName << "\t学习内容:" << contentName << endl;
	changeColor();

CONTENTCHECK:
	cout << "(1)确认无误\t(0)需要更改\n";
	contentCheck = _getch();
	switch (contentCheck) {
	case '1':
		log = classifyName + ',' + tagName + ',' + contentName + ',';
		return log;
		break;
	case '0':
		return contentEnter_sub();
		break;
	default:
		changeColor(深红色);
		cout << "错误输入，请重试！！！";
		changeColor();
		goto CONTENTCHECK;
	}
}

void contentEnter(void) {
	TimeIt nowTime;
	string log, spendTime, others;
	char saveCheck;
	
	log = contentEnter_sub() + nowTime.getTime_t() + ',';

	spendTime = nowTime.Timer();
	log += nowTime.getTime_t() + ',' + spendTime + ',';

SAVECHECK:
	changeColor(深红色, 深黄色);
	cout << log << endl;
	changeColor();

	cout << "想要保存吗？\t(1)是的请保存\t(0)请不要保存\n";
	saveCheck = _getch();
	switch (saveCheck) {
	case '1':
		cout << "请留下备注:";
		cin >> others;
		log += others;
		addLog(log);
		return;
		break;
	case '0':
		log = "";
		return;
		break;
	default:
		goto SAVECHECK;
	}
}

