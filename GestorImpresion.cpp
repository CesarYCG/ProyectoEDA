#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//DECLARACION DE PROTOTIPOS DE FUNCIONES
int bienvenida();
int menu(int);

//Fin de declaracion de prototipos de funciones

int main()
{
	int op; 
	int opmenu;
	bienvenida();
	op = menu (opmenu);
	printf("%i", op);
	
	switch(op)
	{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			printf("Ha elegido salir del sistema de gestion de impresion. Hasta luego.");
			return 0;
			break;
		default:
			printf("Opcion no valida, por favor, ingrese un valor valido ")
	}
	return 0;
}

int bienvenida()
{
	char nombre[20];
	printf("Por favor, ingrese su nombre\n");
	scanf("%s", &nombre);
	printf("Bienvenido %s, por favor, elija alguna de las siguientes opciones:\n", nombre);
	
	return 0;
}

int menu(int a)
{
	printf("1. Ver impresoras disponibles \n2. A%cadir una impresora \n3. Eliminar una impresora \n4. Ver colas de impresion \n5. Mandar a imprimir un archivo\n6. Salir\n", 164);
	printf("Seleccione una opcion por favor: ");
	scanf("%i", &a); 
	return a;
}
