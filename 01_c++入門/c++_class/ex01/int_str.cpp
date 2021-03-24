// Student ID : s1260032
#include <iostream>
#include <stdlib.h>

//Converts an int type argument to a char pointer.
char *intToStr(int num)
{
    int digit_num = 0, flag = 0;
    int divide_digit = 1, tmp = num;
    char *str_tmp;
    if (num < 0)
    {
        num *= -1;
        flag = 1;
    }

    for (int i = 0; i < 10; i++)
    {
        tmp /= 10;
        digit_num++;
        if (tmp == 0)
            break;
    }
    char *str = (char *)malloc((digit_num + flag + 1) * sizeof(char));
    str_tmp = str;

    if (flag == 1)
    {
        *str = '-';
        str += sizeof(char);
    }
    for (int i = 0; i < digit_num - 1; i++)
    {
        divide_digit *= 10;
    }

    for (int i = 0; i < digit_num; i++)
    {
        *str = (char)('0' + (num / divide_digit));
        num %= divide_digit;
        str += sizeof(char);
        divide_digit /= 10;
    }
    *str = '\0';
    return str_tmp;
}

//Converts a char poiner type argument to an int type.
int strToInt(char *str)
{
    int num = 0, flag = 0;
    int str_digit_num = 0, multiple_digit = 1;
    char *str_digit_num_tmp = str;
    if (*str == '-')
    {
        flag = 1;
        str += sizeof(char);
    }
    while (*str != '\0')
    {
        str_digit_num++;
        str += sizeof(char);
    }
    for (int i = 0; i < str_digit_num - 1; i++)
    {
        multiple_digit *= 10;
    }

    str = str_digit_num_tmp + flag*sizeof(char);
    while (*str != '\0')
    {
        if (*str < '0' || '9' < *str)
            break;
        int tmp = *str - '0';
        num += multiple_digit * tmp;
        multiple_digit /= 10;
        str += sizeof(char);
    }
    if (flag == 1)
        return -1*num;
    else return num;
}