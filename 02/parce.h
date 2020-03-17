#ifndef	_PARCE_H_
#define	_PARCE_H_

using onWord = void (*)(std:: string &);
using limits = void (*)();

void register_token(std::string &, onWord, onWord);
void parse (onWord, onWord, limits, limits, const char *);

#endif