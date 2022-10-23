/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:47:24 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/09 07:49:10 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"
#include <stdlib.h>

int	av_check(int ac, char **av)
{
	if (ac != 2)
		return (1);
	if (ft_strlen(av[1]) != 31)
		return (1);
	return (0);
}

int	*char_to_int(char *str)
{
	int	str_index;
	int	puz_index;
	int	*puzzle;

	if(!(puzzle = malloc(sizeof(int) * 16)))
		return (0);
	str_index = -1;
	puz_index = 0;
	while (str[++str_index] != '\0')
		if (str[str_index] >= '0' && str[str_index] <= '9')
			puzzle[puz_index++] = ft_atoi(str + str_index);
	return (puzzle);
}
