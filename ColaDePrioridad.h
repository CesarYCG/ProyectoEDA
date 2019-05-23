#ifndef COLADEPRIORIDAD_H_
#define COLADEPRIORIDAD_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct TNode * ColaDePrioridad;
struct TNode{
	int value;
	ColaDePrioridad post;
};
void crear(ColaDePrioridad * c); //crea una cola vacia
void destruir(ColaDePrioridad * q); //libera el especio en memoria de la cola
void encolar(ColaDePrioridad * c,int val); //pone un elemnto al final de la cola
void desencolar(ColaDePrioridad * c);//saca el primer elemento de la cola
int primero(ColaDePrioridad c);//devuelve el primer elemento de la cola
int tamanio(ColaDePrioridad c);//devuelve el tamaño de la cola
int vacia(ColaDePrioridad c); //devuelve 1 si la cola esta vacia y 0 si tiene un elemento
void mostrar(ColaDePrioridad c); //muestra los elemtos de la cola
#endif //COLADEPRIORIDAD_H_
