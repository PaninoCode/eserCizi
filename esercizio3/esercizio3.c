#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int leggi(int n, int *array)
{
    printf("Inserisci quanti numeri conterrà l'array (non più di 100): ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    return n;
}

/*void generaArray(int *array)
{
    int size = (sizeof(array) / sizeof(int));
    for (int i = 0; i < size; i++)
    {
        array[i] = (rand() % (int)(((size) + 1) - (0))) + (size);
        for (int j = 0; j < size; j++)
        {
            if (array[j] == array[i])
                i--;
        }
    }
}*/

void stampaArray(int n, int *array, char *string, int modalita)
{
    if (modalita == 0)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d%s", array[i], string);
        }
    }
    else if (modalita == 1)
    {
        for (int i = n; i > 0; i--)
        {
            printf("%d%s", array[i - 1], string);
        }
    }
}

int sommaArray(int n, int *array, int tipo){
    int somma = 0;
    if(tipo == 0){
        for (int i = 0; i < n; i++)
        {
            somma += array[i];
        }
    }else if(tipo == 1){
        for (int i = 0; i < n; i++)
        {
            if(array[i] % 2 == 0)
                somma += array[i];
        }
    }else if(tipo == 2){
        for (int i = 0; i < n; i++)
        {
            if(array[i] % 2 != 0)
            somma += array[i];
        }
    }
    return somma;
}

int mediaArray(int n, int *array){
    int somma = 0;
    int media = 0;
    for (int i = 0; i < n; i++)
    {
        somma += array[i];
    }
    media = somma / n;
    return media;
}

int main() // int argc, char *argv)
{
    int size, array[100];
    size = leggi(size, array);
    // generaArray(array);
    printf("Array generato:\n");
    stampaArray(size, array, " ", 0);

    int scelta;
    do
    {
        printf("\nScegli che azione vuoi compiere:\n - [1] Stampa gli elementi dell'array.\n - [2] Stampa inversa degli elementi dell'array.\n - [3] Stampa somma e media dell'array.\n - [4] Somma tutti i numeri pari.\n - [5] Somma tutti i numeri dispari.\n - [10] Esci dal programma.\n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1:
            stampaArray(size, array, " ", 0);
            break;
        case 2:
            stampaArray(size, array, " ", 1);
            break;
        case 3:
            printf("Somma: %d \nMedia: %d", sommaArray(size, array, 0), mediaArray(size, array));
            break;
        case 4:
            printf("Somma: %d\n", sommaArray(size, array, 1));
            break;
        case 5:
            printf("Somma: %d\n", sommaArray(size, array, 2));
            break;
        default:
            break;
        }
    } while (scelta != 10);
    printf("Arrivederci!");
}