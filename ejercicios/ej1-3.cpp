#include "util.h"
/*Ejercicio 3
Escribir un programa:
a.Que genere un arreglo dinámico de tamaño 30 cuyos
valores serán datos aleatorios del 1 al 100.

b.Ordenar el arreglo de menor a mayor

c.Imprimir los valores del arreglo colocando al
costado cuantas veces se ha repetido. 
Si el arreglo fuera de tamaño 10, los valores del arreglo ordenado son:
1, 1, 3, 4, 4, 4, 5, 40, 40, 40
Deberá imprimirse:
1 se repite 2 veces
3 se repite 1 vez
4 se repite 3 veces
5 se repite 1 vez
40 se repite 3 veces

d.Borrar todos los valores repetidos del arreglo 
y dejar solo el primero de cada valor no repetido 
e imprimirlo nuevamente, por ejemplo:
1, 3, 4, 5, 40*/

void imprimiriRepetidos(int*, int);
void borrarRepetidos(int*, int);
int main(){
 int *intArray = new int[30];
 
 llenarArreglo(intArray, 30, 1,100);
 
 listarArreglo(intArray,30);

 ordenarArregloAscendente(intArray,30);
 
 listarArreglo(intArray,30);

 imprimirRepetidos(intArray,30);
 
 borrarRepetidos(intArray,30);

}

void imprimirRepetidos(int *arr, int size){
 int vez = 1;
 for (int i = 0 ; i< size-1; i++) {
  if (arr[i]==arr[i+1]) vez++;
  else 
  {cout << arr[i] <<" se repite "<< vez << " veces " << "\n";
   vez =1; 
  }
 }
}

void borrarRepetidos(int *arr, int size){
  int *newArr = new int[30];
  int n =0;
  for (int i = 0 ; i< size-1; i++) {
   if (arr[i]!=arr[i+1]) newArr[n++] = arr[i]; 
  }
  listarArreglo(newArr, n);
}
