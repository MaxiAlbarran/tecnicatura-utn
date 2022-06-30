/*Se cuenta con un vector de estructuras con datos de camiones que realizan viajes entre ciudades.
Construya cuatro funciones que reciban el vector y su tamaño, y realicen lo siguiente:
a) Permita el ingreso de los datos de 4 camiones y 2 viajes para cada uno.
b) Muestre en pantalla las patentes, sin repetir. No se debe modificar el orden del vector original.
c) Muestre en pantalla la patente del camión que más viajes realizó. Para esto modifique el punto a, de manera de poder ingresar algún camión con más viajes y probar este punto c.
d) Muestre en pantalla todos los viajes, ordenados por fecha. Los que son de la misma fecha se deben ordenar por peso transportado descendente.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 9

char patentes[][10] = {"JUF 249", "JUF 249", "XBY 315", "XBY 315", "OKL 789", "OKL 789", "RFT 317", "RFT 317", "OKL 789"};

char ciudades[][50] = {"LUJAN", "JUNIN", "BAHIA BLANCA", "LA PLATA", "ARECO", "MATADEROS", "QUILMES", "CASANOVA", "MORON"};


struct fecha { int dia; int mes; int anio; };

struct camiones {
	char patente[10];
	char ciudad_origen[50];
	char ciudad_destino[50];
	float peso_transportado;
	struct fecha fecha_viaje;
};

void CARGARDATOS( struct camiones[], char[][10], char[][50], int );

void MOSTRARVIAJES ( struct camiones[], int );
void MOSTRARPATENTES ( struct camiones[], int );

void CALCULAR_VIAJES( struct camiones[], int);

void ORDENAR_VIAJES( struct camiones[], int);
void MOSTRARVIAJES ( struct camiones[], int );

int main(){
    srand(time(0));

    struct camiones camion[N];

    CARGARDATOS(camion, patentes, ciudades, N);

    ORDENAR_VIAJES(camion, N);
    MOSTRARVIAJES(camion, N);

    MOSTRARPATENTES(camion, N);

    CALCULAR_VIAJES(camion, N);


    printf("\n\n\n\n");

}

void CARGARDATOS ( struct camiones camion[], char patentes[][10], char ciudades[][50], int L ){

    for(int I = 0; I < L; I++){
        printf("\n\n\tCamion %d\n\n", I+1);

        printf("PATENTE: ");
        fflush(stdin);
        gets(camion[I].patente);

        printf("\n\nORIGEN: ");
        gets(camion[I].ciudad_origen);
        printf("\n\nDESTINO: ");
        gets(camion[I].ciudad_destino);

        printf("\n\nPESO TRANSPORTADO: ");
        scanf("%f", &camion[I].peso_transportado);

        do{
        printf("\n\n\n");
        printf("Dia: ");
        scanf("%d", &camion[I].fecha_viaje.dia);
        printf("\n\n");
        printf("Mes: ");
        scanf("%d", &camion[I].fecha_viaje.mes);
        printf("\n\n");
        printf("Anio: ");
        scanf("%d", &camion[I].fecha_viaje.anio);
    }while(camion[I].fecha_viaje.dia > 31 || camion[I].fecha_viaje.mes  > 12 || camion[I].fecha_viaje.dia > 28 && camion[I].fecha_viaje.mes == 2);

    }

}

void MOSTRARVIAJES ( struct camiones camion[], int L){

    printf("\n\n\nCAMIONES\n\n");

    for(int I = 0; I < L ; I++){
        printf("\nPATENTE: %s\n\n", camion[I].patente);

        printf("\nDESDE %s HASTA %s\n\n", camion[I].ciudad_origen, camion[I].ciudad_destino);

        printf("\nPESO TRANSPORTADO %.2f\n\n", camion[I].peso_transportado);

        printf("\nFECHA DEL VIAJE %d/%d/%d", camion[I].fecha_viaje.dia, camion[I].fecha_viaje.mes, camion[I].fecha_viaje.anio);

        printf("\n\n\n---------------------------------------------\n");

    }
    printf("\n\n");

}

void MOSTRARPATENTES(struct camiones camion[], int L){

    int cont = 0;

    printf("\n\nPATENTES\n\n");
    for(int I = 0; I < L; I++){
        for(int J = I; J < L; J++){
            if( !strcmpi(camion[I].patente, camion[J].patente) ){
                cont++;
            }
        }
        if(cont == 1){
            printf("\n\n%s\n\n", camion[I].patente);
        }
        cont = 0;
    }

}

void CALCULAR_VIAJES(struct camiones camion[], int L){

    int cont = 0;
    int suma_viajes = 0;
    int posicion;

    printf("\n\n\n\n");
    for(int I = 0; I < L; I++){
        for(int J = I; J < L; J++){
            if( !strcmpi(camion[I].patente, camion[J].patente) ){
                suma_viajes++;
            }
        }
        if(suma_viajes > cont){
            cont = suma_viajes;
            posicion = I;
        }
        suma_viajes = 0;
    }

    printf("\n\nEL CAMION QUE MAS VIAJES REALIZO FUE %s\n\n", camion[posicion].patente);

}

void ORDENAR_VIAJES( struct camiones camion[], int L){

    struct camiones AUX;

    for(int I = 0; I < L - 1; I++){
        for(int J = 0; J < L - I - 1; J++){
            if( camion[J].fecha_viaje.anio > camion[J + 1].fecha_viaje.anio||
                camion[J].fecha_viaje.anio == camion[J + 1].fecha_viaje.anio &&
                camion[J].fecha_viaje.mes > camion[J + 1].fecha_viaje.mes||
                camion[J].fecha_viaje.anio == camion[J + 1].fecha_viaje.anio &&
                camion[J].fecha_viaje.mes == camion[J + 1].fecha_viaje.mes &&
                camion[J].fecha_viaje.dia > camion[J + 1].fecha_viaje.dia  ){

                    AUX = camion[J];
                    camion[J] = camion[J + 1];
                    camion[J + 1] = AUX;

            }else if(camion[J].peso_transportado < camion[J + 1].peso_transportado){

                    AUX = camion[J];
                    camion[J] = camion[J + 1];
                    camion[J + 1] = AUX;

            }
        }
    }

}

/**/

