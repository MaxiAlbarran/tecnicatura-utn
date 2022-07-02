#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std ;

class VISITANTE
{
	public:
			char NOM [20];
			VISITANTE * SIG;

			VISITANTE(char *);
};

VISITANTE::VISITANTE(char * S){

    strcpy(NOM, S);
    SIG = NULL;

}

class MUSEO
{
	public:
			char NOM [20];
			VISITANTE * PVIS;
			MUSEO * SIG;

			MUSEO(char * S);
			~MUSEO();

			int CONTVISIT();
};

MUSEO::MUSEO(char * S){

    PVIS = NULL;
    strcpy(NOM, S);

}

MUSEO::~MUSEO(){

    VISITANTE * P;

    P = PVIS;

    while(P){
        delete P;
        P = P->SIG;
    }

}

int MUSEO::CONTVISIT(){

    VISITANTE * P;
    int cont = 0;
    P = PVIS;

    while(P){

        cont++;

        P = P->SIG;
    }

    return cont;

}

class REGISTROVISITAS  //GUIRNALDA
{
    private:
			MUSEO * INICIO;
			void AGREGAR(MUSEO *);

			MUSEO * BUSCAR(char *);

            void SACAR( MUSEO * );
	public:

			REGISTROVISITAS();
			void NUEVOMUSEO(char *);

			void REGISTRARVISITA(char *, char *);

			void MIRAR();

			void VERVISITANTESPERFECTOS();

			void BORRARMENOSVISITADO();

};

REGISTROVISITAS::REGISTROVISITAS(){

    INICIO = NULL;

}

void REGISTROVISITAS::NUEVOMUSEO(char * S){

    MUSEO * PMUS;

    PMUS = new MUSEO(S);

    AGREGAR(PMUS);
}

void REGISTROVISITAS::AGREGAR(MUSEO * P){

    P->SIG = INICIO;
    INICIO = P;

}

void REGISTROVISITAS::MIRAR(){

    VISITANTE * PVISITA;
    MUSEO * PMUS;

    PMUS = INICIO;

    while(PMUS){

        PVISITA = PMUS->PVIS;

        cout<<"\n\n\t"<< PMUS->NOM  << "\n\n";

        while(PVISITA){

            cout<<"\n\t\t" << PVISITA->NOM;

            PVISITA = PVISITA->SIG;
        }

        cout<< "\n\n\t----------------------------------";

        PMUS = PMUS->SIG;
    }
}

void REGISTROVISITAS::REGISTRARVISITA(char * M, char * V){ // MUSEO, VISITANTE

    MUSEO * PMUS;
    VISITANTE * PVISITA, * P; // P PARA BARRIDO

    PMUS = BUSCAR(M);

    PVISITA = new VISITANTE(V);

    if( !PMUS->PVIS ){ // LISTA VACIA

        PMUS->PVIS = PVISITA;
        return;
    }

    P = PMUS->PVIS; // LISTA NO VACIA

    while( P->SIG ){
        P = P->SIG;
    }

    P->SIG = PVISITA;
}

MUSEO * REGISTROVISITAS::BUSCAR(char * S){

    MUSEO * P;

    P = INICIO;

    while(P){

        if( !strcmp(P->NOM, S) ){
            return P;
        }

        P = P->SIG;
    }
    return NULL;
}

void REGISTROVISITAS::VERVISITANTESPERFECTOS(){

    VISITANTE * PV, * B;
    MUSEO * PM;
    int CONTV = 0;
    int CONTM = 0;

    PM = INICIO;
    B= PV = PM->PVIS;

    while( PV ){

        PM = INICIO;


        while( PM ){

            B = PM->PVIS;

            CONTM++; //CONTADOR DE MUSEOS

            while(B){

                if( !strcmp(B->NOM, PV->NOM) ){
                    CONTV++; //CONTADOR DE VISITAS
                }

                B = B->SIG;
            }

            PM = PM->SIG;
        }

        if(CONTV == CONTM){
            cout<< "\n\n\t" << PV->NOM << " VISITO TODOS LOS MUSEOS\n\n";
        }

        PV = PV->SIG;
        CONTV = 0;
        CONTM = 0;
    }

}

void REGISTROVISITAS::BORRARMENOSVISITADO(){

    MUSEO * PM, *MENOSVISIT;
    VISITANTE * PV;

    int CONT;
    int MINIM;

    PM = INICIO;

    if(PM){

        MINIM = PM->CONTVISIT();
        MENOSVISIT = PM;

    }

    while(PM){

        CONT = PM->CONTVISIT();

        if(CONT < MINIM){

          MINIM = CONT;
          MENOSVISIT = PM;

        }

        PM = PM->SIG;
        CONT = 0;
    }

    SACAR(MENOSVISIT);

}

void REGISTROVISITAS::SACAR(MUSEO * PELIM){

    MUSEO * P;

    P = INICIO;

    if(PELIM == INICIO){ //LISTA VACIA

        INICIO = PELIM->SIG;
        delete PELIM;
        return;
    }

    while(P->SIG != PELIM){ // LISTA NO VACIA

        P = P->SIG;

    }

    if(P){
        P->SIG = P->SIG->SIG; //RESUELVO EL ENLACE
        delete PELIM;
    }

}


int main()
{
	REGISTROVISITAS G;

	G.NUEVOMUSEO("MALBA");
	G.NUEVOMUSEO("MUSEO HISTORICO NAC.");
	G.NUEVOMUSEO("MUSEO DE CS. NATURALES");


	G.REGISTRARVISITA("MUSEO HISTORICO NAC.", "Pepe");
	G.REGISTRARVISITA("MUSEO HISTORICO NAC.", "Roberto Sanchez");
    G.REGISTRARVISITA("MUSEO DE CS. NATURALES", "Pepe");
	G.REGISTRARVISITA("MUSEO DE CS. NATURALES", "Maria Alvarez");
	G.REGISTRARVISITA("MUSEO DE CS. NATURALES", "Roberto Sanchez");
	G.REGISTRARVISITA("MALBA", "Roberto Sanchez");

	G.MIRAR();

	G.VERVISITANTESPERFECTOS();

	G.BORRARMENOSVISITADO();

	G.MIRAR();

    return 0;
}
