#include "functionTest.h"


void addLog(string logData)
{
	fstream log("log.csv", ios::app);
	log.good() ? log << logData << endl, cout << "From addLog : Save Log Successful!" << endl : cerr << "failed Open the file!\n";
}