#include <omp.h>
#include <stdio.h>

#define NUM_THREADS 4

static long num_steps = 100000000;
double step;
int main(int argc, char **argv) {

    int i;
    double pi, sum = 0.0;

    step = 1.0 / (double)num_steps;

#ifdef _OPENMP
    omp_set_num_threads(NUM_THREADS);
    printf("Executando o cálculo com %d threads\n", NUM_THREADS);
#endif

#pragma omp parallel for reduction(+ : sum)
    for (i = 0; i < num_steps; i++) {
        double x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }

    pi = step * sum;

    printf("%f\n", pi);
    return 0;
}
