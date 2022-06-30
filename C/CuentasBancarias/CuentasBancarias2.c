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
    printf("\n\n");
    printf("\tCuenta con mayor saldo\n\n%25d%14c%20.2f\n\n", CUENTA[N-1], TIPO[N-1], SALDO[N-1]);
}

void MOSTRAR(int CUENTA[], char TIPO[], float SALDO[], int L){
    int I;
    printf("\n\t\t  CUENTA  \t  TIPO  \t  SALDO\n\n");
    for(I = 0; I < L; I++){
        printf("\n%25d%14c%20.2f", CUENTA[I], TIPO[I], SALDO[I]);
    }
}

void ACCESO(int CUENTA[], char TIPO[], float SALDO[], int L, int C){
    int I, J, AUXFLOAT, AUXCHAR, AUXINT;
    for(I = 0; I < L-1; I++){
        for(J = 0; J < L-I-1; J++){
            if(SALDO[J] > SALDO[J+1]){
                AUXFLOAT = SALDO[J];
                SALDO[J] = SALDO[J+1];
                SALDO[J+1] = AUXFLOAT;

                AUXCHAR = TIPO[J];
                TIPO[J] = TIPO[J+1];
                TIPO[J+1] = AUXCHAR;

                AUXINT = CUENTA[J];
                CUENTA[J] = CUENTA[J+1];
                CUENTA[J+1] = AUXINT;
            }
        }
    }
}
