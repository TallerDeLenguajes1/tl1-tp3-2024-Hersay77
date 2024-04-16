#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ANIOS 5
#define MESES 12


int main(){
    int matriz[ANIOS][MESES];
    float promedio = 0;
    srand(time(NULL));

    
    for(int i =0 ; i < ANIOS; i++){

        for(int j = 0; j < MESES; j++){
            matriz[i][j] = rand()%40001 + 10000; //Cargue dicha matriz con valores aleatorios entre 10000 y 50000.
            printf("matriz[%d][%d] = $ %d ", i+1,j+1, matriz[i][j]); //Muestre por pantalla los valores cargados
        }
        printf("\n");
    }   

    //Saque el promedio de ganancia por año y muestrelos por pantalla
    printf("\n****Promedio de Ganancias por Anio******\n");

    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            promedio = promedio + matriz[i][j]; 
        }
        promedio = (promedio / MESES); //calculo el promedio del año
        printf("Promedio de ganancias Anio %d: $ %.2f\n",  i+1, promedio);
        promedio = 0; //reinicio el promedio para el proximo año
    }

    //Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de cuándo ocurrió.
    float max = matriz[0][0]; //maximo y minimo omenzara con el primer elemento
    float min = matriz[0][0];
    int imax = 0;
    int jmax = 0;
    int imin = 0;
    int jmin = 0;

    for (int i = 0; i < ANIOS; i++)
    {
        for (int j = 0; j < MESES; j++)
        {
            if (max > matriz[i][j])
            {
                max = matriz[i][j];
                imax = i; 
                jmax = j;
            }
            
            if (min < matriz[i][j])
            {
                min = matriz[i][j];
                imin = i;
                jmin = j;
            }
        }   
    }

    printf("\nEl maximo es: $ %.2f, en el Anio: %d y MES: %d", max, imax,jmax);
    printf("\nEl minimo es: $ %.2f, en el Anio: %d y MES: %d", min, imin,jmin);

    return 0;
}