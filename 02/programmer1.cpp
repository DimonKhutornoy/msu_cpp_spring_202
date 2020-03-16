#include <iostream>
#include <cstdio>
#include "programmer1.h"

void onNumberFound1 (const char * n)
{
	std::cout<<"number(pr1): "<<n<<'\n';
	return;
}

void onStringFound1 (const char * s)
{
	std::cout<<"string(pr1): "<<s<<'\n';
	return;
}

void ParceStart1 ()
{
	std::cout<<"start(pr1)\n";
}

void ParceFinish1 ()
{
	std::cout<<"finish(pr1)\n";
}