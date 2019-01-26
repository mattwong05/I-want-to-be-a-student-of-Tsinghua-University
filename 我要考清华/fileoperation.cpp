#include "functionTest.h"
#include <io.h>

void addLog(string logData)
{
	if ((_access("log.csv", 0)) == -1) {
		logData = "Classify, Tag, Content, Time Spend, Fished Time, Others\n" + logData;
	}
	fstream log("log.csv", ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}