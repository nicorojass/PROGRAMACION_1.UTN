#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Factorial de 5: %d\n", factorialTernario(5));
    return 0;
}

int factorial(int x){
    int rta;

    if(x == 0){
        rta = 1;
    }
    else {
        rta = x * factorial(x - 1);
    }

    return rta;
}

int factorialImplicito(int x){
    int rta = 1;
    if (x > 0){
        rta = x * factorialImplicito(x - 1);
    }
    return rta;
}

int factorialTernario(int x){
    return (x>0) ? x * factorialTernario(x - 1) : 1;
}









