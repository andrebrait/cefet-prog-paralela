#include <omp.h>
#include <stdio.h>

#define NUM_THREADS 4

static long num_steps = 100000000;
double step;
int main(int argc, char **argv) {

    int i, nthreads;
    double pi, sum[NUM_THREADS];

    step = 1.0 / (double)num_steps;

    omp_set_num_threads(NUM_THREADS);

#pragma omp parallel
    {

        int i, id = 0, nthrds = 1;
        double x;

#ifdef _OPENMP
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
#endif

        if (id == 0) {
            nthreads = nthrds;
        }

        printf("Executando o cálculo na thread %d de %d threads\n",
               omp_get_thread_num(), omp_get_num_threads());

        for (i = id, sum[id] = 0.0; i < num_steps; i += nthrds) {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }

    for (i = 0, pi = 0.0; i < nthreads; i++) {
        pi += step * sum[i];
    }

    printf("%f\n", pi);
    return 0;
}
