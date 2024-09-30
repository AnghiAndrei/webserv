#include "webserv.hpp"

bool ft_strchr(std::string str, int c)
{
	size_t i=0;
	char	b=(char)c;
	for (;str[i]!='\0' && str[i]!=b; i++){;}
	if (str[i]==b)
		return true;
	else
		return false;
}

std::string ft_strtrim(std::string s1, std::string set)
{
	size_t	start=0;
	size_t	ls1=s1.length();
	size_t	end=ls1-1;
	std::string trimmed_str="";

	while (start < ls1 && ft_strchr(set, s1[start]) == true)
		start++;
	size_t i=start;
	for (;i<end-start + 2;i++)
		trimmed_str+=s1[i];
	for (size_t i2=0;set[i2]==s1[i]; i2++){
		i++;
	}
	
	for (;i<s1.length();i++)
		trimmed_str+=s1[i];
	return (trimmed_str);
}
