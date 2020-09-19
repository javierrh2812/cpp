#include "util.h"
#include <time.h>

/*Ejercicio 1
Elaborar un programa en entorno consola que permita almacenar en un arreglo hasta 100 valores enteros. Luego realice lo siguiente:
	Generar los datos del arreglo en forma aleatoria
	Listar en pantalla los elementos del arreglo
	Buscar el mayor y mostrar su ubicación
	Buscar el menor y mostrar su ubicación
	Ordenar el arreglo en forma descendente y mostrarlo en pantalla
En la solución considere un menú de opciones para cada funcionalidad y utilice funciones, punteros y arreglos dinámicos.
*/

int main(){
 srand(time(NULL));
 
 int *intArray = new int[100];
 int intArray2[3]{1,2,3};
 llenarArregloInt(intArray, 100 , 0, 100);
  
 cout << "intArray: "<< intArray << endl;
 cout << "*intArray: "<< *intArray << endl;
 cout << "&intArray: "<< &intArray << endl;
 cout << "intArray[0]: "<< intArray[0] << endl;
 cout << "&intArray[0]: "<< &intArray[0] << endl;

 cout << "intArray2: "<< intArray2 << endl;
 cout << "*intArray2: "<< *intArray2 << endl;
 cout << "&intArray2: "<< &intArray2 << endl;
 cout << "intArray2[0]: "<< intArray2[0] << endl;
 cout << "&intArray2[0]: "<< &intArray2[0] << endl;


 int op=0;
 do{
  cout <<"\n===========menu==============\n";
  cout <<"1. listar los datos\n";
  cout <<"2. buscar mayor\n";
  cout <<"3. buscar menor\n";
  cout <<"4. ordenar descendente\n";
  cout <<"5. salir\n";
  cout << "opcion?: ";
  cin >> op; cin.ignore();

  switch(op){
   case 1: 
	   listarArregloInt(intArray,100);
	   break;
   case 2:
	   cout << "el mayor es: "<<buscarMayor(intArray,100);
	   break;
   case 3:
	   cout << "el menor es: "<<buscarMenor(intArray,100);
	   break;
   case 4:
	   break;
   case 5: 
	   cout << "===chau===\n";
	   break;
   default: 
	   break;
  }

 }while (op!=5);
 
}
