#include<stdio.h>

int main( int ac, char **av)

{

#pragma omp parallel // specify the code between the curly brackets is part of an OpenMP parallel section.

{

	printf("2018BTECS00018\n");

}

return 0;

}
