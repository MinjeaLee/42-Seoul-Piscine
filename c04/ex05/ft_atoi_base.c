/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:18:10 by mi                #+#    #+#             */
/*   Updated: 2022/10/20 17:39:52 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	exption(char *str)
{
	char	*ptr_i;
	char	*ptr_j;

	ptr_i = str;
	while (*ptr_i)
	{
		if (*ptr_i == '+' || *ptr_i == '-')
			return (0);
		if ((0x9 <= *ptr_i && *ptr_i <= 0xd) || *ptr_i == ' ')
			return (0);
		ptr_j = ptr_i + 1;
		while (*ptr_j)
		{
			if (*ptr_i == *ptr_j)
				return (0);
			ptr_j++;
		}
		ptr_i++;
	}
	return (1);
}

int	set_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	while ((0x9 <= str[i] && str[i] <= 0xd) || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign *= -1;
		i++;
	}
	return (i);
}

long long	cal_result(char *str, char *base, int i)
{
	int			j;
	long long	result;

	result = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				result = result * ft_strlen(base) + j;
				break ;
			}
			j++;
		}
		if (!base[j])
			break ;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	if (ft_strlen(base) <= 1 || exption(base) == 0)
		return (0);
	i = set_sign(str, &sign);
	result = cal_result(str, base, i);
	return ((int)(result * sign));
}
