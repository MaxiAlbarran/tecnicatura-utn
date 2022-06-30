**Consigna Ferreteria 🧰**

struct producto {  

	char nombre[40]; 
  
	float precio; 
  
	int ventas_mes[12];  
  
};

El programa se utilizará para administrar la información 
de una ferretería con un vector de estas estructuras. 

Cada producto cuenta con un nombre, un precio y un vector
 de 12 enteros en donde se encuentra la cantidad vendida de 
ese producto en cada mes del año (siendo 0 enero y 11 diciembre).

1) Realice la carga de un vector de productos con datos de 
ejemplo fijos (NO use valores aleatorios NI por teclado).

2) Construya una función que, dado el nombre de un producto,
 calcule y muestre la cantidad de unidades vendidas para todo 
 el año.

3) Construya una función que calcule y muestre cuál es el mes 
del año en que se vendieron más productos.


La estructura NO se puede modificar (es decir, agregar o quitar 
campos).
