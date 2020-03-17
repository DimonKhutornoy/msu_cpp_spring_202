#include <iostream>
#include <cstdio>
#include <string>
#include "parce.h"

void register_token(std::string & wrd, onWord callNum, onWord callStr)
{
	char c=wrd[0];
	if (c>='0' && c<='9') callNum(wrd);
	else callStr(wrd);
}

void parse (onWord callNum, onWord callStr, limits start, limits finish, const char * text)
{
	int i=0;
	std::string wrd;
	start();
	while ((*text)!='\0')
	{
		if (isspace(*text))
		{
			if (i!=0)
			{
				wrd[i]='\0';
				register_token(wrd, callNum, callStr);
				i=0;
				wrd.clear();
			}
		}
		else
		{
			wrd.resize(i+1);
			wrd[i]=*text;
			i++;
		}
		text++;
	}
	if (i!=0)
	{
		wrd[i]='\0';
		register_token(wrd, callNum, callStr);
	}
	wrd.clear();
	finish();
}