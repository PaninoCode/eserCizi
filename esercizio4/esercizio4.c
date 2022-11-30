#include <stdio.h>
#include <string.h>
#include <ctype.h>

int VerificaStringa(char stringa[200])
{
    for (int i = 0; i < strlen(stringa); i++)
    {
        // printf("%c\n", stringaa[i]);
        if (!isalpha(stringa[i]))
        {
            return (-1);
        }
    }
    return (0);
}

void ContaLettere(char stringa[200], int tipo, char personalizzato[1], int nvocali, int nconson)
{
    // 65  69  73  79  85
    // 97  101 105 111 117
    unsigned long len = strlen(stringa);
    if (tipo == 0)
    { // Conta Vocali
        for (int i = 0; i < len; i++)
        {
            if (stringa[i] == 65 || stringa[i] == 69 || stringa[i] == 73 ||
                stringa[i] == 79 || stringa[i] == 85 || stringa[i] == 97 ||
                stringa[i] == 101 || stringa[i] == 105 || stringa[i] == 111 ||
                stringa[i] == 111 || stringa[i] == 117)
            {
                nvocali++;

            }else if(isalpha(stringa[i])){
                nconson++;
            }
        }
    }
    else if (tipo == 1)
    { // Conta carattere personalizzato
        for (int i = 0; i < len; i++)
        {
            if (stringa[i] == personalizzato[0])
            {
                nvocali++;
            }
        }
    }
}

const char* DividiStringa(char stringa[200], int tipo)
{
    char stringad[100];
    int contatore = 0;
    unsigned long len = strlen(stringa);
    for (int i = 0; i < len; i++)
    {
        if (i%2 == 0 && tipo == 0)
        {
            strcat(stringad, &stringa[i]);
            contatore++;
        }else if(i%2 != 0 && tipo == 1){
            strcat(stringad, &stringa[i]);
            contatore++;
        }
    }
    return stringad;
}

int main(void)
{
    int scelta, nvocali = 0, nconson = 0, npers = 0, apari[100], adispari[100];
    char stringa[200], findchar[1], strpari[100], strdispari[100];

    printf("Inserisci una stringa:\n");
    scanf("%s", stringa);

    do
    {
        scelta = 0;
        printf("Scegliere l'operazione da eseguire:"
               "\n [1] Controlla se la stringa è composta solo da lettere"
               "\n [2] Conta vocali e consonanti"
               "\n [3] Trova e conta carattere personalizzato"
               "\n [4] Dividi i caratteri in posizione parti e dispari"
               "\n [0] Esci dal software\n");
        scanf("%d", &scelta);
        switch (scelta)
        {
        case 1: //Verifica che la stringa contenga solo numeri e lettere.
            if (VerificaStringa(stringa) == 0)
            {
                printf("La stringa contiene solo lettere.\n");
            }
            else
            {
                printf("La stringa contiene caratteri proibiti!\n");
            }
            break;
        case 2:
            ContaLettere(stringa, 0, " ", nvocali, nconson);
            printf("Numero di vocali: %d\n", nvocali);
            printf("Numero di consonanti: %d\n", nconson);
            break;
        case 3:
            scanf("%s", findchar);
            ContaLettere(stringa, 1, findchar, npers, 0);
            printf("Carattere trovato: %d volte\n", npers);
            break;
        case 4:
            printf("Stringa formata dalle lettere in posizione... \nPari: %s Dispari: %s\n", DividiStringa(stringa, 0), DividiStringa(stringa, 1));
            break;
        }
    } while (scelta != 0);
}