/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:20:58 by jklein            #+#    #+#             */
/*   Updated: 2022/08/23 15:15:08 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/get_next_line.h"

		/* -- This function prototype will declear a buffer -- */
		/* -- The buffer will update in the code using the static variable -- */
		/* -- The location variable obtains the result of the function -- */

static char	*fd_get_next_line(int fd, char *buffer, char *location)
{
	int		fd_bytes_read;
	char	*temp;

	fd_bytes_read = 1;
	while (fd_bytes_read != 0)
	{
		fd_bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (fd_bytes_read == -1)
			return (0);
		else if (fd_bytes_read == 0)
			break ;
		buffer[fd_bytes_read] = '\0';
		if (!location)
			location = fd_strdup("");
		temp = location;
		location = fd_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (fd_strchr (buffer, '\n'))
			break ;
	}
	return (location);
}

		/* -- The fd update function will reset the location varibles -- */
		/* -- The file descripter will allocate new inputs & outputs here -- */

static char	*file_descripter_update(char *line)
{
	size_t	index;
	char	*location;

	index = 0;
	while (line[index] != '\n' && line[index] != '\0')
		index++;
	if (line[index] == '\0' || line[1] == '\0')
		return (0);
	location = fd_substr(line, index + 1, fd_strlen(line) - index);
	if (*location == '\0')
	{
		free(location);
		location = NULL;
	}
	line[index + 1] = '\0';
	return (location);
}

		/* -- This is the get_next_line file descripter location -- 
		 * -- of the program input and output -- */
		/* -- The buffer will collect the statments and arguments here -- */

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*location;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	line = fd_get_next_line(fd, buffer, location);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	location = file_descripter_update(line);
	return (line);
}
