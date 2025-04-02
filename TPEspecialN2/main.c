#include <stdio.h>
#include <stdlib.h>

#define DIM 100

int cargarNotasRandom(int notas[], int dim);
void mostrarNotas(int notas[], int validos);
int cargarNotasManual(int notas[], int validos, int dim);

int main()
{
    srand(time(NULL));

    int notas[DIM];
    int vNotas = 0;

    vNotas = cargarNotasManual(notas, vNotas, DIM);
    mostrarNotas(notas, vNotas);
    printf("\nLa nota menor es: %d", buscarMenor(notas, vNotas));
    printf("\nLa nota mayor es: %d", buscarMayor(notas, vNotas));
    printf("\nEl promedio de los elementos es: %d", promedioNotas(notas, vNotas));
    return 0;
}

int cargarNotasRandom(int notas[], int dim){
    int i = 0;
    for (i = 0; i < dim; i++){
        notas[i] = rand() % 10;
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
    int prom;
    int i;

    for (i = 0; i < validos; i++){
        prom += arr[i];
    }

    return prom / validos;
}
