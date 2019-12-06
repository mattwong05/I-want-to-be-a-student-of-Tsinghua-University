#include "functionTest.h"
#include "Event_V2.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::fstream;


void Event::_load(fstream & EventTree) {
	int event_sum, child_sum;
	string event_name, child_name;
	EventTree >> event_sum;
	//cout << "get event_sum\n";
	for (int i = 0; i < event_sum; i++) {
		EventTree >> event_name;
		event.push_back(event_name);
	}
	EventTree >> child_sum;
	//cout << "get child_sum\n";
	for (int i = 0; i < child_sum; i++) {
		EventTree >> child_name;
		child[child_name]._load(EventTree);
	}
}


void Event::load(void) {
	string workPath = getWorkPath(1);
	string dataPath = workPath + "\\EventTree.dat";
	fstream EventTree(dataPath.c_str(), std::ios::in);
	_load(EventTree);
	cout << "从" << dataPath << "中读取成功。" << endl;
}


void Event::pre_save(void) {
	string workPath = getWorkPath(1);
	string dataPath = workPath + "\\EventTree.dat";
	fstream EventTree(dataPath.c_str(), std::ios::out);
	EventTree.clear();
	EventTree.close();
}


void Event::save(int flag) {	//	flag == 0 第一次调用
	if (flag == 0)	pre_save();
	string workPath = getWorkPath(1);	//	为零会输出保存地址
	string dataPath = workPath + "\\EventTree.dat";
	fstream EventTree(dataPath.c_str(), std::ios::app);
	EventTree << event.size() << endl;
	for (vector<string>::iterator it = event.begin(); it != event.end(); it++) {
		EventTree << (*it) << endl;
	}
	EventTree << child.size() << endl;
	for (map<string, Event>::iterator it = child.begin(); it != child.end(); it++) {
		EventTree << it->first << endl;
		it->second.save(flag+1);
	}
	EventTree.close();
}


void Event::add(void) {
	string x;
	cout << "输入子分类名称:(如果无需分类输入0):";
	cin >> x;
	if (x == "0") {
		cout << "输入事件:";
		cin >> x;
		event.push_back(x);
	}
	else {
		child[x].add();
	}
}


//int main(void) {
//	//  add
//	super_root.load();
//	super_root.add();
//	super_root.save();
//}