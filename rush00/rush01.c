/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seok <seok@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 00:33:59 by seok              #+#    #+#             */
/*   Updated: 2022/10/02 18:57:19 by seok             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_line(int n_row, char first, char mid, char last)
{
	int	i;

	i = 1;
	while (i <= n_row)
	{
		if (i == 1)
			ft_putchar(first);
		else if (i == n_row)
			ft_putchar(last);
		else
			ft_putchar(mid);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int n_col, int n_row)
{
	int	i;

	i = 1;
	while (i <= n_col)
	{
		if (i == 1)
			print_line(n_row, '/', '*', '\\');
		else if (i == n_col)
			print_line(n_row, '\\', '*', '/');
		else
			print_line(n_row, '*', ' ', '*');
		i++;
	}
}
