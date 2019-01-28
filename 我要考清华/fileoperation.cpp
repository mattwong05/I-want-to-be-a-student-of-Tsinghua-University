#include "functionTest.h"
#include <io.h>

void addLog(string logData)
{
	if ((_access("log.csv", 0)) == -1) {
		logData = "学科, 知识点, 内容, 共用时间, 完成时间, 备注\n" + logData;
	}
	fstream log("log.csv", ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}