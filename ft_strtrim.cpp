#include "webserv.hpp"

std::string ft_strtrim(std::string s1, std::string set)
{
	size_t pos = s1.find(set, 0);
	std::string trimmed_str=s1;
	if(set=="/")
		return (s1);
	if(pos==0)
		trimmed_str=s1.substr(strlen(set.c_str()), strlen(s1.c_str()));
	return (trimmed_str);
}
