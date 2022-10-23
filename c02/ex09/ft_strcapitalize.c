/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:29:11 by mi                #+#    #+#             */
/*   Updated: 2022/10/12 15:22:03 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	initialize(char *str)
{
	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
		{
			*str += 0x20;
		}
		str++;
	}
}

void	word_check(char byte, int *flag)
{
	if (!('a' <= byte && byte <= 'z'))
	{
		if (!('A' <= byte && byte <= 'Z'))
		{
			if (!('0' <= byte && byte <= '9'))
			{
				*flag = 0;
			}
		}
	}
}

char	*ft_strcapitalize(char *str)
{
	char	*result;
	int		flag;

	flag = 0;
	result = str;
	initialize(str);
	while (*str)
	{
		word_check(*str, &flag);
		if ('0' <= *str && *str <= '9')
		{
			flag = 1;
		}
		if (flag == 0 && 'a' <= *str && *str <= 'z')
		{
			*str -= 0x20;
			flag = 1;
		}
		str++;
	}
	return (result);
}
