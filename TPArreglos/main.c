#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define DIM 10

int main()
{
    Pila p;
    inicpila(&p);
    int numeros[DIM];
    int vNumeros = 0;

    vNumeros = cargarArreglo(numeros, DIM);
    mostrarArreglo(numeros, vNumeros);
    printf("La suma es: %d\n", sumaElementos(numeros, vNumeros));

    copiaArregloEnPila(numeros, vNumeros, &p);
    mostrar(&p);

    return 0;
}


int cargaArregloRandom(int arr[], int dim){
    int i;
    for (i = 0; i < dim; i++){
        arr[i] = rand() % 1000;
    }
    return i;
}

void mostrarArreglo(int arr[], int validos){
    for (int i = 0; i < validos; i++){
        if(i % 7 == 0)
            printf("\n");
        printf("%5d", arr[i]);
    }
    printf("\n");
}

int cargarArreglo(int arr[], int dim){
    int i,dato;
    for(i = 0; i < dim; i++){
        printf("Ingrese un numero entero: \n");
        scanf("%d", &dato);
        arr[i] = dato;
    }
    return i;
}

int sumaElementos(int arr[], int validos){
    int suma = 0;
    for (int i = 0; i < validos; i++){
        suma += arr[i];
    }
    return suma;
}

void copiaArregloEnPila(int arr[], int validos, Pila *p){
    for (int i = 0; i < validos; i++){
        apilar(p, arr[i]);
    }
}



