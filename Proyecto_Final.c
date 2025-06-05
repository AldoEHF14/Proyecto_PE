#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int dia;
	char mes[50];
	int anio;	
}FECHA;
typedef struct {
	char nombre[150];
	char categoria[150];
	int codigo;
	int existencia;
	double precio_compra;
	double precio_venta;
	FECHA caducidad;
}PRODUCTO;
typedef struct {
	PRODUCTO *productos;
	int N;
}BD;

//Inicializamos la base de datos
void inicializar_BD(BD *bd){
	bd->N=0;
	bd->productos=NULL;
}
//Finalizamos la base de datos
void finaliza_BD(BD *bd){
	free(bd->productos);
	bd->N=0;
}

//Funcion 1 del programa
void Agregar_BD(BD *bd){
		
	bd->N++;
	bd->productos=(PRODUCTO*)realloc(bd->productos,sizeof(PRODUCTO)*bd->N);
	/*Leer datos*/
	system("cls");
	printf("\n-------------- Agregar Productos --------------\n");
	printf("Nombre:");
	scanf(" %[^\n]", bd->productos[bd->N-1].nombre);
	printf("Categoria:");
	scanf(" %[^\n]",bd->productos[bd->N-1].categoria);
	printf("Codigo:");
	scanf("%d",&bd->productos[bd->N-1].codigo);
	printf("Existencia:");
	scanf("%d",&bd->productos[bd->N-1].existencia);
	printf("Precio Compra:");
	scanf("%lf",&bd->productos[bd->N-1].precio_compra);
	printf("Precio Venta:");
	scanf("%lf",&bd->productos[bd->N-1].precio_venta);
	
	printf("Caducidad\n");
	printf("Dia:");
	scanf("%d",&bd->productos[bd->N-1].caducidad.dia);
	printf("Mes:");
	scanf(" %[^\n]",bd->productos[bd->N-1].caducidad.mes);
	printf("Anio:");
	scanf("%d",&bd->productos[bd->N-1].caducidad.anio);
	
	return ;
}

//Funcion 2 del programa
void Eliminar_BD(BD *bd){
	
	int c,count;
    int i,codigo_eliminar=0;
    do{
	system("cls");
	count=0;
	printf("\nProducto a Eliminar\n");
    printf("\n------------------------------------------------\n\n");
    printf("Ingresa el Codigo:");
    scanf("%d",&codigo_eliminar);		
    for(i=0; i<bd->N; i++)
    {
		if(codigo_eliminar==bd->productos[i].codigo ){		
			strcpy(&bd->productos[i].nombre,&bd->productos[bd->N-1].nombre);
			strcpy(&bd->productos[i].categoria,&bd->productos[bd->N-1].categoria);
			strcpy(&bd->productos[i].codigo,&bd->productos[bd->N-1].codigo);
			strcpy(&bd->productos[i].existencia,&bd->productos[bd->N-1].existencia);
			bd->productos[i].precio_compra=bd->productos[bd->N-1].precio_compra;
			strcpy(&bd->productos[i].precio_venta,&bd->productos[bd->N-1].precio_venta);
			
			strcpy(&bd->productos[i].caducidad.dia,&bd->productos[bd->N-1].caducidad.dia);
			strcpy(&bd->productos[i].caducidad.mes,&bd->productos[bd->N-1].caducidad.mes);
			strcpy(&bd->productos[i].caducidad.anio,&bd->productos[bd->N-1].caducidad.anio);
			count++;
			bd->N = bd->N - 1;
			bd->productos = (PRODUCTO*)realloc(bd->productos, sizeof(PRODUCTO)*(bd->N));    
			printf("\n\n\"Producto Eliminado\"");	
			break;
		}
    }
    if(count!=1)
	{
		printf("\n\n\"Error producto no encontado\"");	
	}
		printf("\n------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No(ELiminar Otro): ");
		scanf("%d",&c);		
	}while(c!=1);
    
	return;
}

