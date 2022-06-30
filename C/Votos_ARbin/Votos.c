#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ELECCION {
    char NOM[20];
    char DISTRITO[20];
    int VOTOS;
};

struct ESCRUTADO {
    char NOM[20];
    int VOTOS;
};

void LECTURAELECCIONES(FILE *);

void LECTURARESUMEN(FILE *);

void CONTARVOTOS(FILE *, FILE *, int, int);

void MOSTRARGANADOR(FILE *);

int main(){

    FILE * FP;
    FILE * FRESUMEN;
    struct ELECCION X;
    int N, NCANDIDATOS;

    FP = fopen("BDVOTOS", "rb");
    FRESUMEN = fopen("BDRESUMEN", "r+b");

    if(FP == NULL || FRESUMEN == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        exit(1);
    }

    fseek(FP, 0L, SEEK_END);
    N = ftell(FP) / sizeof(struct ELECCION);
    fseek(FP, 0L, SEEK_SET);

    fseek(FRESUMEN, 0L, SEEK_END);
    NCANDIDATOS = ftell(FRESUMEN) / sizeof(struct ESCRUTADO);
    fseek(FRESUMEN, 0L, SEEK_SET);

    LECTURAELECCIONES(FP);

    LECTURARESUMEN(FRESUMEN);

    MOSTRARGANADOR(FRESUMEN);

    fclose(FP);
    fclose(FRESUMEN);
    printf("\n\nFIN DEL PROGRAMA");
    return 0;
}

void LECTURAELECCIONES(FILE * FP){

    struct ELECCION X;

    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        printf("\n\n\t%-20s %20s %10d", X.NOM, X.DISTRITO, X.VOTOS);

        fread(&X, sizeof(X), 1, FP);
    }

    fseek(FP, 0L, SEEK_SET);
}

void LECTURARESUMEN(FILE * FP){

    struct ESCRUTADO X;

    fseek(FP, 0L, SEEK_SET);

    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        printf("\n\n\t%-20s %10d", X.NOM, X.VOTOS);

        fread(&X, sizeof(X), 1, FP);
    }

    fseek(FP, 0L, SEEK_SET);
}

void CONTARVOTOS(FILE * FP, FILE * FRESUMEN, int N, int NCANDIDATOS){

    struct ELECCION X;
    struct ESCRUTADO Z;

    for(int I = 0; I < NCANDIDATOS; I++){

        fseek(FRESUMEN, (long)(I * sizeof(Z)), SEEK_SET);
        fread(&Z, sizeof(Z), 1, FRESUMEN);

        for(int J = 0; J < N; J++){

            fseek(FP, (long)(J * sizeof(X)), SEEK_SET);
            fread(&X, sizeof(X), 1, FP);

            if( strcmp(Z.NOM, X.NOM) == 0 ){
                Z.VOTOS = Z.VOTOS + X.VOTOS;
            }
        }

        fseek(FRESUMEN, (long)(I * sizeof(Z)) , SEEK_SET);
        fwrite(&Z, sizeof(Z), 1, FRESUMEN);
    }
}

void MOSTRARGANADOR(FILE * FP){

    struct ESCRUTADO X;
    int mayor = 0;
    char ganador[20];

    fseek(FP, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        if(X.VOTOS > mayor){
            mayor = X.VOTOS;
            strcpy(ganador, X.NOM);
        }

        fread(&X, sizeof(X), 1, FP);
    }

    printf("\n\n\tEL GANADOR DE LAS ELECCIONES ES %s CON %d VOTOS", ganador, mayor);

}
