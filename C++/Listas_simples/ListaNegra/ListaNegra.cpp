#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX_VOTOS 15

using namespace std ;

class CANDI {
	public :

	    ~CANDI();

		char NOM[20];
		int VOTOS ;
		CANDI * SIG ;
};

CANDI::~CANDI(){

    cout<<"\n\n\t ELIMINADO: " << NOM;
}

class LISTANEGRA;

class LISTA {
	private :
		CANDI * INICIO ;
		void SACAR(CANDI *);

	public :
		LISTA() ;
		void MIRAR() ;

		void friend IMPUGNA( LISTA &, LISTANEGRA & );
};

LISTA :: LISTA ()
{
	int I ;
	CANDI * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<16 ; I++ ) {
		P = new CANDI ;
		strcpy ( P->NOM , NOM [ I ] ) ;
		P->VOTOS = 1 + rand()% MAX_VOTOS ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTA :: MIRAR ()
{
	CANDI * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "     %-10s%5d\n\n" , P->NOM , P->VOTOS) ;
		P = P->SIG ;
	}
	getch();
}

void LISTA::SACAR(CANDI * PELIM){

    CANDI * P;

    P = INICIO;

    if( PELIM == INICIO ){ //SI ESTA AL PRINCIPIO SE RESUELVE EL ENLACE INICIO

        INICIO = PELIM->SIG;
        delete P;
    }

    while(P->SIG != PELIM){
            P = P->SIG;
    }

    if(P){
        P->SIG = PELIM->SIG;
        delete PELIM;
    }
}

class PERSONA {
	public :
		char NOM[20];
		PERSONA * SIG ;
};

class LISTANEGRA {
	private :
		PERSONA * INICIO ;
	public :
		LISTANEGRA() ;
		void MIRAR() ;
		void friend IMPUGNA( LISTA &, LISTANEGRA & );
};

LISTANEGRA :: LISTANEGRA ()
{
	int I ;
	PERSONA * P ;
	char NOM[][20] = { "PEPE" , "LOLA" , "LAURA" , "CACHO" ,
			   "ANSELMO" , "MARIANO" , "MONICA" , "ANA" ,
			   "EDELMIRO" , "JOSE" , "MIRTA" , "SUSANA" ,
			   "FELIPE" , "ENZO" , "BETO" , "PACO" } ;
	INICIO = NULL ;
	for ( I=0 ; I<100 ; I++ ) {
		P = new PERSONA ;
		strcpy ( P->NOM , NOM [ rand()%16 ] ) ;
		P->SIG = INICIO ;
		INICIO = P ;
	}
}

void LISTANEGRA :: MIRAR ()
{
	PERSONA * P ;
	P = INICIO ;
	cout << "\n\n\n" ;
	while ( P ) {
		printf ( "%10s" , P->NOM ) ;
		P = P->SIG ;
	}
	getch();
}


/*  PROTOTIPO  */
void IMPUGNA ( LISTA & , LISTANEGRA & );


int main()
{

	LISTA L ;
	L.MIRAR() ;
	LISTANEGRA N ;
	N.MIRAR() ;

    IMPUGNA ( L , N );  // ME PASAN EL OBJETO POR REFERENCIA

    L.MIRAR() ;

	cout << "\n\n\nFIN DEL PROGRAMA  " ;
	getch();
	return 0 ;
}

void IMPUGNA (LISTA & L , LISTANEGRA & N){

    CANDI * PCAN;  //PUNTEROS DESTINADOS A BARRIDO
    PERSONA * PPER;

    int CONT = 0;

    PCAN = L.INICIO;

    cout<< "\n\n\t LISTA DE VOTOS \n\n\n" ;
    while(PCAN){

        PPER = N.INICIO;
        while(PPER){

            if( strcmp(PCAN->NOM, PPER->NOM) == 0 ){
                CONT++;
            }

            PPER = PPER->SIG;
        }

        PCAN->VOTOS = PCAN->VOTOS - CONT;

        if(PCAN->VOTOS <= 0){
            L.SACAR(PCAN);
        }

        PCAN = PCAN->SIG;
        CONT = 0;
    }
}
