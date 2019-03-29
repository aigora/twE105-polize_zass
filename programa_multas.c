#include<stdio.h>
//Lo primero que que quermos hacer es que el operador introduzca el numero de radares que hay operativos y el numero de multas puestas.

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