#include <iostream>
#include <cstdio>
#include <string>
#include "programmer2.h"

void onNumberFound2 (std:: string & n)
{
	int res=0;
	for (int i=0; i<n.length(); i++)
	{
		res=res*10+(n[i]-'0');
	}
	std::cout<<"number(pr2): "<<res<<'\n';
	return;
}

void onStringFound2 (std:: string & s)
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