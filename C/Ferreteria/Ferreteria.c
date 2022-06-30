#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 5

struct producto {
	char nombre[40];
	float precio;
	int ventas_mes[12];
};

void CARGAR_PRODUCTOS(struct producto[], int);
void MIRAR_PRODUCTOS(struct producto[], int);
void CALCULAR_VENTAS(struct producto[], int);
void MEJOR_MES(struct producto[], char[], int);

int main(){
    srand(time(0));

    struct producto productos[LENGTH];

    CARGAR_PRODUCTOS(productos, LENGTH);
    MIRAR_PRODUCTOS(productos, LENGTH);
    CALCULAR_VENTAS(productos, LENGTH);
}


void CARGAR_PRODUCTOS(struct producto productos[], int L){

    char nombres[][50] = {"Sierra", "Atornillador", "Sellador", "Taladro", "Amoladora"};

    float precio[] = {3199.99, 19200, 7899.99, 123450, 79800.35};

    for(int I = 0; I < L; I++){
        strcpy(productos[I].nombre, nombres[I]);

        productos[I].precio = precio[I];

        for(int J = 0; J < 12; J++){
            productos[I].ventas_mes[J] = (rand() % 100) + 1;
        }

    }

}

void MIRAR_PRODUCTOS(struct producto productos[], int L){

    for(int I = 0; I < L; I++){
        printf("\n\n%s\n", productos[I].nombre);

        printf("\nPrecio: $%.2f\n", productos[I].precio);

        printf("\nVentas\n");
        for(int J = 0; J < 12; J++){
            printf("\nMes %d: %d ventas\n", J + 1, productos[I].ventas_mes[J]);
        }

        MEJOR_MES(productos, productos[I].nombre, L);
        printf("-----------------------------------------------------------------------------");
    }
}

void CALCULAR_VENTAS(struct producto productos[], int L){

    int meses_ventas[12] = {0};

    for(int I = 0; I < L; I++){
        for(int J = 0; J < 12; J++){
           meses_ventas[J] = meses_ventas[J] + productos[I].ventas_mes[J];
        }

    }

    int suma = 0, posicion;

    for(int J = 0; J < 12; J++){
        if( meses_ventas[J] > suma){
            suma = meses_ventas[J];
            posicion = J;
        }
    }

    printf("\n\nEl mes en el que se obtuvo un mayor porcentaje de ventas fue el %d, donde se vendieron %d productos\n\n", posicion + 1, suma);
}

void MEJOR_MES(struct producto productos[], char producto[], int L){

    int cont = 0, posicion;

    for(int I = 0; I < L; I++){
        if( !strcmp(productos[I].nombre, producto) ){
            for(int J = 0; J < 12; J++){
                if( productos[I].ventas_mes[J] > cont){
                    cont = productos[I].ventas_mes[J];
                    posicion = J;
                }
            }
        }

    }

    printf("\nEl mejor mes de venta fue el mes %d, habiendo vendido %d unidades\n\n", posicion + 1, cont);

}
