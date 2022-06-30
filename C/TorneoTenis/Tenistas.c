#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 8


struct JUGADORES {
    char NOMBRE[20];
    char SEXO;
    int HANDICAP;
};

void CARGARDATOS( struct JUGADORES[], int );
void MIRARDATOS( struct JUGADORES[], int );
void CREARDOBLES( struct JUGADORES[], int );
void SEPARACION(struct JUGADORES[], struct JUGADORES[], struct JUGADORES[], int );
void ORDENAR( struct JUGADORES[], int );
void MOSTRARPAREJAS(struct JUGADORES[], struct JUGADORES[], int);


int main(){
    srand(1500);
    struct JUGADORES JUGADOR[N];

    CARGARDATOS(JUGADOR, N);
    MIRARDATOS(JUGADOR, N);

    CREARDOBLES(JUGADOR, N);
}

void CARGARDATOS ( struct JUGADORES PERSONA[], int L ){
    char NOMBRES[][20] = {"PEPE","JUANITA","CAMI","MAXI",
                          "BAZZI","MELINA","LAUTI","LAURA"};
    char GENERO[]= {'M','F','F','M','M','F','M','F'};

    int I;

    for(I = 0; I < L; I++){
        strcpy(PERSONA[I].NOMBRE , NOMBRES[I]);
        PERSONA[I].SEXO = GENERO[I];
        PERSONA[I].HANDICAP = 1 + rand() % 10;
    }
}

void MIRARDATOS ( struct JUGADORES PERSONA[], int L){
    int I, J;

    printf("\n\n\nNOMBRES \t    SEXO    \tHANDICAP\n\n");
    for(I = 0; I < L ; I++){
        printf("%-10s %10c\t\t %2d\n", PERSONA[I].NOMBRE, PERSONA[I].SEXO, PERSONA[I].HANDICAP);

    }
    printf("\n\n");

}


void CREARDOBLES(struct JUGADORES PARTICIPANTES[], int L){
    int X, T = L/2;
    struct JUGADORES HOMBRES[T], MUJERES[T];

    SEPARACION(HOMBRES, MUJERES, PARTICIPANTES, L);
    ORDENAR(HOMBRES, T);
    ORDENAR(MUJERES, T);
    MOSTRARPAREJAS(HOMBRES, MUJERES, T);


}

void SEPARACION(struct JUGADORES V1[], struct JUGADORES V2[], struct JUGADORES PARTICIPANTES[], int L){
    int I = 0, H = 0, M = 0;
    while(I < L){
        if(PARTICIPANTES[I].SEXO == 'M'){
            V1[H] = PARTICIPANTES[I];
            H++;
        }else{
            V2[M] = PARTICIPANTES[I];
            M++;
        }
        I++;
    }

}

void ORDENAR( struct JUGADORES PERSONA[], int L){
    int I , J;
    struct JUGADORES AUX;

    for(I = 0; I < L - 1; I++){
        for(J = 0; J < L - I - 1; J++){
            if(PERSONA[J].HANDICAP < PERSONA[J+1].HANDICAP){
                AUX = PERSONA[J + 1];
                PERSONA[J + 1] = PERSONA[J];
                PERSONA[J] = AUX;
            }
        }
    }

}

void MOSTRARPAREJAS(struct JUGADORES V1[], struct JUGADORES V2[], int L){
    int I = 0, J = L-1;
    printf("\n\n\tPAREJAS:\n\n");
    while(I < L && J >= 0){
        printf("\n%10s \tY %12s\n", V1[I], V2[J]);
        I++;
        J--;
    }

}
