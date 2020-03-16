#include <iostream>
#include <cstdio>
#include "programmer2.h"

void onNumberFound2 (const char * n)
{
	std::cout<<"number(pr2): "<<n<<'\n';
	return;
}

void onStringFound2 (const char * s)
{
	std::cout<<"string(pr2): "<<s<<'\n';
	return;
}

void ParceStart2 ()
{
	std::cout<<"start(pr2)\n";
}

void ParceFinish2 ()
{
	std::cout<<"finish(pr2)\n";
}