#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM 50
#define ESC 27

int cargarNotasRandom(int notas[], int dim);
void mostrarNotas(int notas[], int validos);
int cargarNotasManual(int notas[], int validos, int dim);

int main()
{
    srand(time(NULL));

    Pila pilaNotas;
    inicpila(&pilaNotas);
    int notas[DIM];
    int vNotas = 0;
    char opcion;

    do{
        opcionesMenu();
        opcion = getch();

        switch(opcion){
            case 49:
                system("cls");
                vNotas = cargarNotasRandom(notas, DIM);
                break;
            case 50:
                system("cls");
                vNotas = cargarNotasManual(notas, vNotas, DIM);
                break;
            case 51:
                system("cls");
                break;
            case 52:
                system("cls");
                mostrarNotas(notas, vNotas);
                break;
            case 53:
                system("cls");
                printf("La nota mas alta es: %d\n", buscarMayor(notas, vNotas));
                break;
            case 54:
                system("cls");
                printf("La nota mas baja es: %d\n", buscarMenor(notas, vNotas));
                break;
            case 55:
                system("cls");
                printf("El promedio de todas las notas es: %d\n", promedioNotas(notas, vNotas));
                break;
            case 56:
                system("cls");
                copiaArregloEnPila(notas, vNotas, &pilaNotas);
                mostrar(&pilaNotas);
                break;
        }
        system("pause");
        system("cls");
    }while (opcion != ESC);

    return 0;
}

void opcionesMenu(){
    printf("\t \t \t Menu de opciones\n");
    printf("1: Cargar notas random\n");
    printf("2: Cargar notas manual\n");
    printf("3: Ordenar notas\n");
    printf("4: Mostrar notas\n");
    printf("5: Nota maxima\n");
    printf("6: Nota minima\n");
    printf("7: Promedio de notas\n");
    printf("8: Copiar aprobados en Pila\n");
    printf("ESC para salir...\n");

}

int cargarNotasRandom(int notas[], int dim){
    int i = 0;
    for (i = 0; i < dim; i++){
        notas[i] = rand() % 11;
    }
    return i;
}

void mostrarNotas(int notas[], int validos){
    printf("\t \t \t NOTAS CARGADAS\n");
    for (int i = 0; i < validos; i++){
        if (i % 5 == 0)
            printf ("\n");
        printf("%3d | ", notas[i]);
    }
}

int cargarNotasManual(int notas[], int validos, int dim){
    char opcion;
    int nota;

    while (validos < dim && opcion != 27){
        printf("Ingrese una nota: \n");
        scanf("%d", &nota);
        if (nota <= 10 && nota >= 1){
            notas
            [validos] = nota;
            validos++;
        }else
            printf("Nota no valida\n");
        printf("Presione cualquier tecla para cargar otra nota o ESC para salir...\n");
        opcion = getch();
    }
    return validos;
}

int buscarMenor(int arr[], int validos){
    int menor = 10;

    for (int i = 0; i < validos; i++){
        if (arr[i] < menor)
            menor = arr[i];
    }
    return menor;
}

int buscarMayor(int arr[], int validos){
    int mayor = 1;

    for (int i = 0; i < validos; i++){
        if (arr[i] > mayor)
            mayor = arr[i];
    }
    return mayor;
}

int promedioNotas(int arr[], int validos){
    int prom = 0;
    int i;

    for (i = 0; i < validos; i++){
        prom += arr[i];
    }

    return prom / validos;
}

void copiaArregloEnPila(int arr[], int validos, Pila *p){

    for (int i = 0; i < validos; i++){
        if(arr[i] > 6)
            apilar(p, arr[i]);
    }
}
