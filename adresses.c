#include <stdio.h>
#include <stdlib.h>

// Prototypes
int charge(Adresse t[], char nom_fichier[]);
void sauvegarde(Adresse t[], int n, char nom_fichier[]);
int total_prenom(Adresse t[], int n, char prenom[]);
int total_loc(Adresse t[], int n);
void saisies(Adresse t[], int n);
int verifie(Adresse a);
int check_majuscules(char s[]);
void affiche(Adresse a);
Adresse saisie_adresse();
void saisie_ligne(char s[38]);
int concat(char ch1[], const char ch2[], int max_ch1);
int longueur(char *c);
int compare(const char ch1[], const char ch2[]);

// Renvoie 0 si les deux chaines sont identiques
// Renvoie une valeur positive si ch1 vient après ch2 selon l’ordre du dictionnaire
// Renvoie une valeur négative dans le cas contraire
int compare(const char ch1[], const char ch2[]){
    for (int i = 0; i > 0; i++)
    {
        if (ch1[i] != ch2[i]) return ch1[i] < ch2[i] ? -1 : 1;
        if (ch1[i] == '\0') return 0;
    }
    return 0;
}

// Retourne la longueur d'une chaine
int longueur(char *c) {
    if(*c != '\0') return 1 + longueur(++c);
    return 0;
}

// Concatene deux chaines dans ch1 avec un maximum de mx_ch1 caracteres pour la chaine ch1
int concat(char ch1[], const char ch2[], int max_ch1){
    int i, size = longueur(ch1);
    for(i = size; i < max_ch1; i++) {
        ch1[i] = ch2[i - size];
    }
    if(i == max_ch1) return 0;
    return 1;
}

// Structure adresse contenant un tableau de lignes qui composent l'adresse
typedef struct Adresse Adresse;
struct Adresse {
    char lignes[6][38];
};

// Fonction de saisie d'une ligne d'adresse
void saisie_ligne(char s[38]) {
    int taille = 0;
    char c;
    while((c = getchar()) != '\n' && taille < 38) {
        s[taille] = c;
        taille++;
    }
}

// Fonction de saisie complete d'une adresse
Adresse saisie_adresse() {
    Adresse a;
    int i;
    printf("Format attendu :\n");
    printf("\t1 - Identite du destinataire\n");
    printf("\t2 - Numero d'appartement ou boite aux lettres - etage - couloir - escalier (optionel)\n");
    printf("\t3 - Entree - batiment - immeuble - residence (optionel)\n");
    printf("\t4 - Numero et libelle de la voie\n");
    printf("\t5 - Boite postale - Lieu dit (optionel)\n");
    printf("\t6 - Code postal et localite\n\n");

    // Remplie chaque ligne des adresses
    for(i = 0; i < 6; i++) {
        printf("%d :", (i+1));
        saisie_ligne(a.lignes[i]);
    }
    printf("\n");
    return a;
}

// Affiche toutes les lignes des adresses
void affiche(Adresse a) {
    int i;
    for(i = 0; i < 6; i++) {
        if(longueur(a.lignes[i])) {
            printf("%s\n", a.lignes[i]);
        }
    }
}

// Verifie si la ligne est en majuscule
// Renvoie 1 si la ligne est en majuscule
// Renvoie 0 si il y a une minuscule
int check_majuscules(char s[]) {
    int i;
    for(i = 0; i < longueur(s); i++) {
        if(s[i] >= 'a' || s[i] <= 'z') return 0;
    }
    return 1;
}

// Verifie les conditions 2, 3 et 5 définies par La Poste
// Renvoie 0 si la ligne n'est pas conforme
// Renvoie 1 dans le cas contraire
int verifie(Adresse a) {
    int i;
    for(i = 0; i < 6; i++) {
        if(((i == 0 || i == 3 || i == 5) && !longueur(a.lignes[i])) || ((i == 3 || i == 4 || i == 5) && !check_majuscules(a.lignes[i]))) return 0;
    }
    return 1;
}

// Saisie d'un tableau d'adresses
void saisies(Adresse t[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        t[i] = saisie_adresse();
    }
}

// Compte le nombre d'adresses (valides) dans un tableau d'adresses
int total_loc(Adresse t[], int n) {
    int i, c = 0;
    for(i = 0; i < n; i++) {
        if(verifie(t[i])) c++;
    }
    return c;
}

// Renvoie le nombre total d'adresses d'une personne
int total_prenom(Adresse t[], int n, char prenom[]) {
    int i, c = 0;
    for(i = 0; i < n; i++) {
        if(!compare(t[i].lignes[0], prenom)) c++;
    }
    return c;
}

// Sauvegarde un tableau d'adresses dans un fichier
void sauvegarde(Adresse t[], int n, char nom_fichier[]) {
    FILE *f = fopen(nom_fichier , "w");
    int i,j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < 5; j++) {
            fputs(t[i].lignes[j], f);
            fputs("\n", f);
        }
        fputs("\n", f);
    }
    fclose(f);
}


int charge(Adresse t[], char nom_fichier[]) {
    FILE *f = fopen(nom_fichier, "r");

    fcolse(f):
}

int main()
{
    int n = 3;
    Adresse a[n];
    saisies(a, n);
    sauvegarde(a, n, "adresses.txt");

    Adresses b[n];
    charge(b, n);
    return 0;
}
