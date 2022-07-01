#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class NODO {
    public:
        char NOM[30];
        NODO * SIG;
};

class LISTA2 ; // SE INDICA QUE LISTA 2 VA A EXISTIR. VOID FRIEND AGREGA()
class LISTA1{
    private:
        NODO * INICIO;
    public:
        LISTA1();
        ~LISTA1();

        void friend AGREGA(LISTA1 &, LISTA2 &);
};

LISTA1::LISTA1(){

	INICIO = NULL ;
    NODO * P;
    char NOM[][20] = { "PEPE" , "LOLA" , "PEPE" , "LOLA" ,
			   "LUIS" , "LUIS" , "MONICA" , "LUIS" ,
			   "LOLA" , "PEPE" , "PEPE" , "LOLA" ,
			   "LOLA" , "MONICA" , "PEPE" , "PACO" } ;

    for(int I = 0; I < 16; I++){
        P = new NODO;
        strcpy(P->NOM, NOM[I]);

        P->SIG = INICIO;
        INICIO = P;
    }

}

LISTA1::~LISTA1(){

    NODO * P;

    P = INICIO;

    while( P ){

        delete P;

        P = P->SIG;
    }
}

class CANDIDATO{
    public:
        char NOM[30];
        int CANT;
        CANDIDATO * SIG;

        CANDIDATO();
};

CANDIDATO::CANDIDATO(){

    SIG = NULL;
    CANT = 0;

}


class LISTA2{
    private:
        CANDIDATO * INICIO;

        CANDIDATO * BUSCAR(char *);

        void PONER(CANDIDATO *);
    public:
        LISTA2();
        ~LISTA2();
        void friend AGREGA(LISTA1 &, LISTA2 &);

        void AGREGAR_CAND(char *);

        void MIRAR();
};

LISTA2::LISTA2(){

    INICIO = NULL;

}

LISTA2::~LISTA2(){

    CANDIDATO * P;

    P = INICIO;

    while(P){

        delete P;

        P = P->SIG;
    }
}


CANDIDATO * LISTA2::BUSCAR(char * NOM){

    CANDIDATO * P;

    P = INICIO;

    while(P){

        if( !strcmp(P->NOM, NOM) ){
            return P;
        }

        P = P->SIG;
    }

    return NULL;
}

void LISTA2::AGREGAR_CAND(char * NOM){

    CANDIDATO * P;

    P = new CANDIDATO;

    strcpy(P->NOM, NOM);
    P->CANT++;

    PONER(P);

}

void LISTA2::PONER(CANDIDATO * P){

    P->SIG = INICIO;    // SE AGREGA EL NUEVO CANDIDATO AL COMIENZO DE LA LISTA
    INICIO = P;

}

void LISTA2::MIRAR(){

    CANDIDATO * P;

    P = INICIO;

    while(P){

        cout<< "\n\n\t" << P->NOM << "\t" << P->CANT;

        P = P->SIG;
    }
}


void AGREGA(LISTA1 &, LISTA2 &);

int main(){

    LISTA1 LV;
    LISTA2 LC;

    AGREGA(LV, LC);

    LC.MIRAR();


    cout<<"\n\n\n\nFIN DEL PROGRAMA\n\n\n";
    return 0;

}

void AGREGA(LISTA1 & LV, LISTA2 & LC){

    NODO * PV; //LISTA 1
    CANDIDATO * PC; //LISTA 2

    PV = LV.INICIO;

    while( PV ){

        PC = LC.BUSCAR( PV->NOM ); // SE BUSCA AL CANDIDATO CON EL NOMBRE EN LISTA

        if( PC ){

            PC->CANT++;

        }else{

            LC.AGREGAR_CAND(PV->NOM);

        }

        PV = PV->SIG;
    }
}
