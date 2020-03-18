#ifndef	_PARCE_H_
#define	_PARCE_H_

using onNum = void (*)(int);
using onWord = void (*)(std:: string);
using limits = void (*)();

class parcing
{
	onNum callNum; 
	onWord callStr; 
	limits start;
	limits finish;
public:
	parcing ();
	void forNum (onNum);
	void forStr (onWord);
	void forStart (limits);
	void forFinish (limits);
	void register_token(std::string &);
	void parce (const char *);
};
#endif