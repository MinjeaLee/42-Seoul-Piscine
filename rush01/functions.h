/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heejunki <heejunki@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 07:01:12 by heejunki          #+#    #+#             */
/*   Updated: 2022/10/09 07:33:27 by heejunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	ft_putstr(char *str);

int		ft_atoi(char *str);
int		ft_strlen(char *str);
int		*char_to_int(char *str);
int		av_check(int ac, char **av);
int		check_col_row(int puzzle[4][4], int position, int value);
int		check_correct_case(int puzzle[4][4], int position, int input[16]);

#endif
