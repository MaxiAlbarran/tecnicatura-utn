#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std ;

class AUTO { //NODOS
    public:
        char MODELO[30];
        int ANIO;
        AUTO * SIG;

        AUTO(char *, int);

};

AUTO::AUTO(char * N, int A){

    strcpy(MODELO, N);
    ANIO = A;
}

class CLIENTE { //LISTA
    public:
        char NOMBRE[30];
        char TELEFONO[20];
        AUTO * PRIMERAUTO;
        CLIENTE * SIG;

        CLIENTE(char *, char *);
        ~CLIENTE();
};

CLIENTE::CLIENTE(char * N, char * T){

    PRIMERAUTO = NULL;
    strcpy(NOMBRE, N);
    strcpy(TELEFONO, T);

}

CLIENTE::~CLIENTE(){

    AUTO * P;

    P = PRIMERAUTO;

    while(P){
        delete P;
        P = P->SIG;
    }

}

class LISTACLIENTES { //GUIRNALDA
    private:
        CLIENTE * INICIO;
        CLIENTE * BUSCAR(char *);

        void PONER(CLIENTE *);
    public:
        LISTACLIENTES();
        ~LISTACLIENTES();

        void AGREGAR(char *, char *);

        void AGREGARAUTO(char *, char *, int);

        void MIRAR();

        int CANTAUTOS(char *);

        void VACIARAUTOS(char *);

        int CANTCLIENTES();
};

LISTACLIENTES::LISTACLIENTES(){

    INICIO = NULL;

}

LISTACLIENTES::~LISTACLIENTES(){

    CLIENTE * P;

    P = INICIO;

    while(P){

        delete P;

        P = P->SIG;
    }
}

void LISTACLIENTES::AGREGAR(char * NOM, char * TEL){

    CLIENTE * PCLI;

    PCLI = new CLIENTE(NOM, TEL);

    PONER(PCLI);

}

void LISTACLIENTES::PONER(CLIENTE * P){

    P->SIG = INICIO;
    INICIO = P;
}

void LISTACLIENTES::MIRAR(){

    AUTO * PAUT;
    CLIENTE * PCLI;

    PCLI = INICIO;

    while(PCLI){

        PAUT = PCLI->PRIMERAUTO;

        cout<< "\n\n\t----------------------------------";

        cout<<"\n\n\t"<< PCLI->NOMBRE << " " << PCLI->TELEFONO << "\n\n";

        while(PAUT){

            cout<<"\n\t"<< PAUT->MODELO << " " << PAUT->ANIO << "\n\n";

            PAUT = PAUT->SIG;
        }

        PCLI = PCLI->SIG;
    }
}

void LISTACLIENTES::AGREGARAUTO(char * S, char * MODELO, int ANIO){

        AUTO * PAUT, * P;
        CLIENTE * PCLI;

        PCLI = BUSCAR(S);
        PAUT = new AUTO(MODELO, ANIO);


        if( PCLI->PRIMERAUTO == NULL ){               //LISTA VACIA
            PCLI->PRIMERAUTO = PAUT;
            return;
        }

        P = PCLI->PRIMERAUTO;

        while(P->SIG){                  //LISTA NO VACIA
            P = P->SIG;
        }

        P->SIG = PAUT;
}

CLIENTE * LISTACLIENTES::BUSCAR(char * S){

    CLIENTE * P;

    P = INICIO;

    while(P){

        if( !strcmp(P->NOMBRE, S) ){
            return P;
        }

        P = P->SIG;
    }
    return NULL;
}

int LISTACLIENTES::CANTAUTOS(char * S){

    AUTO * PAUT;
    CLIENTE * PCLI;
    int CONT = 0;

    PCLI = BUSCAR(S);

    PAUT = PCLI->PRIMERAUTO;

    while(PAUT){
        CONT++;
        PAUT = PAUT->SIG;
    }

    return CONT;
}

void LISTACLIENTES::VACIARAUTOS(char * S){

    AUTO * PAUT;
    CLIENTE * PCLI;

    PCLI = BUSCAR(S);

    PAUT = PCLI->PRIMERAUTO;

    while(PAUT){

        delete PAUT;

        PAUT = PAUT->SIG;
    }

    PCLI->PRIMERAUTO = NULL;
}


int LISTACLIENTES::CANTCLIENTES(){

    CLIENTE * PCLI;

    PCLI = INICIO;
    int CONT = 0;

    while(PCLI){
        CONT++;

        PCLI = PCLI->SIG;
    }

    return CONT;

}
int main() {
    LISTACLIENTES G;

    G.AGREGAR("PEPE", "4555-6565");
    G.AGREGAR("MARIA", "4444-3232");
    G.AGREGAR("CARLOS", "5460-1111");

    G.AGREGARAUTO("PEPE","Renault 12", 1980); //PRIMER PARAMETRO SE INDICA EL CLIENTE
    G.AGREGARAUTO("PEPE","Renault Fluence", 2013);

    G.MIRAR();

    cout<< "\n\n\tPEPE TIENE " << G.CANTAUTOS("PEPE") << " AUTOS";

    G.VACIARAUTOS("PEPE");

    cout<< "\n\n\tPEPE TIENE " << G.CANTAUTOS("PEPE") << " AUTOS\n\n\n\n";


    cout<< "\n\n\tLA GUIRNALDA TIENE " << G.CANTCLIENTES() << " CLIENTES\n\n\n\n";

    return 0;
}
