/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jklein <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:22:02 by jklein            #+#    #+#             */
/*   Updated: 2022/08/23 15:16:14 by jklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

		/* -- This function will be called using the header file -- */
		/* -- The statments and arguments get used in get_next_line file -- */

size_t	fd_strlen(const char *str)
{
	size_t	line;

	line = 0;
	if (!str)
		return (0);
	while (str[line])
		line++;
	return (line);
}

char	*fd_substr(const char *str, unsigned int start, size_t len)
{
	char	*dest;
	size_t	next_line;

	next_line = 0;
	if (str == NULL)
		return (NULL);
	if (start > fd_strlen(str) || len == 0)
		return (fd_strdup(""));
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (str[start + next_line] != '\0' && next_line < len)
	{
		dest[next_line] = str[start + next_line];
		next_line++;
	}
	dest[next_line] = '\0';
	return (dest);
}

char	*fd_strchr(const char *s1, int i)
{
	while (*s1)
	{
		if (*s1 == i)
			return ((char *)s1);
		s1++;
	}
	if (i == '\0')
		return ((char *)s1);
	return (0);
}

char	*fd_strdup(const char *str)
{
	size_t	len;
	char	*newstr;

	len = 0;
	newstr = (char *)malloc(sizeof(char) * (fd_strlen(str) + 1));
	while (str[len])
	{
		newstr[len] = str [len];
		len++;
	}
		newstr[len] = '\0';
	return (newstr);
}

char	*fd_strjoin(const char *s1, const char *s2)
{
	int		strcpy1;
	int		strcpy2;
	char	*str;

	strcpy1 = 0;
	strcpy2 = 0;
	str = (char *)malloc(sizeof(char) * (fd_strlen(s1) + fd_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[strcpy1] != '\0')
	{
		str[strcpy1] = s1[strcpy1];
		strcpy1++;
	}
	while (s2[strcpy2] != '\0')
	{
		str[strcpy1 + strcpy2] = s2[strcpy2];
		strcpy2++;
	}
	str[strcpy1 + strcpy2] = '\0';
	return (str);
}
