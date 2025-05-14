#include <stdio.h>
#include <stdlib.h>
#include "mockAlumnos.h"
#include "mocks.h"
#include "gotoxy.h"

#define DIM 50
#define ARCHI_ALUMNOS "alumnos.dat"

int main()
{
    /*for (int i = 0; i < 256; i++){
        color(i);
        printf("\n Color: %d", i);
    }
    system("pause");
    */

    stAlumno alumnos[DIM];
    int vAlumnos = 0;

    vAlumnos = cargaArregloAlumnosAuto(alumnos, DIM);
    printf("Listado de alumnos del arreglo\n");
    mostrarArregloAlumnos(alumnos, vAlumnos);
    printf("\nListado de alumnos del archivo\n");
    arreglo2archivo(alumnos, vAlumnos, ARCHI_ALUMNOS);
    leeArchivo(ARCHI_ALUMNOS);
    printf("\nCantidad de registros: %d", cuentaRegistros(ARCHI_ALUMNOS));
    return 0;
}

void mostrarArregloAlumnos(stAlumno a[], int validos){
    for (int i = 0; i < validos; i++){
        mostrarUnAlumno(a[i]);
    }
}

void arreglo2archivo(stAlumno a[], int v, char nombreArchivo[]){
    //int contId = cuentaRegistros(nombreArchivo);
    int contId = ultimoId(nombreArchivo);
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){
        for (int i = 0; i < v; i++){
            contId++;
            a[i].id = contId;
            fwrite(&a[i], sizeof(stAlumno), 1, archi);
        }
        fclose(archi);
    }
}

void arregloCompleto2archivo(stAlumno a[], int v, char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "ab");
    if(archi){
        fwrite(a, sizeof(stAlumno), v, archi);
        fclose(archi);
    }
}

void leeArchivo(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    if (archi){
        while(fread(&alumno, sizeof(stAlumno), 1, archi) > 0){
            if (alumno.nota >= 6){
                color(15);
                printf("\n Aprobo");
            }else{
                color(4);
                printf("\n No aprobo");
            }
            mostrarUnAlumno(alumno);
        }
        fclose(archi);
    }
}

int cuentaRegistros(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    int cont = 0;
    if(archi){
        fseek(archi, 0, SEEK_END);
        cont = ftell(archi);
        cont = cont / sizeof(stAlumno);
    }
    return cont;
}

int ultimoId(char nombreArchivo[]){
    FILE *archi = fopen(nombreArchivo, "rb");
    stAlumno alumno;
    int ultID;
    if (archi){
        fseek(archi, -1 * sizeof(stAlumno), SEEK_END);
        fread(&alumno, sizeof(stAlumno), 1, archi);
        ultID = alumno.id;
    }
    return ultID;
}

int buscaDniArchivo(char nombreArchivo[], char dni[]){
    int encontrado = 0;
    stAlumno a;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi){
        while (fread(&a, sizeof(stAlumno),1, archi) > 0 && encontrado == 0){
            if (strcmp(dni, a.dni) == 0)
                encontrado = 1;
        }
        fclose(archi);
    }
    return encontrado;
}

stAlumno buscaAlumnoDni(char nombrearchivo[], char dni[]){
    int encontrado = 0;
    stAlumno a;
    FILE *archi = fopen(nombreArchivo, "rb");
    if(archi){
        while (encontrado == 0 && fread(&a, sizeof(stAlumno),1, archi) > 0){
            if (strcmp(dni, a.dni) == 0)
                encontrado = 1;
        }
        fclose(archi);
    }
    return a;
}


