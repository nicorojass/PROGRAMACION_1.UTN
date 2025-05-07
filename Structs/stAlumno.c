#include "stAlumno.h"

void mostrarUnAlumno(stAlumno a){
    printf("ID: %d\n", a.id);
    printf("Nombre: %s\n", a.nombre);
    printf("Apellido: %s\n", a.apellido);
    printf("DNI: %s\n", a.dni);
    printf("Legajo: %d\n", a.legajo);
    printf("--------------------------------------------\n");
}

stAlumno cargarUnAlumno(){
    static int id = 0;
    id++;
    stAlumno a;
    a.id = id;
    printf("Nombre: \n");
    gets(a.nombre);
    printf("Apellido: \n");
    gets(a.apellido);
    printf("DNI: \n");
    gets(a.dni);
    printf("Legajo: \n");
    scanf("%d", &a.legajo);
    fflush(stdin);

    return a;
}

