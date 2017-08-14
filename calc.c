#include<stdio.h>
#include"subt.h"
#include"Sum.h"
#include"D.h"
#include"raiz.h"
#include"multiply.h"
#include<math.h>

int main(){

char operacao;
printf("Escolha a operacao desejada:\n a-Soma b-Subtracao c-Multiplicacao d-Divisao e-Raiz quadrada\n\n");

scanf("%c", &operacao);
double a, b, n;

if(operacao == 'a'){
printf("Digite dois numeros:  \n   ");
scanf("%lf %lf", &a, &b);
	printf("  Resultado:  %lf\n   ", Sum(a, b));
}
if(operacao == 'b'){
printf("Digite dois numeros:  \n   ");
scanf("%lf %lf", &a, &b);
	printf("  Resultado:  %lf\n   ", subt(a, b));
}
if(operacao == 'd'){
printf("Digite dois numeros:  \n   ");
scanf("%lf %lf", &a, &b);
	printf("  Resultado:  %lf\n   ", D(a, b));
}
if(operacao == 'c'){
printf("Digite dois numeros:  \n   ");
scanf("%lf %lf", &a, &b);
	printf("  Resultado:  %lf\n   ", mult(a, b));
}
if(operacao == 'e'){
printf("Digite um numero:  \n   ");
scanf("%lf", &n);
	raiz(n);
}
return 0;
}
