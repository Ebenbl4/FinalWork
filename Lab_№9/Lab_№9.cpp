#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
int main()
{
    setlocale(LC_ALL, "Russian");
    setlocale(LC_ALL, "rus");
    int cp = GetConsoleCP();
    const char shapka[] =
        "+-------------------------------------------------------------------+\n"
        "|   |                 |               |           Ёмкость           |\n"
        "| # | Формат контента |     Цена      |-------------------+---------|\n"
        "|   |                 |               |       байты       | м.байты |\n"
        "|   |                 |               |-------------------|         |\n"
        "|   |                 |               |   min   |   max   |         |\n"
        "+---+-----------------+---------------+---------+---------+---------+\n";
    struct str
    {
        int num;
        char form[200];
        char price[999];
        struct vol
        {
            struct bytes
            {
                char minb[800], maxb[800];
            }bytes;
            char mbytes[32];
        }vol;
    };
    int i;

    struct str cdiscs[5], temp;
    for (i = 0; i < 5; i++)
    {
        cdiscs[i].num = i + 1;
        printf("Введите формат контента %d диска: ", i + 1);
        scanf("%[^\n]s", cdiscs[i].form);
        getchar();
        printf("Введите цену %d диска : ", i + 1);
        scanf("%[^\n]d", cdiscs[i].price);
        getchar();
        printf("Введите ёмкость в байтах %d диска (min): ", i + 1);
        scanf("%[^\n]d", cdiscs[i].vol.bytes.minb);
        getchar();
        printf("Введите ёмкость в байтах %d диска (max): ", i + 1);
        scanf("%[^\n]d", cdiscs[i].vol.bytes.maxb);
        getchar();
        printf("Введите ёмкость в мегабайтах %d диска: ", i + 1);
        scanf("%[^\n]d", cdiscs[i].vol.mbytes);
        getchar();
    }
    system("cls");
    printf("%s", shapka);
    SetConsoleCP(1251);
    for (i = 0; i < 5; i++)
    {
        printf("| %-2d| %-16s| %-14s| %-8s| %-8s| %-8s|\n", cdiscs[i].num, cdiscs[i].form, cdiscs[i].price, cdiscs[i].vol.bytes.minb, cdiscs[i].vol.bytes.maxb, cdiscs[i].vol.mbytes);
        printf("+-------------------------------------------------------------------+\n");
    }

    temp = cdiscs[0];
    cdiscs[0] = cdiscs[4];
    cdiscs[4] = temp;
    SetConsoleCP(cp);
    printf("\n\n%s", shapka);
    SetConsoleCP(1251);
    for (i = 0; i < 5; i++)
    {
        printf("| %-2d| %-16s| %-14s| %-8s| %-8s| %-8s|\n", cdiscs[i].num, cdiscs[i].form, cdiscs[i].price, cdiscs[i].vol.bytes.minb, cdiscs[i].vol.bytes.maxb, cdiscs[i].vol.mbytes);
        printf("+-------------------------------------------------------------------+\n");
    }
    return 0;
}