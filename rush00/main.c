/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:42:15 by seok              #+#    #+#             */
/*   Updated: 2022/10/02 19:13:28 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int n_col, int n_row);

int	ft_atoi(char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while ((9 <= *str && *str <= 13) || 32 == *str)
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != 0)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		result = (result * 10) + *str - '0';
		str++;
	}
	return (result * sign);
}

int	main(int ac, char *av[])
{
	int	row;
	int	col;

	row = ft_atoi(av[1]);
	col = ft_atoi(av[2]);
	if (ac == 3 && (0 < row && 0 < col))
		rush(col, row);
	else
		write(2, "ERROR", 5);
	return (0);
}
