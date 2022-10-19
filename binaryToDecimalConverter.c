/**
 * mersonfufu@gmail.com
 * github.com/mersonfufu
 */

#include <stdio.h>

int main(){
	int i, cont = 0, potencia = 1, decimal = 0;
	char vetor[32] = {0};
	for(i = 0; scanf("%c", &vetor[i]); i++){
		if(vetor[i] == '\n')
			break;
		cont++;
	}
	for(i = cont - 1; i >= 0; i--){
		if(vetor[i] == '1')
			decimal += potencia;
		potencia *= 2;
	}
	printf("%d", decimal);
	return 0;
}