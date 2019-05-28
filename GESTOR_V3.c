//PROTOTIPO DE GESTION v3
/*INTEGRANTES DEL EQUIPO
AGUILAR BUSTILLOS ALAN
CALDERON GUEVARA CESAR YAIR
MACEDA PATRICIO FERNANDO     
COMPILADOR UTILIZADO: Dev-C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ColaDePrioridad.h"
#include "Impresora.h"

#define USUARIO "fernando"
#define CLAVE "maceda"

#define LONGITUD 80

//DECLARACION DE PROTOTIPOS DE FUNCIONES
int login(); //contraseña y usuario para acceso al programa
int bienvenida();
int menu(int);
//Fin de declaracion de prototipos de funciones

//Estructuras



int main()
{
	login();
	int op; 
	int opmenu;
	//printf("%i", op);
		cola miCola1;
		cola miCola2;
		cola miCola3;
		cola miCola4;
		cola miCola5;
	do
	{
		system("cls");
		op = menu (opmenu);
		switch(op)
		{
			case 1:
				system("cls");
				impresora(miCola1);
				break;
			case 2: 
				system("cls");
				impresora(miCola2);
				break;
			case 3: 
				system("cls");
				impresora(miCola3);
				break;
			case 4: 
				system("cls");
				impresora(miCola4);
				break;
			case 5:
				system("cls");
				impresora(miCola5);
				break;
			case 6: //ayuda
				system("cls");
				break;
			case 7: //salir del programa
				system("cls");
				printf("Ha elegido salir del sistema de gestion de impresion. Hasta luego.");
				return 0;
				break;
			default:
				printf("Opcion no valida, por favor, ingrese un valor valido:  ");
				//scanf("%i", &op);
				break;
		}
	getchar();	
	}while(op!=7);
	
	return 0;
}

int login(){
	char usuario[LONGITUD + 1];
    char clave[LONGITUD + 1];
    int intento = 0;
    int ingresa = 0;
    char caracter;
    int i = 0;
    
    do {
        i = 0;
        system("cls");
        printf("\n\t\t\tINICIO DE SESION\n");
        printf("\t\t\t---------------\n");
        printf("\n\tUSUARIO: ");
        gets(usuario);
        printf("\tCLAVE: ");
        while (caracter = getch()) {
            if (caracter == 13) {
                clave[i] = '\0';
                break;
                
            } else if (caracter == 8) {
                if (i > 0) {
                    i--;
                    printf("\b \b");
                }
                
            } else {
            	               if (i < LONGITUD) {
                    printf("*");
                    clave[i] = caracter;
                    i++;
                }
            }
        }
        
        if (strcmp(usuario, USUARIO) == 0 && strcmp(clave, CLAVE) == 0) {
            ingresa = 1;
            
        } else {
            printf("\n\tUsuario y/o clave son incorrectos\n");
            intento++;
            getchar();
        }
        
    } while (intento < 3 && ingresa == 0);
    
    if (ingresa == 1) {
        printf("\n\n\tBienvenido al Sistema\n");
        
    } else {
        printf("\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
    }

    return 0;
}

int bienvenida()
{
//	char nombre[20];
//	printf("Por favor, ingrese su nombre\n");
//	scanf("%s", &nombre);
	printf("\n\tBienvenido %s, por favor, elija alguna de las siguientes opciones:\n\n", USUARIO);
	
	return 0;
}

int menu(int a)
{
	bienvenida();
	printf("\n\t1. Impresora 1\n\t2. Impresora 2\n\t3. Impresora 3\n\t4. Impresora 4\n\t5. Impresora 5\n\t6. Ayuda \n\t7. Salir\n\t", 164);
	printf("\tSeleccione una opcion por favor: ");
	scanf("%i", &a); 
	return a;
}
