/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:58:35 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/13 13:02:33 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*del_line(char *db)
{
	char	*newdb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!db)
		return (0);
	while (db[i] && db[i] != '\n')
		i++;
	if (!db[i])
	{
		free(db);
		return (0);
	}
	if (!(newdb = malloc(sizeof(char) * ((ft_strlen(db) - i) + 1))))
		return (0);
	i++;
	while (db[i])
		newdb[j++] = db[i++];
	newdb[j] = '\0';
	free(db);
	return (newdb);
}

char	*next_line(char *db)
{
	size_t		index;
	char		*line;

	index = 0;
	if (!db)
		return (0);
	while (db[index] && db[index] != '\n')
		index++;
	if (!(line = malloc(sizeof(char) * (index + 1))))
		return (0);
	index = 0;
	while (db[index] && db[index] != '\n')
	{
		line[index] = db[index];
		index++;
	}
	line[index] = '\0';
	return (line);
}

int		get_next_line(const int fd, char **line)
{
	char		*buffer;
	static char	*db[OPEN_MAX];
	int			res;

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!is_line(db[fd]) && res != 0)
	{
		if ((res = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		buffer[res] = '\0';
		db[fd] = ft_strjoin(db[fd], buffer);
	}
	free(buffer);
	*line = next_line(db[fd]);
	db[fd] = del_line(db[fd]);
	if (res == 0)
		return (0);
	return (1);
}
