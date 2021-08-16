#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	int		i;
	int		j;
	char	*dest1;
	char	*src1;

	j = n;
	i = 0;
	dest1 = (char *)dest;
	src1 = (char *)src;
	if (dest1 == '\0' && src1 == '\0')
		return (dest);
	while (i < j)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*a;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	a = (char *)malloc(len * sizeof(char));
	j = 0;
	i = 0;
	if (a == 0)
		return (NULL);
	while (s1[i])
	{
		a[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		a[i + j] = s2[j];
		j++;
	}
	a[i + j] = '\0';
	return (a);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*result;
	char	*a;

	len = ft_strlen(s) + 1;
	a = (char *)malloc(sizeof(char) * len);
	if (a == 0)
		return (0);
	result = ft_memcpy(a, s, len);
	return (result);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	while (i < size - 1 && src[i] != '\0' && size > 0)
	{
		dst[i] = src[i];
		i++;
	}
	if (size != 0)
		dst[i] = '\0';
	return ((ft_strlen(src)));
}

int	ft_strchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == c)
		{
			return (i);
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
	{
		return (i);
	}
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*string;
	size_t	i;
	size_t	a;

	if (s == NULL)
		return (0);
	i = 0;
	a = ft_strlen(&s[start]);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if (a < len)
		len = a;
	string = (char *)malloc(sizeof(char) * (len + 1));
	if (string == NULL)
		return (NULL);
	ft_strlcpy(string, &s[start], len + 1);
	return (string);
}
