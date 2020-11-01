#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  double pts[100][3], pvec[3], som[3], v1[3], v2[3];
  int nbpts, i, k;
  double aire;
  printf("\nNombre de points du polygone ? ");
  scanf("%d", & nbpts);
  for (i = 0; i < nbpts; i = i + 1) {
    printf("\n Point No %d >", i);
    scanf("%lf%lf%lf", & pts[i][0], & pts[i][1], & pts[i][2]);
  }
  som[0] = som[1] = som[2] = 0.0;
  for (i = 1; i < nbpts - 1; i = i + 1) {
    for (k = 0; k < 3; ++k) {
      v1[k] = pts[i][k] - pts[0][k];
      v2[k] = pts[i + 1][k] - pts[0][k];
    }
    pvec[0] = v1[1] * v2[2] - v1[2] * v2[1];
    pvec[1] = -(v1[0] * v2[2] - v1[2] * v2[0]);
    pvec[2] = v1[0] * v2[1] - v1[1] * v2[0];
    for (k = 0; k < 3; ++k) {
      som[k] = som[k] + pvec[k];
    }
  }
  aire = 0.5 * sqrt(som[0] * som[0] + som[1] * som[1] + som[2] * som[2]);
  printf("\nL’aire de votre polygone est : %lf\n", aire);
  return 0;
}
