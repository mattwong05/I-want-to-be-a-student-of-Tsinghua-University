#pragma once


class Event {
private:
	int total_time = 0;
	std::map<std::string, Event> child;
	std::vector<std::string> event;
public:
	void load(void);	//	主读取函数
	void _load(std::fstream &);	//	供主读取函数调用
	void save(int flag = 0);
	void pre_save(void);
	void add(void);
};

