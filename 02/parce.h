#ifndef	_PARCE_H_
#define	_PARCE_H_

using onWord = void (*)(const char*);
using limits = void (*)();

void register_token(const char *, onWord, onWord);
void parse (onWord, onWord, limits, limits, const char *);

#endif