#include <iostream>
#include <cstdio>
#include <string>
#include "programmer1.h"
#include "programmer2.h"
#include "parce.h"

int main()
{
	parcing pr1(onNumberFound1, onStringFound1, ParceStart1, ParceFinish1);
	pr1.parce("Text for programmer number 1");
	parcing pr2(onNumberFound2, onStringFound2, ParceStart2, ParceFinish2);
	pr2.parce("Text for programmer number 2");
	return 0;
}