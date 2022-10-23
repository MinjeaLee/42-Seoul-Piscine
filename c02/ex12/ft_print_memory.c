/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:00:53 by mi                #+#    #+#             */
/*   Updated: 2022/10/12 15:39:38 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	init(long long addr_int, long long *pow)
{
	int			i;
	int			len;
	long long	tmp;
	int			return_len;

	i = 0;
	tmp = addr_int;
	*pow = 1;
	len = 0;
	return_len = 0;
	while (tmp > 0)
	{
		tmp /= 0x10;
		*pow *= 0x10;
		len ++;
	}
	while (i < 0x10 - len - 1)
	{
		write(1, "0", 1);
		i++;
		return_len++;
	}
	return (return_len);
}

void	print_address(void *addr, char *hex)
{
	long long	pow;
	long long	addr_int;
	int			index;
	int			len;
	int			i;

	addr_int = (long long)addr;
	len = init(addr_int, &pow);
	i = 0;
	while (addr_int > 0x9)
	{
		index = addr_int / pow;
		addr_int %= pow;
		pow /= 0x10;
		write(1, (hex + index), 1);
		len++;
	}
	while (i++ < 0x10 - len)
		write(1, "0", 1);
	write(1, ": ", 2);
}

void	print_ascii(void *addr, unsigned int len, char *hex)
{
	int				i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)addr;
	while (len / 2 > 0)
	{
		while (i++ < 2)
		{
			write(1, (hex + (*str / 0x10)), 1);
			write(1, (hex + (*str % 0x10)), 1);
			str++;
			len--;
		}
		write(1, " ", 1);
		i = 0;
	}
	if (len)
	{
		write(1, (hex + (*str / 0x10)), 1);
		write(1, (hex + (*str % 0x10)), 1);
		write(1, " ", 1);
	}
	if (len % 2 != 0)
		write(1, "  ", 2);
}

void	print_char(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	if (size % 2 == 1)
		i = 1;
	str = (unsigned char *)addr;
	while (i < (0x10 - size))
	{
		write(1, "     ", 5);
		i += 2;
	}
	while (size--)
	{
		if (0x20 <= *str && *str <= 0x7e)
			write(1, str, 1);
		else if (*str == '\0')
			write(1, "\n", 1);
		else
			write(1, ".", 1);
		str++;
	}
	if (*(str - 1) != '\0')
		write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	*hex;
	int		len;

	hex = "0123456789abcdef";
	while (size)
	{
		if (size / 0x10)
		{
			len = 0x10;
		}
		else
		{
			len = size;
		}
		print_address(addr, hex);
		print_ascii(addr, len, hex);
		print_char(addr, len);
		size -= len;
		addr += 0x10;
	}
	return (addr);
}
