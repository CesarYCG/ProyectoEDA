#include "ColaDePrioridad.h"

void crear(ColaDePrioridad * c){
	(*c) = NULL;
}

void destruir(ColaDePrioridad * c){
	if((*c)==NULL)return;
	else{
		ColaDePrioridad aux = (*c);
		(*c)=(*c)->post;
		free(aux);
		destruir(c);
	}
}

void encolar(ColaDePrioridad * c,int val){
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

void desencolar(ColaDePrioridad * c){
	if((*c)==NULL)
		printf("No se puede eliminar elementos: cola vacia");
	else{
		ColaDePrioridad aux = (*c);
		(*c) = (*c)->post;
		free(aux);
	}
		
}
int primero(ColaDePrioridad c){
	if(c==NULL)
		printf("La cola esta vacia\n");
	else{
		return c->value;
	}
	
}

int tamanio(ColaDePrioridad c){
	if(c == NULL)return 0;
	else{
		return 1+size(c->post);
	}
}

int vacia(ColaDePrioridad c){
	if(c == NULL) return 1;
	else
		return 0;
}

void mostrar(ColaDePrioridad c){
	if(c == NULL)
		printf("NULL\n");
	else{
		printf("%i->",c->value);
		mostrar(c->post);
	}
}
