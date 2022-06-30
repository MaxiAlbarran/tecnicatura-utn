#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct atleta {
		char NOMBRE[50];
		char PAIS[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

struct pais {
		char NOMBRE[30];
		int ORO;
		int PLATA;
		int BRONCE;
};


void LECTURA(FILE *);
void LECTURAPAISES(FILE *);

void SUMARMEDALLAS(FILE *, int, FILE *, int);

void CONTARMEDALLAS(FILE *);

int main(){

    FILE * FPATLETAS, * FPPAISES;

    int cantAtl, cantPais;

    FPATLETAS = fopen("ATLETAS", "rb");
    FPPAISES = fopen("PAISES", "r+b");

    if( FPATLETAS == NULL || FPPAISES == NULL){
        printf("ERROR EN LA APERTURA DEL ARCHIVO");
        exit(1);
    }

    fseek(FPATLETAS, 0L, SEEK_END);
    fseek(FPPAISES, 0L, SEEK_END);

    cantAtl = ftell(FPATLETAS) / sizeof(struct atleta);
    cantPais = ftell(FPPAISES) / sizeof(struct pais);

    fseek(FPATLETAS, 0L, SEEK_SET);
    fseek(FPPAISES, 0L, SEEK_SET);

    printf("\n\n\n\tATLETAS");
    LECTURA(FPATLETAS);

    printf("\n\n\n\tPAISES");
    LECTURAPAISES(FPPAISES);

    CONTARMEDALLAS(FPPAISES);


    fclose(FPATLETAS);fclose(FPPAISES);
    FPATLETAS = 0;FPPAISES = 0;

    printf("\n\nFIN DEL PROGRAMA");
    return 0;
}

void LECTURA(FILE * FP){

    struct atleta X;

    printf("\n\n\t %-15s %20s %10s %10s %10s", "PAIS", "NOMBRE", "ORO", "PLATA", "BRONCE");


    fseek(FP, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        printf("\n\n\t %-15s %20s %10d %10d %10d", X.PAIS, X.NOMBRE, X.ORO, X.PLATA, X.BRONCE);

        fread(&X, sizeof(X), 1, FP);
    }

}


void LECTURAPAISES(FILE * FP){

    struct pais X;

    printf("\n\n\t %-15s %10s %10s %10s", "PAIS", "ORO", "PLATA", "BRONCE");


    fseek(FP, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FP);

    while( !feof(FP) ){

        printf("\n\n\t %-15s %10d %10d %10d", X.NOMBRE, X.ORO, X.PLATA, X.BRONCE);

        fread(&X, sizeof(X), 1, FP);
    }

}

void SUMARMEDALLAS( FILE * FPATLETAS, int cantAtl, FILE * FPPAISES, int cantPais){

    struct atleta X;
    struct pais Y;

    for(int I = 0; I < cantPais; I++){

        fseek(FPPAISES, (long)(I * sizeof(struct pais)), SEEK_SET);
        fread(&Y, sizeof(Y), 1, FPPAISES);

        for(int J = 0; J < cantAtl; J++){

            fseek(FPATLETAS, (long)(J * sizeof(struct atleta)), SEEK_SET);
            fread(&X, sizeof(X), 1, FPATLETAS);

            if( strcmp(Y.NOMBRE, X.PAIS) == 0){
                Y.BRONCE = Y.BRONCE + X.BRONCE;
                Y.PLATA = Y.PLATA + X.PLATA;
                Y.ORO = Y.ORO + X.ORO;

                fseek(FPPAISES, (long)(-1 * sizeof(struct pais)), SEEK_CUR);
                fwrite(&Y, sizeof(Y), 1, FPPAISES);
            }
        }
        fseek(FPPAISES, 0L, SEEK_SET);
    }
}

void CONTARMEDALLAS(FILE * FPPAISES){

    struct pais X;
    char ganador[30];
    int cont, medallero = 0;

    fseek(FPPAISES, 0L, SEEK_SET);
    fread(&X, sizeof(X), 1, FPPAISES);

    while( !feof(FPPAISES) ){

        cont = X.BRONCE + X.PLATA + X.ORO;

        if(cont > medallero){
            strcpy( ganador, X.NOMBRE );
            medallero = cont;
        }

        fread(&X, sizeof(X), 1, FPPAISES);
    }

    printf("\n\n\tEL PAIS QUE MAS MEDALLAS OBTUVO ES %s CON %d MEDALLAS", ganador, medallero);
}
