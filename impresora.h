#ifndef IMPRESORA_H_
#define IMPRESORA_H_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//HACIENDO UNA COLA

#define MAXCOLA 5 //La impresora podra almacenar un maximo de 5 elementos

struct structCola
{
	char nombre[MAXCOLA] [50];
	//int head;
	int tail;
}; typedef struct structCola cola;

//DECLARACION DE PROTOTIPOS DE FUNCIONES
void crearCola(cola *miCola); //Crea la cola
int colaVacia(cola *miCola); //Funcion que me indicara si la cola esta vacia
int colaLlena(cola *miCola); //Funcion que indica si la cola esta llena
void reajusteColas(cola *miCola); //Movera los elementos de la cola cuando se efectuen operaciones pop
void push(cola *miCola, char nombre[]); //Agrega un elemento por el tail de la cola
char *pop(cola *miCola); //Elimina el elemento ubicado en el head de la cola
void mostrarTope(cola *miCola); //Muestra el tope de la cola
void mostrarFULLCola(cola *miCola); //Muestra todo el contenido de la cola
void ayudaMenu();
//FIN DE DECLARACION DE PROTOTIPOS DE FUNCIONES

void impresora(cola miCola)
{
	//cola miCola; //variable miCola tipo cola
	int op;
	char nombre[50];
	char *nombreReturn; //Para la funcion pop, que almacenara la variable que retorna pop
	
	crearCola(&miCola);
	
	do
	{
		system("cls"); //Limpiamos la pantalla
		printf("//-----MENU-----//\n\n");
		printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
		printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
		scanf("%i", &op);
		
		switch(op)
		{
			case 1: //Push
				system("cls");
				if(colaLlena(&miCola))
				printf("La cola de impresion esta llena. Seleccione otra impresora");
				else
				{
					printf("Escriba el nombre de su archivo: ");
					scanf("%s", nombre);
					push(&miCola, nombre);
					printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
				}
				break;
			case 2: //Pop
				system("cls");
				
				if (colaVacia(&miCola))
					printf("La cola de impresion se encuentra vacia");
				else
				{
					nombreReturn=pop(&miCola);
					strcpy(nombre, nombreReturn);
					printf("Se ha impreso %s y se ha retirado de la cola de impresion", nombre);
				}
				break;
			case 3: //Muestra tope de la cola
				system("cls");
				if(colaVacia(&miCola))
					printf("La cola de impresion se encuentra vacia");
				else
				{
					printf("El tope de la cola es: ");
					mostrarTope(&miCola);
				}
				break;
			case 4: //Muestra TODA la cola de impresion
				system("cls");
				mostrarFULLCola(&miCola);
				break;
			case 5: //Despliega un menu de AYUDA
				ayudaMenu();
				break;
			case 6: //Sale del gestor de impresion
				system("cls");
				printf("Usted ha salido del gestor de impresion con exito...");
				break;
			default:
				printf("\nOPCION NO VALIDA. POR FAVOR, SELECCIONE UN ELEMENTO VALIDO DEL MENU");
				break;
		}		
		getch();
	}while(op!=6);
	
	//return 0;
}

//--------------------PROGRAMACION DE FUNCIONES-------------------------//
void crearCola(cola *miCola) //Crea la cola
{
	//miCola->head=0;
	miCola->tail=-1;
}
int colaVacia(cola *miCola) //Funcion que me indicara si la cola esta vacia
{
	if (miCola->tail==-1)
		return 1;
	
	return 0;
}
int colaLlena(cola *miCola) //Funcion que 
{
	if (miCola->tail==MAXCOLA-1)
		return 1;
	
	return 0;
}
void reajusteColas(cola *miCola) //Movera los elementos de la cola cuando se efectuen operaciones pop
{
	int i;
	
	for(i=0; i<miCola->tail;i++)
		strcpy(miCola->nombre[i], miCola->nombre[i+1]);
		
	miCola->tail--;
}
void push(cola *miCola, char nombre[]) //Agrega un elemento por el tail de la cola
{
	miCola->tail++;
	strcpy(miCola->nombre[miCola->tail], nombre);
}
char *pop(cola *miCola) //Elimina el elemento ubicado en el head de la cola
{
	char aux[50]; //Esta variable almacena temporalmente los datos sacados de la cola
	strcpy(aux, miCola->nombre[0]);
	reajusteColas(miCola);
	
	return aux;
}
void mostrarTope(cola *miCola) //Muestra el tope de la cola
{
	printf("%s", miCola->nombre[0]);
		
}
void mostrarFULLCola(cola *miCola) //Muestra todo el contenido de la cola
{
	cola colaAux; //Auxiliar para imprimir todos los valores de la cola, no modifica la cola original
	char auxiliar[50];
	
	colaAux=*miCola;
	
	if (colaVacia(&colaAux))
		printf("La cola esta vacia\n");
	else
	{
		printf("Los documentos encolados de la impresora son:  ");
		do
		{
			strcpy(auxiliar, pop(&colaAux));
			printf("%s -> ", auxiliar);
		}while(!colaVacia(&colaAux)); //Se ejecuta mientras la cola no este vacia
	}
	printf("/Fin de archivos para impresion/");
}
void ayudaMenu()
{
	system("cls");
	printf("		...:::BIENVENIDO AL SISTEMA DE GESTOR DE IMPRESIONES:::...\n\n");
	printf("A continuacion se mencionan las funciones presentes en el gestor con una breve descripcion:\n\n");
	printf("1. Insertar archivo en la impresora: Permite al usuario a%cadir el nombre del documento que\n ", 164);
	printf("  desea imprimir.\n\n");
	printf("2. Imprimir elemento siguiente: Imprime el elemento de la impresora seleccionada, elimina\n");
	printf("   el archivo de la cola de impresion y recorre los archivos pendientes por imprimir.\n\n");
	printf("3. Mostrar tope de la impresora: Despliega el proximo documento a imprimirse de la cola.\n\n");
	printf("4. Mostrar la cola de impresion: Despliega el total de archivos encolados para imprimirse.\n\n");
	printf("5. Ayuda: Despliega el menu 'Ayuda'.\n\n");
	printf("6. Salir: Sale del programa 'Gestor de impresion'.\n\n");
	printf("\n\nPulse cualquier tecla para volver al menu...");
}
#endif //COLADEPRIORIDAD_H_
