
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 14

struct INSCRIPTOS {
    int legajo;
    char carrera[20];
};

struct INGRESANTES {
    int legajo;
    int nota;
};

void CONTARINSCRIPTOS(FILE *);

void CONTAREXAMEN(FILE *, FILE *, int);

int main(){

    FILE * INGRESO, * EXAMEN;

    struct INSCRIPTOS X;
    struct INGRESANTES Y;

    INGRESO = fopen("INGRESO", "rb");
    EXAMEN = fopen("EXAMEN", "rb");

    if(INGRESO == NULL || EXAMEN == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        exit(1);
    }

    fread(&X, sizeof(X), 1, INGRESO);

    while( !feof(INGRESO) ){

        printf("\n\n\t%d    %s", X.legajo, X.carrera);

        fread(&X, sizeof(X), 1, INGRESO);
    }

    fread(&Y, sizeof(Y), 1, EXAMEN);

    while( !feof(EXAMEN) ){

        printf("\n\n\t%d    %d", Y.legajo, Y.nota);

        fread(&Y, sizeof(Y), 1, EXAMEN);
    }

    CONTARINSCRIPTOS(INGRESO);

    CONTAREXAMEN(INGRESO, EXAMEN, NUM);


    fclose(INGRESO);
    fclose(EXAMEN);

    printf("\n\nFIN DEL PROGRAMA");
    return 0;
}

void CONTARINSCRIPTOS(FILE * FP){

    struct INSCRIPTOS X;
    int cont = 0;

    fseek(FP, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        if( strcmp(X.carrera, "INGENIERIA") == 0 ){
            cont++;
        }

        fread(&X, sizeof(X), 1, FP);
    }

    printf("\n\n\t %d ALUMNOS SE INCRIBIERON EN INGENIERIA", cont);

}

void CONTAREXAMEN( FILE * INGRESO, FILE * EXAMEN, int N){

    struct INSCRIPTOS X;
    struct INGRESANTES Y;

    int cont = 0, aprobados = 0;

    fseek(INGRESO, 0L, SEEK_SET);
    fseek(EXAMEN, 0L, SEEK_SET);

    for(int I = 0; I < N; I++){

        fseek(INGRESO, (long)(I * sizeof(X)), SEEK_SET);
        fread(&X, sizeof(X), 1, INGRESO);

        if(strcmp(X.carrera, "INGENIERIA") == 0){

            for(int J = 0; J < N; J++){

                fseek(EXAMEN, (long)(J * sizeof(Y)), SEEK_SET);
                fread(&Y, sizeof(Y), 1, EXAMEN);

                if( X.legajo == Y.legajo ){

                    cont++;

                    if(Y.nota >= 6){
                        aprobados++;
                    }
                }

            }
        }
    }

    printf("\n\n\t %d ALUMNOS DE INGENIERIA RINDIERON EL EXAMEN Y LO APROBARON %d", cont, aprobados);
}
