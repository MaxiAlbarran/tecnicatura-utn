**Consigna de Cine :performing_arts:**

Un complejo de cine cuenta con 4 salas, de 24 butacas, 4 filas y 6 columnas

En el complejo se almacena la ocupación de los asientos con la siguiente estructura:
struct SALA { 

int CODIGO;

int BUTACA [4][6];

char PELI [30];

};

Donde cada BUTACA tiene 0 si el asiento esta vacio, y 1 si está ocupado; CODIGO es el
nro de sala y PELI el nombre de la película que se está proyectando (una película
distinta en cada sala).

Se pide:

1) Hacer la función (int) MAS_VISTA (struct SALA VEC[4])
Que recibe un vector de 4 salas y retorna el CODIGO de sala más concurrida en este
momento.

2) Hacer la función (int) BUSCAR_PELI( struct SALA VEC [4], char TITULO [30])
Que recibe un vector de 4 salas y un título, y retorna el CODIGO de la sala en la que se
está proyectando, o bien -1 si no está.
