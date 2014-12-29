#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

# define INT 0
# define CHAR 1

char		*ctoh(int c)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * 3);
	res[0] = ((c / 16) < 10) ? ((c / 16) + 48) : ((c / 16) + 87);
	res[1] = ((c % 16) < 10) ? ((c % 16) + 48) : ((c % 16) + 87);
	res[2] = 0;
	return (res);
}

int			htoc(char *hex)
{
	int	res,i,j;

	i = (hex[0] > '9') ? 87 : 48;
	j = (hex[1] > '9') ? 87 : 48;
	res = (hex[0] - i) * 16;
	res += (hex[1] - j);
	return (res);
}

int			encrypt(char *s)
{
	int		i;

	for (i=0; s[i]; i++)
		printf("%s", ctoh(abs(s[i])));
	return (printf("\n"));
}

char		*strtolower(char *s)
{
	int		i;
	char	*res;

	res = (char *)malloc(sizeof(char) * strlen(s));
	for (i=0; s[i]; i++)
		res[i] = tolower(s[i]);
	res[i] = 0;
	return (res);
}

int			decrypt(char *s, int type)
{
	int		i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * 3);
	for (i=0; s[i]; i++)
		if (!isspace(s[i]))
		{
			tmp[0] = tolower(s[i]);
			tmp[1] = tolower(s[i+1]);
			tmp[2] = 0;
			if (type == CHAR)
				printf("%c", htoc(tmp));
			else
				(i < strlen(s)-2) ? printf("%d ", htoc(tmp)) : printf("%d", htoc(tmp));
			i++;
		}
	free(tmp);
	return (printf("\n"));
}

int			isvalid(char *s)
{
	int		i, j, c;

	for (i=0, j=0; s[i]; i++)
	{
		c = tolower(s[i]);
		if (!((c >= 'a' && c <= 'f') || (c >= '0' && c <= '9')))
		{
			if (c == ' ')
				j++;
			else
				return (printf("\033[91mError\033[0m: Bad string format\n"));
		}
	}
	if ((strlen(s)%2 + j)%2)
		return (printf("\033[91mError\033[0m: Bad string length\n"));
	return (0);
}

int			usage()
{
	printf("\033[91musage\033[0m: \033[92mhexReadWrite\033[0m <option> <str>\n");
	printf("\n\033[1mOptions\033[0m:\n");
	printf("  <-w  | --write>\tConvert a string to hexa pairs\n");
	printf("  <-r  | --read>\tConvert hexa pairs to a string\n");
	printf("  <-i  | --readi>\tConvert hexa pairs to a string of integers\n");
	return (-1);
}

int			main(int ac, char **av)
{
	if (ac != 3)
		return (usage());
	if (!strcmp(av[1], "-w") || !strcmp(av[1], "--write"))
		encrypt(av[2]);
	else if (!strcmp(av[1], "-r") || !strcmp(av[1], "--read"))
	{
		if (!isvalid(av[2]))
			decrypt(av[2], CHAR);
	}
	else if (!strcmp(av[1], "-i") || !strcmp(av[1], "--readi"))
	{
		if (!isvalid(av[2]))
			decrypt(av[2], INT);
	}
	else
		return (usage());
	return (0);
}
