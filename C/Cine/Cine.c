#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 4

struct sala {
    int codigo;
    int butaca [4][6];
    char peli [30];
};

void CARGARDATOS(struct sala[], int);
void MIRARDATOS(struct sala[], int);

int MAS_VISTA(struct sala[]);
int BUSCAR_PELI(struct sala[], char[30]);

int main(){

    srand(3450);
    struct sala pelicula[LENGTH];
    char titulo[30];

    CARGARDATOS(pelicula, LENGTH);
    MIRARDATOS(pelicula, LENGTH);

    printf("\n\n");
    printf("La sala mas concurrida en este momento es la %d", MAS_VISTA(pelicula));

    printf("\n\n");
    printf("Ingrese el nombre de una pelicula para saber en que sala se encuentra\n\n");
    fflush(stdin);
    gets(titulo);
    printf("\n \nSala %d" ,BUSCAR_PELI(pelicula, titulo));

    printf("\n\n\n\n");
}

void CARGARDATOS(struct sala pelicula[], int L){


    char nombre[][30] = {"SPIDERMAN", "BATMAN", "AVENGERS", "DONT LOOK UP"};

    for(int I = 0; I < L; I++){
        pelicula[I].codigo = (rand() % 20) + 1;
        strcpy(pelicula[I].peli, nombre[I]);

        for(int J = 0; J < 4; J++){
            for(int N = 0; N < 6; N++){
                pelicula[I].butaca[J][N]= rand() % 2;
            }
        }
    }


}

void MIRARDATOS(struct sala pelicula[], int L){

    for(int I = 0; I < L; I++){
        printf("\n%s  Sala %d", pelicula[I].peli, pelicula[I].codigo);


        for(int J = 0; J < 4; J++){
            printf("\n\n\n\t\t\t\t");
            for(int N = 0; N < 6; N++){
                printf("%8d", pelicula[I].butaca[J][N] );
            }
        }
        printf("\n\n\n------------------------------------------------------------------------------------------------------------------\n\n");
    }

}

int MAS_VISTA(struct sala pelicula[]){

    int suma = 0;
    int espectadores = 0;
    int codigo;

    for(int I = 0; I < 4; I++){

        for(int J = 0; J < 4; J++){
            for(int N = 0; N < 6; N++){
                suma  = suma + pelicula[I].butaca[J][N];
            }
        }

        if(suma > espectadores){
            espectadores = suma;
            codigo = pelicula[I].codigo;
        }
        suma = 0;
    }

    return codigo;
}


int BUSCAR_PELI(struct sala pelicula[], char titulo[]){

    int codigo = -1;
    for(int I = 0; I < 4; I++){
        if( !strcmpi(pelicula[I].peli, titulo)){
            codigo = pelicula[I].codigo;
    }

}
    return codigo;

}
