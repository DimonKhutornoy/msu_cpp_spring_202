#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

#ifndef	_MTXLIB_H_
#define	_MTXLIB_H_

class Matrix 
{
	size_t m, n;
	uint32_t **mtx;
public:
	size_t getRows () const;
	size_t getColumns () const;
	Matrix (size_t, size_t);
	Matrix (const Matrix &);
	void MtxRead (std::istream &);
	void MtxPrint (std::ostream &);
	Matrix & operator*=(const uint32_t);
	bool operator==(const Matrix &);
	bool operator!=(const Matrix &);
	class Vec
	{
		size_t vn;
		uint32_t *v;
	public:
		Vec (uint32_t *, size_t);
		uint32_t & operator[](const size_t);
		const uint32_t & operator[](const size_t) const;
	};
	Vec operator[](const size_t);
	const Vec operator[](const size_t) const;
	~Matrix();
};

#endif