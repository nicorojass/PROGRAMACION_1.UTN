#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pila.h"
#include <time.h>

#define ESC 27


int main()
{
    srand(time(NULL));

    Pila temperaturas;
    inicpila(&temperaturas);

    char opcion;

    do{
        opcionesMenu();
        opcion = getch();
        switch (opcion){
        case 49:
            system("cls");
            cargarTemperaturasRandom(&temperaturas);
            break;
        case 50:
            system("cls");
            cargarTemperaturasManual(&temperaturas);
            break;
        case 51:
            system("cls");
            ordenarTemperaturas(&temperaturas);
            break;
        case 52:
            system("cls");
            mostrarTemperaturas(temperaturas);
            break;
        case 53:
            system("cls");
             printf("La temperatura mayor es: %d\n",buscarMayor(&temperaturas));
            break;
        case 54:
            system("cls");
            printf("La temperatura menor es: %d\n",buscarMenor(&temperaturas));
            break;
        case 55:
            system("cls");
            printf("El promedio de las temperaturas es: %d\n", calcularPromedio(&temperaturas));
            break;
        }
        system("pause");
        system("cls");
    }while (opcion != ESC);


    return 0;
}


void cargarTemperaturasRandom(Pila *p){
    char opcion;

    do
    {
        printf("Presione cualquier tecla si desea cargar una temperatura random o ESC para salir\n");
        opcion = getch();
        apilar(p, rand()% 51 + (-10));
    }while (opcion != ESC);
}

void cargarTemperaturasManual(Pila *p){
    int dato;
    char opcion;

    do{
        printf("Ingrese una temperatura entre -10° y 40°\n");
        scanf("%d", &dato);

        if(dato < -10 || dato > 40){
            printf("Temperatura invalida\n");
        }
        else
        {
            apilar(p, dato);
            printf("Presione ESC para salir o cualquier tecla para seguir cargando temperaturas\n");
            opcion = getch();
        }
    }while (opcion != ESC);

}

int buscarMenor(Pila *p){
    int menor;
    Pila aux;
    inicpila(&aux);


    if (!pilavacia(p)){
        menor = desapilar(p);

        while (!pilavacia(p)){
            if(tope(p) < menor){
                apilar(&aux, menor);
                menor = desapilar(p);
            }
            else
                apilar(&aux,desapilar(p));
        }
        while (!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
    return menor;

}

void ordenarTemperaturas(Pila *p){
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(p)){
        apilar(&aux, buscarMenor(p));
    }
    while (!pilavacia(&aux)){
        apilar (p, desapilar(&aux));
    }
}

void mostrarTemperaturas(Pila p){
    int cont;

    while (!pilavacia(&p)){
        printf("%4d° | \n", tope(&p));
        desapilar(&p);
        cont++;
    }

}

int buscarMayor(Pila *p){
    int mayor;
    Pila aux;
    inicpila(&aux);

    if (!pilavacia(p)){
        mayor = desapilar(p);

        while (!pilavacia(p)){
            if(tope(p) > mayor){
                apilar(&aux, mayor);
                mayor = desapilar(p);
            }
            else
                apilar(&aux,desapilar(p));
        }
        while (!pilavacia(&aux)){
            apilar(p, desapilar(&aux));
        }
    }
    return mayor;
}

int calcularPromedio(Pila p){
    int promedio;
    int cont = 0;

    while(!pilavacia(&p)){
        promedio += tope(&p);
        desapilar(&p);
        cont++;
    }
    promedio = promedio / cont;
    return promedio;
}

void opcionesMenu(){
    printf("\t \t \t Menu de temperaturas\n");
    printf("1: Cargar temperaturas random\n");
    printf("2: Cargar temperaturas manual\n");
    printf("3: Ordenar temperaturas\n");
    printf("4: Mostrar temperaturas\n");
    printf("5: Mostrar temperatura maxima\n");
    printf("6: Mostrar temperatura minima\n");
    printf("7: Calcular promedio de temperaturas\n");
    printf("ESC para salir...\n");
}


