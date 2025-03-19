#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include <time.h>

#define ESC 27


int main()
{
    srand(time(NULL)); // para que los randoms varíen.


    Pila p, ord;
    inicpila(&p);
    inicpila(&ord);


    cargarPila(&p, "Ingrese un nro:");
    mostrarPila(&p);
    pasarElementosOrdenados(&p, &ord);
    mostrarPila(&p);
    mostrarPila(&ord);


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































