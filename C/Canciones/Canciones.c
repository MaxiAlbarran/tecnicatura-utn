#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 5

struct cancion {
	char nombre[50];
	char autor[50];
	int reproducciones[12]; //Cantidad de reproducciones de la cancion en cada mes del año
};

void CARGARCANCIONES(struct cancion[], int, int);
void MIRARCANCIONES(struct cancion[], int, int);
void autores(struct cancion[], int); //Esta funcion muestra el nombre de los artistas sin repetirlos
void autor_totales(struct cancion[], int, char[]); // Esta funcion debe mostrar la cantidad de reproducciones total del artista ingresado

int main(){

    srand(10);

    struct cancion canciones[LENGTH];
    char artista[50];

    CARGARCANCIONES(canciones, LENGTH, 12);
    MIRARCANCIONES(canciones, LENGTH, 12);
    autores(canciones, LENGTH);

    printf("\n\nIngrese el nombre de un artista para ver la cantidad total de reproducciones de sus canciones: ");
    fflush(stdin);
    gets(artista);

    autor_totales(canciones, LENGTH, artista);

}

void CARGARCANCIONES(struct cancion canciones[], int L, int R){

    char nombres_canciones[][50] = {"My Name Is", "Life is good", "One dance", "Diamonds", "Stan"};
    char autores[][50] = {"Eminem", "Drake", "Drake", "Rihanna", "Eminem"};

    for(int I = 0; I < L; I++){
        strcpy(canciones[I].nombre, nombres_canciones[I]);
        strcpy(canciones[I].autor, autores[I]);
        for(int J = 0; J < R; J++){
            canciones[I].reproducciones[J] = (rand() % 900) + 100;
        }
    }

}

void MIRARCANCIONES(struct cancion canciones[], int L, int R){

    char meses[][20] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};

    for(int I = 0; I < L; I++){
        printf("\nAutor: %s\n", canciones[I].autor);
        printf("\nCancion: %s\n", canciones[I].nombre);
        printf("\nReproducciones\n");
        for(int J = 0; J < R; J++){
            printf("%s: %d M\n\n", meses[J], canciones[I].reproducciones[J]);
        }
        printf("\t\t----------------------------------------------------------------------------\n");
    }

}

void autores(struct cancion canciones[], int L){

    int cont = 0;
    printf("\n\n\tARTISTAS\n\n");
    for(int I = 0; I < L; I++){
        for(int J = I; J < L ; J++){
            int comparacion = strcmp(canciones[I].autor, canciones[J].autor);
            if(comparacion == 0){
                cont++;
            }
        }
        if(cont == 1){
            printf("\n%s\n", canciones[I].autor);
        }

        cont = 0;
    }

}

void autor_totales(struct cancion canciones[], int L, char autor[]){

    int suma = 0;
    char artista[50];
    for(int I = 0; I < L; I++){
        if( !strcmpi(canciones[I].autor, autor)){
            strcpy(artista, canciones[I].autor);
            for(int J = 0; J < 12; J++){
                suma = suma + canciones[I].reproducciones[J];
            }
        }
    }

    if(suma > 0){
    printf("\n%s tuvo en total %d M de reproducciones\n", artista, suma);
    }else{
    printf("\nEl autor %s no se encuentra disponible, verifique su ingreso\n", autor);
    }

}
