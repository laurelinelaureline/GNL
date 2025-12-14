/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_ligne.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laureline.pierre <laureline.pierre@lear    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:17:06 by laureline.p       #+#    #+#             */
/*   Updated: 2025/12/14 20:17:20 by laureline.p      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*accumulator;
	char		buffer[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!accumulator || !ft_strchr(accumulator, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		accumulator = ft_strjoin(accumulator, buffer);
		if (ft_strchr(accumulator, '\n'))
			break ;
	}
	if (!accumulator || !accumulator[0] == '\0')
		return (NULL);
	return (ft_extract_line(&accumulator));
}
