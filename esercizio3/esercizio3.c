#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv)
{
    char **stringArray[500];
    printf("Inserisci gli elementi (solo numeri) uno alla volta, inserire il carattere [x] per terminare l'inserimento.");
    int contatore = 0;
    char elemento[4];
    do {
        printf("\n(%d)> ", contatore);
        scanf("%s", elemento);
        if(strcmp(elemento, "x") == 0 && atoi(elemento) == 0 || 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9){
            printf("we");
        } 
    }while(elemento != "x");
    return 0;
}