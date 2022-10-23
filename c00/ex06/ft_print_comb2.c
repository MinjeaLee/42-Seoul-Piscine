/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:50:19 by mi                #+#    #+#             */
/*   Updated: 2022/10/02 17:20:58 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	initialize(char arr[])
{
	*(arr) = '0';
	*(arr + 1) = '0';
	*(arr + 2) = ' ';
	*(arr + 3) = '0';
	*(arr + 4) = '1';
	*(arr + 5) = ',';
	*(arr + 6) = ' ';
}

void	write_str(char arr[])
{
	if (arr[0] == '9' && arr[1] == '8' && arr[3] == '9' && arr[4] == '9')
	{
		write(1, arr, 5);
	}
	else
	{
		write(1, arr, 7);
	}
}

void	plus_first(char arr[])
{
	*(arr) += 1;
	*(arr + 1) = '0';
	*(arr + 3) = *(arr + 0);
	*(arr + 4) = *(arr + 1) + 1;
}

void	ft_print_comb2(void)
{
	char	arr[7];

	initialize(arr);
	while (arr[0] <= '9')
	{
		while (arr[1] <= '9')
		{
			while (arr[3] <= '9')
			{
				while (arr[4] <= '9')
				{
					write_str(arr);
					arr[4]++;
				}
				arr[3]++;
				arr[4] = '0';
			}
			arr[1]++;
			arr[3] = arr[0];
			arr[4] = arr[1] + 1;
		}
		plus_first(arr);
	}
}
