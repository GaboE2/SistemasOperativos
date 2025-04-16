
/*
Nombre Alumno: Gabriel Alejandro Baca Flores
Fecha de entrega: 1/04/2025
Tiempo dedicado: (2horas 30 aprox)


Original Author: Meher Shaikh
Modifier Author: Rosa Paccotacya
Date: March 26, 2025
This project familiarizes you to: 
arrays, structures and pointers in C language.
Here you have created an array and have passed 
the ARRAY to different functions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_STUDS 5
#define DATA_LEN 80

typedef struct student
{
    char name[DATA_LEN];
    int id;
    double GPA;
} student;

void enterstudinfo(student *slist) // por medio del puntero acceder a la clase student
{
    char line[DATA_LEN]; // igual se define aqui

   

    for (int i = 0; i < NUM_STUDS; i++)
    {
        printf("Student %d:\n", i + 1); // c tiende a correr en desorden el dgets asi que, la terminal pedira algo en vacio, pero lo primero que recibirá si es el printf

        // Nombre
        printf("Enter student %d name: ", i + 1);
        fgets(line, DATA_LEN, stdin);
        line[strcspn(line, "\n")] = 0; // busca el caracter \n y ahora es 0, sin ignorar el saldo
        strcpy(slist[i].name, line);  // ingresarlo a name

        // ID
        printf("Enter id: ");
        fgets(line, DATA_LEN, stdin);
        sscanf(line, "%d", &slist[i].id);

        // GPA
        printf("Enter GPA: ");
        fgets(line, DATA_LEN, stdin);
        sscanf(line, "%lf", &slist[i].GPA);

        printf("\n");
    }
}

void displstudinfo(student *slist)
{
    printf("*************Students Report:---------\n");
    printf("--------------------------------------\n");
    printf("%-25s| %-5s | %s\n", "NAME", "ID", "GPA");

    for (int i = 0; i < NUM_STUDS; i++)
    {
        printf("%-25s| %-5d | %.2f\n", slist[i].name, slist[i].id, slist[i].GPA);
    }
}


int main()
{

    
    student studArr[NUM_STUDS];

    enterstudinfo(studArr);
    displstudinfo(studArr);

    printf("\n");

    return 0;
}

// OUTPUT:
/*
 gcc -o prog01 prog01.c 
 ./prog01

Student 1: 
Enter student 1 name: James Bond
Enter id: 7
Enter GPA: 3.9999

Student 2: 
Enter student 2 name: Zack Smith
Enter id: 23
Enter GPA: 2.78

Student 3: 
Enter student 3 name: Mary Sean Bonnet
Enter id: 12
Enter GPA: 3.5678

*************Students Report:---------
--------------------------------------
NAME                     | ID    | GPA  |
James Bond               | 7     | 4.00 |
Zack Smith               | 23    | 2.78 |
Mary Sean Bonnet         | 12    | 3.57 |
*/
