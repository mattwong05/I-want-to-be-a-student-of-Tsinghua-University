#include "functionTest.h"
#include "TimeIt.h"
#include "Event_V2.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;
//using namespace std;	//	虽然我在function.h中包含了 using namespace std 但是有时候还是会报错
						//	2019/12/6	头文件中改成std::的形式了
//	版本控制
string versionInf = "0.1.4,为2.0版本做铺垫，新增Event类，希望可以实现：不限任务等级层数，方便的数据统计及管理，目前实现了不限制层数的储存和读取,2019/12/06";

//	主程序所需命名
bool mainFlag = true;
char mainControler;


int main(void)
{
	system("title 我要考清华!!!");
	TimeIt timeIt;
	timeIt.getTime();
	cout << timeIt.getTime_t();
	//cout << "\nWhere there is a will, there is a way!\t有志者，事竟成！\n";
	cout << "Now version is " << versionInf << "\n\n\n";
	makeWorkPath();
	/*
		Event class test
	*/
	Event super_root;
	super_root.load();
	//	end
	while (mainFlag)
	{
		system("title 我要考清华!!!");
		cout << "请输入数字：(1)记录时间 (2)插入记录 (3)查询记录_即将推出 (4)分析结果_即将推出 (5)记录自控力+心情日志 (6)测试版插入日志 (8)计时器 (9)倒计时 (0)退出程序\n";
		mainControler = _getch();
		switch (mainControler) {
		case '1':
			//	时间记录
			contentEnter();
			break;

		case '2':
			//	插入记录
			insertLog();
			break;

		case '3':
			//	查询时间_待补充

			break;

		case '4':
			//	分析时间_待补充

			break;

		case '5':
			//	心情、自控力日志
			insertMood();
			break;

		case '6':
			super_root.add();
			super_root.save();
			break;

		case '7':
			//	彩蛋
			familyWithChildren();
			break;

		case '8':
			//	计时器
			timeIt.Timer();
			break;

		case '9':
			//	倒计时
			timeIt.countDown();
			break;

		case '0':
			//	退出程序
			mainFlag = false;
			break;

		default:
			cout << "错误的按键! 请重新输入!\n";
			break;
		}
	}
	cout << "再见，加油！\n";
	sendOff();
	return 0;
}
