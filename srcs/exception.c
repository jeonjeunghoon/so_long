/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeunjeon <jeunjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 01:48:31 by jeunjeon          #+#    #+#             */
/*   Updated: 2021/11/20 16:52:30 by jeunjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	exception(int argc, char *map_file)
{
	int	file_len;

	if (argc != 2)
		return (ERROR);
	file_len = ft_strlen(map_file);
	if (ft_strncmp(&(map_file[file_len - 4]), ".ber", 4) != 0)
		return (ERROR);
	return (0);
}
