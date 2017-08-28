#include<stdio.h>
#include<omp.h>

int main(int argc, char **argv){

	#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf("hello(%d)", ID);
		printf("world(%d)\n", ID);
	}
	printf("Este é só uma vez!\n");

	return 0;
}
