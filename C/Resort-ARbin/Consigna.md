**Consigna de Resort♨️**

En un resort de alta categoría cada huésped tiene una pulsera con un código que lo identifica y que tiene formato de int (campo ID). Cuando un huésped utiliza un determinado servicio, se captura el código del huésped y se almacena con la fecha y el servicio en un archivo llamado “SERVICIOS” cuyos registros tienen la forma:


struct FECHA { 

int DIA; 
int MES: 
int ANIO;

}:

struct SERV { 

char SERVICIO[20];

int ID; 

struct FECHA HOY;

}.  
Por otro lado, se dispone del archivo LISTA_PRECIOS que almacena los valores de cada uno de los servicios que brinda el establecimiento, estando estos estructurados de la forma:

struct PRECIO { 
char SERVICIO[20]; 
int COSTO;
}; 

Se pide:
1. Determinar cuál es el huésped que más dinero gastó. (Lo consideramos único)
2. Ingresar un nombre de servicio y mostrar que huéspedes lo utilizaron y en qué fecha.
