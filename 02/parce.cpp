#include <iostream>
#include <cstdio>
#include <string>
#include "parce.h"

onNum callNum=nullptr; 
onWord callStr=nullptr; 
limits start=nullptr;
limits finish=nullptr;

parcing::parcing(){};

void parcing::forNum (onNum f)
{
	callNum=f;
}

void parcing::forStr (onWord f)
{
	callStr=f;
}

void parcing::forStart (limits f)
{
	start=f;
}

void parcing::forFinish (limits f)
{
	finish=f;
}

void parcing::register_token(std::string & wrd)
{
	int flag=1;
	for (int i=0; i<wrd.length(); i++)
		flag*=(isdigit(wrd[i]));
	
	if (callNum && flag) 
	{
		int number = atoi(wrd.c_str());
		callNum(number);
	}
	else if (callStr) callStr(wrd);
}

void parcing::parce (const char * text)
{
	std::string wrd;
	if (start) start();
	while ((*text)!='\0')
	{
		if (isspace(*text))
		{
			if (wrd.length())
			{
				register_token(wrd);
				wrd.clear();
			}
		}
		else
		{
			wrd+=(*text);
		}
		text++;
	}
	if (wrd.length())
	{
		register_token(wrd);
	}
	wrd.clear();
	if (finish) finish();
}