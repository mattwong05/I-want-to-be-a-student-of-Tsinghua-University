#include "functionTest.h"
#include "TimeIt.h"
//using namespace std;	//	虽然我在function.h中包含了 using namespace std 但是有时候还是会报错

//	版本控制
string versionInf = "0.1.1,修补了在0.1.0中出现的show()函数刷新导致的记录时间的总时间出现问题,2019/02/20";


//	主程序所需命名
bool mainFlag = true;
char mainControler;


int main(void)
{
	system("title 我要考清华!!!");
	TimeIt timeIt;
	timeIt.getTime();
	cout << timeIt.getTime_t();
	cout << "\nWhere there is a will, there is a way!\t有志者，事竟成！\n";
	cout << "Now version is " << versionInf << "\n\n\n";
	makeWorkPath();

	while (mainFlag)
	{
		system("title 我要考清华!!!");
		cout << "请输入数字：(1)记录时间 (2)插入记录 (3)查询记录_即将推出 (4)分析结果_即将推出 (5)记录心情日志 (8)计时器 (9)倒计时 (0)退出程序\n";
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
			//	心情日志
			insertMood();
			break;

		case '8':
			//	计时器
			timeIt.Timer();
			break;

		case '9':
			//	倒计时
			timeIt.countDown();
			break;

		case '7':
			//	彩蛋
			familyWithChildren();
			break;

		case '0':
			//	退出程序
			mainFlag = false;
			break;

		default:
			cout << "Wrong Key! Please Try Again!\n";
			break;
		}
	}
	cout << "Good Bye! TsingHua University is waiting for the man who is hardworking!\n";
	sendOff();
	return 0;
}
