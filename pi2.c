#include <omp.h>
#include <stdio.h>

#define NUM_THREADS 4

static long num_steps = 10000000;
double step;
int main(int argc, char **argv) {

  int i;
  double pi;

  step = 1.0 / (double)num_steps;

  omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
  {

    int i, id, nthrds;
    double x, sum = 0.0;

    id = omp_get_thread_num();
    nthrds = omp_get_num_threads();

    printf("Executando o cálculo na thread %d de %d threads\n",
           omp_get_thread_num(), omp_get_num_threads());

    for (i = id; i < num_steps; i += nthrds) {
      x = (i + 0.5) * step;
      sum += 4.0 / (1.0 + x * x);
    }

#pragma omp critical
    { pi += step * sum; }
  }

  printf("%f\n", pi);
  return 0;
}
