#include "is_palindrome.h"

bool IsPalindrome1(const std::string& str)
{
	for (size_t i = 0; i < str.length() / 2; ++i)
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

bool IsPalindrome2(const std::string& str)
{
	std::string reversed_str;
	for (int i = str.length() - 1; i > -1; --i)
	{
		reversed_str.push_back(str[i]);
	}
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] != reversed_str[i])
		{
			return false;
		}
	}
	return true;
}
