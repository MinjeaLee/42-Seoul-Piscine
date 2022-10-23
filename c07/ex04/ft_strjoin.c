#include <stdlib.h>

// Up to five functions can be declared and each function cannot exceed 25 lines.

char *ft_strjoin(int size, char **strs, char *sep);

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *ft_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    while (dest[i])
        i++;
    j = 0;
    while (src[j])
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return (dest);
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    int i;
    int j;
    int len;
    char *str;

    if (size == 0)
    {
        str = (char *)malloc(sizeof(char));
        str[0] = '\0';
        return (str);
    }
    len = 0;
    i = 0;
    while (i < size)
    {
        len += ft_strlen(strs[i]);
        i++;
    }
    len += ft_strlen(sep) * (size - 1);
    str = (char *)malloc(sizeof(char) * (len + 1));
    str[0] = '\0';
    i = 0;
    while (i < size)
    {
        ft_strcat(str, strs[i]);
        if (i < size - 1)
            ft_strcat(str, sep);
        i++;
    }
    return (str);
}