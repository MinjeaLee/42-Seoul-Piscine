/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mi <mi@student.42seoul.kr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:47:08 by mi                #+#    #+#             */
/*   Updated: 2022/10/20 17:47:09 by mi               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char **ft_split(char *str, char *charset);

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_is_charset(char c, char *charset)
{
    int i;

    i = 0;
    while (charset[i])
    {
        if (c == charset[i])
            return (1);
        i++;
    }
    return (0);
}

int ft_count_words(char *str, char *charset)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (ft_is_charset(str[i], charset) == 0)
        {
            count++;
            while (ft_is_charset(str[i], charset) == 0 && str[i])
                i++;
        }
        i++;
    }
    return (count);
}

char **ft_split(char *str, char *charset)
{
    int i;
    int j;
    int k;
    char **result;

    i = 0;
    j = 0;
    result = (char **)malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
    while (str[i])
    {
        if (ft_is_charset(str[i], charset) == 0)
        {
            k = 0;
            result[j] = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
            while (ft_is_charset(str[i], charset) == 0 && str[i])
                result[j][k++] = str[i++];
            result[j++][k] = '\0';
        }
        i++;
    }
    result[j] = 0;
    return (result);
}