//Funcion 3 del programa
void Guardar_BD_a_Binario(BD *bd){
	
	int c;
	FILE *archivo= fopen("BD_producto.dat","w+b");
	fwrite(&bd->N,sizeof(int),1,archivo);
	fwrite(bd->productos,sizeof(PRODUCTO),bd->N,archivo);
	fclose(archivo);
	system("cls");
	printf("\n------------------------------------------------\n");
	printf("\nBD Guardado con Exito\n");
	do{
		printf("------------------------------------------------\n");
		printf("\nRegresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	
	return;
}

//Funcion 4 del programa
void Leer_BD(BD *bd){
	
	int N,c;
	FILE *archivo= fopen("BD_producto.dat","rb");
	system("cls");
	if(bd->productos!= NULL){		
		finaliza_BD(bd);
	}
	fread(&N,sizeof(int),1,archivo);//&N -- &bd->N
	bd->productos=(PRODUCTO*)malloc(sizeof(PRODUCTO)*N);
	fread(bd->productos,sizeof(PRODUCTO),N,archivo);
	bd->N=N;
	fclose(archivo);
	printf("\n------------------------------------------------\n");
	printf("\n BD Leido(Abierto) con Exito\n");
	do{
		printf("------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	
	return;
}

//Funcion 5 del programa
void Mostrar_BD(BD *bd){
	
	int i,c;
	system("cls");
	printf("\n-------------- Lista de Productos --------------\n\n");
	for (i=0;i<bd->N;i++)
	{	
		printf("----------------- %d\n",i+1);
		printf("Nombre: %s\n", bd->productos[i].nombre);
		printf("Categoria: %s\n",bd->productos[i].categoria);
		printf("Codigo: %d\n", bd->productos[i].codigo);
		printf("Existencia: %d\n",bd->productos[i].existencia);
		printf("Precio Compra: %.2lf\n",bd->productos[i].precio_compra);
		printf("Precio Venta: %.2lf\n",bd->productos[i].precio_venta);
		
		printf("Caducidad\n");
		printf("Dia: %d\n",bd->productos[i].caducidad.dia);
		printf("Mes: %s\n",bd->productos[i].caducidad.mes);
		printf("Anio: %d",bd->productos[i].caducidad.anio);
		printf("\n\n");
	}
	do{
		printf("------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	
	return;
}

//Funcion 6 del programa
void Buscar_BD_opc(BD *bd){
	
	int opc,codigo_buscar=0,i,c;
	int count;
	char *nombre_b;
	system("cls");
	count=0;
	printf("Producto a Buscar 1.Codigo/2.Nombre:");
	scanf("%d",&opc);
	if (opc==1)
	{
		printf("\nIngresa el Codigo:");
		scanf("%d",&codigo_buscar);
	}
	else if(opc==2)
	{
		printf("\nIngresa el Nombre:");
		scanf(" %[^\n]",nombre_b);
	}
	for (i=0;i<bd->N;i++)
	{
		if( strcmp(bd->productos[i].nombre,nombre_b)==0 
		|| bd->productos[i].codigo==codigo_buscar && count==0)
		{		
			printf("----------------- %d\n",i+1);
			printf("Nombre: %s\n", bd->productos[i].nombre);
			printf("Categoria: %s\n",bd->productos[i].categoria);
			printf("Codigo: %d\n", bd->productos[i].codigo);
			printf("Existencia: %d\n",bd->productos[i].existencia);
			printf("Precio Compra: %.2lf\n",bd->productos[i].precio_compra);
			printf("Precio Venta: %.2lf\n",bd->productos[i].precio_venta);
			
			printf("Caducidad\n");
			printf("Dia: %d\n",bd->productos[i].caducidad.dia);
			printf("Mes: %s\n",bd->productos[i].caducidad.mes);
			printf("Anio: %d",bd->productos[i].caducidad.anio);
			printf("\n\n");
			count++;
		}
	}
	if(count!=1)
	{
		printf("\n\n\"Error producto no encontado\"\n");	
	}
	do{
		printf("\n------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	return;
}

//Funcion 7 del programa
void C_Invertido(BD *bd){

	system("cls");
	int i,c;
	double suma=0;
	for(i=0; i<bd->N; i++){
		suma= suma + (bd->productos[i].precio_compra*bd->productos[i].existencia);
	}
	printf("\n------------------------------------------------\n\n");
	printf("Cual es el capital invertido en los productos de la tienda? \n\t\n $ %.2lf\n",suma);
	do{
		printf("\n------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	return;
}

//Funcion 8 del programa
void C_Ganancias(BD *bd){

	system("cls");
	int i,c;
	double suma=0.0,suma1=0.0;
	double ganacias_t=0.0;
	for(i=0; i<bd->N; i++){
		suma= suma + (bd->productos[i].precio_compra*bd->productos[i].existencia);
		suma1= suma1 + (bd->productos[i].precio_venta*bd->productos[i].existencia);
	}
	ganacias_t = suma1-suma;
	printf("\n------------------------------------------------\n\n");
	printf("Cual es la ganancia total de los productos en la tienda? \n\t\n $ %.2lf",ganacias_t );
	do{
	printf("\n------------------------------------------------\n");
	
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%d",&c);		
	}while(c!=1);
	
	return;
}

//Funcion qsort programa 9 Ascendente
int anio_caducidad_producto1(const void *a, const void *b)
{
	PRODUCTO *reg1 = (PRODUCTO*)a;
    PRODUCTO *reg2 = (PRODUCTO*)b;
    int a1 = reg1->caducidad.anio;
    int a2 = reg2->caducidad.anio;
    
  	return ( a1 - a2);	
}
//Funcion qsort programa 9 Ascendente
int anio_caducidad_producto2(const void *a, const void *b)
{
	PRODUCTO *reg1 = (PRODUCTO*)a;
    PRODUCTO *reg2 = (PRODUCTO*)b;
    int a1 = reg1->caducidad.anio;
    int a2 = reg2->caducidad.anio;   
    
  	return ( a2 - a1);	
}
//Funcion qsort programa 10
int num_existencias(const void *a, const void *b)
{
    PRODUCTO *reg3 = (PRODUCTO*)a;
    PRODUCTO *reg4 = (PRODUCTO*)b;
    int a3 = reg3->existencia;
    int a4 = reg4->existencia;
    return ( a3 - a4);
}

//Funcion 9 del programa
void Ord_caducidad(BD *bd){
	int i,c;
	do{
	system("cls");
	printf("\nAnio de Caducidad del Producto Orden:\n");
	printf("\n------------------------------------------------\n");
	int op;
	printf("\n\t\t ORDNE \n\n 1.Ascendente / 2.Descendente : ");
	scanf("%i",&op);		
	printf("\n------------------------------------------------\n");
	if(op==1){
		qsort(bd->productos, bd->N, sizeof(PRODUCTO), anio_caducidad_producto1);
	}else if(op==2){
		qsort(bd->productos, bd->N, sizeof(PRODUCTO), anio_caducidad_producto2);
	}
	for(i=0; i<bd->N; i++)
	{	
		printf("----------------- %d\n",i+1);
		printf("Nombre: %s\n", bd->productos[i].nombre);
		printf("Categoria: %s\n",bd->productos[i].categoria);
		printf("Codigo: %d\n", bd->productos[i].codigo);
		printf("Existencia: %d\n",bd->productos[i].existencia);
		printf("Precio Compra: %.2lf\n",bd->productos[i].precio_compra);
		printf("Precio Venta: %.2lf\n",bd->productos[i].precio_venta);
		
		printf("Caducidad\n");
		printf("Dia: %d\n",bd->productos[i].caducidad.dia);
		printf("Mes: %s\n",bd->productos[i].caducidad.mes);
		printf("Anio: %d",bd->productos[i].caducidad.anio);
		printf("\n\n");
	}
		printf("\n------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No(Otra Opcion) : ");
		scanf("%i",&c);		
	}while(c!=1);
	
	return ;
}

//Funcion 10 del programa
void Ord_exitencia(BD *bd){
	
	int i,c;
	system("cls");
	qsort(bd->productos, bd->N, sizeof(PRODUCTO), num_existencias);
	printf("\nNumero de Productos en Existencia Ordenado\n");
	printf("------------------------------------------------\n");
	for(i=0; i<bd->N; i++){
		printf("Producto --------- %d\n",i+1);
		printf("Nombre: %s\n", bd->productos[i].nombre);
		printf("Categoria: %s\n",bd->productos[i].categoria);
		printf("Codigo: %d\n", bd->productos[i].codigo);
		printf("Existencia: %d\n",bd->productos[i].existencia);
		printf("Precio Compra: %.2lf\n",bd->productos[i].precio_compra);
		printf("Precio Venta: %.2lf\n",bd->productos[i].precio_venta);
		
		printf("Caducidad\n");
		printf("Dia: %d\n",bd->productos[i].caducidad.dia);
		printf("Mes: %s\n",bd->productos[i].caducidad.mes);
		printf("Anio: %d",bd->productos[i].caducidad.anio);
		printf("\n\n");
	}
	do{
		printf("\n------------------------------------------------\n");
		printf("\n Regresar al Menu Principal: 1.Si / 2.No : ");
		scanf("%i",&c);		
	}while(c!=1);
	
	return;
}

//Funcion Principal
int main(){	
	
	BD bd;
	int opc;
	inicializar_BD(&bd);
	do{
		system("cls");
		printf("********************* Bienvenido a la Tienda *********************\n\n");
		printf("1.Agregar Producto\n");
		printf("2.Eliminar Producto\n");		
		printf("3.Archivo Binario (Escribir-Guardar)\n");
		printf("4.Leer Archivo (Abrir)\n");
		printf("5.Mostrar Productos\n");
		printf("6.Buscar producto\n");
		printf("7.Capital invetido\n");
		printf("8.Ganacias Totales\n");	
		printf("9.Ordenacion de productos\n");
		printf("10.Ordenamiento existencias\n\n");		
		printf("-----\n");
		printf("11.Salir del Programa\n");
		printf("----\n");
		printf("Ingresa una Opcion: ");
		scanf("%d",&opc);
		printf("\n\n");
		
		switch(opc){
			case 1:
				Agregar_BD(&bd);
				break;
			case 2:
				Eliminar_BD(&bd);
				break;
			case 3:
				Guardar_BD_a_Binario(&bd);
				break;
			case 4:
				Leer_BD(&bd);
				break;				
			case 5:
				Mostrar_BD(&bd);
				break;				
			case 6:
				Buscar_BD_opc(&bd);
				break;
			case 7:
				C_Invertido(&bd);
				break;
			case 8:
				C_Ganancias(&bd);
				break;
			case 9:			
				Ord_caducidad(&bd);
				break;
			case 10:
				Ord_exitencia(&bd);
				break;
			case 11:
                printf("\nCierre de Programa \n");
				break;
			default: break;
		}
	}while(opc!=11);
	
	finaliza_BD(&bd);
	return 0;
}
