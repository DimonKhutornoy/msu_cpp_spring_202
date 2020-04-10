#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <sstream>

#ifndef _FORMAT_H_
#define _FORMAT_H_

std::string format_req(const std::string&, const std::vector<std::string>&);
std::string format(const std::string&);

template <typename T>
std::string to_string(const T& t)
{
    std::stringstream str;
    str << t;
    return str.str();
}

template <typename Arg, typename... Args>
std::string format_req(const std::string& s, std::vector<std::string>& strings, Arg&& arg, Args&&... args)
{
    strings.push_back(to_string(std::forward<Arg>(arg))); // adding all arguments in our vector
    return format_req(s, strings, std::forward<Args>(args)...);
}

template <typename Arg, typename... Args>
std::string format(const std::string& s, Arg&& arg, Args&&... args)
{
    std::vector<std::string> strings; // vector of arguments for exchange
    return format_req(s, strings, std::forward<Arg>(arg), std::forward<Args>(args)...);
}

#endif