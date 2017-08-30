#include <stdio.h>
#include <stdlib.h>


void printMatrix(double** matriz, int tamanho){
    int i, j;
    for(i=0; i<tamanho; i++){
        for(j = 0; j<=tamanho; j++){
            printf("%lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

void TrocarLinhas(double** matriz, int n, int linha, int linha2){
    int j;
    double aux;
    for(j=0; j<=n; j++){
        aux = matriz[linha][j];
        matriz[linha][j] = matriz[linha2][j];
        matriz[linha2][j] = aux;
    }
}

void Divisao(double** matriz, int n, int linha, double fator){
    int j;
        for(j=0; j<=n; j++){
            matriz[linha][j] = matriz[linha][j]/fator;
        
	}
}

void Subtracao(double** matriz, int n, int linha, int linha2, double fator){
	int j;
	for ( j=0; j<=n; j++){
		matriz[linha][j] = matriz[linha][j] - fator*matriz[linha2][j];
	}
}
	



int main(){
    
    int i, j, n ;
        
    printf("Digite o tamanho da sua matriz : \n ");
    scanf("%d", &n);

    printf ("Digite a sua matriz MxN : \n ");
    double **Matriz = (double**)malloc(n*sizeof(double*));
    if(Matriz == NULL) {
        return -1;
    }
    for(i=0; i<n; i++){
        Matriz[i] = (double*)malloc((n+1)*sizeof(double));
        if(Matriz[i] == NULL) {
            return -1;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%lf", &(Matriz[i][j]));
        }
    }
    for(i=0; i<n; i++){
        scanf("%lf", &(Matriz[i][n]));
    }

for(j=0; j<n; j++){
	if(Matriz[j][j] == 0){
		for(i=j+1; i<n; i++){
			if(Matriz[i][j] != 0){
				TrocarLinhas(Matriz, n, j, i);
				break;
			}	
		}
	}
	Divisao(Matriz, n, j, Matriz[j][j]);

	for(i=0; i<n; i++){
		if(i != j){ 
			Subtracao(Matriz, n, i, j, Matriz[i][j]);
		}
	}	
}
	
	for(i=0; i<n; i++){
		printf("%lf ", Matriz[i][n]);
	}
	
	
    for(i=0; i<n; i++){
        free(Matriz[i]);
    }
    free(Matriz);    
}
