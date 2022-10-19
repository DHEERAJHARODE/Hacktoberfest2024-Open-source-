/**
 * mersonfufu@gmail.com
 * github.com/mersonfufu
 */

#define _TAM 20
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quick_sort(int *vetor, int inicio, int fim){
	int i, j, pivot, aux;
	i = inicio;
	j = fim;
	pivot = vetor[((i + j) / 2)];
	do {
		while(vetor[i] < pivot) i++;
		while(vetor[j] > pivot) j--;
		if(i <= j){
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	} while(i < j);
	if(inicio < j) quick_sort(vetor, inicio, j);
	if(i < fim) quick_sort(vetor, i, fim);
}

int main(){
	int i, vetor[_TAM];

	srand(time(NULL));
	for(i = 0; i < _TAM; i++)
		vetor[i] = rand() % 99 + 1;

	for(i = 0; i < _TAM; i++)
		printf("%03d ", vetor[i]);

	quick_sort(vetor, 0, _TAM-1);

	for(i = 0; i < _TAM; i++)
		printf("%03d ", vetor[i]);
	return 0;
}
