#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#define DIM 10
#define ESC 27

void opcionesMenu();
int cargaArregloRandom(int arr[], int dim);
void mostrarArreglo(int arr[], int validos);
int cargarArreglo(int arr[], int dim);
int sumaElementos(int arr[], int validos);
void copiaArregloEnPila(int arr[], int validos, Pila *p);
int cargaArregloFloat(float arr[], int dim);
void mostrarArregloFloat(float arr[], int validos);
float sumaArregloF(float arr[], int validos);
int buscarElemento(int arr[], int validos,int dBuscado);
int arregloCapicua(int arr[], int validos);
void intercambio(int *a, int *b);
int buscarPosMenor(int arr[], int validos, int inicio);
void ordenaPorSeleccion(int arr[], int validos);
int insertaOrdenado(int arr[], int v, int dim, int dato);

int main()
{
    char opcion;
    Pila p;
    inicpila(&p);
    int numeros[DIM];
    int vNumeros = 0;
    float numerosFloat[DIM];
    int vNumerosFloat = 0;
    char caracteres[DIM];
    int matrizNumeros[3][3];

    do {
        opcionesMenu();
        opcion = getch();

        switch(opcion){
        case 49:
            system("cls");
            vNumeros = cargaArregloRandom(numeros, DIM - 1);
            break;
        case 50:
            system("cls");
            mostrarArreglo(numeros, vNumeros);
            break;
        case 51:
            system("cls");
            vNumeros = cargarArreglo(numeros, DIM);
            break;
        case 52:
            system("cls");
            printf("La suma de los elementos del arreglo es: %d\n", sumaElementos(numeros, vNumeros));
            break;
        case 53:
            system("cls");
            copiaArregloEnPila(numeros, vNumeros, &p);
            mostrar(&p);
            break;
        case 54:
            system("cls");
            vNumerosFloat = cargaArregloFloat(numerosFloat, DIM);
            break;
        case 55:
            system("cls");
            mostrarArregloFloat(numerosFloat, vNumerosFloat);
            break;
        case 56:
            system("cls");
            printf("Suma de FLOATS: %.2f\n", sumaArregloF(numerosFloat, vNumerosFloat));
            break;
        case 57:
            system("cls");
            int datoABuscar;
            printf("Ingrese dato a buscar: \n");
            scanf("%d", &datoABuscar);
            if (buscarElemento(numeros, vNumeros, datoABuscar) == 1)
                printf("Elemento encontrado\n");
            else
                printf("Elemento no se encuentra en el arreglo\n");
        case 97:
            system("cls");
            if(arregloCapicua(numeros, vNumeros) == 1)
                printf("El arreglo es capicua\n");
            else
                printf("El arreglo no es capicua\n");
            break;
        case 98:
            system("cls");
            ordenaPorSeleccion(numeros, vNumeros);
            break;
        case 99:
            system("cls");
            vNumeros = insertaOrdenado(numeros, vNumeros, DIM, 3);
            break;
        case 100:
            system("cls");
            ordenaPorInsercion(numeros, vNumeros);
            break;
        case 101:
            system("cls");
            cargarMatriz(3, 3, matrizNumeros);
            break;
        case 102:
            system("cls");
            mostrarMatriz(3, 3, matrizNumeros);
            break;
        }
        printf("\n");
        system("pause");
        system("cls");
    }while (opcion != ESC);

    return 0;
}

void opcionesMenu(){
printf("\t \t \t Menu de opciones\n");
printf("1: Cargar arreglo de INT random\n");
printf("2: Mostrar arreglo de INT\n");
printf("3: Cargar arreglo de INT manual\n");
printf("4: Sumar elementos del arreglo INT\n");
printf("5: Copiar los elementos del ARREGLO en una Pila\n");
printf("6: Cargar arreglo de FLOAT manual\n");
printf("7: Mostrar arreglo de FLOAT\n");
printf("8: Sumar elementos del arreglo FLOAT\n");
printf("9: Buscar elemento del arreglo INT\n");
printf("a: Arreglo capicua\n");
printf("b: Ordernar arreglo por seleccion\n");
printf("c: Insertar dato en arreglo ordenado\n");
printf("d: Ordenar arreglo por insercion\n");
printf("e: Cargar matriz INT \n");
printf("f: Mostrar matriz INT \n");
printf("ESC para salir...\n");
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

int cargaArregloFloat(float arr[], int dim){
    int i = 0;
    float dato;
    for(i = 0; i < dim; i++){
        printf("Ingrese un valor float: \n");
        scanf("%f", &dato);
        arr[i] = dato;
    }
    return i;
}

void mostrarArregloFloat(float arr[], int validos){

    for (int i = 0; i < validos; i++){
        if (i % 7 == 0)
            printf("\n");
        printf("%.2f |", arr[i]);
    }
}

float sumaArregloF(float arr[], int validos){
    float suma = 0;
    for(int i = 0; i < validos; i ++){
        suma += arr[i];
    }
    return suma;
}

int buscarElemento(int arr[], int validos,int dBuscado){
    int encontrado = 0;

    for (int i = 0; i < validos; i++){
        if (arr[i] == dBuscado)
            encontrado = 1;
    }
    return encontrado;
}

int arregloCapicua(int arr[], int validos){
    int contador = 0;
    int capicua = 0;
    int ultimo = validos - 1;

    for (int i = 0; i < validos; i++){
        if (arr[i] == arr[ultimo])
        {
            contador++;
        }
        ultimo--;
    }
    if (contador == validos){
        capicua = 1;
    }
    return capicua;
}

void intercambio(int *a, int *b){
    int aux;
    aux = *a;
    *a = *b;
    *b = aux;
}

int buscarPosMenor(int arr[], int validos, int inicio){
    int posMenor = -1;
    if (validos > 0){
        posMenor = inicio;
    }
    for(int i = inicio; i < validos; i++){
        if (arr[i] < arr[posMenor]){
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenaPorSeleccion(int arr[], int validos){
    int posMenor;

    for(int i = 0; i < validos - 1; i++){
        posMenor = buscarPosMenor(arr, validos, i);
        intercambio(&arr[i], &arr[posMenor]);
    }

}

int insertaOrdenado(int arr[], int v, int dim, int dato){
    int validos = -1;
    int i = v - 1;
    if (v < dim){
        while (i >= 0 && dato < arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = dato;
        validos = v + 1;
    }
    return validos;
}

void insertaOrdenado2(int arr[], int v, int dato){
    int i = v - 1;
        while (i >= 0 && dato < arr[i]){
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = dato;
}

void ordenaPorInsercion(int arr[], int validos){
    for(int i = 0; i < validos; i++){
        insertaOrdenado2(arr, i, arr[i+1]);
    }
}

void cargarMatriz(int fil, int col, int m[fil][col]){
    for(int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            m[i][j] = rand() % 100;
        }
    }
}
void mostrarMatriz(int fil, int col, int m[fil][col]){
    int cont = 0;
    for(int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
                if(cont % 3 == 0)
                    printf("\n");
            printf("%4d |", m[i][j]);
            cont++;
        }
    }
}

void cargarMatrizManual(int fil, int col, int m[fil][col]){

}


