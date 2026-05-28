#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
  double D = b*b - 4*a*c;
  if (D < 0) return 0;
  if (D == 0) {
    *x1 = -b/(2*a);
    *x2 = -b/(2*a);
    return 1;
  }
  *x1 = (-b - sqrt(D)) / (2*a);
  *x2 = (-b + sqrt(D)) / (2*a);
  return 2;
  
}

int main(void)
{
  double a, b, c;
  scanf("%lf %lf %lf", &a, &b, &c);
  double* xf = (double*)malloc(sizeof(double));
  double* xs = (double*)malloc(sizeof(double));
  *xf = 0.0; *xs = 0.0;
  int roots = solve_quadratic(a, b, c, xf, xs);

  if (roots == 0) {
    printf("No real roots\n");
    return 0;
  }
  printf("%f ", *xf);
  printf("%f", *xs);
  free(xf);
  free(xs);
  return 0;
}
