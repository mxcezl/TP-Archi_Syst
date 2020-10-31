#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constante de préprocesseur
#define NB_POINTS_MAX 100
#define DIM 3

// Prototypes
int saisir_points(double pts[NB_POINTS_MAX][DIM]);
void init_som(double som[DIM]);
void calc_pvec(double pvec[DIM], double v1[DIM], double v2[DIM]);
void calculer_som(int nbpts, double pts[NB_POINTS_MAX][DIM], double som[DIM]);
double calculer_aire(double som[DIM]);

/* ----------------------------------------------- */
// Fonction demandant à l'utilisateur le nombre de points à saisir
// Et demande à l'utilisateur de renseigner les valeurs de ces points
int saisir_points(double pts[NB_POINTS_MAX][DIM]) {
    int nbpts, i;
    printf("\nNombre de points du polygone ? ");
    scanf("%d", &nbpts);
    for (i = 0; i < nbpts; i = i + 1) {
        printf("\n Point No %d >", i);
        scanf("%lf%lf%lf", &pts[i][0], &pts[i][1], &pts[i][2]);
    }
    return nbpts;
}

/* ----------------------------------------------- */
// Fonction d'initialisation du tableau som
void init_som(double som[DIM]) {
    int i;
    for(i = 0; i < DIM; i++) {
        som[i] = 0.0;
    }
}

/* ----------------------------------------------- */
// Fonction qui remplit le tableau pvec
void calc_pvec(double pvec[DIM], double v1[DIM], double v2[DIM]) {
    pvec[0] = v1[1] * v2[2] - v1[2] * v2[1];
    pvec[1] = -(v1[0] * v2[2] - v1[2] * v2[0]);
    pvec[2] = v1[0] * v2[1] - v1[1] * v2[0];
}

/* ----------------------------------------------- */
// Fonction qui calcule et renseigne le tableau som
void calculer_som(int nbpts, double pts[NB_POINTS_MAX][DIM], double som[DIM]) {
    int i, k;
    double pvec[DIM], v1[DIM], v2[DIM];

    for (i = 1; i < nbpts - 1; i = i + 1) {
        for (k = 0; k < DIM; ++k) {
            v1[k] = pts[i][k] - pts[0][k];
            v2[k] = pts[i + 1][k] - pts[0][k];
        }

        calc_pvec(pvec, v1, v2);

        for (k = 0; k < DIM; ++k) {
            som[k] = som[k] + pvec[k];
        }
    }
}

/* ----------------------------------------------- */
// Fonction qui calcule l'aire d'un polynome
double calculer_aire(double som[DIM]) {
    return 0.5 * sqrt(som[0] * som[0] + som[1] * som[1] + som[2] * som[2]);
}

/* ----------------------------------------------- */
// Fonction principale
// Essayer avec 4 points :
// - 0 0 0
// - 0 2 0
// - 2 2 0
// - 2 0 0
// Devrait retourner : 4.00
int main(void) {
    double pts[NB_POINTS_MAX][DIM], som[DIM];

    int nbpts = saisir_points(pts);
    init_som(som);
    calculer_som(nbpts, pts, som);

    double aire = calculer_aire(som);

    printf("\nL’aire de votre polygone est : %lf\n", aire);
    return 0;
}
