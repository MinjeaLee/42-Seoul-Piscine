#include <unistd.h>

int ft_ten_queens_puzzle(void);
int ft_ten_queens_puzzle2(int *arr, int index);
int check(int *arr, int x, int y);
void print(int *arr);
void ft_putchar(char c);

int ft_ten_queens_puzzle(void)
{
    int arr[10];
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < 10)
    {
        arr[i] = -1;
        i++;
    }
    i = 0;
    while (i < 10)
    {
        arr[0] = i;
        count += ft_ten_queens_puzzle2(arr, 1);
        i++;
    }
    return (count);
}

int ft_ten_queens_puzzle2(int *arr, int index)
{
    int i;
    int count;

    count = 0;
    if (index == 10)
    {
        print(arr);
        return (1);
    }
    i = 0;
    while (i < 10)
    {
        if (check(arr, index, i))
        {
            arr[index] = i;
            count += ft_ten_queens_puzzle2(arr, index + 1);
        }
        i++;
    }
    return (count);
}

int check(int *arr, int x, int y)
{
    int i;

    i = 0;
    while (i < x)
    {
        if (arr[i] == y)
            return (0);
        if (x - i == y - arr[i])
            return (0);
        if (x - i == arr[i] - y)
            return (0);
        i++;
    }
    return (1);
}

void print(int *arr)
{
    int i;

    i = 0;
    while (i < 10)
    {
        ft_putchar(arr[i] + '0');
        i++;
    }
    ft_putchar('\n');
}

void ft_putchar(char c)
{
    write(1, &c, 1);
}

#include <stdio.h>
#include <string.h>

int main() {
    ft_ten_queens_puzzle();

    return 0;
}