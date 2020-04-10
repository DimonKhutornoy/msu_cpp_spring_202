#include "format.h"

std::string format_req(const std::string& fmt, const std::vector<std::string>& strs)
{
    std::string res, buf;
    size_t num;
    char c;
    bool fl = false, is_last;
    for (size_t i = 0; i <= fmt.size(); ++i)
    {
        is_last = i == fmt.size();
        c = fmt[i];
        if (fl)
        {
            if (isdigit(c))
            {
                buf += c;
            }
            else
            {
                if (c == '}')
                {
                    fl = false;
                }
                else
                {
                    throw std::runtime_error("Error!");
                }
                num = 0;
                if (!buf.empty())
                    num = atoi(buf.c_str());
                if (num >= 0 && num < strs.size())
                    res += strs[num];
                else
                    throw std::runtime_error("Error!");
                buf.clear();
            }
        }
        else
        {
            if (c == '{')
            {
                fl = true;
            }
            else if (c == '}')
            {
                throw std::runtime_error("Error!");
            }
            else
            {
                if (!is_last)
                    res += c;
            }
        }
    }
    return res;
}

std::string format(const std::string& s)
{
    return s;
}
