#ifndef COLADEPRIORIDAD_H_
#define COLADEPRIORIDAD_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode * ColaDePrioridad;
typedef struct Impresora;

struct Impresora {
	char[25] nombre;
	ColaDePrioridad cola;
	int impresiones;
};

struct TNode{
	Impresora impre;
	int value;
	ColaDePrioridad post;
};

void crear(ColaDePrioridad * c){ //crea una cola vacia
	(*c) = NULL;
}

void destruir(ColaDePrioridad * c){ //libera el especio en memoria de la cola
	if((*c)==NULL)return;
	else{
		ColaDePrioridad aux = (*c);
		(*c)=(*c)->post;
		free(aux);
		destruir(c);
	}
}

void encolar(ColaDePrioridad * c,int val){ //pone un elemnto al final de la cola
	if((*c)==NULL){
		(*c)=(ColaDePrioridad)malloc(sizeof(struct TNode));
		(*c)->value = val;
		(*c)->post=NULL;
	}else{
		ColaDePrioridad prev=NULL;
		ColaDePrioridad aux = (*c);
		ColaDePrioridad fst=(*c);
		while((*c)!=NULL&&(*c)->value<val){
			prev=(*c);
			(*c)=(*c)->post;
		}
		if((*c)==NULL){
			(*c)=(ColaDePrioridad)malloc(sizeof(struct TNode));
			(*c)->value = val;
			(*c)->post= NULL;
			prev->post=(*c);
			(*c)=fst;
		}else if((*c)->value >= val){//El elemento dado al pricipio de la cola
			if(prev == NULL){ //comprobamos que el primer elemto es mayor que el dado
				prev = (ColaDePrioridad)malloc(sizeof(struct TNode));
				prev->value=val;
				prev->post = (*c);
				(*c) = prev;
			}else{
				ColaDePrioridad aux = (*c); //aux ira entre prev->value y (*q)->value
				aux = (ColaDePrioridad) malloc(sizeof(struct TNode));
				aux->value = val;
				prev->post = aux;
				aux->post = (*c);
				(*c)= fst;
			}
		}
	}
}

void desencolar(ColaDePrioridad * c){ //saca el primer elemento de la cola
	if((*c)==NULL)
		printf("No se puede eliminar elementos: cola vacia");
	else{
		ColaDePrioridad aux = (*c);
		(*c) = (*c)->post;
		free(aux);
	}
		
}
int primero(ColaDePrioridad c){ //devuelve el primer elemento de la cola
	if(c==NULL)
		printf("La cola esta vacia\n");
	else{
		return c->value;
	}
	
}

int tamanio(ColaDePrioridad c){ //devuelve el tamaño de la cola
	if(c == NULL)return 0;
	else{
		return 1+tamanio(c->post);
	}
}

int vacia(ColaDePrioridad c){ //devuelve 1 si la cola esta vacia y 0 si tiene un elemento
	if(c == NULL) return 1;
	else
		return 0;
}

void mostrar(ColaDePrioridad c){  //muestra los elemtos de la cola
	if(c == NULL)
		printf("NULL\n");
	else{
		printf("%i->",c->value);
		mostrar(c->post);
	}
}

#endif //COLADEPRIORIDAD_H_
