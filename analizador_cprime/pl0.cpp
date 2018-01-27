//pl0 versi�n 3.0-solo scanner (analizador lexicogr�fico)

//abril de 2011,Agosto 2012
//se us� Microsoft Visual C++ 2010 para escribir este scanner

#include "pl0.h"
#include "auxiliares.h"
#include "scanner.h"
#include "lexico.h"
#include "string.h"

FILE *fp; //apuntador a archivo conteniendo el programa fuente

//main: inicia el compilador...solo scanner
int main (int argc,char *argv[]) { 

 //verificar si hay archivo fuente
 if (argc!=2)
	printf("\nNo se ha proporcionado el nombre del programa fuente (uso: scanner progfuente)");
 else { 
	fp=fopen(argv[1],"r"); //abrir el fuente solo para lectura
	if (fp==NULL) 
	   printf("\nNo se encontro el programa fuente indicado");
	else {
	     printf("\n\nAnalizador lexicografico CPRIME  \n");
	     //inicializacion de tokens de s�mbolos especiales (en auxiliares.cpp)
	     inicializar_espec() ; 

	     //inicializacion de otras variables (en scanner.h)
	     ch=' ';
	     fin_de_archivo=0;
	     offset=-1;ll=0;
	     num_linea = 0;flag_leido = 0;
	     char linea_s[MAXID+1];      

		 //tokenizar el programa fuente
	     while (1) {
               obtoken();        //en scanner.cpp
               if(token!=nulo){
				imprime_token();  //en auxiliares.cpp
				printf(" | %s",lexid);
				printf(" | %d,%d\n",num_linea,offset-strlen(lexid));
               }	
         }
	 	}
 }
 return (0);
}


 

