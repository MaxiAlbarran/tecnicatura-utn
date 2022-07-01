**Consigna Votacion de Candidatos 👨‍⚖️**

La clase LISTA1 esta formada por un puntero a la clase NODO (privado) y las funciones asociadas.

La clase NODO esta compuesta por los miembros públicos NOM (string de 20) y el puntero SIG (NODO *), más las funciones asociadas.

La lista contiene nombres que no guardan ningún orden y aparecen repetidos correspondiendo cada nodo a un voto en un certamen de popularidad.

La clase LISTA2 esta formada por un puntero a la clase CANDIDATO (privado) y las funciones asociadas.

La clase CANDIDATO esta compuesta por los miembros públicos NOM (string de 20), CANT(int) y el puntero SIG (CANDIDATO *), más las funciones asociadas.

La lista2 contiene nombres (que no se repiten) y la cantidad de votos recibidos .

Se pide construir la función void AGREGA(LISTA1& , LISTA2&), tal que agregue a LISTA2 los votos de LISTA1. Cada NODO que reciba incrementará 1 voto en el NODO2 correspondiente, o darlo de alta en caso de no existir ese nombre en LISTA2.

Indicar que característica debe tener la función AGREGA() para acceder a ambas listas.
