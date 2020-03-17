#include <iostream>
#include <cstdio>
#include <string>
#include "programmer1.h"
#include "programmer2.h"
#include "parce.h"

int main()
{
	parcing pr;
	pr.forNum(onNumberFound1);
	pr.forStart(ParceStart1);
	pr.parce("Text for programmer number 1");
	std::cout<<'\n';
	pr.forStr(onStringFound2);
	pr.forFinish(ParceFinish2);
	pr.parce("Text for\n1 and 2-th\tprogrammers");
	std::cout<<'\n';
	pr.forStart(ParceStart2);
	pr.forNum(onNumberFound2);
	pr.parce("Text for programmer number 2");
	std::cout<<'\n';
	return 0;
}