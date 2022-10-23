/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:01:04 by mi                #+#    #+#             */
/*   Updated: 2022/10/02 17:21:56 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	_init(char arr[])
{
	*(arr) = '0';
	*(arr + 1) = '1';
	*(arr + 2) = '2';
	*(arr + 3) = ',';
	*(arr + 4) = ' ';
}

void	_write(char arr[])
{
	if (arr[0] == '7' && arr[1] == '8' && arr[2] == '9')
	{
		write(1, arr, 3);
	}
	else
	{
		write(1, arr, 5);
	}
}

void	ft_print_comb(void)
{
	char	str[5];

	_init(str);
	while (str[0] <= '7')
	{
		while (str[1] <= '8')
		{
			while (str[2] <= '9')
			{
				_write(str);
				str[2]++;
			}
			str[1]++;
			str[2] = str[1] + 1;
		}
		str[0]++;
		str[1] = str[0] + 1;
		str[2] = str[1] + 1;
	}
}
