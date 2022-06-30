#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH 20

struct fecha{
    int dia;
    int mes;
    int anio;
};

struct alumno {
    char nombre[20];
    char sexo;
    int notas[20];
    struct fecha nacimiento;
};

void CARGAR_DATOS(struct alumno[], int);

void CALCULAR_PROMEDIOS(struct alumno[], int); //Muestra en pantalla el promedio tanto de las mujeres como de los hombres
void DATOS_MATERIA(struct alumno[], int, int); //Muestra de manera decreciente los datos de cada alumno segun la materia ingresada
void ORDENAR_DATOS(struct alumno[], int,  int);
void PROMEDIO_ALUMNO(struct alumno[], char[], int);//Muestra el promedio total de un alumno segun el nombre


int main(){

    srand(time(0));
    struct alumno alumnos[LENGTH];

    CARGAR_DATOS(alumnos, LENGTH);
    CALCULAR_PROMEDIOS(alumnos, LENGTH);

    int ingreso;
    do{
        printf("\n\nIngrese la materia que desee del 1 al 20 ");
        scanf("%d", &ingreso);
    }while(ingreso > 20 || ingreso < 1);

    DATOS_MATERIA(alumnos,ingreso, LENGTH);

    char nombre[20];
    printf("\n\nIngrese el nombre de algun alumno para calcular su promedio ");
    fflush(stdin);
    gets(nombre);

    PROMEDIO_ALUMNO(alumnos, nombre, LENGTH);
}

void CARGAR_DATOS(struct alumno alumnos[], int L){

    char sexo;

    for(int I = 0; I < L; I++){
        printf("\nAlumno %d", I + 1);

        printf("\n\nNombre: ");
        fflush(stdin);
        gets(alumnos[I].nombre);

        printf("\n\nSexo (F O M): ");
        int exit = 0;
        do{
            alumnos[I].sexo = getchar();
            if(alumnos[I].sexo == 'F' || alumnos[I].sexo == 'M' )
                exit = 1;
        }while( exit == 0);

        do{
            printf("\n\nDia: ");
            scanf("%d", &alumnos[I].nacimiento.dia);
            printf("\n\n");
            printf("Mes: ");
            scanf("%d", &alumnos[I].nacimiento.mes);
            printf("\n\n");
            printf("Anio: ");
            scanf("%d", &alumnos[I].nacimiento.anio);
        }while(alumnos[I].nacimiento.dia > 31 || alumnos[I].nacimiento.mes  > 12 || alumnos[I].nacimiento.dia > 28 &&  alumnos[I].nacimiento.mes == 2);

        for(int J = 0; J < 20; J++){
            alumnos[I].notas[J] = (rand() % 10) + 1;
        }
    }
}

void CALCULAR_PROMEDIOS(struct alumno alumnos[], int L){

    int alumnosF = 0, notasF = 0;
    int alumnosM = 0, notasM = 0;
    float promedioM, promedioF;

    for(int I = 0; I < L; I++){
        if(alumnos[I].sexo == 'F'){
            alumnosF++;
            for(int J = 0; J < 20; J++){
                notasF = notasF + alumnos[I].notas[J];
            }
        }else{
            alumnosM++;
            for(int J = 0; J < 20; J++){
                notasM = notasM + alumnos[I].notas[J];
            }
        }
    }


    promedioF = (float)notasF / (20*alumnosF);
    promedioM = (float)notasM / (20*alumnosM);

    printf("\nEl promedio total de los %d alumnos masculinos es de %.2f\n\n", alumnosM, promedioM);
    printf("El promedio total de los %d alumnos femeninos es de %.2f\n\n", alumnosF, promedioF);

}

void DATOS_MATERIA(struct alumno alumnos[],int codigo, int L){

    for(int I = 0; I < L; I++){
        for(int J = 0; J < 20; J++){
            if(J == codigo - 1){
                ORDENAR_DATOS(alumnos, codigo - 1, L);
                printf("\nAlumno: %s\n", alumnos[I].nombre);
                printf("\nSexo %c\n", alumnos[I].sexo);
                printf("\nNotas\n\n");
                printf("Nota: %d\n", alumnos[I].notas[J]);
                printf("\n\n\n-------------------------------------------------\n\n");
            }
        }
    }
}

void ORDENAR_DATOS(struct alumno alumnos[],int C, int L){

    struct alumno AUX;

    for(int I = 0; I < L - 1; I++){
        for(int J = 0; J < L - I - 1; J++){
            if(alumnos[J].notas[C] < alumnos[J + 1].notas[C]){
                AUX = alumnos[J + 1];
                alumnos[J + 1] = alumnos[J];
                alumnos[J] = AUX;
            }
        }
    }
}

void PROMEDIO_ALUMNO(struct alumno alumnos[], char N[], int L){

    int suma = 0;
    float promedio;

    for(int I = 0; I < L; I++){
        if( !strcmpi(alumnos[I].nombre, N) ){
            for(int J = 0; J < 20; J++){
                suma = suma + alumnos[I].notas[J];
            }
        }
    }

    promedio = (float)suma / 20;

    if( promedio != 0 ){
        printf("\n\nEl promedio de %s es de %.2f\n\n", N, promedio);
    }else{
        printf("\n\nEl nombre ingresado es invalido\n\n");
    }
}
