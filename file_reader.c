#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *aspell, *wikipedia;

char *compare_with_corpora (char *input_word) {
    char *correction = malloc(2048);
    char *word = malloc(2048);
    /* Appends $ to "word" */
    sprintf(word, "$%s", input_word);
    printf("%s\n", word);

    // while(1)
    //     if(fscanf(aspell, "%s\n", correction) == EOF)
    //         break; 

    strcpy(correction, word);
    return correction;
}

int main (int argc, char* argv[]) {
    /*
    * Takes word as imput.
    * Compares it with all the words starting with $ in aspell.dat, wikipedia.dat
    */
    if (argv[1] == NULL) {
        printf("Usage : ./file_reader word");
        return 1;
    }

    char *word = (char *) argv[1]; 
    char *correction = malloc(2048);

    aspell = fopen("corpora/aspell.dat", "r");
    wikipedia = fopen("corpora/wikipedia.dat", "r");

    correction = compare_with_corpora(word);

    printf("%s\n", correction);

    return 0;
}