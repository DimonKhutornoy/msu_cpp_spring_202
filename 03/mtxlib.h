#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_
#include "mtxlib.h"

class Matrix 
{
	size_t m, n;
	uint32_t **mtx;
public:
	size_t getRows () const;
	size_t getColumns () const;
	Matrix (size_t, size_t);
	Matrix (const Matrix &);
	void MtxRead ();
	void MtxPrint ();
	Matrix & operator*=(const uint32_t);
	bool operator==(const Matrix &);
	bool operator!=(const Matrix &);
	class vec
	{
		size_t vn;
		uint32_t *v;
	public:
		vec (uint32_t *, size_t);
		uint32_t & operator[](const size_t);
	};
	vec operator[](size_t);
	~Matrix();
};

#endif