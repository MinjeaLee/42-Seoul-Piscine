/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:42:37 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/09 07:46:36 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int	check_col_row(int puzzle[4][4], int position, int value)
{
	int	index;

	index = -1;
	while (++index < position / 4)
		if (puzzle[index][position % 4] == value)
			return (1);
	index = -1;
	while (++index < position % 4)
		if (puzzle[position / 4][index] == value)
			return (1);
	return (0);
}

int	build_puzzle(int puzzle[4][4], int input[16], int position)
{
	int	value;

	if (position == 16)
		return (1);
	value = 0;
	while (++value <= 4)
	{
		if (check_col_row(puzzle, position, value) == 0)
		{
			puzzle[position / 4][position % 4] = value;
			if (check_correct_case(puzzle, position, input) == 0)
			{
				if (build_puzzle(puzzle, input, position + 1))
					return (1);
			}
			else
				puzzle[position / 4][position % 4] = 0;
		}
	}
	return (0);
}

void	display_solution(int puzzle[4][4])
{
	int	y;
	int	x;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			ft_putnbr(puzzle[y][x]);
			ft_putchar(' ');
		}
		ft_putchar('\n');
	}
}

int	main(int ac, char **av)
{
	int	puzzle[4][4];
	int	*input;
	int	x;
	int	y;

	y = -1;
	x = -1;
	while (++y <= 3)
		while (++x <= 3)
			puzzle[y][x] = 0;
	if (av_check(ac, av))
		return (0);
	input = char_to_int(av[1]);
	if (build_puzzle(puzzle, input, 0) == 1)
		display_solution(puzzle);
	else
		ft_putstr("Did not find any solutions\n");
	return (0);
}
