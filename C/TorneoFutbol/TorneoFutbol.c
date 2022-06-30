#include <stdio.h>
#include <stdlib.h>
#define N 100

void MOSTRARTABLA(int[], int[], int);
void ORDENARTABLA(int[], int[], int);
void ARMARCRUCES(int [], int);

int main(){
    int EQUIPOS[N], PUNTAJE[N], I;
    srand(320);

    for(I = 0; I < N; I++){
        EQUIPOS[I]= (rand() % 8999) + 1000;
        PUNTAJE[I]=  rand() % 45;
    }
    ORDENARTABLA(EQUIPOS, PUNTAJE, N);
    MOSTRARTABLA(EQUIPOS, PUNTAJE, N);
    ARMARCRUCES(EQUIPOS, N);
}

void MOSTRARTABLA(int VECT1[], int VECT2[], int L){
    int I;
    printf("\n\t\t  EQUIPO  \t  PUNTAJE\n");
    for(I = 0; I < N; I++){
        printf("\n%24d%13d", VECT1[I], VECT2[I]);
    }
    printf("\n\n");
}

void ORDENARTABLA(int V1[], int V2[], int L){
    int I, J, AUX1, AUX2;
    for(I = 0; I < L - 1; I++){
        for(J = 0; J < N - I - 1; J++){
            if(V2[J] < V2[J+1]){
                AUX1 = V1[J];
                V1[J] = V1[J+1];
                V1[J+1] = AUX1;

                AUX2 = V2[J];
                V2[J] = V2[J+1];
                V2[J+1] = AUX2;
            }
        }
    }
}

void ARMARCRUCES(int V[], int L){
    int T = L / 2;
    int I = 0 , J = L - 1;
    printf("\n\n\tCruces de play offs: \n");
    while(I < T && J >= T){
        printf("\n%24d VS %d\n", V[I], V[J]);
        I++;
        J--;
    }

}
