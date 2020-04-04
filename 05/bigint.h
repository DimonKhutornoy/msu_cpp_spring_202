#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>

#ifndef _BIGINT_H_
#define _BIGINT_H_

class BigInt 
{
	char * num;
	bool sgn;
	uint32_t cnt;
	
public:

	BigInt(); 
	BigInt(int64_t); 
	BigInt(const BigInt&);
	BigInt& operator=(const BigInt&);
	BigInt(BigInt&&);
	BigInt& operator=(BigInt&&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
	bool operator==(BigInt) const;
	bool operator!=(BigInt) const;
	bool operator<=(BigInt) const;
	bool operator>=(BigInt) const;
	bool operator<(BigInt) const;
	bool operator>(BigInt) const;
	BigInt operator+(BigInt) const;
	BigInt operator-(BigInt) const;
	void del_zero();
	BigInt& operator-();
	~BigInt();
};


#endif