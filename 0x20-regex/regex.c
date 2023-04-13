#include "regex.h"

/**
 * regex_helper - helper function for regex_match
 * @str: string to match
 * @pattern: pattern to match
 * Return: 1 if match, 0 otherwise
 */

bool regex_helper(const char *str, const char *pattern)
{
	if (*pattern == '\0')
	{
		return (*str == '\0');
	}

	bool first_match = *str && (*str == *pattern || *pattern == '.');

	if (pattern[1] == '*')
	{
		  return (
            regex_helper(str, pattern + 2) ||
            (first_match && regex_helper(str + 1, pattern))
        );
	} else
	{
		return (first_match && regex_helper(str + 1, pattern + 1));
	}
}
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: string to match
 * @pattern: pattern to match
 * Return: 1 if match, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{
	return (regex_helper(str, pattern) ? 1 : 0);
}
