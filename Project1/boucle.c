#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define CARRE(x) x * x

int main()
{

	int nb = 5;
	printf("le nombre est %d\n", nb);
	int a = CARRE(nb);
	printf("le carre du nombre est %d\n", a);
	int b = CARRE((nb + 1));
	printf("le carre du nombre est %d", b);
}