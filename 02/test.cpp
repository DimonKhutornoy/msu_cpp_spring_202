#include <iostream>
#include "programmer1.h"
#include "programmer2.h"
#include "parce.h"

int main()
{
	parse(onNumberFound1, onStringFound1, ParceStart1, ParceFinish1, "Text for programmer number 1");
	parse(onNumberFound2, onStringFound2, ParceStart2, ParceFinish2, "Text for programmer number 2");
	return 0;
}