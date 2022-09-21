#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void stringGen(char *dest, size_t length) {
  char charset[] = "0123456789"
                   "abcdefghijklmnopqrstuvwxyz"
                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  while (length-- > 0) {
    size_t index = (double)rand() / RAND_MAX * (sizeof charset - 1);
    *dest++ = charset[index];
  }
  *dest = '\0';
}

int writeToFile(char *filename, char *text) {
  int num;
  FILE *fptr;

  // use appropriate location if you are using MacOS or Linux
  fptr = fopen(filename, "a");

  if (fptr == NULL) {
    printf("Error!");
    exit(1);
  }

  fprintf(fptr, "%s\n", text);
  fclose(fptr);
}

void main(int argc, char **argv) {
  if (argc != 3) {
    printf("Numero di argomenti errati.\n");
    exit(1);
  }

  srand(time(NULL));

  printf("Generazione di %s dati in corso.\n", argv[1]);

  char str[] = {[20] = '\1'};

  for (int i = 0; i < atoi(argv[1]); i++) {
    stringGen(str, sizeof str - 1);
    // puts(str);
    writeToFile(argv[2], str);
  }
}