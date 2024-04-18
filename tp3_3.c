#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *Buff; //creo el buffer para cargar los nombres
    Buff= (char *) malloc(100*sizeof(char));

    char **nombres; //declaraion puntero doble 
    nombres = (char **)malloc(5 * sizeof(char *)); // asigno la direccion del primer elemento de un reserva dinmica que contendra a su vez tipos punteros char
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: \n", i+1);
        gets(Buff);
        nombres[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char)); //por cada nombre que se ingrese (filas) se reserva memoria dinamica para un arreglo tipo char segun el tamaño del nombre + espacio para "\0"
        strcpy(nombres[i],Buff); //se copia lo ingresado en buff a la primera fila
    }

    //Muestro la matriz
    printf("\n*******LISTA DE NOMBRES******\n");

    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]); //como cada fila es un arreglo tipo char utilizo notacion subindexada para mostrara los elementos de una fil, es decir un nombre
    }

    for (int i = 0; i < 5; i++)
    {
        free(nombres[i]); //libero memoria en el heap, de cada nombre
    }
    
    free(nombres); //libero memoria de filas
    free(Buff); //libero memoria del buff donde se guardaba el nombre

    return 0;
}



