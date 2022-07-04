**Consigna Campeonato de Sueldos 💸**

Se dispone de una lista simplemente enlazada de clases SUELDO compuesta por el nombre de un jugador ( char NOM[20] ), el sueldo mensual ( int SUELDO ) y el puntero al siguiente jugador ( SUELDO * SIG ).  

El puntero al inicio es un miembro privado de la clase CAMPEONATO de la forma SUELDO * INISUELDO. 

También se dispone de una estructura tipo guirnalda compuesta por la clase EQUIPO, formada por el nombre del equipo ( char NOM[20]),  el inicio de la lista de jugadores que integran ese equipo (JUGADOR * PUNJU), y el puntero al siguiente equipo (EQUIPO * SIG ). 

La clase JUGADOR esta formada simplemente por el nombre del jugador   char NOM[20]),   y el puntero al siguiente jugador (JUGADOR * SIG ). 

El puntero al inicio de la guirnalda es un miembro privado de la clase CAMPEONATO de la forma EQUIPO * INIEQUIPO. 

Se pide : 

1. Dibujar la estructura descripta, con sus enlaces y nombres de campos y clases de nodos.
2. Construir la función void MILLONARIO( CAMPEONATO & ) que muestre en pantalla cual es el equipo que más gasta mensualmente en sueldos de jugadores y cuál es ese monto. 
