#include <stdio.h>
#include <stdlib.h>
#define N 8

// estructuras
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
    int umbral_resto;
}T_RADAR;

typedef struct {
    char dni[10];
    float tasa;
    float sancion;
}T_ALCOHOL;

// prototipos
void CargaRadaresManual(T_RADAR *radares, int num_radares);
void CargaMultasManual(T_MULTA *multas, int num_multas);
void RellenarUnRadar(T_RADAR *prad);
void RellenarUnaMulta(T_MULTA *pmul);
void RellenarFecha(T_FECHA *pfecha);
float CalculaMultas(T_MULTA *multas, int num_multas, T_RADAR *radares, int num_radares);
int BuscarIndiceRadar(int identificador_radar, T_RADAR *radares, int num_radares); 
void RellenarMultaAlcohol(T_ALCOHOL *palc);
void CargarMultaAlcohol(T_ALCOHOL *multas, int num_multas);
float CalcularMultaAlcohol(T_MULTA *multas, int num_multas);


int main(){
	
	T_RADAR *v_radares;
   	T_MULTA *v_multas;
    int op;
    int n_multas;
    int n_radares;
    float multas_totales;
    
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
			printf("\nFuncion primer programa");
            
            //pide el numero de radares y se repite hasta que sea un numero positivo
            do{
               printf("\nIntroduce el numero de radares: ");
               scanf("%d",&n_radares);
               if(n_radares<=0){
                   printf("\nDebe ser positivo");
               }
           }while(n_radares<=0);
           
           //pide el numero de multas y se repite hasta que el numero sea posivo 
           do{
               printf("\nIntroduce el numero de multas: ");
               scanf("%d",&n_multas);
               if(n_multas<=0){
                   printf("\nDebe ser positivo");
               }
           }while(n_multas<=0);
           
               v_radares=(T_RADAR *)calloc(n_radares,sizeof(T_RADAR));
			   v_multas=(T_MULTA *)calloc(n_multas,sizeof(T_MULTA));
			   if(v_radares==NULL||v_multas==NULL){
			       printf("\nError guardando menoria dinamica");
			   }
			   else{
			       CargaRadaresManual(v_radares,n_radares);
			       CargaMultasManual(v_multas,n_multas);
			       multas_totales= CalculaMultas(v_multas, n_multas, v_radares, n_radares);
			       printf("\nEl valor total de la sancion impuesta es: %.2f",multas_totales);
			       free(v_radares);
			       free(v_multas);
			   }

			break;
            
		case 2:
			printf("\nFuncion segundo programa");
            
            do{
               printf("\nIntroduce el numero de multas: ");
               scanf("%d",&n_multas);
               if(n_multas<=0){
                   printf("\nDebe ser positivo");
               }
           }while(n_multas<=0);
            //memoria dinamica
            v_multas=(T_ALCOHOL *)calloc(n_multas,sizeof(T_ALCOHOL));
			if(v_multas==NULL){
               printf("\nError guardando menoria dinamica");
            }
            else{
            CargarMultaAlcohol(v_multas,n_multas);
            printf("\nEl valor total de la sancion impuesta es: %.2f",multas_totales);
            free(v_multas);
            break;
            
            default:
            printf("\nError");
    }
   return 0;
}


void CargaRadaresManual(T_RADAR *radares, int num_radares){
    int i;
    for(i=0; i<num_radares; i++){
        RellenarUnRadar(&radares[i]);
    }
    return;
}

void CargaMultasManual(T_MULTA *multas,int num_multas){
    int i;
    for(i=0; i<num_multas; i++){
        RellenarUnaMulta(&multas[i]);
    }
    return;
}

