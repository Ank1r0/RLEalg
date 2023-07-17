#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void arhivatordemo(char* str, char* result)
{
	int count = 1,
		i = 0,
		size = 0;
	while (*str)
	{
		if (*str == *(str + 1))
		{
			count++;
		}
		else
		{
			if (count == 1)
			{
				i = sprintf(result, "%c", *str);
			}
			else
			{
				i = sprintf(result, "%d%c", count, *str);
				count = 1;
			}
			result += i;
			size += i;
		}
		str++;
	}

	//printf("%d\n", size);
}

void desarhivatordemo(char* str)
{
	int	number = 1;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			number = strtoll(str, &str, 10);
		}
		for (int k = 0; k < number; ++k)
		{
			printf("%c", *str);
		}
		number = 1;
		str++;
	}
	printf("\n");
}

int main(int argc, char argv[])
{
	char str[] = "AAAADDDDCFFFFFAAAAAAAAAARRTTTTTTTGDFFFF";
	char* result = (char*)calloc(strlen(str) + 1, sizeof(char));

	printf("\n\n\n");
	arhivatordemo(str, result);
	printf("%s\n", result);
	printf("\n\n\n");

	desarhivatordemo(result);

	system("pause");
	return 0;
}