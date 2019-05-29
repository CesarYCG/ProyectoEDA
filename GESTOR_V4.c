#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define MAXCOLA 5 //La impresora podra almacenar un maximo de 5 elementos
#define USUARIO "fernando"
#define CLAVE "maceda"

#define LONGITUD 80

//Estructuras
struct structCola
{
	char nombre[MAXCOLA] [50];
//	int head;
	int tail;
}; typedef struct structCola cola;

//DECLARACION DE PROTOTIPOS DE FUNCIONES
int login(); //contraseña y usuario para acceso al programa
int bienvenida();
int menu(int);
void impresora(cola miCola);
void crearCola(cola *miCola); //Crea la cola
int colaVacia(cola *miCola); //Funcion que me indicara si la cola esta vacia
int colaLlena(cola *miCola); //Funcion que indica si la cola esta llena
void reajusteColas(cola *miCola); //Movera los elementos de la cola cuando se efectuen operaciones pop
void push(cola *miCola, char nombre[]); //Agrega un elemento por el tail de la cola
char *pop(cola *miCola); //Elimina el elemento ubicado en el head de la cola
void mostrarTope(cola *miCola); //Muestra el tope de la cola
void mostrarFULLCola(cola *miCola); //Muestra todo el contenido de la cola
void ayudaMenu();
//Fin de declaracion de prototipos de funciones


