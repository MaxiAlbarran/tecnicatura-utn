#include <stdio.h>
#include <stdlib.h>
#define N 10

void MOSTRAR(int[], char[], float[], int);
void ACCESO(int[], char[], float[], int, int);

int main(){
    int CUENTA[N]= {458, 321, 744, 228, 349, 201, 198, 705, 789, 227};
    char TIPO[N]= {'B', 'A', 'C', 'C', 'B', 'A', 'C', 'A', 'B', 'C'};
    float SALDO[N]= {458.32, 105.00, 750.00, 250.00, 633.50, 129.00, 732.40, 900.00, 498.99, 867.66};
    int C;

    MOSTRAR(CUENTA, TIPO, SALDO, N);
    ACCESO(CUENTA, TIPO, SALDO, N, C);
}

void MOSTRAR(int CUENTA[], char TIPO[], float SALDO[], int L){
    int I;
    printf("\n\t\t  CUENTA  \t  TIPO  \t  SALDO\n\n");
    for(I = 0; I < L; I++){
        printf("\n%25d%14c%20.2f", CUENTA[I], TIPO[I], SALDO[I]);
    }
}

void ACCESO(int CUENTA[], char TIPO[], float SALDO[], int L, int C){
    int I;
    printf("\n\n\t\t\t     Cuentas de tipo A ");
    for(I = 0; I < L; I++){
        if(TIPO[I] == 'A'){
            printf("\n");
            printf("\n%25d%14c%20.2f\n\n", CUENTA[I], TIPO[I], SALDO[I]);
        }
    }
}
