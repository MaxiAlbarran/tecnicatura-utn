#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>

using namespace std;

class LISTA_PRECIOS;
class COMPONENTE_QUIMICO;
class LABORATORIO;

class DOLENCIA{
    public:
        char NOM[20];
        DOLENCIA * SIG;
        DOLENCIA(char *);
};

DOLENCIA::DOLENCIA(char * NOMBRE){

    strcpy(NOM, NOMBRE);
    SIG = NULL;

}

class COMPONENTE{
    public:
        char NOM[20];
        COMPONENTE * SIG;
        COMPONENTE(char *);
};

COMPONENTE::COMPONENTE(char * NOMBRE){

    strcpy(NOM, NOMBRE);
    SIG = NULL;

}

class MEDICINA{
    public:
        char NOM[20];
        DOLENCIA * PDOL;
        COMPONENTE * PCOM;
        MEDICINA * SIG;

        MEDICINA(char *);
        ~MEDICINA();
};

MEDICINA::MEDICINA(char * NOMBRE){

    strcpy(NOM, NOMBRE);
    PDOL = NULL;
    PCOM = NULL;
    SIG = NULL;

}

MEDICINA::~MEDICINA(){

    COMPONENTE * PC;
    DOLENCIA * PD;

    PC = PCOM;
    PD = PDOL;

    while(PC){
        delete PC;
        PC = PC->SIG;
    }

    while(PD){
        delete PD;
        PD = PD->SIG;
    }
}

class VADEMECUM{
    private:
        MEDICINA * ORIGEN;

        void AGREGAR_MEDICAMENTO(MEDICINA *);
        void AGREGAR_DOLENCIA(MEDICINA *, DOLENCIA *);
        void AGREGAR_COMPONENTE(MEDICINA *, COMPONENTE *);

        MEDICINA * BUSCAR_MEDIC(char *);
    public:
        VADEMECUM();

        void INGRESAR_MEDICAMENTO(char *);
        void INGRESAR_DOLENCIA(char *, char *);
        void INGRESAR_COMPONENTE(char *, char *);

        void MIRAR();

        int CHEAPER(char *, LISTA_PRECIOS &);
};

VADEMECUM::VADEMECUM(){

    ORIGEN = NULL;

}

void VADEMECUM::INGRESAR_MEDICAMENTO(char * NOMBRE){

    MEDICINA * MEDIC;

    MEDIC = new MEDICINA(NOMBRE);

    AGREGAR_MEDICAMENTO(MEDIC);

}

void VADEMECUM::AGREGAR_MEDICAMENTO(MEDICINA * MEDIC){

    MEDIC->SIG = ORIGEN;
    ORIGEN = MEDIC;

}

MEDICINA * VADEMECUM::BUSCAR_MEDIC(char * NOMBRE){

    MEDICINA * PM;

    PM = ORIGEN;

    while(PM){
        if( !strcmp(NOMBRE, PM->NOM) ){
            return PM;
        }

        PM = PM->SIG;
    }
    return NULL;
}

void VADEMECUM::INGRESAR_DOLENCIA(char * MEDICAMENTO, char * DOLOR){

    MEDICINA * PM;
    DOLENCIA * PD;

    PM = BUSCAR_MEDIC(MEDICAMENTO);

    PD = new DOLENCIA(DOLOR);

    if(PM){

        AGREGAR_DOLENCIA(PM, PD);

    }

}

void VADEMECUM::AGREGAR_DOLENCIA(MEDICINA * PM, DOLENCIA * PD){

    DOLENCIA * P; // BARRIDO

    if( !PM->PDOL ){

        PD->SIG = PM->PDOL;
        PM->PDOL = PD;
        return;
    }

    P = PM->PDOL;

    while(P->SIG){        //NOS PARAMOS EN LA ULTIMA DOLENCIA
        P = P->SIG;
    }

    P->SIG = PD;
}

void VADEMECUM::INGRESAR_COMPONENTE(char * MEDICAMENTO, char * COMP){

    MEDICINA * PM;
    COMPONENTE * PC;

    PM = BUSCAR_MEDIC(MEDICAMENTO);

    PC = new COMPONENTE(COMP);

    if(PM){

        AGREGAR_COMPONENTE(PM, PC);

    }
}

void VADEMECUM::AGREGAR_COMPONENTE(MEDICINA * PM, COMPONENTE * PC){

    COMPONENTE * P; // BARRIDO

    if( !PM->PCOM ){

        PC->SIG = PM->PCOM;
        PM->PCOM = PC;
        return;
    }

    P = PM->PCOM;

    while(P->SIG){        //NOS PARAMOS EN EL ULTIMO COMPONENTE
        P = P->SIG;
    }

    P->SIG = PC;
}


