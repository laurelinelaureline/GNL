/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laureline.pierre <laureline.pierre@lear    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:17:06 by laureline.p       #+#    #+#             */
/*   Updated: 2025/12/15 20:53:56 by laureline.p      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!accumulator)
		accumulator = ft_strdup("");
	while (!ft_strchr(accumulator, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
	}
	free(buffer);
	if (!accumulator || accumulator[0] == '\0')
		return (free(accumulator), accumulator = NULL, NULL);
	return (ft_extract_line(&accumulator));
}
