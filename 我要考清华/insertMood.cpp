#include "functionTest.h"
#include <io.h>


void insertMood(void) {
	string logData;
	cout << "请输入您的心情 : ";
	getline(cin, logData);
	getchar();
	string workPath = getWorkPath();
	string logPath = workPath + "\\Log.txt";
	if (_access(logPath.c_str(), 0) == -1){
		logData = ".LOG\n" + logData;
	}
	fstream log(logPath.c_str(), ios::app);
	log.good() ? log << endl << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}