/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:55:11 by mi                #+#    #+#             */
/*   Updated: 2022/10/04 21:55:47 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	non_printable_check(char byte)
{
	if (!(0x20 <= byte && byte <= 0x7e))
	{
		return (0);
	}
	return (1);
}

char	num_to_hex_over_a(int n)
{
	char	result;

	if (n <= 9)
	{
		result = n + '0';
		return (result);
	}
	else
	{
		result = 'a' + (n % 10);
		return (result);
	}
}

void	non_print_to_hex(int n)
{
	char	hex[3];
	int		i;

	hex[0] = '\\';
	hex[1] = '0';
	hex[2] = '0';
	i = 0;
	if (n < 0)
	{
		n += 256;
	}
	hex[1] = num_to_hex_over_a(n / 0x10);
	hex[2] = num_to_hex_over_a(n % 0x10);
	write(1, hex, 3);
}

void	ft_putstr_non_printable(char *str)
{
	int	non_print;

	while (*str)
	{
		if (!non_printable_check(*str))
		{
			non_print = *str;
			non_print_to_hex(non_print);
			str++;
		}
		else
		{
			write(1, str, 1);
			str++;
		}
	}
}
