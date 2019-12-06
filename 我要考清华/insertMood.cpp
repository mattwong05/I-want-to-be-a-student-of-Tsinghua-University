#include "functionTest.h"
#include "TimeIt.h"
#include <io.h>
using namespace std;


void insertMood(void) {
	TimeIt timeIt;
	string logData;
	int starsOfMood;
	int ageOfSelfControl;
	cout << "请输入您今日的心情评分(1-5) : ";
	cin >> starsOfMood;
	cout << "请输入您今日的自控力年龄(10-20):";
	cin >> ageOfSelfControl;
	cout << "请输入您的备注 : ";
	cin >> logData;
	string workPath = getWorkPath();
	string logPath = workPath + "\\心情+自控力日志.csv";
	if (_access(logPath.c_str(), 0) == -1){
		fstream log(logPath.c_str(), ios::app);
		cout << "新增文件 : " << logPath << endl;
		log << "时间,心情评分,自控力年龄,备注\n";
		log.close();
	}
	fstream log(logPath.c_str(), ios::app);
	logData = timeIt.getTime_t() + ',' + to_string(starsOfMood) + ',' + to_string(ageOfSelfControl) + ',' + logData + "\n";
	changeColor(浅红色);
	cout << logData;
	changeColor();
	log.good() ? log << logData, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
	log.close();
}