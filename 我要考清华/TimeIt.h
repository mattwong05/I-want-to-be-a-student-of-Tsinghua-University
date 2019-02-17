#pragma once


class TimeIt {
private:
	clock_t begin, finish;
	int consumeTime, consumeTime_buf;
	bool timerFlag;

public:
	void getTime(void);
	string getTime_t(int x = 0);
	void reset(void);
	void start(void);
	void pause(void);
	void stop(void);
	void show(void);
	void countDown(void);
	void Timer(void);
};