#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct ARTICULO {
	int NUMART ;
	char DESCRIP[20];
	int STOCK ;
	char PROVE[15] ;
	float COSTO ;
};

void LECTURA(FILE *);

void DEPURARBD(FILE *, FILE *, char[30]);

int main()
{

    FILE * FP , * FPAUX;

    struct ARTICULO X;
    char art[30];
    int flag = 1;

    FP = fopen("BDPEREZ", "rb");
    FPAUX = fopen("BDPEREZAUX", "wb");

    if(FP == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        exit(1);
    }

    fseek(FP, 0L, SEEK_END);
    int N = ftell(FP) / sizeof(struct ARTICULO);
    printf("\n\n\tLA NUEVA BASE DE DATOS CONTIENE %d ARTICULOS\n", N);

    LECTURA(FP);

    fseek(FP, 0l, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while(flag){

        if( strcmp(X.PROVE, "PEREZ") == 0){
            strcpy(art, X.DESCRIP);

            flag = 0;
        }

        fread(&X, sizeof(X), 1, FP);

    }   // SE BUSCA EL NOMBRE DEL ARTICULO QUE PROVEE PEREZ


    printf("\n\nEL ARTICULO A ELIMINAR ES %s\n\n", art);

    DEPURARBD(FP, FPAUX, art);

	fclose(FP);
	fclose(FPAUX);
	FP = 0;
	FPAUX = 0;

	//ELIMINACION DE LA VIEJA BD Y RENOMBRAMIENTO DE LA AUXILIAR

	remove("BDPEREZ");
	rename("BDPEREZAUX", "BDPEREZ");

	fclose(FP);
	FP = 0;

	printf("\n\n\nFIN DEL PROGRAMA  ") ;
	return 0;
}

void LECTURA(FILE * FP){

    struct ARTICULO X;

    fseek(FP, 0l, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        printf("\n\n\t%d  %s  %d  %s  %.2f", X.NUMART, X.DESCRIP, X.STOCK, X.PROVE, X.COSTO);

        fread(&X, sizeof(X), 1, FP);
    }
}

void DEPURARBD(FILE * FP, FILE * FPAUX, char articulo[30]){

    struct ARTICULO X;

    fseek(FP, 0l, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        if( strcmp(articulo, X.DESCRIP) != 0 || strcmp(X.PROVE, "PEREZ") == 0){

            fwrite(&X, sizeof(X), 1, FPAUX);

        }

        fread(&X, sizeof(X), 1, FP);
    }

}

