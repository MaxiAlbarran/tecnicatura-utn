#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

class CELEB{

    public:
        char NOM[30];
        int VOTOS;
        CELEB * SIG;

        CELEB(char *);

};

CELEB::CELEB(char * S){

    strcpy(NOM, S);
    VOTOS = 1;

}

class LISTA{
    private:
        CELEB * INICIO;
        void PONER( CELEB * );
        CELEB * BUSCAR(char *);

        CELEB * MAXIMO();

    public:

        LISTA();
        ~LISTA();
        void AGREGAR(char *);

        void MIRAR();

        void ESCRUTAR();

};

LISTA::LISTA(){

    INICIO = NULL;

}

LISTA::~LISTA(){

    CELEB * P;

    P = INICIO;

    while(P){

        delete P;

        P = P->SIG;
    }
}

void LISTA::AGREGAR( char * S ){

    CELEB * P;

    P = BUSCAR(S);

    if( !P ){

        P = new CELEB(S); //PERSONALIDAD NO EXISTENTE

        PONER(P);
        return;
    }

    P->VOTOS++;

}

CELEB * LISTA::BUSCAR(char * S){

    CELEB * P;

    P = INICIO;

    while(P){

        if( !strcmp(P->NOM, S) ){
            return P;
        }

        P = P->SIG;
    }

    return NULL;
}

void LISTA::PONER( CELEB * P ){

    P->SIG = INICIO;
    INICIO = P;

}

void LISTA::MIRAR(){

    CELEB * P;

    P = INICIO;

    cout<< "\n\n\tLISTA DE PERSONALIDADES\n\n";

    while(P){

        cout<< "\n\n"<< P->NOM << "   :   "<< P->VOTOS;
        P = P->SIG;
    }
}

CELEB * LISTA::MAXIMO(){

    CELEB * P, * GANADOR;

    GANADOR = P = INICIO;

    while( P ){

        if( P->VOTOS > GANADOR->VOTOS){
            GANADOR = P;
        }

        P = P->SIG;
    }

    return GANADOR;
}

void LISTA::ESCRUTAR(){

    CELEB * GAN;

    GAN = MAXIMO();

    cout<< "\n\n\nEL GANADOR ES "<< GAN->NOM << " CON " << GAN->VOTOS << " VOTOS\n\n\n" ;

}

int main(){

    LISTA L;

    char VOTO[30];

    cout<< "\n\n\n\tPERSONALIDAD DEL AÑO: ";
    gets(VOTO);

    while( strcmp(VOTO, "FIN") ){

        L.AGREGAR(VOTO);

        cout<< "\n\n\n\tPERSONALIDAD DEL AÑO: ";
        gets(VOTO);
    }

    L.MIRAR();
    L.ESCRUTAR();

    return 0;
}
