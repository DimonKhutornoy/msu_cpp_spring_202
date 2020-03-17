#include <iostream>
#include <cstdio>
#include <string>
#include "programmer1.h"

void onNumberFound1 (std:: string & n)
{
	int res=0;
	for (int i=0; i<n.length(); i++)
	{
		res=res*10+(n[i]-'0');
	}
	std::cout<<"number(pr1): "<<res<<'\n';
	return;
}

void onStringFound1 (std:: string & s)
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