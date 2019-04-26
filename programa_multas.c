#include<stdio.h>

}// estructuras
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

typedef struct {
    int id_radar;
    int velocidad_limite;
    int umbral20;
    int umbral40;
    int umbralresto;
}T_RADAR;

// prototipos
void CargaRadaresManual();
void CargaMultasManual();
void RellenarUnRadar();
void RellenarUnaMulta();

int main(){
    
    int op;
    int n_multas;
    int n_radares;
    
	//En caso de no elegir ni la primera ni la segunda vuelve a preguntar 
	do{
		printf("Elige programa: Multas por velocidad(1) o multas por alcohol(2) \n");
		scanf("%i", &op);
        if(op!=1 && op!=2){
            printf("Error, el programa selecionado no existe\n\n");
        }
	}while(op!=1 && op!=2);
	
    switch(op){
		case 1:
			printf("funcion primer programa\n");
            
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
           
           CargaRadaresManual();
           CargaMultasManual();
			break;
            
		case 2:
			printf("funcion segundo programa\n");
        break;
    }
   
   return 0;
}


void CargaRadaresManual(){
    int i;
    for(i=0; i<num_radares; i++){
        RellenarUnRadar();
    }
    return;
}

void CargaMultasManual(){
    int i;
    for(i=0; i<num_multas; i++){
        RellenarUnaMulta();
    }
    return;
}


void RellenarUnRadar(){
    printf("\nIntroduce el identificador del radar: ");
    scanf("%d",&(prad->id_radar));
    printf("\nIntroduce la velocidad limite: ");
    scanf("%d",&(prad->velocidad_limite));
    printf("\nIntroduce la cantidad en el umbral 0-20: ");
    scanf("%d",&(prad->umbral20));
    printf("\nIntroduce la cantidad en el umbral de 20-40: ");
    scanf("%d",&(prad->umbral40));
    printf("\nIntroduce la cantidad en el umbral >40: ");
    scanf("%d",&(prad->umbral_resto));
    return;
}


void RellenarUnaMulta(){
    RellenarFecha();
    printf("\nIntroduce el numero identificador del radar: ");
    scanf("%d", &(pmul->id_radar));
    printf("\nIntroduce la matricula: ");
    //scanf("", );
    printf("\nIntroduce la velocidad: ");
    scanf("%d", &(pmul->velocidad));
    return;
}