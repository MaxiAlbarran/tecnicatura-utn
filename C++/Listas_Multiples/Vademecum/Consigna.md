**Consigna de Medicamentos 🏥**

Se dispone de una clase de tipo guirnalda llamada VADEMECUM que tiene un puntero ORIGEN a la clase MEDICINA.  
Esto conformará el listado de medicamentos donde cada uno tiene un nombre que lo identifica.  
La clase MEDICINA está formada por el nombre del medicamento antes mencionado, y por los elementos medicinales que lo componen, así como las dolencias a las que se aplica.  

Los elementos forman una lista simplemente enlazada con el nombre de estos, mientras que las dolencias también forman una lista simplemente enlazada. 

class  COMPONENTE { 

    public:	 

    char NOM[20] ; 

    COMPONENTE * SIG ; 

}  

class  DOLENCIA { 

    public :	 

    char NOM[20] ; 

    DOLENCIA * SIG ; 

}; 

 

class  MEDICINA { 

    public : 

    char NOM[20] ; 

    COMPONENTE * PCOM ; 

    DOLENCIA * PDOL ; 

    MEDICINA * SIG ; 

};  

class  VADEMECUM { 

    private : 

    MEDICINA * ORIGEN ; 

    . . . . . . . . . . . . . . . . . . .  

    public : 

    int CHEAPER (char *, const LISTA_DE_PRECIOS &) ; 

};  

Se dispone asimismo de otra clase de tipo guirnalda llamada LISTA_DE_PRECIOS en la que cada nodo de tipo COMPONENTE QUIMICO tiene el nombre del componente y un enlace a la clase LABORATORIO.  
Estos nodos tienen la información del nombre del laboratorio y el costo en $ (int) del componente químico al que pertenecen. 

Esto esta estructurado de la siguiente forma : 

class  LISTA_DE_PRECIOS { 

    private : 

    COMPONENTE_QUIMICO * COMPORIGEN ; 

    . . . . . . . . . . . . . . . . . . .  

    public : 

    friend int VADEMECUM::CHEAPER (char *, const LISTA_DE_PRECIOS &) ; 

}; 

class  COMPONENTE_QUIMICO { 

    public : 

    char NOM[20] ; 

    LABORATORIO * PLAB ; 

    COMPONENTE_QUIMICO * SIG ; 

};  

class  LABORATORIO { 

    public : 

    char NOM[20] ; 

    int COSTO ; 

    LABORATORIO * SIG ; 

};  

Se pide construir la función int VADEMECUM::CHEAPER (char *, const LISTA_DE_PRECIOS &) ; 

Donde el primer argumento corresponde a la dolencia por la que se consulta.  
El segundo permite acceder a la lista de precios y el valor retornado debe ser el menor costo posible para tratar esa dolencia con los elementos disponibles en el mercado. 
