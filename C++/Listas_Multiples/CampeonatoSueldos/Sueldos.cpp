#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

using namespace std;

class JUGADOR{
    public:
        char NOM[30];
        JUGADOR * SIG;

        JUGADOR(char *);

};

JUGADOR::JUGADOR(char * NOMBRE){

    SIG = NULL;
    strcpy(NOM, NOMBRE);

}

class EQUIPO{
    public:
        char NOM[20];
        JUGADOR * PUNJU;
        EQUIPO * SIG;

        EQUIPO(char *);
        ~EQUIPO();

};

EQUIPO::EQUIPO(char * NOMBRE){

    strcpy(NOM, NOMBRE);
    PUNJU = NULL;
    SIG = NULL;

}

EQUIPO::~EQUIPO(){

    JUGADOR * P;

    P = PUNJU;

    while(P){
        delete P;

        P = P->SIG;
    }


}

class SUELDO{
    public:
        char NOM[30];
        int SALARIO;
        SUELDO * SIG;

        SUELDO(char * , int);

};

SUELDO::SUELDO(char * NOMBRE, int CANT){

    strcpy(NOM, NOMBRE);
    SALARIO = CANT;

}


class CAMPEONATO{

    private:
        SUELDO * INISUELDO;
        EQUIPO * INIEQUIPO;

        void INSERTAR_SUELDO(SUELDO *);
        void INSERTAR_EQUIPO(EQUIPO *);

        int BUSCAR(char *);

    public:
        CAMPEONATO();
        ~CAMPEONATO();

        void MIRAR_SUELDOS();
        void MIRAR_EQUIPOS();

        void INSERTAR_JUGADOR(EQUIPO *, JUGADOR *);
        void CREAR_EQUIPO(char[][20]);

        void friend MILLONARIO(CAMPEONATO &);

};

CAMPEONATO::CAMPEONATO(){

    INISUELDO = NULL;
    INIEQUIPO = NULL;

    SUELDO * PSUELDO;
    EQUIPO * PEQUIPO;
    JUGADOR * PJUGADOR;

    char NOM_JUGADORES[16][20] = {"MESSI" , "RIQUELME" , "RONALDO" , "ZIDANE" ,
                                "PELE" , "NEYMAR" , "MBAPPE" , "MARADONA" ,
                                "HENRY" , "ROMERO" , "PAREDES" , "IBARRA" ,
                                "PALACIOS" , "PALERMO" , "ROMARIO" , "SUAREZ" };

    char NOM_EQUIPOS[][20] = {"BLANCO", "AZUL", "ROJO", "AMARILLO"};

    int SALARIO;

    for(int J = 0; J < 4; J++){

        PEQUIPO = new EQUIPO(NOM_EQUIPOS[J]);

        INSERTAR_EQUIPO(PEQUIPO);
    }

    for(int I = 0; I < 16; I++){

        SALARIO = (rand() % 900) + 100;
        PSUELDO = new SUELDO(NOM_JUGADORES[I], SALARIO);

        INSERTAR_SUELDO(PSUELDO);

    }

    CREAR_EQUIPO(NOM_JUGADORES);

}

CAMPEONATO::~CAMPEONATO(){

    SUELDO * PSUELDO;
    EQUIPO * PEQUIPO;

    PSUELDO = INISUELDO;
    PEQUIPO = INIEQUIPO;

    while(PSUELDO){

        delete PSUELDO;

        PSUELDO = PSUELDO->SIG;
    }

    while(PEQUIPO){
        delete PEQUIPO;
        PEQUIPO = PEQUIPO->SIG;
    }
}

void CAMPEONATO::INSERTAR_SUELDO(SUELDO * PSUELDO){

    PSUELDO->SIG = INISUELDO;
    INISUELDO = PSUELDO;

}

void CAMPEONATO::INSERTAR_EQUIPO(EQUIPO * PEQUIPO){

    PEQUIPO->SIG = INIEQUIPO;
    INIEQUIPO = PEQUIPO;

}

void CAMPEONATO::CREAR_EQUIPO(char NOMBRES[][20]){

    EQUIPO * PEQUIPO;
    JUGADOR * PJUGADOR;

    PEQUIPO = INIEQUIPO;

    for(int I = 0; I < 16; I++){

        PJUGADOR = new JUGADOR(NOMBRES[I]);
        INSERTAR_JUGADOR(PEQUIPO, PJUGADOR);

        if(PEQUIPO->SIG != NULL){
            PEQUIPO = PEQUIPO->SIG;
        }
        else{
            PEQUIPO = INIEQUIPO;
        }
    }
}


void CAMPEONATO::INSERTAR_JUGADOR(EQUIPO * PEQUIPO, JUGADOR * PJUGADOR){

    JUGADOR * P;

    if( !PEQUIPO->PUNJU ){ //LISTA VACIA

        PEQUIPO->PUNJU = PJUGADOR;
        return;
    }


    P = PEQUIPO->PUNJU;

    while(P->SIG){
        P = P->SIG;
    }

    P->SIG = PJUGADOR;


}


void CAMPEONATO::MIRAR_SUELDOS(){

    SUELDO * P;

    P = INISUELDO;

    while(P){

        cout<<"\n\n\t" << P->NOM << " $ " << P->SALARIO;

        P = P->SIG;
    }
}

void CAMPEONATO::MIRAR_EQUIPOS(){

    EQUIPO * PEQUIPO;
    JUGADOR * PJUGADORES;

    PEQUIPO = INIEQUIPO;

    while(PEQUIPO){

        PJUGADORES = PEQUIPO->PUNJU;
        cout<<"\n\n\t\t\t EQUIPO " << PEQUIPO->NOM;

        while(PJUGADORES){

            cout<<"\n\n\t " << PJUGADORES->NOM;

            PJUGADORES = PJUGADORES->SIG;
        }

        PEQUIPO = PEQUIPO->SIG;
        cout<< "\n\n\t----------------------------------";
    }
}

int CAMPEONATO::BUSCAR(char * NOMBRE){

    SUELDO * P;

    P = INISUELDO;

    while(P){

        if( !strcmp(P->NOM, NOMBRE) ){
            return P->SALARIO;
        }

        P = P->SIG;
    }
    return 0;

}

void MILLONARIO(CAMPEONATO &);

int main(){

    srand(290);
    CAMPEONATO C;

    C.MIRAR_SUELDOS();
    C.MIRAR_EQUIPOS();

    MILLONARIO(C);


    cout<<"\n\n\n\n\n\n\n";
    return 0;
}

void MILLONARIO (CAMPEONATO & CAMP){

    EQUIPO * PEQUIPO, * MAS_CARO;
    JUGADOR * PJUGADOR;

    PEQUIPO = CAMP.INIEQUIPO;
    int MONTO = 0;
    int MAXIMO = 0;

    while(PEQUIPO){
        PJUGADOR = PEQUIPO->PUNJU;

        while(PJUGADOR){

            MONTO = MONTO + CAMP.BUSCAR(PJUGADOR->NOM); // Esta funcion retorna el sueldo del jugador buscado

            PJUGADOR = PJUGADOR->SIG;
        }

        if(MONTO > MAXIMO){
            MAXIMO = MONTO;
            MAS_CARO = PEQUIPO;
        }

        PEQUIPO = PEQUIPO->SIG;
        MONTO = 0;
    }

    cout<< "\n\n\n\tEL EQUIPO MAS CARO ES "<< MAS_CARO->NOM << " GASTANDO UN TOTAL DE "<< MAXIMO << " EN SUELDOS";
}
