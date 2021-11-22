/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:40:25 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 17:23:41 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	add_line(char **line, char **room)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*room)[i] != '\0')
	{
		if ((*room)[i] == '\n')
			break ;
		i++;
	}
	if (i < (int)ft_strlen(*room))
	{
		*line = ft_substr(*room, 0, i);
		temp = ft_substr(*room, i + 1, ft_strlen(*room));
		free(*room);
		*room = ft_strdup(temp);
		free(temp);
	}
}

int	is_continue(int fd, int byte, char **line, char **room)
{
	if (byte == 0)
	{
		if (room[fd] == NULL)
			*line = ft_strdup("");
		else
			*line = ft_strdup(room[fd]);
		free((room[fd]));
		return (0);
	}
	else
	{
		add_line(line, &(room[fd]));
		free(*line);
		return (1);
	}
}

void	add_room(char **room, char *buf)
{
	char	*temp;

	if (*room == NULL)
		*room = ft_strdup(buf);
	else
	{
		temp = ft_strjoin(*room, buf);
		free(*room);
		*room = ft_strdup(temp);
		free(temp);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*room[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			byte;

	if (line == NULL)
		return (-1);
	byte = 1;
	while (byte)
	{
		byte = read(fd, buf, 1);
		if (byte < 0)
			return (-1);
		buf[byte] = '\0';
		add_room(&(room[fd]), buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (is_continue(fd, byte, line, room) == TRUE)
		return (TRUE);
	return (0);
}
