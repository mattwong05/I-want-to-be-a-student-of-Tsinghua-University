#include "functionTest.h"


void sendOff()
{
	//送别
	const int ONE_BEEP = 600;
	const int HALF_BEEP = 300;

	const int NOTE_1 = 440;
	const int NOTE_2 = 495;
	const int NOTE_3 = 550;
	const int NOTE_4 = 587;
	const int NOTE_5 = 660;
	const int NOTE_6 = 733;
	const int NOTE_7 = 825;

	//长亭外
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_5, HALF_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP * 2);

	//古道边
	Beep(NOTE_6, ONE_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP);
	Beep(NOTE_5, ONE_BEEP * 2);

	//芳草碧连天
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_1, HALF_BEEP);
	Beep(NOTE_2, HALF_BEEP);
	Beep(NOTE_3, ONE_BEEP);
	Beep(NOTE_2, HALF_BEEP);
	Beep(NOTE_1, HALF_BEEP);
	Beep(NOTE_2, ONE_BEEP * 4);

	//晚风扶柳笛声残
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_5, HALF_BEEP);
	Beep(NOTE_1 * 2, HALF_BEEP * 3);
	Beep(NOTE_7, HALF_BEEP);
	Beep(NOTE_6, ONE_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP);
	Beep(NOTE_5, ONE_BEEP * 2);

	//夕阳山外山
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_2, HALF_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_4, HALF_BEEP * 3);
	Beep((int)(NOTE_7 / 2 + 0.5), HALF_BEEP);
	Beep(NOTE_1, ONE_BEEP * 4);

	//天之涯
	Beep(NOTE_6, ONE_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP * 2);

	//地之角  
	Beep(NOTE_7, ONE_BEEP);
	Beep(NOTE_6, HALF_BEEP);
	Beep(NOTE_7, HALF_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP * 2);

	//知交半零落  
	Beep(NOTE_6, HALF_BEEP);
	Beep(NOTE_7, HALF_BEEP);
	Beep(NOTE_1 * 2, HALF_BEEP);
	Beep(NOTE_6, HALF_BEEP);
	Beep(NOTE_6, HALF_BEEP);
	Beep(NOTE_5, HALF_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_1, HALF_BEEP);
	Beep(NOTE_2, ONE_BEEP * 4);

	//一壶浊酒尽余欢  
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_5, HALF_BEEP);
	Beep(NOTE_1 * 2, HALF_BEEP * 3);
	Beep(NOTE_7, HALF_BEEP);
	Beep(NOTE_6, ONE_BEEP);
	Beep(NOTE_1 * 2, ONE_BEEP);
	Beep(NOTE_5, ONE_BEEP * 2);

	//今宵别梦寒  
	Beep(NOTE_5, ONE_BEEP);
	Beep(NOTE_2, HALF_BEEP);
	Beep(NOTE_3, HALF_BEEP);
	Beep(NOTE_4, HALF_BEEP * 3);
	Beep((int)(NOTE_7 / 2 + 0.5), HALF_BEEP);
	Beep(NOTE_1, ONE_BEEP * 3);

}