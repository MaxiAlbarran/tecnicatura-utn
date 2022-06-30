#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct FECHA{
    int DIA;
    int MES;
    int ANIO;
};

struct SERV{
    char SERVICIO[20];
    int ID;
    struct FECHA HOY;
};

struct PRECIO{
    char SERVICIO[20];
    int COSTO;
};


void LECTURA(FILE *);
void LECTURAPRECIOS(FILE *);

void BUSCARCLIENTE(FILE *, FILE *, int, int);

void BUSCARSERVICIO(FILE *);

int main(){

    FILE * FSERVICIOS, * FPRECIOS;

    struct SERV X;
    struct PRECIO Y;
    int NHUESPEDES, NSERVICIOS;

    FSERVICIOS = fopen("SERVICIOS", "rb");
    FPRECIOS = fopen("LISTA_PRECIOS", "rb");

    if(FSERVICIOS == NULL || FPRECIOS == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        exit(1);
    }

    fseek(FSERVICIOS, 0L, SEEK_END);
    NHUESPEDES = ftell(FSERVICIOS) / sizeof(struct SERV);
    fseek(FSERVICIOS, 0L, SEEK_SET);

    fseek(FPRECIOS, 0L, SEEK_END);
    NSERVICIOS = ftell(FPRECIOS) / sizeof(struct PRECIO);
    fseek(FPRECIOS, 0L, SEEK_SET);

    LECTURAPRECIOS(FPRECIOS);

    printf("\n\n\t-------------------------------------------------------\n\n");

    LECTURA(FSERVICIOS);

    printf("\n\n\t-------------------------------------------------------\n\n");

    BUSCARCLIENTE(FSERVICIOS, FPRECIOS, NHUESPEDES, NSERVICIOS);

    printf("\n\n\t-------------------------------------------------------\n\n");


    BUSCARSERVICIO(FSERVICIOS);


    fclose(FSERVICIOS);
    fclose(FPRECIOS);
    printf("\n\nFIN DEL PROGRAMA");
    return 0;
}

void LECTURA(FILE * FP){

    struct SERV X;

    fread(&X, sizeof(X), 1, FP);

    printf("\n\n\t%-15s %10s %10s", "SERVICIO", "HUESPED", "FECHA");

    while( !feof(FP) ){

        printf("\n\n\t%-15s %10d\t%d / %d / %d", X.SERVICIO, X.ID, X.HOY.DIA, X.HOY.MES, X.HOY.ANIO);

        fread(&X, sizeof(X), 1, FP);
    }
}

void LECTURAPRECIOS(FILE * FP){

    struct PRECIO X;

    fread(&X, sizeof(X), 1, FP);

    printf("\n\n\t%-15s %10s ", "SERVICIO", "PRECIO");

    while( !feof(FP) ){

        printf("\n\n\t%-15s %10d", X.SERVICIO, X.COSTO);

        fread(&X, sizeof(X), 1, FP);
    }
}

void BUSCARCLIENTE(FILE * FSERVICIOS, FILE * FPRECIOS, int NHUESPEDES, int NSERVICIOS){

    struct SERV X;
    struct SERV Y;
    struct PRECIO Z;
    int monto = 0, cont = 0, huesped;


    for(int I = 0; I < NHUESPEDES; I++){

        fseek(FSERVICIOS, (long)(I * sizeof(X)), SEEK_SET);
        fread(&X, sizeof(X), 1, FSERVICIOS);

        for(int J = I; J < NHUESPEDES; J++){

            fseek(FSERVICIOS, (long)(J * sizeof(X)), SEEK_SET);
            fread(&Y, sizeof(Y), 1, FSERVICIOS);

            if(X.ID == Y.ID){

                for(int H = 0; H < NSERVICIOS; H++){

                    fseek(FPRECIOS, (long)(H * sizeof(Z)), SEEK_SET);
                    fread(&Z, sizeof(Z), 1, FPRECIOS);

                    if(strcmp( Y.SERVICIO, Z.SERVICIO ) == 0){
                        cont = cont + Z.COSTO;
                    }
                }
            }
        }

        if(cont > monto){
            huesped = X.ID;
            monto = cont;
        }

        cont = 0;
    }

    printf("\n\n\tEL HUESPED QUE MAS GASTO FUE %d CON UN TOTAL DE %d", huesped, monto);
}


void BUSCARSERVICIO(FILE * FP){

    struct SERV X;
    char servicio[20];

    printf("\n\n\tINGRESAR SERVICIO: ");
    gets(servicio);

    fseek(FP, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        if( strcmp(X.SERVICIO, servicio) == 0){
            printf("\n\n\t%d\t %d / %d / %d", X.ID, X.HOY.DIA, X.HOY.MES, X.HOY.ANIO);
        }

        fread(&X, sizeof(X), 1, FP);
    }
}


