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

typedef struct {
    char dn1[10];
    float tasa;
    float sancion;
}T_ALCOHOL

// prototipos
void CargaRadaresManual();
void CargaMultasManual();
void RellenarUnRadar(T_RADAR *prad);
void RellenarUnaMulta(T_MULTA *pmul);
void RellenarFecha(T_FECHA *pfecha);
void RellenarMultaAlcohol();
void CargarMultaAlcohol();
void CalcularMultaAlcohol();


int main(){
    
    int op;
    int n_multas;
    int n_radares;
    int multas_totales;
    int num_multas;
    
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
           
           CargaRadaresManual();
           CargaMultasManual();
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
            
            CargarMultasAlcohol();
            
            multas_totales = CalcularMultaAlcohol();
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
    RellenarFecha(&fecha);
    printf("\nIntroduce el numero identificador del radar: ");
    scanf("%d", &(pmul->id_radar));
    printf("\nIntroduce la matricula: ");
    scanf("%Ns", &(pmul->matricula));
    printf("\nIntroduce la velocidad: ");
    scanf("%d", &(pmul->velocidad));
    return;
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


void CargarMultasAlcochol(){
    int i;
    for(i=0; i<num_multas; i++){
        RellenarMultaAlcohol;
    }
    return;
}

void RellenarMultaAlcohol(){
    RellenarFecha(&fecha);
    printf("\nIntroduce el dni: ");
    scanf("%9s", &(pal->dni));
    printf("\nIntroduce la tasa de alcohol del conductor: ");
    scanf("%f", &(pal->tasa));
    return;
}

void CalcularMultaAlcohol(){
    char op;
    printf("\n¿Es noble el conductor?: si o no\n");
    scanf("%c", &op);
    
    switch(op){
        case 'si':
                if(tasa<0.15){
                    multa[i].sancion = 0;
                }else if(tasa>0.15 && tasa<=0.30){
                    multa[i].sancion = 500;
                }else if(tasa>0.3 && tasa<=0.6){
                    multa[i].sancion = 1000;
                }
                break;
                
                case 'no':
                if(tasa<0.25){
                    multa[i].sancion = 0;
                }else if(tasa>0.25 && tasa<=0.5){
                    multa[i].sancion = 500;
                }else if(tasa>0.5 && tasa<=0.6){
                    multa[i].sancion = 1000;
                }
                break;
                
                default:
                printf("\nError");
    }
    break;
}