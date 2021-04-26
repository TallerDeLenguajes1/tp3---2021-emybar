#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>



struct Producto{
               int ProductoID;
               int Cantidad;
               char *TipoProducto;
               float PrecioUnitario;
};typedef struct Producto prod ;

struct Cliente {
                int ClienteID;
                char *NombreCliente;
                int CantidadProdusctosAPedir;
                Producto *Productos;
};typedef struct Cliente cliente;

 char * TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
void cargarDato(Cliente *pcliente, int n,Producto * productos);
prod obtenerprod (int id);
void cargarProductos (cliente pcliente);
void mostrarProducto (Producto producto);
void mostrarProductos ( Producto * productos,int cant);
void mostrarClientes ( Cliente * pclientes, int n);
void mostrarCliente (Cliente pcliente);
float totalProducto (Producto producto);
float totalCliente (Cliente pcliente);

int main(){
srand (time(NULL)); 
Cliente  *p_cliente;
Producto  *p_prod;
int nclientes; 


    printf("Ingrese la cantidad de clientes que desea cargar: ");
    scanf("%d", &nclientes);
    fflush(stdin);

    p_cliente=(Cliente *) malloc(sizeof(Cliente) *nclientes);

cargarDato(p_cliente, nclientes,p_prod);
mostrarClientes (p_cliente, nclientes);
free(p_cliente);

    return 0 ; 
}

void cargarDato( cliente *pcliente, int n, Producto * productos){
  for (int i = 0; i < n; i++){
    pcliente[i].ClienteID = i+1;
    printf("------------INGRESE LOS DATOS DEL Cliente [%d]---------------\n", i+1); 
    fflush(stdin);
    pcliente[i].NombreCliente = (char *) malloc(50);
	printf("Nombre del cliente:");
	gets( pcliente[i].NombreCliente);
    pcliente[i].CantidadProdusctosAPedir = 1 + rand()% 5;
    fflush(stdin);
    pcliente[i].Productos = (prod*)malloc(sizeof(prod) *pcliente[i].CantidadProdusctosAPedir);
    fflush(stdin);
    printf("Cantidad de productos: %d \n", pcliente[i].CantidadProdusctosAPedir);
    fflush(stdin);
    cargarProductos(pcliente[i]);
    fflush(stdin);
    printf("------------PRODUCTOS DEL ID [%d]---------------\n", i+1); 
    mostrarProductos(pcliente[i].Productos,pcliente[i].CantidadProdusctosAPedir);
    fflush(stdin);

    }
}

prod obtenerprod (int id) {

Producto p_prod;
    p_prod.ProductoID = id;
	p_prod.Cantidad = 1 + rand() % 10;
    p_prod.TipoProducto=(char*)malloc(sizeof(char));
	p_prod.TipoProducto = TiposProductos[rand() % 5];
	p_prod.PrecioUnitario = 10 + rand() % 91;

	return p_prod;
}

void cargarProductos (cliente pcliente){
        for (int i = 0; i < pcliente.CantidadProdusctosAPedir; i++){
		pcliente.Productos[i] = obtenerprod(i + 1);
    
	}
}

void mostrarProducto (Producto producto){
	printf("ID DEL PRODUCTO: %d\n", producto.ProductoID);
	printf("CANTIDAD: %d\n", producto.Cantidad);
	printf("TIPO: %s\n", producto.TipoProducto);
	printf("PRECIO UNITARIO: $%.2f\n", producto.PrecioUnitario);
    printf("\t------------Precio Total: $%.2f ------------\n", totalProducto(producto));
	printf("\n");
}

void mostrarProductos ( Producto * productos,int cant){
	for (int i = 0 ; i < cant ; i++){
		mostrarProducto(productos[i]);
}
}

void mostrarCliente (cliente pcliente){
	printf("------------ ID DEL CLIENTE:%d", pcliente.ClienteID);printf("------------\n");
	printf("NOMBRE: %s\n", pcliente.NombreCliente);
	printf("----------PRODUCTOS PEDIDOS :----------\n");
	mostrarProductos(pcliente.Productos,pcliente.CantidadProdusctosAPedir);
    printf("\t------------TOTAL A PAGAR: $%.2f ----------\n", totalCliente(pcliente));
    
}

void mostrarClientes ( Cliente * pclientes, int n){
	printf("------------COMPRAS DEL CLIENTE---------------\n");
	for (int i = 0 ; i < n ; i++){
		mostrarCliente(pclientes[i]);
}
}

float totalProducto (Producto producto){
    float total=0;

      total = producto.Cantidad * producto.PrecioUnitario;

return total;

}

float totalCliente (Cliente pcliente){
    float total=0;
    for (int i = 0 ; i < pcliente.CantidadProdusctosAPedir ; i++){
		total =total +  totalProducto(pcliente.Productos[i]);
	}
	return total;
}

