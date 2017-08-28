#include<stdio.h>
#include<omp.h>

#define NUM_THREADS 4

static long num_steps = 10000000;
double step;
int main (int argc, char** argv){
	
	int i;
	double pi, sum = 0.0;
	
	step = 1.0 / (double) num_steps;
	
	omp_set_num_threads(NUM_THREADS);
	
	#pragma omp parallel
	{	
	
		double x;
		
		printf("Executando o cálculo na thread %d de %d threads\n", omp_get_thread_num(), omp_get_num_threads());
		
		#pragma omp for reduction(+:sum)
		for (i = 0; i < num_steps; i++){
			x = (i + 0.5) * step;
			sum += 4.0 / (1.0 + x * x);
		}
		
	}
	
	pi = step * sum;

	printf("%f\n", pi);
	return 0;
}
