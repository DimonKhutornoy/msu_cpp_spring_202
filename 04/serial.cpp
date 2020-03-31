#include"serial.h"

Error Deserializer::ld(bool& value)
{
    std::string text;
    in_ >> text;

    if (text == "true")
        value = true;
    else if (text == "false")
        value = false;
    else
        return Error::CorruptedArchive;

    return Error::NoError;
}

Error Deserializer::ld(uint64_t & value)
{
    std::string text;
    in_ >> text;
	bool Error_flag=false;
	value=0;
	for (int i=0; i<text.size(); i++)
	{
		if (!isdigit(text[i])) 
		{
			Error_flag=true;
			break;
		}
		value=10*value+(text[i]-'0');
	}
    if(Error_flag)
        return Error::CorruptedArchive;

    return Error::NoError;
}
Error Serializer::sav(bool value)
{
    if (value)
        out_<<"true"<<Separator;
    else 
        out_<<"false"<<Separator;

    return Error::NoError;
}

Error Serializer::sav(uint64_t value)
{
	std::string text="";
	bool fl=1, sgn;
	value<0 ? sgn=-1 : sgn=1;
	value*=sgn;
	while (value>0)
	{
		fl=0;
		text=(char)(value%10+'0')+text;
		value/=10;
	}
	if (fl)
	{
		out_<<"0"<<Separator;
	}
	if (sgn==-1) text='-'+text;
	else
	{
		out_<<text<<Separator;
	}
    return Error::NoError;
}