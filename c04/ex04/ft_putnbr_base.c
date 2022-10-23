/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:41:38 by mi                #+#    #+#             */
/*   Updated: 2022/10/20 17:43:12 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	exption(char *str)
{
	int		flag;
	char	*ptr_i;
	char	*ptr_j;

	flag = 1;
	ptr_i = str;
	while (*ptr_i)
	{
		ptr_j = ptr_i + 1;
		while (*ptr_j)
		{
			if (*ptr_i == *ptr_j)
				flag = 0;
			if (*ptr_i == '+' || *ptr_i == '-')
				flag = 0;
			ptr_j++;
		}
		ptr_i++;
	}
	return (flag);
}

void	set_sign(int nbr, int *sign)
{
	if (nbr < 0)
	{
		*sign = -1;
		write(1, "-", 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		len;
	int		nbr_base[100];
	int		sign;

	i = 0;
	sign = 1;
	len = str_len(base);
	if (len <= 1 || exption(base) == 0)
		return ;
	set_sign(nbr, &sign);
	if (nbr == 0)
	{
		write(1, &base[0], 1);
		return ;
	}
	while (nbr)
	{
		nbr_base[i] = nbr % len;
		nbr /= len;
		i++;
	}
	while (i--)
		write(1, &(base[nbr_base[i] * sign]), 1);
}
