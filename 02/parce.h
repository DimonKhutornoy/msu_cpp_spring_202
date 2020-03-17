#ifndef	_PARCE_H_
#define	_PARCE_H_

using onWord = void (*)(std:: string &);
using limits = void (*)();

class parcing
{
	onWord callNum; 
	onWord callStr; 
	limits start;
	limits finish;
public:
	parcing (onWord, onWord, limits, limits);
	void register_token(std::string &);
	void parce (const char *);
};
#endif