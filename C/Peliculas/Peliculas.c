#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F 4
#define A 4
#define C 20

struct pelicula {
    char nombre[C];
    int recaudacion;
    char personajes[A][C];
    int estreno;
};

void CARGARDATOS(struct pelicula[], int, int);
void ORDENARDATOS(struct pelicula[], int);
void MOSTRARDATOS(struct pelicula[], int, int);


int main(){

    srand(329);
    struct pelicula film[F];

    CARGARDATOS(film, F, A);
    ORDENARDATOS(film, F);
    MOSTRARDATOS(film, F, A);

}

void CARGARDATOS (struct pelicula film[], int L, int P){

    for(int I = 0; I < L ; I++){
        //Se ingresa el nombre
        printf("\nIngrese el nombre de la pelicula que desee: ");
        fflush(stdin);
        gets(film[I].nombre);

        //Se determina la recaudacion total
        film[I].recaudacion = rand() % 900000 + 100000;

        //Se ingresa los personajes de esa pelicula
        printf("\nIngresar %d personajes en esa pelicula\n", P);
        for(int J = 0; J < P; J++){
            printf("\nPersonaje[%d]: ", J+1);
            fflush(stdin);
            gets(film[I].personajes[J]);
        }

        //Se ingresa el año de lanzamiento
        printf("\nIngresar estreno: ");
        scanf("%d", &film[I].estreno);

        if( I < L - 1 ){
            printf("\n\nSiguiente pelicula\n");
        }
    }
}

void ORDENARDATOS(struct pelicula film[], int L){

    struct pelicula AUX;
    for(int I = 0; I < L - 1; I++){
        for(int J = 0; J < L - I - 1; J++){
            if(film[J].estreno < film[J + 1].estreno){
                AUX = film[J];
                film[J] = film[J + 1];
                film[J + 1] = AUX;
            }
            else if(film[J].estreno == film[J + 1].estreno){       //Si el año de estreno es el mismo, se ordena alfabeticamente
                if(strcmp(film[J].nombre, film[J + 1].nombre) > 0){
                    AUX = film[J];
                    film[J] = film[J + 1];
                    film[J + 1] = AUX;
                }
            }
        }
    }


}

void MOSTRARDATOS(struct pelicula film[], int L, int P){

    for(int I = 0; I < L; I++){

        printf("\n%s\n", film[I].nombre);

        printf("\nPersonajes\n");
        for(int J = 0; J < P; J++){
            printf("%d.%s\n", J + 1, film[I].personajes[J]);
        }

        printf("\nRecaudacion total de $%d\n", film[I].recaudacion);

        printf("\nFecha de lanzamiento %d\n\n", film[I].estreno);

    }

}
