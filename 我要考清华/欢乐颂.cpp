#include "functionTest.h"
#include <stdio.h>
#include <conio.h>
#include <Windows.h>

/*定义1/8时间长度为225ms，中速*/
const unsigned PER = 200;

/*定义音阶：低音*/
enum { Do = 262, Re = 294, Mi = 330, Fa = 349, So = 392, La = 440, Xi = 494 };
/*定义播放一节音符的函数
f--表示音符，其值为上述定义的枚举型
a--	表示音高，其值为1(低音)、2(中音)、3(高音)
*/

void Play(int f, int a, int t)
{
	Beep((unsigned)(f*a), t*PER);
}

/*定义休止函数*/
void Stop(int t)
{
	Sleep(t*PER);
}

void songOfJoy(void)
{
	/*欢乐颂，第一段*/
	/*第一节:3 3 4 5*/
	Play(Mi, 2, 2); Play(Mi, 2, 2); Play(Fa, 2, 2); Play(So, 2, 2);

	/*第二节:5 4 3 2*/
	Play(So, 2, 2); Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 2);

	/*第三节:1 1 2 3*/
	Play(Do, 2, 2); Play(Do, 2, 2); Play(Re, 2, 2); Play(Mi, 2, 2);

	/*第四节:3 2 2 -*/
	Play(Mi, 2, 3); Play(Re, 2, 1); Play(Re, 2, 4);

	/*欢乐颂第二段*/
	/*第一节:3 3 4 5*/
	Play(Mi, 2, 2); Play(Mi, 2, 2); Play(Fa, 2, 2); Play(So, 2, 2);

	/*第二节:5 4 3 2*/
	Play(So, 2, 2); Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 2);

	/*第三节:1 1 2 3*/
	Play(Do, 2, 2); Play(Do, 2, 2); Play(Re, 2, 2); Play(Mi, 2, 2);

	/*第四节:2 1 1 -*/
	Play(Re, 2, 3); Play(Do, 2, 1); Play(Do, 2, 4);
}

void peppaPig(void) {
	Play(So, 2, 2); Play(Mi, 2, 1); Play(Do, 2, 1); Play(Re, 2, 2); Play(So, 1, 2);
	Play(So, 1, 1); Play(Xi, 1, 1); Play(Re, 2, 1); Play(Fa, 2, 1); Play(Mi, 2, 2); Play(Do, 2, 2);
}

void familyWithChildren(void) {
	Play(Mi, 2, 2); Play(So, 2, 2); Play(Mi, 2, 2); Play(Do, 2, 2); Play(Re, 2, 4);
	Play(Do, 2, 2); Play(Mi, 2, 2); Play(Do, 2, 2); Play(La, 1, 2); Play(Xi, 1, 4);
	Play(La, 1, 2); Play(Fa, 1, 2); Play(La, 1, 2); Play(Xi, 1, 2);
	Play(Do, 2, 2); Play(So, 1, 2); Play(Do, 2, 2); Play(Mi, 2, 2);
	Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 2); Play(Do, 2, 2);
	Play(Mi, 2, 4); Play(Re, 2, 4);

	Play(Mi, 2, 2); Play(So, 2, 2); Play(Mi, 2, 2); Play(Do, 2, 2); Play(Re, 2, 4);
	Play(Do, 2, 2); Play(Mi, 2, 2); Play(Do, 2, 2); Play(La, 1, 2); Play(Xi, 1, 4);
	Play(La, 1, 2); Play(Fa, 1, 2); Play(La, 1, 2); Play(Xi, 1, 2);
	Play(Do, 2, 2); Play(So, 1, 2); Play(Do, 2, 2); Play(Mi, 2, 2);
	Play(Fa, 2, 2); Play(Mi, 2, 2); Play(Re, 2, 1); Play(Mi, 2, 1); Play(Re, 2, 1); Play(Do, 2, 1); Play(Do, 2, 4);
}