#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, i, j, k;
	double aux, m;
	printf("Digite o tamanho da matriz\n");
	scanf("%d", &n);
	double **matriz = (double**)malloc(n*sizeof(double*));
	for(i = 0; i < n; i++){
	 	matriz[i] = (double*)malloc((n+1)*sizeof(double));
	}
	for(i = 0; i < n; i++){
		printf("Digite os elementos da linha %d \n", i);
		for(j = 0; j < n+1; j++){
			scanf("%lf", &matriz[i][j]);
		}
	}
	for(i = 0; i < n; i++){ //garante que não tem zeros na diagonal principal
		if(matriz[i][i] == 0){
			if(i == 0){
				for(j = 0; j <= n; j++){
					aux = matriz[i][j];
					matriz[i][j] = matriz[i+1][j];
					matriz[i+1][j] = aux;
				}
			}else{
				for(j = 0; j <= n; j++){
					aux = matriz[i][j];
					matriz[i][j] = matriz[i-1][j];
					matriz[i-1][j] = aux;
				}
			}
		}
	}
	for(j = 0; j < n; j++){ //tenta zerar os outros elementos
		for(i = 0; i < n; i++){
			if(i != j){
				m = matriz[i][j]/matriz[j][j];
				for(k = 0; k <= n; k++){
					matriz[i][k] = matriz[i][k] - m*matriz[j][k];
				}
			}
		}
	}
	for(i = 0; i < n; i++){ //imprime os resultados
		printf("%lf\n", matriz[i][n]/matriz[i][i]);
	}

	free(matriz);
	return 0;
} 
