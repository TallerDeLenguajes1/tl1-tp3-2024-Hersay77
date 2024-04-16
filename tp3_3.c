#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char *Buff; //creo el buffer para cargar los nombres
    Buff= (char *) malloc(100*sizeof(char));

    //creo la matriz dinamica con puntero doble
    char **nombres;
    nombres = (char **)malloc(5 * sizeof(char *));
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre %d: \n", i+1);
        gets(Buff);
        nombres[i]= (char *) malloc((strlen(Buff)+1)*sizeof(char));
        strcpy(nombres[i],Buff);
    }

    //Muestro la matriz
    printf("\n*******LISTA DE NOMBRES******\n");

    for (int i = 0; i < 5; i++)
    {
        puts(nombres[i]);
    }

    free(nombres);
    free(Buff);
    
    return 0;
}



