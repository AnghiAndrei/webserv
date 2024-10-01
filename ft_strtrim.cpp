#include "webserv.hpp"

std::string ft_strtrim(std::string s1, std::string set)
{
	size_t pos=0;
	std::string trimmed_str=s1;
	while ((pos = s1.find(set, pos)) != std::string::npos){
		if(pos!=0)
			break;
		trimmed_str=s1.substr(strlen(set), strlen(s1));
	}
	return (trimmed_str);
}