//para introducir todos los datos q componen el rardar
void RellenarUnRadar(T_RADAR *prad){
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

//introduce todos los datos q cumponen la multa
void RellenarUnaMulta(T_MULTA *pmul){
    T_FECHA fecha;
    RellenarFecha(&fecha);
    printf("\nIntroduce el numero identificador del radar: ");
    scanf("%d", &(pmul->id_radar));
    printf("\nIntroduce la matricula: ");
    scanf("%Ns", &(pmul->matricula));
    printf("\nIntroduce la velocidad: ");
    scanf("%d", &(pmul->velocidad));
    return;
}

int BuscarIndiceRadar(int identificador_radar,T_RADAR*radares,int num_radares)
{	
   int i;
   int indice;
   indice=-1;
   i=0;
   while(i<num_radares&&indice==-1){
       if(radares[i].id_radar==identificador_radar){
           indice=i;
       }
       i++;
   }
   return indice;
}


float CalculaMultas(T_MULTA *multas,int num_multas,T_RADAR *radares,int num_radares)
{
   int i;
   float res;
   int indice;
   int diferencia;
   float umbral;
   res=0;
   for(i=0;i<num_multas;i++){
       indice=BuscarIndiceRadar(multas[i].id_radar,radares,num_radares);
       if(indice==-1){
           printf("\nEl identificador %d no existe",multas[i].id_radar);
       }
       else{
           diferencia=multas[i].velocidad-radares[indice].velocidad_limite;
           if(diferencia>0){
               umbral=diferencia*100/(float)radares[indice].velocidad_limite;
               if(umbral>0&&umbral<=20){
                   multas[i].sancion=radares[indice].umbral20;
               }
               else{
                   if(umbral>20&&umbral<=40){
                       multas[i].sancion=radares[indice].umbral40;
                   }
                   else{
                           multas[i].sancion=radares[indice].umbral_resto;
                   }
               }
               res=res+multas[i].sancion;
               printf("\nLa sancion del vehiculo %s ha sido de %.f euros",multas[i].matricula,multas[i].sancion);
           }
       }
   }
   return res;
}



void RellenarFecha(T_FECHA *pfecha){
    printf("\nIntroduce la fecha:");
    printf("\nDia: ");
    scanf("%d", &(pfecha->dia));
    printf("\nMes: ");
    scanf("%d", &(pfecha->mes));
    printf("\nAnio: ");
    scanf("%d", &(pfecha->anio));
    return;
}


void CargarMultaAlcohol(T_ALCOHOL *multas,int num_multas){
    int i;
    for(i=0; i<num_multas; i++){
        RellenarMultaAlcohol(&multas[i]);
    }
    return;
}

void RellenarMultaAlcohol(T_ALCOHOL *palc){
    T_FECHA fecha; 
    RellenarFecha(&fecha);
    printf("\nIntroduce el dni: ");
    scanf("%9s", &(palc->dni));
    printf("\nIntroduce la tasa de alcohol del conductor: ");
    scanf("%f", &(palc->tasa));
    return;
}

float CalcularMultaAlcohol(T_ALCOHOL *multas,int num_multas){
    char op;
    int i;
    float tasa;
    float res;
    
    printf("\n¿Es noble el conductor?: s(si la respuesta es SI) o no(si la respuesta es NO)\n");
    scanf("%c", &op);
    
    switch(op){
        case 's':
                if(tasa<0.15){
                    multas[i].sancion = 0;
                }else if(tasa>0.15 && tasa<=0.30){
                    multas[i].sancion = 500;
                }else if(tasa>0.3 && tasa<=0.6){
                    multas[i].sancion = 1000;
                }
                break;
                
        case 'n':
                if(tasa<0.25){
                    multas[i].sancion = 0;
                }else if(tasa>0.25 && tasa<=0.5){
                    multas[i].sancion = 500;
                }else if(tasa>0.5 && tasa<=0.6){
                    multas[i].sancion = 1000;
                }
                break;
                
        default:
                printf("\nError");
    }
    res=res+multas[i].sancion;
    printf("\nLa sancion de la persona con DNI: %s ha sido de %.f euros",multas[i].dni, multas[i].sancion);
    return res;
}