int main()
{
	login();
	int op; 
	int opmenu;
	//cola miCola; //variable miCola tipo cola
	char nombre[50];
	char *nombreReturn; //Para la funcion pop, que almacenara la variable que retorna pop
	
	
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
				int op2;
				do
				{
					system("cls"); //Limpiamos la pantalla
					printf("//-----MENU-----//\n\n");
					printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
					printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
					scanf("%i", &op2);
		
					switch(op2)
					{
						case 1: //Push
						system("cls");
						if(colaLlena(&miCola1))
						printf("La cola de impresion esta llena. Seleccione otra impresora");
						else
					{
						printf("Escriba el nombre de su archivo: ");
						scanf("%s", nombre);
						push(&miCola1, nombre);
						printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
					}
					break;
					case 2: //Pop
						system("cls");
				
						if (colaVacia(&miCola1))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El usuario %s ",USUARIO);
							nombreReturn=pop(&miCola1);
							strcpy(nombre, nombreReturn);
							printf(" ha impreso %s y se ha retirado de la cola de impresion", nombre);
						}
						break;
						case 3: //Muestra tope de la cola
							system("cls");
							if(colaVacia(&miCola1))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El tope de la cola es: ");
							mostrarTope(&miCola1);
						}
						break;
						case 4: //Muestra TODA la cola de impresion
							system("cls");
							mostrarFULLCola(&miCola1);
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
				}while(op2!=6);
	
				
				break;
			case 2: 
				system("cls");
				int op3;
				do
				{
					system("cls"); //Limpiamos la pantalla
					printf("//-----MENU-----//\n\n");
					printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
					printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
					scanf("%i", &op3);
		
					switch(op3)
					{
						case 1: //Push
						system("cls");
						if(colaLlena(&miCola2))
						printf("La cola de impresion esta llena. Seleccione otra impresora");
						else
					{
						printf("Escriba el nombre de su archivo: ");
						scanf("%s", nombre);
						push(&miCola2, nombre);
						printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
					}
					break;
					case 2: //Pop
						system("cls");
				
						if (colaVacia(&miCola2))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El usuario %s ",USUARIO);
							nombreReturn=pop(&miCola1);
							strcpy(nombre, nombreReturn);
							printf(" ha impreso %s y se ha retirado de la cola de impresion", nombre);
						}
						break;
						case 3: //Muestra tope de la cola
							system("cls");
							if(colaVacia(&miCola2))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El tope de la cola es: ");
							mostrarTope(&miCola2);
						}
						break;
						case 4: //Muestra TODA la cola de impresion
							system("cls");
							mostrarFULLCola(&miCola2);
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
				}while(op3!=6);			
				break;
			case 3: 
				system("cls");
				int op4;
				do
				{
					system("cls"); //Limpiamos la pantalla
					printf("//-----MENU-----//\n\n");
					printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
					printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
					scanf("%i", &op4);
		
					switch(op4)
					{
						case 1: //Push
						system("cls");
						if(colaLlena(&miCola3))
						printf("La cola de impresion esta llena. Seleccione otra impresora");
						else
					{
						printf("Escriba el nombre de su archivo: ");
						scanf("%s", nombre);
						push(&miCola3, nombre);
						printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
					}
					break;
					case 2: //Pop
						system("cls");
				
						if (colaVacia(&miCola3))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El usuario %s ",USUARIO);
							nombreReturn=pop(&miCola3);
							strcpy(nombre, nombreReturn);
							printf(" ha impreso %s y se ha retirado de la cola de impresion", nombre);
						}
						break;
						case 3: //Muestra tope de la cola
							system("cls");
							if(colaVacia(&miCola3))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El tope de la cola es: ");
							mostrarTope(&miCola3);
						}
						break;
						case 4: //Muestra TODA la cola de impresion
							system("cls");
							mostrarFULLCola(&miCola3);
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
				}while(op4!=6);				
				break;
			case 4: 
				system("cls");
				int op5;
				do
				{
					system("cls"); //Limpiamos la pantalla
					printf("//-----MENU-----//\n\n");
					printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
					printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
					scanf("%i", &op5);
		
					switch(op5)
					{
						case 1: //Push
						system("cls");
						if(colaLlena(&miCola4))
						printf("La cola de impresion esta llena. Seleccione otra impresora");
						else
					{
						printf("Escriba el nombre de su archivo: ");
						scanf("%s", nombre);
						push(&miCola4, nombre);
						printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
					}
					break;
					case 2: //Pop
						system("cls");
				
						if (colaVacia(&miCola4))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El usuario %s ",USUARIO);
							nombreReturn=pop(&miCola4);
							strcpy(nombre, nombreReturn);
							printf(" ha impreso %s y se ha retirado de la cola de impresion", nombre);
						}
						break;
						case 3: //Muestra tope de la cola
							system("cls");
							if(colaVacia(&miCola4))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El tope de la cola es: ");
							mostrarTope(&miCola4);
						}
						break;
						case 4: //Muestra TODA la cola de impresion
							system("cls");
							mostrarFULLCola(&miCola4);
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
				}while(op5!=6);				
				break;
			case 5:
				system("cls");
				int op6;
				do
				{
					system("cls"); //Limpiamos la pantalla
					printf("//-----MENU-----//\n\n");
					printf("1. Insertar archivo en la impresora.\n2. Imprimir elemento siguiente.\n3. Mostrar tope de la impresora.\n");
					printf("4. Mostrar la cola de impresion.\n5. Ayuda.\n6. Salir.\n\nSeleccione una opcion: ");
					scanf("%i", &op6);
		
					switch(op6)
					{
						case 1: //Push
						system("cls");
						if(colaLlena(&miCola5))
						printf("La cola de impresion esta llena. Seleccione otra impresora");
						else
					{
						printf("Escriba el nombre de su archivo: ");
						scanf("%s", nombre);
						push(&miCola5, nombre);
						printf("\nSu documento '%s' se ha agregado a la cola de impresion correctamente", nombre);
					}
					break;
					case 2: //Pop
						system("cls");
				
						if (colaVacia(&miCola5))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El usuario %s ",USUARIO);
							nombreReturn=pop(&miCola5);
							strcpy(nombre, nombreReturn);
							printf(" ha impreso %s y se ha retirado de la cola de impresion", nombre);
						}
						break;
						case 3: //Muestra tope de la cola
							system("cls");
							if(colaVacia(&miCola5))
							printf("La cola de impresion se encuentra vacia");
						else
						{
							printf("El tope de la cola es: ");
							mostrarTope(&miCola5);
						}
						break;
						case 4: //Muestra TODA la cola de impresion
							system("cls");
							mostrarFULLCola(&miCola5);
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
				}while(op6!=6);				
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

//--------------------PROGRAMACION DE FUNCIONES-------------------------//
void crearCola(cola *miCola) //Crea la cola
{
	cola c;
//	miCola->head=1;
	miCola->tail=0;
//	return c;
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

