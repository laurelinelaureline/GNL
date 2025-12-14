#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cc;
	size_t			i;

	if (!s)
		return (NULL);
	cc = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (cc == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_extract_line(char **accumulator)
{
	char	*line;
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while ((*accumulator)[i] && (*accumulator)[i] != '\n')
		i++;
	if ((*accumulator)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = (*accumulator)[j];
		j++;
	}
	line[j] = '\0';
	rest = malloc(ft_strlen(*accumulator + i) + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while ((*accumulator)[i])
		rest[j++] = (*accumulator)[i++];
	rest[j] = '\0';
	free(*accumulator);
	*accumulator = rest;
	return (line);
}
