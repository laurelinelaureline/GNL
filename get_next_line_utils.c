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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*ptr_dest;
	unsigned const char	*ptr_src;
	size_t				i;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return ((void *)(ptr_dest));
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
	size_t	len_s1;
	size_t	len_s2;

	if (!s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = malloc(len_s1 + len_s2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, len_s2);
	res[len_s1 + len_s2] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s)
{
	unsigned char	*ptr;
	int				len;
	int				i;

	i = 0;
	len = ft_strlen(s);
	ptr = (unsigned char *)malloc(len * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return ((char *)ptr);
}

char	*ft_extract_line(char **accumulator)
{
	char	*line;
	char	*rest;
	int		i;

	i = 0;
	while ((*accumulator)[i] && (*accumulator)[i] != '\n')
		i++;
	if ((*accumulator)[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, *accumulator, i);
	line[i] = '\0';
	if ((*accumulator)[i] == '\0')
	{
		free(*accumulator);
		*accumulator = NULL;
		return (line);
	}
	rest = ft_strdup(*accumulator + i);
	free(*accumulator);
	*accumulator = rest;
	return (line);
}
