#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

#ifndef	_SERIAL_H_
#define	_SERIAL_H_

enum class Error
{
	NoError,
	CorruptedArchive
};

class Serializer
{
	std::ostream & out_;
	static constexpr char Separator = ' ';
public:
	explicit Serializer(std::ostream& out)
		: out_(out)
	{
	}

	template <class T>
	Error save(T& object)
	{
		return object.serialize(*this);
	}

	template <class... ArgsT>
	Error operator()(ArgsT &... args)
	{
		return process(args...);
	}

	Error sav(bool);
	Error sav(uint64_t);
private:

	template <class T>
	Error process(T&& val)
	{
		return sav(val);
	}

	template <class T, class... Args>
	Error process(T&& val, Args&&... args)
	{
		if (sav(val)==Error::CorruptedArchive)
		{
			val=0;
			return Error::CorruptedArchive;
		}
		process(std::forward<Args>(args)...);
	}
};

class Deserializer
{
	std::istream & in_;
	static constexpr char Separator = ' ';
public:
	explicit Deserializer(std::istream & in)
		: in_(in)
	{
	}

	template <class T>
	Error load(T& object)
	{
		return object.serialize(*this);
	}

	template <class... ArgsT>
	Error operator()(ArgsT &... args)
	{
		return process(args...);
	}

	Error ld(bool &);
	Error ld(uint64_t &);
    
private:
	template <class T>
	Error process(T&& val)
	{
		Error Err=ld(val);
		return Err;
	}

	template <class T, class... Args>
	Error process(T&& val, Args&&... args)
	{
		if (ld(val)==Error::CorruptedArchive)
		{
			return Error::CorruptedArchive;
		}
		process(std::forward<Args>(args)...);
	}
};

#endif