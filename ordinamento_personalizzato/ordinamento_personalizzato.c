#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int GeneraNumero(int min, int max)
{
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int ScegliNumero(int pos, int array[], int min, int max)
{
    int num;
    num = GeneraNumero(min, max);
    for (int j = 0; j < pos; j++)
    {
        if (num == array[j])
        {
            return 0;
        }
    }
    return num;
}

int ContaNumeri(int array[], int size, int tipo)
{
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if ((array[i] % 2 == 0 && tipo == 0) || (array[i] % 2 != 0 && tipo == 1))
        {
            c++;
        }
    }
    return c;
}

int* ordinaInteroArray(int array[], int size)
{
    int ultimo, a, b, spostamento;
    if (size % 2 == 0)
    {
        ultimo = 1;
    }
    else
    {
        ultimo = 0;
    }
    do
    {
        spostamento = 0;
        for (int i = 0; i < size; i++)
        {
            if (array[i] > array[i + ultimo])
            {
                spostamento = 1;
                a = array[i];
                b = array[i + ultimo];
                array[i] = b;
                array[i + ultimo] = a;
            }
        }
    }while(spostamento == 1);

    return array;
}

int* ordinaEstremiArray(int array[], int arrayvuoto[], int size, int qpari, int qdispari){
    int npari = -1;
    int ndispari = -1;
    for(int i = 0; i < qpari; i++){
        for(int j = 0; j < size; j++){
            if(array[j] % 2 == 0 && j > npari){
                npari = j;
                arrayvuoto[i] = array[j];
                break;
            }
        }
    }
    for(int i = qdispari; i > size - qdispari; i--){
        for(int j = 0; j < size; j++){
            if(array[j] % 2 != 0 && j > ndispari){
                ndispari = array[j];
                arrayvuoto[i] = array[j];
                break;
            }
        }
    }
    for(int i = qpari; i < size - qdispari; i++){
        arrayvuoto[i] = array[i];
    }
    
    return arrayvuoto;
}

int main(int argc, char *argv[])
{
    int array[20], arraylibero[20], arrayordinato[0], arrayordinato2[0], size, num, qpari, qdispari;
    size = (sizeof(array) / sizeof(int));
    srand(time(NULL));
    printf("\nArray Generato: ");
    for (int i = 0; i < size; i++)
    {
        do
        {
            num = ScegliNumero(i, array, 1, 233);
            if (num != 0)
            {
                array[i] = num;
                printf("%d ", num);
            }
        } while (num == 0);
    }

    qpari = ContaNumeri(array, size, 0);
    if (qpari > 20)
    {
        qpari = 20;
        printf("\nL'array contiene almeno %d numeri pari.", qpari);
    }
    else
    {
        printf("\nL'array contiene %d numeri pari.", qpari);
    }

    qdispari = ContaNumeri(array, size, 1);
    if (qdispari > 20)
    {
        qdispari = 20;
        printf("\nL'array contiene almeno %d numeri dispari.", qdispari);
    }
    else
    {
        printf("\nL'array contiene %d numeri dispari.", qdispari);
    }

    printf("\nArray ordinato: ");

    memcpy(arrayordinato, ordinaInteroArray(array, size), size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayordinato[i]);
    }

    printf("\n\n\nArray ordinato 2: ");

    memcpy(arrayordinato2, ordinaEstremiArray(arrayordinato, arraylibero, size, qpari, qdispari), size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arrayordinato2[i]);
    }

    //ordinaPrimiNumeriPari();
}