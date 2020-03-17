#include <iostream>
#include <cstdio>
#include <string>
#include "parce.h"


parcing::parcing (onWord n, onWord s, limits st, limits fi)
{
	callNum=n;
	callStr=s; 
	start=st;
	finish=fi;
}

void parcing::register_token(std::string & wrd)
{
	char c=wrd[0];
	if (c>='0' && c<='9') callNum(wrd);
	else callStr(wrd);
}

void parcing::parce (const char * text)
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
				register_token(wrd);
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
		register_token(wrd);
	}
	wrd.clear();
	finish();
}