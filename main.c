#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*//Exercice 1
    int c;
    while((c = getchar()) != '\n') {
        putchar(c);
    }
    */

    /* //Exercice 2
    int curr;
    int last;
    while((curr = getchar()) != '\n') {
        if(!(last == ' ' && curr == ' ')){
            putchar(curr);
            last = curr;
        }
    }
    */

    /* //Exercice 3
    int curr;
    int last;
    while((curr = getchar()) != '\n') {
        if((curr == ' ' || curr == '\t' || curr == '\n') && last != ' ') {
            putchar('\n');
        } else if(!(last == ' ' && curr == ' ')){
            putchar(curr);
            last = curr;
        }
    }
    */

    /* //Exercice 4
    int c;
    int countE = 0, countTot = 0;
    while((c = getchar()) != '\n') {
        if(c == 'e') countE++;
        if(c == '.' || c == '?' || c == '!') countTot++;
    }
    printf("\nNombre d'occurences de 'e' : %d\nNombre d'occurences de '.', '?' et '!' : %d", countE, countTot);
    */

    //Exercice 5
    printf("Entrer un caractere : ");
    int c = getchar();
    printf("Caractere : %c (%d en ASCII)\n", c, c);


    /* // Exercice 6
    int c = getchar() - 'A' + 1;
    putchar('\n'); // Affichage
    int i,j;
    // Affiche le haut du triangle
    for(i = 1; i <= c; i++) {
        for(j = 1; j <= i; j++) {
            printf("* ");
            //putchar('*');
            //putchar(' ');
        }
        putchar('\n');
    }

    // Affiche le bas du triangle
    for(i = c; i > 1; i--) {
        for(j = 1; j < i; j++) {
            printf("* ");
            //putchar('*');
            //putchar(' ');
        }
        putchar('\n');
    }
    */

    /* //Exercice 7
    const int larg = 3;
    const int haut = 4;
    printf("Entrez L ou I : ");
    int c = getchar();
    if(c != 'L' && c != 'I') {
        printf("Erreur, entrez L ou I.");
    } else {
        int i,j;
        for(i = 0; i < haut; i++) { // Ligne
            for(j = 0; j < larg; j++) { // Colonne
                if(c == 'I' && (i == 0 || i == (haut-1))) { // Haut ou bas du I
                    putchar('*');
                } else if (c == 'I') { /// Corps du I
                    if(j == larg/2) putchar('*');
                    else putchar(' ');
                } else if (c == 'L' && i == (haut-1)) { // Bas du L
                    putchar('*');
                }
            }
            if(c == 'L' && i != (haut-1)) putchar('*'); // Corps du L
            putchar('\n');
        }
    }
    */
    return 0;
}
