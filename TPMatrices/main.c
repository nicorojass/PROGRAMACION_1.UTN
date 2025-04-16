#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ESC 27
#define DIM 100

void menuOpciones();
void cargarMatrizRandom(int f, int c, int matriz[f][c]);
float calcularPromedioMatriz(int fil, int col, int m[fil][col]);

int main()
{
    srand(time(NULL));

    char opcion;
    int matrizNumeros[3][3];
    char matrizNombres[DIM][30];
    int vNombres = 0;
    int dato;

    do{
        menuOpciones();
        opcion = getch();
        switch(opcion){
            case 49:
            system("cls");
            cargarMatrizRandom(3, 3, matrizNumeros);
            break;
            case 50:
            system("cls");
            mostrarMatriz(3, 3, matrizNumeros);
            break;
            case 51:
            system("cls");
            vNombres = cargarNombres(DIM, matrizNombres);
            break;
            case 52:
            system("cls");
            mostrarNombres(DIM, matrizNombres, vNombres);
            break;
            case 53:
            system("cls");
            printf("La suma de los numeros de la matriz es: %d\n", sumarNumerosMatriz(3,3, matrizNumeros));
            break;
            case 54:
            system("cls");
            printf("El promedio de los numeros de la matriz es: %.2f\n", calcularPromedioMatriz(3,3, matrizNumeros));
            break;
            case 55:
            system("cls");
            printf("Ingrese dato a buscar en la matriz: \n");
            scanf("%d", &dato);
            if (buscarElementoEnMatriz(3,3, matrizNumeros, dato) == 1)
                printf("El elemento se encuentra en la matriz\n");
            else
                printf("El elemento no se encuentra en la matriz\n");
            break;
        }
        system("pause");
        system("cls");
    }while (opcion != ESC);

    return 0;
}

void menuOpciones(){
    printf("\t \t \t Menu de Matrices\n");
    printf("1.- Cargar matriz random\n");
    printf("2.- Mostrar matriz\n");
    printf("3.- Cargar arreglo de strings (nombres)\n");
    printf("4.- Mostrar arreglo de strings (nombres)\n");
    printf("5.- Sumar numeros de matriz INT\n");
    printf("6.- Calcular promedio de matriz INT\n");
    printf("7.- Buscar elemento en la matriz\n");
    printf("8.- \n");
    printf("9.- \n");
    printf("ESC para salir... \n");
}

void cargarMatrizRandom(int f, int c, int matriz[f][c]){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            matriz[i][j] = rand() % 100;
        }
    }
}

void mostrarMatriz(int f, int c, int matriz[f][c]){
    for(int i = 0; i < f; i++){
        for(int j = 0; j < c; j++){
            printf("%4d | ", matriz[i][j]);
        }
        printf("\n");
    }
}

int cargarNombres(int dim, char nombres[dim][30]){
    int i = 0;
    char opcion = 0;

    while (i < dim && opcion != 27){
        printf("Ingrese un nombre:\n");
        // scanf("%s", nombres[i]);
        gets(nombres[i]);
        printf("Presione cualquier tecla para continuar o ESC para salir...\n");
        opcion = getch();
        i++;
    }
    return i;
}

void mostrarNombres(int dim, char nombres[dim][30], int validos){
    printf("<<<<<< Nombres >>>>>>\n\n");
    for(int i = 0; i < validos; i++){
        printf("%s\n", nombres[i]);
    }
}

int sumarNumerosMatriz(int f, int c, int matriz[f][c]){
   int suma = 0;

   for(int i = 0; i < f; i++){
    for (int j = 0; j < c; j++){
        suma += matriz[i][j];
    }
   }

   return suma;
}

float calcularPromedioMatriz(int fil, int col, int m[fil][col]){
    float promedio = 0;
    int cont = 0;

    for (int i = 0; i < fil; i++){
        for (int j = 0; j < col; j++){
            promedio += m[i][j];
            cont++;
        }
    }
    promedio = promedio / cont;
    return promedio;
}

int buscarElementoEnMatriz(int fil, int col, int m[fil][col], int dato){
    int encontrado = 0;
    int i = 0;
    int j = 0;

    while (i < fil){
        while (j < col){
            if (m[i][j] == dato){
                encontrado = 1;
            }
            j++;
        }
        i++;
    }
    return encontrado;
}






