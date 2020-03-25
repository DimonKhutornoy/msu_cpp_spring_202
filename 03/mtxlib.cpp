#include "mtxlib.h"

size_t Matrix::getRows () const {return m;}
size_t Matrix::getColumns () const {return n;}

Matrix::Matrix (size_t size1, size_t size2) : m(size1), n(size2) 
{
	mtx=(uint32_t**)malloc(sizeof(uint32_t*)*m);
	if (!mtx) throw std::out_of_range("Init Error!");
	for (size_t i=0; i<m; i++)
	{
		mtx[i]=(uint32_t*)malloc(sizeof(uint32_t)*n);
		if (!mtx[i]) 
		{
			throw std::out_of_range("Init Error!");
			for (size_t j=0; j<i; j++)
			{
				free(mtx[j]);
			}
			free(mtx);
		}
	}
}

Matrix::Matrix (const Matrix & cp)
{
	m=cp.m;
	n=cp.n;
	mtx=(uint32_t**)malloc(sizeof(uint32_t*)*m);
	if (!mtx) throw std::out_of_range("Copy Error!");
	for (size_t i=0; i<m; i++)
	{
		mtx[i]=(uint32_t*)malloc(sizeof(uint32_t)*n);
		if (!mtx[i]) 
		{
			throw std::out_of_range("Copy Error!");
			for (size_t j=0; j<i; j++)
			{
				free(mtx[j]);
			}
			free(mtx);
		}
	}
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			mtx[i][j]=cp.mtx[i][j];
		}
	}
}

void Matrix::MtxRead (std::istream &in)
{
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			in>>mtx[i][j];
		}
	}
}
void Matrix::MtxPrint (std::ostream & out)
{
	for (size_t i=0; i<m; i++)
	{
		for (size_t j=0; j<n; j++)
		{
			out<<mtx[i][j]<<' ';
		}
	out<<'\n';
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
			if (!res)
			{
				break;
			}
		}
	}
	return res;
}

bool Matrix::operator!=(const Matrix & op2)
{
	
	return !(*this==op2);
}

Matrix::Vec::Vec (uint32_t * mas, size_t sz)
{
	vn=sz;
	v=mas;
} 

uint32_t & Matrix::Vec::operator[](const size_t i)
{
	if (i>=vn) throw std::out_of_range("Size Error!");
	return v[i];
}

const uint32_t & Matrix::Vec::operator[](const size_t i) const
{
	if (i>=vn) throw std::out_of_range("Size Error!");
	return v[i];
}

Matrix::Vec Matrix::operator[](const size_t i)
{
	if (i>=m) throw std::out_of_range("Size Error!");
	return Vec(mtx[i], this->n);
}	

const Matrix::Vec Matrix::operator[](const size_t i) const
{
	if (i>=m) throw std::out_of_range("Size Error!");
	return Vec(mtx[i], this->n);
}	


Matrix::~Matrix()
{
	for (size_t i=0; i<m; i++)
	{
		free(mtx[i]);
	}
	free(mtx);
}