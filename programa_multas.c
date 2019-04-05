#include<stdio.h>
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

