#include <iostream>
#include <cstdio>
#include <string>
#include "programmer1.h"

void onNumberFound1 (int n)
{
	std::cout<<"number(pr1): "<<n<<'\n';
	return;
}

void onStringFound1 (std:: string s)
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