#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "stAlumno.h"
#include "mocks.h"

#define ESC 27
#define DIM 100

int main()
{
    stAlumno alumnos[100];
    int vAlumnos = 0;
    vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);

    // vAlumnos = cargaArregloAlumnos(alumnos, vAlumnos, DIM);
    muestraArregloAlumnos(alumnos,vAlumnos);

    return 0;
}

int cargaArregloAlumnos(stAlumno a[], int validos, int dim){
    char opcion = 0;
    int i = validos;

    while (validos < dim && opcion != ESC){
        a[i] = cargarUnAlumno();
        i++;
        printf("Presione cualquier tecla para seguir cargando o ESC para salir...\n");
        opcion = getch();
        system("cls");
    }

    return i;
}

void muestraArregloAlumnos(stAlumno a[], int validos){
    for(int i = 0; i < validos; i++){
        mostrarUnAlumno(a[i]);
    }
}