void VADEMECUM::MIRAR(){

    MEDICINA * PM;
    DOLENCIA * PD;
    COMPONENTE * PC;

    PM = ORIGEN;

    cout<<"\n\n\tMEDICAMENTOS\n";

    while(PM){
        PD = PM->PDOL;
        PC = PM->PCOM;

        cout<<"\n\n\n\t"<< PM->NOM;

        cout<<"\n\n\tCOMPONENTES\n\n";
        while(PC){
            cout<<"\n\t\t"<< PC->NOM;

            PC = PC->SIG;
        }

        cout<<"\n\n\tDOLENCIAS\n\n";
        while(PD){
            cout<<"\n\t\t"<< PD->NOM;

            PD = PD->SIG;
        }

        cout<<"\n\n\n\t\t---------------------------";
        PM = PM->SIG;
    }

}

/*GUIRNALDA LISTA DE PRECIOS*/

class LABORATORIO{
    public:
        char NOM[20];
        int COSTO;
        LABORATORIO * SIG;
        LABORATORIO(char *, int);
};

LABORATORIO::LABORATORIO(char * NOMBRE, int PRECIO){

    strcpy(NOM, NOMBRE);
    COSTO = PRECIO;
    SIG = NULL;

}

class COMPONENTE_QUIMICO{
    public:
        char NOM[20];
        LABORATORIO * PLAB;
        COMPONENTE_QUIMICO * SIG;
        COMPONENTE_QUIMICO(char *);

        int MENOR_COSTO(); // Esta funcion retorna la opcion menos costosa para un determinado componente
};

COMPONENTE_QUIMICO::COMPONENTE_QUIMICO(char * NOMBRE){

    strcpy(NOM, NOMBRE);
    PLAB = NULL;
    SIG = NULL;

}

int COMPONENTE_QUIMICO::MENOR_COSTO(){

    LABORATORIO * PLABO;
    int MIN = 0;

    PLABO = PLAB; // INICIO DE LABORATORIOS

    if(PLABO){
        MIN = PLABO->COSTO;
    }

    while(PLABO){

        if(PLABO->COSTO < MIN){
            MIN = PLABO->COSTO;
        }

        PLABO = PLABO->SIG;
    }

    return MIN;

}

class LISTA_PRECIOS{
    private:
        COMPONENTE_QUIMICO * ORIGEN;

        void AGREGAR_COMPQUIM(COMPONENTE_QUIMICO *);
        void AGREGAR_LABORATORIO(COMPONENTE_QUIMICO *, LABORATORIO *);

        COMPONENTE_QUIMICO * BUSCAR_COMPQUIM(char *);

    public:
        LISTA_PRECIOS();

        void INGRESAR_COMPQUIM(char *);
        void INGRESAR_LABORATORIO(char *, char *, int);

        void MIRAR();

        void MOSTRAR_PRECIOS(MEDICINA *);

        int friend VADEMECUM::CHEAPER(char *, LISTA_PRECIOS &);
};

LISTA_PRECIOS::LISTA_PRECIOS(){

    ORIGEN = NULL;

}

void LISTA_PRECIOS::INGRESAR_COMPQUIM(char * COMP){

    COMPONENTE_QUIMICO * PCQ;

    PCQ = new COMPONENTE_QUIMICO(COMP);

    AGREGAR_COMPQUIM(PCQ);

}

void LISTA_PRECIOS::AGREGAR_COMPQUIM(COMPONENTE_QUIMICO * PCQ){

    PCQ->SIG = ORIGEN;
    ORIGEN = PCQ;

}

COMPONENTE_QUIMICO * LISTA_PRECIOS::BUSCAR_COMPQUIM(char * NOM){

    COMPONENTE_QUIMICO * PCQ;

    PCQ = ORIGEN;

    while(PCQ){

        if( !strcmp(NOM, PCQ->NOM) ){
            return PCQ;
        }

        PCQ = PCQ->SIG;
    }
    return NULL;
}

void LISTA_PRECIOS::INGRESAR_LABORATORIO(char * COMP, char * LAB, int COSTO){

    LABORATORIO * PL;
    COMPONENTE_QUIMICO * PCQ;

    PL = new LABORATORIO(LAB, COSTO);

    PCQ = BUSCAR_COMPQUIM(COMP);

    if(PCQ){
        AGREGAR_LABORATORIO(PCQ, PL);
    }

}

