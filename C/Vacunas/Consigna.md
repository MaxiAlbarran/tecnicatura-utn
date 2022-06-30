**Consigna de Vacunas:syringe:**

Dadas las siguientes estructuras utilizadas
para el registro en un centro de vacunacion COVID:

struct fecha { int dia; int mes; int anio;}

struct registro { 

	int dni; 
	char nombre[50]; 
	struct fecha fecha_v; 
	int dosis;
  
}


Cada vez que se vacuna a una persona se utiliza
 una de estas struct para registrarlo.
El campo dosis tiene el valor 1 ó 2, indicando 
si fue aplicación de la dosis 1 ó 2.

Las estructuras no se pueden modificar (es decir,
 agregar o quitar campos).




1) Realice una función que recibe un vector de
 registros y su largo, con el siguiente
 prototipo:
void mejor_mes(struct registro[], int n);

Debe mostrar en pantalla el mes que más dosis se 
aplicaron, es decir que más personas 
totales se vacunaron, considerando por igual las
 aplicaciones de dosis 1 como dosis 2.
Se pide mostrar el nombre del mes y no el número 
(por ejemplo "Septiembre" y no 9).

Tenga en cuenta que el vector que recibe no está 
ordenado de ninguna forma especifica, pudiendo 
estar los registros en cualquier orden.



2) Realice otra función llamada 
pacientes_completos que muestre en pantalla el 
nombre de los pacientes que ya han recibido
las dos dosis.
