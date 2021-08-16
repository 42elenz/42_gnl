#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "get_next_line_utils.c"

char	*ft_gnl(int fd)
{
	static char	*rest;
	char		*t;
	char		*ausgabe;
	char		*c;
	int			buffersize;
	int			x;
	int			readret;

	x = 1;
	buffersize = BUFFERSIZE;
	c = malloc((buffersize + 1) * sizeof(char));
	while (x == 1)
	{
		if (rest == NULL)
		{
			readret = read(fd, c, buffersize);
			if (readret == 0)
				return (NULL);
			c[readret] = '\0';
			rest = ft_strdup(c);
		}
		if (ft_strchr(rest, '\n') == -1)
		{
			readret = read(fd, c, buffersize);
			if (readret == 0)
				return (NULL);
			c[readret] = '\0';
			t = ft_strjoin(rest, c);
			free(rest);
			rest = t;
		}
		else
		{
			ausgabe = ft_substr(rest, 0, ft_strchr(rest, '\n') + 1);
			t = ft_substr(rest, (ft_strchr(rest, '\n') + 1), ft_strlen(rest));
			free (rest);
			rest = t;
			return (ausgabe);
		}
	}
	return (NULL);
}

int	main()
{
	int	fd;
	char *s;
	int x;

	fd = open("foo.txt", O_RDONLY);
	while (x < 5)
	{
		s = ft_gnl(fd);
		printf("NEUE %s", s);
		x++;
	}
	return (0);
}
