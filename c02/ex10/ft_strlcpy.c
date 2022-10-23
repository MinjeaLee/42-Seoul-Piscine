/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 19:39:44 by mi                #+#    #+#             */
/*   Updated: 2022/10/06 22:19:03 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	result;
	unsigned int	i;
	char			*tmp;

	tmp = src;
	i = 0;
	result = 0;
	while (*tmp)
	{
		tmp++;
		result++;
	}
	while (i + 1 < size && *src)
	{
		*dest++ = *src++;
		i++;
	}
	*dest = '\0';
	return (result);
}
