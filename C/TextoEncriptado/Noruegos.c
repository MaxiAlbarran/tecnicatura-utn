#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int desencriptar( char [], int);

int main(){

    FILE *encriptado;
    int valor;
    char caracter, cadena[50];

    encriptado = fopen("ENCRIPTADO.txt", "rt");

    if(encriptado == NULL){
        printf("\n\n\tNO FUE POSIBLE ABRIR EL ARCHIVO\n\n");
        exit(1);
    }

    while( !(feof(encriptado)) ){
        fscanf(encriptado, "%s", cadena);
        valor = desencriptar(cadena, strlen(cadena));
    }

    fclose(encriptado);

    encriptado = fopen("ENCRIPTADO.txt", "rt");

    caracter = getc(encriptado);

    while( !(feof(encriptado)) ){
        if((int)caracter == 10 || (int)caracter == 13){
            printf("%c", caracter);
        }else{
            printf("%c", (int)caracter - valor);
        }
        caracter = getc(encriptado);
    }

    fclose(encriptado);

    return 0;

}

int desencriptar (char cadena[50], int L){

    int valor;
    for(int I = 1; I < 100; I++){
        for(int J = 0; J < L; J++){
            cadena[J] = (int)cadena[J] - I;
        }
        if( strcmpi (cadena, "noruegos") != 0 ){
            for(int J = 0; J < L; J++){
                cadena[J] = (int)cadena[J] + I;
            }
        }else{
            valor = I;
        }
    }

    return valor;
}
