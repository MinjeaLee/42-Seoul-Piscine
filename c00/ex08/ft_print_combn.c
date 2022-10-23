/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:21:46 by mi                #+#    #+#             */
/*   Updated: 2022/10/02 17:17:42 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_extra(int prev, int n, int len, char *num)
{
	int	i;

	if (n == len)
	{
		write(1, num, len);
		write(1, ", ", 2);
		return ;
	}
	i = prev;
	while (++i <= 10 - len + n)
	{
		*(num + n) = '0' + i;
		print_extra(i, n + 1, len, num);
	}
}

void	print_last(int i)
{
	char	c;

	while (i <= 9)
	{
		c = '0' + i++;
		write(1, &c, 1);
	}
}

void	ft_print_combn(int n)
{
	int		i;
	int		len;
	char	num[10];

	i = 0;
	len = n;
	while (i < 10 - n)
	{
		*(num) = '0' + i;
		print_extra(i, 1, len, num);
		i++;
	}
	print_last(i);
}
