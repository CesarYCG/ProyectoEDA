//LISTA DE IMPRESORAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Impresora.h"


typedef struct nodo
{
	//char *nombre;
	cola *miCola;
	struct nodo *sig;
}Nodo;

//DECLARACION DE PROTOTIPOS DE FUNCIONES
Nodo *listaNodo(Nodo *Lista);
Nodo *agregarNodo(Nodo *Lista, cola *miCola);
//FIN DE DECLARACION DE PROTOTIPOS

int main()
{
	int dato, i;
	Nodo *Lista = listaNodo(Lista);
	printf("Ingresa el numero de impresoras que deseas crear\n");
	scanf("%i", &dato);
	for(i=0	)
	/*Lista = agregarNodo(Lista, "Impresora 1"); //Aqui irian las colas de impresion, pero 
	Lista = agregarNodo(Lista, "Impresora 2");  //En este codigo estan asignados los espacios por valor*/
	printf("Elementos de la lista: \n");
	while(Lista!=NULL){
		printf("%s", Lista->miCola);
		printf("\n");
		Lista = Lista->sig;
	}
	return 0;
}
//---------------FUNCIONES-------------------

Nodo *listaNodo(Nodo *Lista) //inicia la lista en NULL 
{
	Lista=NULL;
	return Lista;
}
Nodo *agregarNodo(Nodo *Lista, cola *miCola)
{
	Nodo *nuevoNodo, *aux;
	nuevoNodo=(Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->miCola=miCola;
	nuevoNodo->sig=NULL;
	if(Lista==NULL)
	{
		Lista = nuevoNodo;
	}else{
		aux = Lista;
		while(aux->sig!=NULL){
			aux= aux->sig;
			
		}
		aux->sig=nuevoNodo;
	}
	
	return Lista;
}
