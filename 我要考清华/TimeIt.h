#pragma once


class TimeIt {
private:
	clock_t begin, finish;
	int consumeTime;
	double consumeTime_buf;
	bool timerFlag;

public:
	void getTime(void);
	string getTime_t(void);
	void reset(void);
	void start(void);
	void pause(void);
	void stop(void);
	string show(void);
	void countDown(void);
	string Timer(void);
	string toStd(int year, int month, int day, int hour, int minute, int second);
	string stdSubtract(string a, string b);
	string TimeSub(int h1, int m1, int s1, int h2, int m2, int s2);
};