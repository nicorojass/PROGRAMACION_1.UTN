#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char nombre[30];
    char apellido[30];
    char dni[9];
    int legajo;
} stAlumno;

void mostrarUnAlumno(stAlumno a);
stAlumno cargarUnAlumno();

#endif // STALUMNO_H_INCLUDED
