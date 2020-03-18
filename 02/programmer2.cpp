#include <iostream>
#include <cstdio>
#include <string>
#include "programmer2.h"

void onNumberFound2 (int n)
{
	std::cout<<"number(pr2): "<<n<<'\n';
	return;
}

void onStringFound2 (std:: string s)
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