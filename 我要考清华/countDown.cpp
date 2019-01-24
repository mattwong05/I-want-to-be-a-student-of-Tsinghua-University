#include "functionTest.h"
void countDown(int hh, int mm, int ss)
{
	ss += hh * 3600 + mm * 60;
	ss *= 1000;
	Sleep(ss);
	cout << "Ê±¼äµ½£¡£¡£¡" << endl;
	if (hh > 0 || mm >= 1) {
		songOfJoy();
	}
}