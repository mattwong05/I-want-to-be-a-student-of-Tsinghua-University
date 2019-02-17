//#include "functionTest.h"
//
////	记录时间所需命名
//string logData;
//string classifyName, tagName, contentName, spendTimes, finishedTime, others;
//char saveCheck;
//char notSaveCheck;
//char contentCheck;
//char othersCheck;
//bool contentCheckFlag;
//bool needChangeFlag;
//bool saveFlag;
//
////	计时器所需命名
//clock_t start, finish;
//double consumeTime, consumeTime_buf;
//char timerControler;	//	记录计时器状态
//bool timerFlag = true;
//
//void eventAdd() {
//	//	时间记录
//	system("title 记录时间");
//	logData = "";
//	needChangeFlag = true;
//	while (needChangeFlag)
//	{
//		cout << "欢迎记录你的时间！\n";
//		cout << "请输入你要学习的大分类:";
//		cin >> classifyName;
//		cout << "请输入你要学习的子分类:";
//		cin >> tagName;
//		cout << "请输入你要学习的内容:";
//		cin >> contentName;
//
//		//	确认请求
//		changeColor(6);
//		cout << "请您确认您的请求，检查无误后我们就要开始啦!!!\n";
//		cout << "大分类:" << classifyName << "\t子分类:" << tagName << "\t学习内容:" << contentName << endl;
//		changeColor();
//		contentCheckFlag = true;
//		while (contentCheckFlag)
//		{
//			cout << "(1)确认无误\t(2)需要更改\n";
//			contentCheck = _getch();
//			switch (contentCheck) {
//			case '1':
//				contentCheckFlag = false;
//				needChangeFlag = false;
//				logData = classifyName + ',' + tagName + ',' + contentName + ',';
//				break;
//			case '2':
//				contentCheckFlag = false;
//				break;
//			default:
//				changeColor(6, 12);
//				cout << "错误输入，请重试\n";
//				changeColor(6);
//				break;
//			}
//		}
//	}
//	changeColor();
//
//	//	整段引用计时器代码
//	timerFlag = true;
//	consumeTime = consumeTime_buf = 0;
//	getTime();
//	cout << "摁下任意按键以开始计时\n";
//	_getch();
//	start = clock();
//	while (timerFlag) {
//		system("cls");
//		cout << "**********************计时器************************\n";
//		cout << "摁下任意按键以暂停计时\n";
//		_getch();
//		finish = clock();
//		consumeTime_buf = (double)(finish - start) / CLOCKS_PER_SEC;
//		consumeTime += consumeTime_buf;
//		printTime(consumeTime);
//		cout << "停止请按0，其余按键继续\n";
//		timerControler = _getch();
//		if (timerControler == '0') {
//			timerFlag = false;
//			printTime(consumeTime);
//		}
//		start = clock();
//	}
//	_getch();
//	system("cls");
//	//	引用完毕
//
//	logData += printTime_t(consumeTime) + ',' + getTime_t(1);
//
//	saveFlag = true;
//	while (saveFlag) {
//		changeColor(12, 14);
//		cout << logData << endl;
//		changeColor();
//		cout << "保存吗?\t(1)是的，请保存\t(0)不要保存\n";
//		saveCheck = _getch();
//		switch (saveCheck) {
//		case '1':
//			saveFlag = false;
//			cout << "需要保存备注吗?\t(1)是的，我想留下几句话\t(0)不需要了，谢谢\n";
//			othersCheck = _getch();
//			if (othersCheck == '1') {
//				cout << "请留下备注，以enter键结束:";
//				cin >> others;
//				logData += ',' + others;
//			}
//			addLog(logData);
//
//			//cout << "保存成功！" << endl;
//
//			break;
//		case '0':
//			cout << "确认不保存吗？\t(1)后悔了\t(0)狠心不保存\n";
//			notSaveCheck = _getch();
//			if (notSaveCheck == '0')	saveFlag = false;
//		}
//	}
//}
