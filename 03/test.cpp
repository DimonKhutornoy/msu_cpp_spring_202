#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include "mtxlib.h"
	
int main()
{
	bool test_flag=true;
	const size_t rows = 5;
	const size_t cols = 3;
	Matrix m(rows, cols);
	m.MtxRead();

	test_flag&=(m.getRows()==5);
	test_flag&=(m.getColumns()==3);

	m[1][2] = 5;
	test_flag&=(m[1][2]==5);
	
	uint32_t x = m[4][1];
	test_flag&=(m[4][1]==x);
	
	Matrix m1=m;
	test_flag&=(m1 == m);
	
	m *= 3; //умножение на число
	test_flag&=(m1 != m);
	
	for (size_t i=0; i<m.getRows(); i++)
		for (size_t j=0; j<m.getColumns(); j++)
			test_flag&=((m1[i][j] * 3)==m[i][j]);
		
	if (test_flag)
		std::cout<<"Test is OK!\n";
	else std::cout<<"ERROR\n";
		
	return 0;
}