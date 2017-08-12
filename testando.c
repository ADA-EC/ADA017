#include<math.h>
#include<stdio.h>
#include "raiz.h"

int main(){
	double m;
	printf("Digite um número:\n");
	scanf("%lf", &m);
	printf("Raiz de %lf é: %lf\n", m, raiz(m));
	return 0;
}
