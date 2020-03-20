#include "mtxlib.h"

size_t Matrix::getRows () const {return m;}
size_t Matrix::getColumns () const {return n;}
Matrix::Matrix (size_t size1, size_t size2)
{
	m=size1;
	n=size2;
	mtx=(uint32_t**)malloc(sizeof(uint32_t*)*m);
	for (size_t i=0; i<m; i++)
	{
		mtx[i]=(uint32_t*)malloc(sizeof(uint32_t)*n);
	}
}

Matrix::Matrix (const Matrix & cp)
{
	m=cp.m;
	n=cp.n;
	mtx=(uint32_t**)malloc(sizeof(uint32_t*)*m);
	for (size_t i=0; i<m; i++)
	{
		mtx[i]=(uint32_t*)malloc(sizeof(uint32_t)*n);
	}
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			mtx[i][j]=cp.mtx[i][j];
		}
	}
}

void Matrix::MtxRead ()
{
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			std::cin>>mtx[i][j];
		}
	}
}
void Matrix::MtxPrint ()
{
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			std::cout<<mtx[i][j]<<' ';
		}
	std::cout<<'\n';
	}
}

Matrix & Matrix::operator*=(const uint32_t p)
{
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			mtx[i][j]*=p;
		}
	}
}

bool Matrix::operator==(const Matrix & op2)
{
	bool res=true;
	if (m!=op2.m || n!=op2.n)
	{
		return false;
	}
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			res&=(mtx[i][j]==op2.mtx[i][j]);
		}
	}
	return res;
}

bool Matrix::operator!=(const Matrix & op2)
{
	bool res=true;
	if (m!=op2.m || n!=op2.n)
	{
		return false;
	}
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			res&=(mtx[i][j]==op2.mtx[i][j]);
		}
	}
	return !res;
}

Matrix::vec::vec (uint32_t * mas, size_t sz)
{
	vn=sz;
	v=mas;
} 

uint32_t & Matrix::vec::operator[](const size_t i)
{
	if (i>=vn) throw std::out_of_range("Size Error!");
	return (this->v)[i];
}

Matrix::vec Matrix::operator[](size_t i)
{
	if (i>=m) throw std::out_of_range("Size Error!");
	vec r(mtx[i], n);
	return r;
}	

Matrix::~Matrix()
{
	for (size_t i=0; i<m; i++)
	{
		free(mtx[i]);
	}
	free(mtx);
}