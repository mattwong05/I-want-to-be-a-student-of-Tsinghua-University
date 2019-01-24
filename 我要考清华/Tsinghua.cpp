#include "functionTest.h"

//	版本控制
string nowVersion = "0.0.4";
string versionInf = "将项目上传到GitHub";
string discipline[10] = {
	"Mathematics_数学", "Chinese_语文", "English_英语",
	"Physics_物理", "Chemistry_化学", "biology_生物"
};

//	主程序所需命名
bool mainFlag = true;	
char mainControler;

//	计时器所需命名
clock_t start, finish;
double consumeTime, consumeTime_buf;
char timerControler;	//	记录计时器状态
bool timerFlag = true;	

//	倒计时所需命名
int countDownHH, countDownMM, countDownSS;





int main(void)
{
	system("title 我要考清华!!!");
	getTime();
	cout << "Where there is a will, there is a way!\t有志者，事竟成！\n";
	cout << "Now version is " << nowVersion << "\n\n\n";

	while (mainFlag)
	{
		cout << "请输入数字：(1)记录时间 (2)查询记录_comming_soon (3)分析结果_comming_soon (5)计时器 (6)倒计时 (0)退出程序\n";
		mainControler = _getch();
		switch (mainControler) {
			case '1':
				//	时间记录

				break;

			case '2':
				//	查询时间_待补充

				break;

			case '3':
				//	分析时间_待补充

				break;

			case '4':
				//	暂无_title测试
				cout << "I am arrive 4\n";
				system("title 清华清华清华!");
				mainFlag = false;
				break;

			case '5':
				//	计时器
				timerFlag = true;
				consumeTime = consumeTime_buf = 0;
				getTime();
				cout << "摁下任意按键以开始计时\n";
				_getch();
				start = clock();
				while (timerFlag) {
					system("cls");
					cout << "**********************计时器************************\n现在时间为";
					cout << "摁下任意按键以暂停计时\n";
					_getch();
					finish = clock();
					consumeTime_buf = (double)(finish - start) / CLOCKS_PER_SEC;
					consumeTime += consumeTime_buf;
					printTime(consumeTime);
					cout << "停止请按0，其余按键继续\n";
					timerControler = _getch();
					if (timerControler == '0') {
						timerFlag = false;
						printTime(consumeTime);
					}
					start = clock();
				}
				break;

			case '6':
				//	倒计时
				cout << "请输入所需倒计时的时间 (hours minutes seconds)并以换行结束输入:";
				cin >> countDownHH >> countDownMM >> countDownSS;
				countDown(countDownHH, countDownMM, countDownSS);
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
	cout << "Good Bye! Tsinghua University is waiting for the man who is hardworking!\n";
	sendOff();
	return 0;
}