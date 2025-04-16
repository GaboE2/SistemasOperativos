/*
Gabriel Alejandro Baca Flores
Author: Rosa Paccotacya
Date: Apr 9, 2025
This project familiarizes you to: 
fork() and wait() functions in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void collatz(int num)
{
    while (num != 1)
    {
        printf("%d, ", num);
        if (num % 2 == 0)
            num = num / 2;
        else
            num = 3 * num + 1;
    }
    printf("1,\n");
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        int num = atoi(argv[1]);
        if (num <= 0 || num >= 50)
        {
            printf("Ingresar un numero positivo\n");
            return 1;
        }

        pid_t pid = fork();
        if (pid < 0)
        {
            perror("El fork fallo");
            return 1;
        }
        else if (pid == 0)
        {
            collatz(num);
        }
        else
        {
            wait(NULL);
        }
    }
    else
    {
        printf("Usage: ./program <starting value>\n");
    }
    return 0;
}
