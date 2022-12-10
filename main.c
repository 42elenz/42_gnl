#include "get_next_line.h"
#include "fcntl.h"

int main()
{
	int fd = 0;
	fd = open("foo.txt", O_RDONLY);
	char *str = NULL;

	str =get_next_line(fd);
	while(str)
	{
		printf("%s", str);
		str = get_next_line(fd);
	};
	close(fd);
	return (0);
}