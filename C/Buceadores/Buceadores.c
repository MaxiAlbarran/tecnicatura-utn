#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 15

struct buceador{
    char nombre[20];
    int puntaje;
};

void CARGAR_DATOS(struct buceador[], int);
void ORDENARTABLA(struct buceador[], int);
void MIRARTABLA(struct buceador[], int);


int main(){

    struct buceador buceadores[LENGTH];

    printf("\n\nConcurso de capturas! Anote los competidores!\n\n(La competencia termina con el ingreso de -1)\n\n");

    CARGAR_DATOS(buceadores, LENGTH);
    MIRARTABLA(buceadores, LENGTH);

    int ingreso = 0;
    while(ingreso != -1){
        printf("\n\nPosicion de competidor que consiguio una captura: ");
        scanf("%d", &ingreso);

        if(ingreso > LENGTH || ingreso < -1 || ingreso == 0){
            printf("\n\nVerifique su ingreso\n\n");
        }else{
            buceadores[ingreso - 1].puntaje++;
            ORDENARTABLA(buceadores, LENGTH);
            MIRARTABLA(buceadores, LENGTH);
        }


    }

    printf("\n\nEL CAMPEON ES %s CON %d CAPTURAS!!\n\n\n\n", buceadores[0].nombre, buceadores[0].puntaje );
}

void CARGAR_DATOS(struct buceador buceadores[], int L){

    for(int I = 0; I < L; I++){
        printf("\n\nCompetidor %d: ", I + 1);
        fflush(stdin);
        gets(buceadores[I].nombre);

        buceadores[I].puntaje = 0;
    }
}

void ORDENARTABLA(struct buceador buceadores[], int L){
    struct buceador AUX;

    for(int I = 0; I < L - 1; I++){
        for(int J = 0; J < L - I - 1; J++){
            if( buceadores[J].puntaje < buceadores[J + 1].puntaje){
                AUX = buceadores[J];
                buceadores[J] = buceadores[J + 1];
                buceadores[J + 1] = AUX;
            }
        }
    }
}

void MIRARTABLA(struct buceador buceadores[], int L ){

    printf("\n\nTabla de buceadores\n");
    for(int I = 0; I < L ; I++){
        printf("\n%d_ %s: %d\n", I + 1, buceadores[I].nombre, buceadores[I].puntaje);
    }
}
