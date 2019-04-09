#include "functionTest.h"
#include <io.h>
#include <direct.h>


void makeWorkPath(void) {
	string workPath = getWorkPath();
	if (_access(workPath.c_str(), 0) == -1) {
		_mkdir(workPath.c_str());
		cout << "已经创建了 : " << workPath << endl;
	}
	else {
		cout << "已存在 : " << workPath << endl;
	}
	cout << endl;
}


string getWorkPath(void) {
	char nowPath[256];
	_getcwd(nowPath, 256);
	string workPath = nowPath;
	workPath += "\\我要考清华";
	cout << workPath << endl;
	return workPath;
}

void addLog(string logData)
{
	string workPath = getWorkPath();
	string logPath = workPath + "\\log.csv";
	if (_access(logPath.c_str(), 0) == -1) {
		logData = "学科,知识点,内容,开始时间,完成时间,共用时间,备注\n" + logData;
	}
	fstream log(logPath.c_str(), ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}