#include <iostream>

using namespace std;


int numeroAleatorio(int min, int max){
 return min+rand()%(max-min+1);
}

void llenarArreglo(int *arr, int size, int min, int max){
 for (int i=0; i<size; i++){
  *(arr+i)=numeroAleatorio(min, max);
 }
}

void listarArreglo(int *arr, int size){
 
 for (int i=0; i<size; i++){
 cout << "intArray["<<i<<"]"<<arr[i] << endl;
 }
}


int buscarMayor(int *arr, int size){
  int mayor=0; 
  for (int i=0; i<size; i++){
   if (*(arr+i) > mayor) mayor = *(arr+i);
  }
  return mayor;
}

int buscarMenor(int *arr, int size){
  int menor=999;
  for (int i=0; i<size; i++){
   if (*(arr+i) < menor) menor = *(arr+i);
  }
  return menor;
}

void xchg(int &val1, int &val2){
 int aux = val1;
 val1 = val2;
 val2 = aux;
}

void ordenarArregloAscendente(int *arr, int size){
 for (int i=0; i<size-1; i++){
   //cout << "\nIteration"<<i<<"\n";
   for (int j=0; j<size-i; j++){
    if(arr[j]>arr[j+1]) xchg(arr[j],arr[j+1]); 
   }
  //listarArreglo(arr,size);
 } 
}






/*FUNCIONES PARA LOS CARACTERES*/

bool esNumero(char c){
 if ((int)c>=48 && (int)c<=57) return true;
 return false;
}

bool esMinuscula(char c){
 if ((int)c>=65 && (int)c<=90) return true;
 return false;
}


bool esMayuscula(char c){
 if ((int)c>=97 && (int)c<=122) return true;
 return false;
}






















