#include<stdio.h>
//Aqui comienza el menu del programa en el que te deja elegir la funcion del primer programa o la del segundo 
void main()
{
	int op;
	printf("Elige programa: Multas por velocidad(1) o multas por alcohol(2) \n");
	scanf("%i", &op);
	//En caso de no elegir ni la primera ni la segunda vuelve a preguntar 
	while(op!=1 && op!=2)
	{
		printf("Elige programa: Multas por velocidad(1) o multas por alcohol(2) \n");
		scanf("%i", &op);
	}
	switch(op)
	{
		case 1:
			printf("funcion primer programa\n");
			break;
		case 2:
			printf("funcion segundo programa\n");
				break;
			}		
}// FIN DEL MENU
//Lo primero que que quermos hacer es que el operador introduzca el numero de radares que hay operativos y el numero de multas puestas.
typedef struct {
   int id_radar;
   char matricula[N];
   int velocidad;
   float sancion;
}T_MULTA;

typedef struct {
   int dia;
   int mes;
   int anio;
}T_FECHA;


int main(){
   int n_multas;
   int n_radares;
   do{
       printf("\nIntroduce el numero de radares: ");
       scanf("%d",&n_radares);
       if(n_radares<=0){
           printf("\nDebe ser positivo");
       }
   }while(n_radares<=0);
   do{
       printf("\nIntroduce el numero de multas: ");
       scanf("%d",&n_multas);
       if(n_multas<=0){
           printf("\nDebe ser positivo");
       }
   }while(n_multas<=0);
   
   return 0;

}

