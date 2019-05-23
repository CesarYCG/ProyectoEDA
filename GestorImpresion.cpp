#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define USUARIO "fernando"
#define CLAVE "maceda"

#define LONGITUD 80

//DECLARACION DE PROTOTIPOS DE FUNCIONES
int bienvenida();
int menu(int);
int login();

//Fin de declaracion de prototipos de funciones

int main()
{
	int op; 
	int opmenu;
	login();
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
			printf("Opcion no valida, por favor, ingrese un valor valido ");
	}
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
        printf("\n\tBienvenido al Sistema\n");
        
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
	printf("Bienvenido %s, por favor, elija alguna de las siguientes opciones:\n", USUARIO);
	
	return 0;
}

int menu(int a)
{
	printf("1. Ver impresoras disponibles \n2. A%cadir una impresora \n3. Eliminar una impresora \n4. Ver colas de impresion \n5. Mandar a imprimir un archivo\n6. Salir\n", 164);
	printf("Seleccione una opcion por favor: ");
	scanf("%i", &a); 
	return a;
}
