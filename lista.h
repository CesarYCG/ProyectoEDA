#ifndef LISTA_H_
#define LISTA_H_

#include<stdio.h>
#include <conio.h>
#include<stdlib.h>
#include "Impresora.h"

typedef struct Nodo{
    cola miCola;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
}Lista;

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

//cola miCola;
Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,cola);  
void borrarUltimo(Lista*);

//cola
cola miCola1;
cola miCola2;
cola miCola3;
cola miCola4;
cola miCola5;


//LISTA
void lista1(){
	printf("Bienvenido al programa \n");
	int opcion= 0;
	Lista lista1= crearLista();
	
	do{
		printf("Selecciona la opción deseada: \n");
		printf("1.- AGREGAR ELEMENTO AL INICIO \n");		
		printf("2.- ELIMINAR AL FINAL \n");	
		printf("3.- IMPRIMIR LISTA  \n");	
		scanf("%d",&opcion);
		printf("\n");	
		
		switch(opcion){
			case 1:
				;
				printf("Has anadido una impresora: \n");
				addPrincipioLista(&lista1,miCola1);
				addPrincipioLista(&lista1,miCola2);
				addPrincipioLista(&lista1,miCola3);
				addPrincipioLista(&lista1,miCola4);
				addPrincipioLista(&lista1,miCola5);
			break;
			case 2:
				borrarUltimo(&lista1);
			break;
			case 3:
				printf("Los elementos de la lista son: \n");
				print_list(lista1);
			break;
			defalut:
			//acciones
			break;
		}
	}while (opcion!=4);
	print_list(lista1);
}
//FIN LISTA


void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
       	Nodo *current = lista.head;
   		while (current != 0) {
        	printf("%s \n",current->miCola.nombre);
			current = current->next;
   	 	}
	}
}

void addPrincipioLista(Lista *lista, cola miCola) {
	Nodo *new_node;
    new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->miCola = miCola;
    new_node->next = lista->head;
    lista->head = new_node;
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	if(temp->next==NULL){
    		lista->head = NULL;
			free(lista->head);	
    	}else{
    		Nodo *current = lista->head;
    		while (current->next->next != NULL) {
        		current = current->next;
    		}
    		current->next = NULL;
			free(current->next);
    		
    	}
	}

}

#endif
