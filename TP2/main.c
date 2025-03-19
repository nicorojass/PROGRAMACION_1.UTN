#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include <time.h>

#define ESC 27

void cargarPila(Pila *p, char s[]);
void mostrarPila(Pila p);
void pasarPila(Pila *p, Pila *destino);
void pasarPilaEnOrden(Pila *p, Pila *destino);
int buscarMenor(Pila *p);
void pasarElementosOrdenados(Pila *p, Pila *destino);
void opcionesMenu();
void ordenarPilaPorSeleccion(Pila *p);
int buscarEnPila(Pila p, int aBuscar);
int sumarAnteriorYTope(Pila p);

int main()
{
    srand(time(NULL)); // para que los randoms varíen.

    char opcion;
    Pila p, p2;
    inicpila(&p);
    inicpila(&p2);

    do{
        opcionesMenu();
        opcion = getch();
        switch(opcion){
            case 49:
                system("cls");
                cargarPila(&p, "Cargue un numero:");
                break;
            case 50:
                system("cls");
                printf("Pila 1\n");
                mostrarPila(p);
                printf("\n-------------------------\n");
                printf("Pila 2\n");
                mostrarPila(p2);
                break;
            case 51:
                system("cls");
                pasarPila(&p, &p2);
                break;
            case 52:
                system("cls");
                pasarPilaEnOrden(&p, &p2);
                break;
            case 53:
                system("cls");
                pasarElementosOrdenados(&p, &p2);
                break;
            case 54:
                system("cls");
                ordenarPilaPorSeleccion(&p);
                break;
            case 55:
                system("cls");
                printf("Ingrese valor a buscar: \n");
                int valorABuscar;
                scanf("%d", &valorABuscar);
                if(buscarEnPila(p, valorABuscar) == 1)
                {
                    printf("El nro. se encuentra en la lista\n");
                }
                else
                    printf("El nro. no se encuentra en la lista\n");
                break;
            case 56:
                system("cls");
                printf("La suma del tope y anterior es: %d\n", sumarAnteriorYTope(p));
                break;
            case 57:
                system("cls");
                int numAContar;
                printf("Ingrese un numero:\n");
                scanf("%d", &numAContar);
                printf ("%d" ,contarDigitos(numAContar));
                break;
        }
        system("pause");
        system("cls");
    }while (opcion != ESC);



    return 0;
}


void cargarPila(Pila *p, char s[]){
    int elemento;
    char cont;

    do{
        printf("%s\n", s);
        scanf("%d", &elemento);

        apilar(p, elemento);

        printf("Presione ESC para salir o cualquier tecla para seguir cargando\n");
        cont = getch();

    }while (cont != ESC);
}

void mostrarPila(Pila p){

    Pila AUX;
    inicpila(&AUX);
    int cont = 0;
    while(!pilavacia(&p)){
        apilar(&AUX, desapilar(&p));
    }
    while(!pilavacia(&AUX)){
        if(cont % 7 == 0)
            printf("\n");
        printf("%4d | ", tope(&AUX));
        desapilar(&AUX);
        cont++;
    }

}

void pasarPila(Pila *p, Pila *destino){
    while(!pilavacia(p)){
        apilar(destino, desapilar(p));
    }
}

void pasarPilaEnOrden(Pila *p, Pila *destino){
    Pila AUX;
    inicpila(&AUX);

    pasarPila(p,&AUX);
    pasarPila(&AUX,destino);
}

int buscarMenor(Pila *p){
    Pila AUX;
    inicpila(&AUX);
    int menor;

    if (!pilavacia(p)){
        menor = desapilar(p);

        while(!pilavacia(p)){
            if(tope(p) < menor){
                apilar(&AUX,menor);
                menor = desapilar(p);
            }
            else
                apilar(&AUX, desapilar(p));
        }
        pasarPila(&AUX, p);
    }
    return menor;
}

void pasarElementosOrdenados(Pila *p, Pila *destino){

    while(!pilavacia(p)){
        apilar(destino, buscarMenor(p));
    }

}

void opcionesMenu(){
    printf("\t \t \t <<<<<< Menu de opciones >>>>>>\n");
    printf("1: Cargar pila\n");
    printf("2: Mostrar pila\n");
    printf("3: Pasar pila\n");
    printf("4: Pasar pila en orden\n");
    printf("5: Crear pila de elementos ordenados\n");
    printf("6: Ordenar pila por seleccion\n");
    printf("7: Buscar un valor en la pila\n");
    printf("8: Sumar TOPE y ANTERIOR\n");
    printf("9: \n");
    printf("ESC para salir...\n");
}

void ordenarPilaPorSeleccion(Pila *p){
    Pila AUX;
    inicpila(&AUX);

    while(!pilavacia(p)){
        apilar(&AUX, buscarMenor(p));
    }
    pasarPila(&AUX, p);

}

int buscarEnPila(Pila p, int aBuscar){
    int encontrado = 0;
    Pila AUX;
    inicpila(&AUX);

    while (!pilavacia(&p) && encontrado == 0){
        if (tope(&p) == aBuscar)
            encontrado = 1;
        else
            apilar (&AUX, desapilar(&p));
    }
    return encontrado;
}

/* void pasarElementosPorInsercion(Pila *p, Pila *destino){
    while (!pilavacia(p)){
    }
}
*/

int sumarAnteriorYTope(Pila p){
    int suma = desapilar(&p) + desapilar(&p);
    return suma;
}

int contarDigitos(int nroAContar){
    int sumaDigitos = 0;

    sumaDigitos = (log10(nroAContar) + 1);



    return sumaDigitos;
}





















