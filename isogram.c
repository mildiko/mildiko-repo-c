/*
 * isogram.c
 *
 *  Created on: Dec 12, 2017
 *      Author: eildmih
 */

#include <string.h>
#include <ctype.h>
#include <stdio.h>

int is_empty_string(const char *string)
{
	if (strlen(string) == 0) {
		return 1;
	}
	return 0;
}

int is_lower_case_only(const char *string)
{
	const char *p;

	for(p = string; *p != '\0'; p++)
	{
		if (isupper(*p))
			return 0;
	}
	return 1;
}


int duplicated_letter(const char *string)
{
	int i, size;
	size = strlen(string);
	char buff[size];

	for (i = strlen(string) - 1; i > 0; i--)
	{
		memset(buff, '\0', size);
		memcpy(buff, string, i);
		if ( isalpha(string[i]))
			{
				if (strchr(buff ,tolower(string[i])) || strchr(buff ,toupper(string[i])))
				{
					return 1;
				}
			}
	}
	return 0;
}


int is_isogram(const char *string)
{

	printf("String to test: %s\n", string);
	if (is_empty_string(string))
		{
			printf("Empty string\n");
			return 1;
		}
	else{
		printf("Not empty string...\n");
		if (is_lower_case_only(string))
			{
				printf("Is lower-case only...\n");
				if( duplicated_letter(string) == 0)
				{
					printf("Lower-case and not duplicate letter\n");
					return 1;
				}
				else
				{
					printf("Duplicate in lower-case string\n");
					return 0;
				}
			}
		else
		{
			printf("Not lowercase only....");
			if (duplicated_letter(string) == 0)
			{
				printf("Not duplicated letter\n");
				return 1;
			}
			else
			{
				printf("Duplicate letter\n");
				return 0;
			}
			printf("Non-Duplicated letter...\n");
		}
	}
	return 0;


}

