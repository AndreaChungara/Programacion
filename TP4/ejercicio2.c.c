/*
Ejercicio 2: Dada una lista A de N números enteros, que puede contener números repetidos, calcular el
	promedio de los números que se encuentran en posiciones impares del arreglo y crear otra lista B conteniendo
	los elementos de A que sean mayores al promedio calculado. Mostrar ambas listas.
*/

#include <stdio.h>
typedef int Tlista[20];

void cargarLista(Tlista, int*);
float promPosImp(Tlista, int);
void mayoresAlProm(Tlista,Tlista,int,int*,float);
void mostrarLista(Tlista,int);

int main(int argc, char *argv[]) {
	Tlista A,B;
	int tam, tam2; 
	float prom;
	cargarLista(A, &tam);
	prom=promPosImp(A,tam);
	printf("\npromedio: %f",prom);//////////////
	mayoresAlProm(A,B,tam,&tam2,prom);
	printf("\nLa lista A es: ");
	mostrarLista(A,tam);
	printf("\nLa lista B es: ");
	mostrarLista(B,tam2);
	return 0;
}
void cargarLista(Tlista A, int *tam){
	int i;
	printf("\nIngrese el tamanio de la lista: ");
	scanf("%d", tam);
	for(i=1;i<=*tam;i++){
		printf("\nIngrese el numero entero de la posicion %d:",i);
		scanf("%d",&A[i]);
	}
}
float promPosImp(Tlista A, int tam){
	int sum=0,i;
	for(i=1;i<=tam;i=i+2){
		sum=sum+A[i];
	}
	return sum/tam;
}
void mayoresAlProm(Tlista A, Tlista B, int tam, int *tam2,float prom){
	int i, cont=0;
	for(i=1;i<=tam;i++){
		if(A[i]>prom){
			cont++;
			B[cont]=A[i];
		}
	}
	*tam2=cont;
}
void mostrarLista(Tlista X, int tam){
	int i;
	for(i=1;i<=tam;i++){
		printf("\n vec[%d]: %d", i,X[i]);
	}
}
