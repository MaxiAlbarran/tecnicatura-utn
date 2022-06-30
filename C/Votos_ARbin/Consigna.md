**Consigna VOTOS 	:postbox:**

El archivo BDVOTOS está formado por registros de la forma :

struct {

		char NOM[20] ;
		char DISTRITO[20] ;
		int VOTOS ;
    
} ;

Contiene los datos de una elección, en donde figuran en cada registro la cantidad de votos que obtuvo cada candidato en cada uno de los distritos.

Se pide :

1.	Construir el archivo depurado BD_RESUMEN donde figure cada candidato UNA SOLA VEZ con la cantidad total de votos obtenidos. Cada registro será igual al anterior, pero sin el distrito.
2.	Determinar el Candidato ganador.
3.	Indicar en que DISTRITO obtuvo mas votos.

NOTA : NO SE PUEDEN BAJAR LOS ARCHIVOS A MEMORIA PUES NO SE PUEDE ASEGURAR QUE ESTA SEA SUFICIENTE.
