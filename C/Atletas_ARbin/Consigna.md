**Consigna Juego olimpico 🥇:**


Se cuenta con un archivo ATLETAS, conteniendo registros con esta forma:

struct atleta {
		char NOMBRE[50];
		char PAIS[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

Este archivo indica cuántas medallas ganó cada atleta en cierta edición de los Juegos Olímpicos.

Por otro lado, se cuenta con un archivo PAISES, con registros de esta forma:

struct pais {
		char NOMBRE[30];
		int ORO;
		int PLATA;
		int BRONCE;
};

El archivo PAISES está inicializado actualmente en cero, es decir, que todos los paises indican 0 medallas en las 3 categorías.


Se pide, en un solo programa:

1) Imprimir en pantalla los ATLETAS, para verificar que la lectura del archivo es correcta.

2) Actualizar el archivo PAISES para que refleje la cantidad de medallas obtenidas por cada país, sumadas, de acuerdo a los datos del archivo ATLETAS.

3) Mostrar en pantalla el archivo PAISES para corroborar los resultados.

4) Mostrar en pantalla el nombre del país que más medallas totales ganó, es decir, sumando las 3 categorías.
Resultado esperado para el ejemplo proporcionado: ALEMANIA (6 medallas)
