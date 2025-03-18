#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"



int main()
{
    char opcion;

    do {
        opcionesMenu();

        opcion = getch();

        switch(opcion){
            case 49:
                system("cls");
                Ejercicio1();
                break;
            case 50:
                system("cls");
                Ejercicio2();
                break;
            case 51:
                system("cls");
                Ejercicio3();
                break;
            case 52:
                system("cls");
                Ejercicio4();
                break;
            case 53:
                system("cls");
                EjercicioClase();
                break;
            case 54:
                system("cls");
                EjercicioFuncionesref();
                break;
            case 27:
                system("cls");
                printf("Usted salio del menu \n");
                break;
            default:
                printf("Opcion incorrecta \n");
                break;
            }
            Sleep(3000);
            system("cls");

    }while (opcion != 27);



return 0;
}


void opcionesMenu(){
    printf("\t \t Elija una opcion \n");
    printf("1: Ejercicio 1 \n");
    printf("2: Ejercicio 2 \n");
    printf("3: Ejercicio 3 \n");
    printf("4: Ejercicio 4 \n");
    printf("5: Ejercicio Clase \n");
    printf("6: Ejercicio Funciones \n");
    printf("ESC: Salir \n");
}

void Ejercicio1(){
    printf("1.- Sumar los elementos de una pila (usar variables enteras): \n");

    int suma = 0;
    Pila p,AUX;

    inicpila(&p);
    inicpila(&AUX);

    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);

    while(!pilavacia(&p)){
        suma = suma + tope(&p);
        apilar(&AUX, desapilar(&p));
    }

    printf("La suma de los elementos de la pila es: %d", suma);
}

void Ejercicio2(){
    printf("2.- Contar los elementos de una pila (usar variables enteras)\n");

    Pila p;
    int sumaElementos = 0;

    inicpila(&p);

    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);

    while(!pilavacia(&p))
    {
    sumaElementos++;
    desapilar(&p);
    }

    printf("La cantidad de elementos que tiene la pila es: %d", sumaElementos);

}

void Ejercicio3(){
    printf("3.- Calcular el promedio de los valores de una pila (usar variables)\n");

    Pila p;
    float promedio;

    inicpila(&p);

    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);

    promedio = (desapilar(&p) + desapilar(&p) + desapilar(&p) + desapilar(&p) ) / 4;

    printf("El promedio de los valores de la pila es: %f", promedio);
}

void Ejercicio4(){
    printf("4.- Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda. \n");

    Pila p;
    int elemento;

    inicpila(&p);

    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);

    printf("ingrese elemento a buscar: \n");
    scanf("%d", &elemento);

    while (!pilavacia(&p))
    {
        if (tope(&p) == elemento){
            printf("El elemento esta en la pila \n");
            break;
    }
    else {
        desapilar(&p);
    }
    }

}

void EjercicioClase(){
    int suma = 0;
    Pila p,AUX;

    inicpila(&p);
    inicpila(&AUX);

    leer(&p);
    leer(&p);
    leer(&p);
    leer(&p);

    while(!pilavacia(&p)){

    if(tope(&p) > 0){
        suma = suma + tope(&p);
        apilar(&AUX, desapilar(&p));
    }
    else
        apilar(&AUX, desapilar(&p));
    }

    printf("La suma de los elementos de la pila es: %d", suma);
}

void EjercicioFuncionesref(){

    Pila origen, destino;

    inicpila(&origen);
    inicpila(&destino);

    cargarPilaRnd(&origen);

    copiaPila(&origen, &destino);

    mostrarPila(&origen);
    mostrar(&destino);

}

void copiaPila(Pila origen, Pila *destino){

    Pila AUX;
    inicpila(&AUX);

    while(!pilavacia(&origen)){
        apilar(&AUX, desapilar(&origen));
    }
    while(!pilavacia(&AUX)){
        apilar(destino,desapilar(&AUX));
    }

}

void cargarPilaRnd(Pila *p){

    for(int i = 0; i < 20; i++){
        apilar(p,rand()%101);
    }
}

void mostrarPila(Pila origen){

    Pila AUX,AUX2;
    inicpila(&AUX);
    inicpila(&AUX2);

    while(!pilavacia(&origen)){
        apilar(&AUX, desapilar(&origen));
    }
    while(!pilavacia(&AUX)){
        printf("%d\n", tope(&AUX));
        apilar(&AUX2,desapilar(&AUX));
    }

}
