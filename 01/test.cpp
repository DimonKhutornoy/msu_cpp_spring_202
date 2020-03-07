#include<iostream>
#include "allocator.h"

using namespace std;

int main()
{
	int fl=1;
	char*mas1, *mas2;
	makeAllocator(sizeof(char)*8);
	mas1=alloc(sizeof(char)*4);
	mas2=alloc(sizeof(char)*4);
	*mas1='1';
	*mas2='2';
	fl*=(mas1[0]=='1'&& mas2[0]=='2');
	reset();
	makeAllocator(sizeof(char)*2);
	mas1=alloc(sizeof(char)*3);
	fl*=(!mas1);
	if (fl==1)
		cout<<"Test is OK"<<endl;
	if (fl==0)
		cout<<"Error"<<endl;
	return 0;
}