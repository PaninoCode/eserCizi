#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int GeneraNumero(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int CalcolaESistema(int array[], int numeri_trovati[][2], int size)
{
    int size_nt = 0, trovato;
    for (int i = 0; i < size; i++)
    {
        trovato = 0;
        for (int j = 0; j < size_nt; j++)
        {
            if (array[i] == numeri_trovati[j][0])
            {
                trovato = 1;
                numeri_trovati[j][1]++;
            }
        }
        if (trovato == 0)
        {
            numeri_trovati[size_nt][0] = array[i];
            numeri_trovati[size_nt][1] = 1;
            size_nt++;
        }
    }
    return size_nt;
}

int Sorting(int array[], int size, int type)
{
    int ultimo = 1, a, b, spostamento;
    if (size % 2 == 0)
        ultimo = 1;
    do
    {
        spostamento = 0;
        for (int i = 0; i < size; i++)
        { // 0 = decrescente, 1 = crescente
            if ((array[i] < array[i + ultimo] && type == 0) || (array[i] > array[i + ultimo] && type == 1))
            {
                spostamento = 1;
                a = array[i];
                b = array[i + ultimo];
                array[i] = b;
                array[i + ultimo] = a;
            }
        }
    } while (spostamento == 1);
}

int OrdinaArray(int array[], int size, int array_pari[], int array_dispari[])
{
    int cpari = 0, cdispari = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] % 2 == 0)
        {
            array_pari[cpari] = array[i];
            cpari++;
        }
        if (array[i] % 2 != 0)
        {
            array_dispari[cdispari] = array[i];
            cdispari++;
        }
    }
    Sorting(array_pari, cpari, 0);
    Sorting(array_dispari, cdispari, 1);
    return cpari;
}

int main(int argc, char *argv[])
{
    int size, cpari = 0, cdispari = 0;
    if (argc != 2)
    {
        size = 50;
    }
    else
    {
        size = atoi(argv[1]);
    }

    int array[size], array2[size][2], array_pari[size], array_dispari[size], num;
    srand(time(NULL));
    printf("\nArray Generato: ");
    for (int i = 0; i < size; i++)
    {
        num = GeneraNumero(69, 420);
        printf("%d ", num);
        array[i] = num;
    }

    printf("\nArray senza numeri ripetuti, e frequenze:\n");
    for (int i = 0; i < CalcolaESistema(array, array2, size); i++)
    {
        printf("Numero: %d Frequenza: %d\n", array2[i][0], array2[i][1]);
    }

    cpari = OrdinaArray(array, size, array_pari, array_dispari);
    cdispari = size - cpari;

    printf("\nNumeri pari ordinati: ");
    for (int i = 0; i < cpari; i++)
    {
        printf("%d ", array_pari[i]);
    }
    printf("\nNumeri dispari ordinati: ");
    for (int i = 0; i < cdispari; i++)
    {
        printf("%d ", array_dispari[i]);
    }
    printf("\n\n");
}