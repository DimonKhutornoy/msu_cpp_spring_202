#include <iostream>
#include <cstdio>
#include "parce.h"

using onWord = void (*)(const char*);
using limits = void (*)();

void register_token(const char * wrd, onWord callNum, onWord callStr)
{
	char c=*wrd;
	if (c>='0' && c<='9') callNum(wrd);
	else callStr(wrd);
}

void parse (onWord callNum, onWord callStr, limits start, limits finish, const char * text)
{
	int i=0;
	int sz=20;
	char*wrd=(char*)malloc(sizeof(char)*sz);
	if (!wrd)
		std::cout<<"error"<<'\n';
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
				sz=20;
				free(wrd);
				wrd=(char*)malloc(sizeof(char)*sz);
				if (!wrd)
					std::cout<<"error"<<'\n';
			}
		}
		else
		{
			if (i>=sz-1)
			{
				sz*=2;
				wrd=(char*)realloc(wrd, sizeof(char)*sz);
			}
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
	free(wrd);
	finish();
}