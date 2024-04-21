/*4) Considere la siguiente situación: En una distribuidora necesita implementar la carga de
productos de sus preventistas, los cuales recolectan los productos que sus clientes van
necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
equipo de programación que se encargará de hacer el módulo para los preventistas:
Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
puede pedir hasta 10 productos*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
}typedef producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    producto *Productos //El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
}typedef cliente;

float calcularCostoTotal(producto prod);

int main(){
    int cantClientes;
    float costoTotal, sumatoria;
    //i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de clientes.
    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantClientes);

    //ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
    cliente *clientes = (cliente *)malloc(cantClientes * (sizeof(cliente))); //creo puntero a reserva dinamica de tipo estructura para cada cliente

    char *Buff; //creo el buffer para cargar los nombres
    Buff= (char *) malloc(100*sizeof(char));

    srand(time(NULL)); //para numeros aleatorios
    
    puts("\n***********CARGA DE DATOS*************");
    for (int i = 0; i < cantClientes; i++)
    {
        clientes[i].ClienteID = i+1; //el id del cliente viene del ciclo iterativo
        printf("\nIngrese datos Cliente %d: ", clientes[i].ClienteID);
        printf("\nIngrese el nombre del cliente: ");
        fflush(stdin); //limpio el buffer de entrada
        gets(Buff);
        clientes[i].NombreCliente = (char *)malloc(strlen(Buff)+1 * sizeof(char)); //creo reserva de memoria dinamica para el nombre del cliente i, segun tamaño del buff
        strcpy(clientes[i].NombreCliente,Buff);
        clientes[i].CantidadProductosAPedir = rand()%(5) + 1; //genero cantidad de productos en rango 1  5

        clientes[i].Productos = (producto *)malloc(clientes[i].CantidadProductosAPedir * sizeof(producto)); //creo reserva dinamica para arreglo de tipo producto que contendra caracteristicas de cada producto

        //iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de productos asociados al cliente y sus características.
        //Cargo datos de producto de forma aleatoria
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            clientes[i].Productos[j].ProductoID = j+1;
            clientes[i].Productos[j].Cantidad = rand()%(10) + 1; 
            clientes[i].Productos[j].TipoProducto = TiposProductos[j]; //aqui uso el indice j y no un rand para que no se repita el producto 
            clientes[i].Productos[j].PrecioUnitario = (float)(rand()%(91) + 10);
        }
    }

    //v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente (sumatoria del costo de todos los productos)
    puts("\n\n*******MOSTRANDO DATOS********");
    for (int i = 0; i < cantClientes; i++)
    {
        printf("\n*****Datos de Cliente %d: ******\n", clientes[i].ClienteID);
        printf("\nNombre del cliente: %s", clientes[i].NombreCliente);
        printf("\nCantidad de produtos: %d", clientes[i].CantidadProductosAPedir);
        puts("\n\n------Productos: -------");
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nProducto: %d", clientes[i].Productos[j].ProductoID);
            printf("\nCantidad: %d\n", clientes[i].Productos[j].Cantidad);
            printf("Tipo de Producto: %s\n", clientes[i].Productos[j].TipoProducto);
            printf("Precio Unitario:$ %.2f\n", clientes[i].Productos[j].PrecioUnitario);

            //iv) Implemente una función que calcule el costo total de un producto. Esta función debe recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por el PrecioUnitario.
            costoTotal = calcularCostoTotal(clientes[i].Productos[j]);
            printf("El costo total del producto %s es:$ %.2f\n", clientes[i].Productos[j].TipoProducto ,costoTotal);
            sumatoria  += costoTotal; //parte del punto 5 - total a pagaar por cliente que seria la suma de los costos totales de cada producto 
        }

        printf("\nEl costo total de todos los productos para el cliente (sumatoria) es:$ %.2f\n", sumatoria);
    }

    for (int i = 0; i < cantClientes; i++)
    {   
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            free(clientes[i].Productos); //libero memoria dinamica para cada producto de cada cliente
        }
    }
    

    for (int i = 0; i < cantClientes; i++)
    {
        free(clientes[i].NombreCliente); //libero memoria dinamica para cada nombre
    }

    free(clientes); //libero memoria reservada para arreglo de clientes
    free(Buff); //libero memoria reservada para el buff

        
    return 0;
}

float calcularCostoTotal(producto prod){
    return   prod.PrecioUnitario * prod.Cantidad; 
}