/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 06:49:23 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/09 06:53:07 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_col_up(int puzzle[4][4], int position, int input[16])
{
	int	index;
	int	visible_max_height;
	int	visible_count;

	index = 0;
	visible_max_height = 0;
	visible_count = 0;
	if (position / 4 == 3)
	{
		while (index < 4)
		{
			if (puzzle[index][position % 4] > visible_max_height)
			{
				visible_max_height = puzzle[index][position % 4];
				visible_count++;
			}
			index++;
		}
		if (input[position % 4] != visible_count)
			return (1);
	}
	return (0);
}

int	check_row_right(int puzzle[4][4], int position, int input[16])
{
	int	index;
	int	visible_max_height;
	int	visible_count;

	index = 4;
	visible_max_height = 0;
	visible_count = 0;
	if (position % 4 == 3)
	{
		while (--index >= 0)
		{
			if (puzzle[position / 4][index] > visible_max_height)
			{
				visible_max_height = puzzle[position / 4][index];
				visible_count++;
			}
		}
		if (input[12 + position / 4] != visible_count)
			return (1);
	}
	return (0);
}

int	check_col_down(int puzzle[4][4], int position, int input[16])
{
	int	index;
	int	visible_max_height;
	int	visible_count;

	index = 3;
	visible_max_height = 0;
	visible_count = 0;
	if (position / 4 == 3)
	{
		while (index >= 0)
		{
			if (puzzle[index][position % 4] > visible_max_height)
			{
				visible_max_height = puzzle[index][position % 4];
				visible_count++;
			}
			index--;
		}
		if (input[4 + position % 4] != visible_count)
			return (1);
	}
	return (0);
}

int	check_row_left(int puzzle[4][4], int position, int input[16])
{
	int	index;
	int	visible_max_height;
	int	visible_count;

	index = 0;
	visible_max_height = 0;
	visible_count = 0;
	if (position % 4 == 3)
	{
		while (index < 4)
		{
			if (puzzle[position / 4][index] > visible_max_height)
			{
				visible_max_height = puzzle[position / 4][index];
				visible_count++;
			}
			index++;
		}
		if (input[8 + position / 4] != visible_count)
			return (1);
	}
	return (0);
}

int	check_correct_case(int puzzle[4][4], int position, int input[16])
{
	if (check_row_left(puzzle, position, input) == 1)
		return (1);
	if (check_row_right(puzzle, position, input) == 1)
		return (1);
	if (check_col_down(puzzle, position, input) == 1)
		return (1);
	if (check_col_up(puzzle, position, input) == 1)
		return (1);
	return (0);
}
