#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 5

struct fecha { int dia; int mes; int anio;};

struct registro {
	int dni;
	char nombre[50];
	struct fecha fecha_v;
	int dosis;
};

void CARGARDATOS(struct registro[], int);
void MIRARDATOS(struct registro[], int);
void mejor_mes(struct registro[], int); //Funcion que debe imprimir en pantalla el mejor mes de vacunacion, mes en el cual se aplicaron mas dosis.
void pacientes_completos(struct registro[], int);

int main(){

    srand(398325);

    struct registro persona[LENGTH];

    CARGARDATOS(persona, LENGTH);

    mejor_mes(persona, LENGTH);

    pacientes_completos(persona, LENGTH);
}

void CARGARDATOS (struct registro persona[], int L){

    char nombre[50];

    printf("\nIngrese el registro de %d pacientes vacunados\n\n", L);

    for(int I = 0; I < L; I++){

    printf("\nNombre del paciente %d\n\n", I + 1);
    fflush(stdin);
    strcpy(persona[I].nombre, gets(nombre));

    printf("\nNumero de DNI\n\n");
    scanf("%d", &persona[I].dni);

    printf("\n\n");

    do{
        printf("Dia: ");
        scanf("%d", &persona[I].fecha_v.dia);
        printf("\n\n");
        printf("Mes: ");
        scanf("%d", &persona[I].fecha_v.mes);
        printf("\n\n");
        printf("Anio: ");
        scanf("%d", &persona[I].fecha_v.anio);
    }while(persona[I].fecha_v.dia > 31 || persona[I].fecha_v.mes  > 12 || persona[I].fecha_v.dia > 28 && persona[I].fecha_v.mes == 2);

    do{
        printf("\nNumero de dosis\n\n");
        scanf("%d", &persona[I].dosis);

    }while(persona[I].dosis > 2);

     printf("\nNombre: %s\n\nDNI: %d\n\nFecha: %d/%d/%d\n\nDosis numero: %d\n\n", persona[I].nombre, persona[I].dni,persona[I].fecha_v.dia,
                                                                                      persona[I].fecha_v.mes, persona[I].fecha_v.anio,
                                                                                      persona[I].dosis);

    }
}

void MIRARDATOS (struct registro persona[], int L){


    for(int I = 0; I < L; I++){
        printf("\nNombre: %s\n\nDNI: %d\n\nFecha: %d/%d/%d\n\nDosis numero: %d\n\n", persona[I].nombre, persona[I].dni,persona[I].fecha_v.dia,
                                                                                      persona[I].fecha_v.mes, persona[I].fecha_v.anio,
                                                                                      persona[I].dosis);
    }

}

void mejor_mes(struct registro persona[], int L){

    int dosis_aplicadas[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    char meses[][20] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO",
                        "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE",
                        "DICIEMBRE"};
    int aux;
    char aux2[20];

    for(int I = 0; I < L; I++){
        dosis_aplicadas[persona[I].fecha_v.mes - 1]++; //Se resta uno porque seria su posicion en el vector de dosis aplicadas
    }

    int cont = 0, posicion = 0;
    for(int J = 0; J < 12; J++){
        if(dosis_aplicadas[J] > cont){
            cont = dosis_aplicadas[J];
            posicion = J;
        }
    }

    printf("\nEl mejor mes de vacunacion fue %s, se vacuno %d persona/s\n", meses[posicion], cont);
    printf("\n\n");
}

void pacientes_completos(struct registro personas[], int L){

    int cont = 0;
    printf("\nPacientes con esquema de vacunacion completo\n");
    for(int I = 0; I < L; I++){
        if(personas[I].dosis == 2){
            printf("\n\n%s", personas[I].nombre);
        }
    }

    printf("\n\n\n");
}