void LISTA_PRECIOS::AGREGAR_LABORATORIO(COMPONENTE_QUIMICO * PCQ, LABORATORIO * PL){

    LABORATORIO * P; //BARRIDO

    if(!PCQ->PLAB){
        PCQ->PLAB = PL;
        return;
    }

    P = PCQ->PLAB;

    while(P->SIG){
        P = P->SIG;
    }

    P->SIG = PL;

}


void LISTA_PRECIOS::MIRAR(){

    COMPONENTE_QUIMICO * PCQ;
    LABORATORIO * PL;

    PCQ = ORIGEN;

    cout<< "\n\n\n\n\n\tLISTA DE PRECIOS\n\n\n";

    while(PCQ){

        PL = PCQ->PLAB;

        cout<<"\n\n\tCOMPONENTE: "<< PCQ->NOM;

        while(PL){

            cout<<"\n\n\t\tLaboratorio: "<< PL->NOM << "\tCosto: $ " << PL->COSTO;

            PL = PL->SIG;
        }

        PCQ = PCQ->SIG;
    }

    cout<<"\n\n\n\n\n";
}

int VADEMECUM::CHEAPER(char * DOLOR, LISTA_PRECIOS & LP){

    MEDICINA * PMED;
    DOLENCIA * PD;
    COMPONENTE * PC;

    COMPONENTE_QUIMICO * PCQ;

    int ACUMULADOR, PRIMER_VALOR = 1, MIN;

    PMED = ORIGEN;

    while(PMED){

        PD = PMED->PDOL;

        while(PD){

            if( !strcmp(PD->NOM, DOLOR) ){ // SI LA MEDICINA CURA LA DOLENCIA
                PC = PMED->PCOM;
                ACUMULADOR = 0;

                while(PC){

                    PCQ = LP.BUSCAR_COMPQUIM(PC->NOM);

                    ACUMULADOR = ACUMULADOR + PCQ->MENOR_COSTO();

                    PC = PC->SIG;
                }

                if(PRIMER_VALOR){
                    MIN = ACUMULADOR;
                    PRIMER_VALOR = 0;
                }
            }

            PD = PD->SIG;
        }

        if(ACUMULADOR < MIN){
            MIN = ACUMULADOR;
        }

        PMED = PMED->SIG;
    }

    return MIN;
}


int main(){

    VADEMECUM V;
    LISTA_PRECIOS LP;

    V.INGRESAR_MEDICAMENTO("CREMA");
    V.INGRESAR_MEDICAMENTO("PASTILLAS");
    V.INGRESAR_MEDICAMENTO("JARABE");

    V.INGRESAR_DOLENCIA("JARABE", "TOS");
    V.INGRESAR_DOLENCIA("JARABE", "DOLOR DE GARGANTA");
    V.INGRESAR_DOLENCIA("PASTILLAS", "TOS");
    V.INGRESAR_DOLENCIA("PASTILLAS", "DOLOR DE CABEZA");
    V.INGRESAR_DOLENCIA("CREMA", "IRRITACION");

    V.INGRESAR_COMPONENTE("JARABE", "MIEL");
    V.INGRESAR_COMPONENTE("JARABE", "AGUA");
    V.INGRESAR_COMPONENTE("PASTILLAS", "MENTA");
    V.INGRESAR_COMPONENTE("PASTILLAS", "MIEL");
    V.INGRESAR_COMPONENTE("CREMA", "ANALGESICO");

    V.MIRAR();

    LP.INGRESAR_COMPQUIM("MIEL");
    LP.INGRESAR_COMPQUIM("AGUA");
    LP.INGRESAR_COMPQUIM("MENTA");
    LP.INGRESAR_COMPQUIM("ANALGESICO");

    LP.INGRESAR_LABORATORIO("MIEL", "BAYER", 100);
    LP.INGRESAR_LABORATORIO("AGUA", "BAYER", 150);
    LP.INGRESAR_LABORATORIO("MENTA", "BAYER", 120);
    LP.INGRESAR_LABORATORIO("MIEL", "PFIZER", 20);
    LP.INGRESAR_LABORATORIO("MENTA", "PFIZER", 180);
    LP.INGRESAR_LABORATORIO("MIEL", "SPUTNIK", 10);
    LP.INGRESAR_LABORATORIO("ANALGESICO", "SPUTNIK", 135);

    LP.MIRAR();

    cout<< "\n\n\tEL PRECIO MAS BARATO PARA LA TOS ES $"<< V.CHEAPER("TOS", LP) << "\n\n\n";

    return 0;
}
