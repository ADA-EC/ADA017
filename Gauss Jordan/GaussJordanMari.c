#include<stdio.h>
#include<stdlib.h>

void Sistema(int l, int c){
	int w,j,b,k;
	double x,aux;
	double **matriz = (double**)malloc(l * sizeof(double*));

	// Receber os valores da matriz
	for(b=0; b<l; b++) 
		matriz[b] = (double*)malloc(c * sizeof(double));
		printf("Digite os valores dos coeficientes de uma linha sistema e o valor da soma deles, respectivamente: \n");
		for(b=0; b<l; b++){
			printf("Essa e a linha %d", b);				
			printf("\n");
			for(j=0; j<c; j++){
	  		scanf("    %lf" ,&matriz[b][j]);
			}
	     }
	
	printf("O sistema linear que sera resolvido e este:\n\n");
	for(b=0; b<l; b++){
		for(j=0; j<c; j++){
			printf("      %lf      ", matriz[b][j]); 
		}
		printf("\n");
	}
		
	// Checar se na diagonal principal nao ha zeros, se houver linhas serao invertidas
	for(b=0; b<l; b++){
		if(matriz[b][b] == 0){
			if(b == l){
				for(j=0; j<c; j++){
					w = matriz[b][j];
					matriz[b][j] = matriz[b-1][j];
					matriz[b-1][j] = w;
				}	
			}
			else{
				for(j=0; j<c; j++){
					w = matriz[k][j];
					matriz[k][j] = matriz[k+1][j];
					matriz[k+1][j] = w;
				}
			}
		}
	}
		
	// Escalonamento (a mágica acontece) 
	for(k=0; k<(l-1); k++){ 
		for(b=(k+1),w=1; b<l; b++,w++){ 
			x = (-matriz[b][k]) / matriz[b-w][k];
			for(j=k; j<c; j++){
				matriz[b][j] = matriz[b][j] + (x*matriz[b-w][j]);
			}
		}
	}

	for(k=(l-1); k>=0; k--){ 
		for(b=(k-1),w=1; b>=0; b--,w++){ 
			x = (-matriz[b][k]) / matriz[b+w][k];
			for(j=(c-1); j>=0; j--){
				matriz[b][j] = matriz[b][j] + (x*matriz[b+w][j]);
			} 
		}
	}
	
	// Resultado (na diagonal principal so havera o numero um)
	for(b=0; b<l; b++){ 
		aux = matriz[b][b];
		matriz[b][b] = matriz[b][b]/aux;
		matriz[b][c-1] = matriz[b][c-1]/aux;			
	}
	printf("O sistema linear apos ser resolvido e este:\n\n");
	for(b=0; b<l; b++){
		for(j=0; j<c; j++){
			printf("      %lf      ", matriz[b][j]); 
		}
		printf("\n");
	}
		
	printf("Os coeficientes das incognitas sao:\n\n");
	for(b = 0; b < l; b++){ 
		printf("      %lf\n", matriz[b][c-1]);
	} 

	free(matriz);
}
				

		
int main(){
	int a;
	
	printf("Digite o numero de variaveis do sistema:    ");
	scanf("%d" , &a);
	
	Sistema(a,a+1);
}
