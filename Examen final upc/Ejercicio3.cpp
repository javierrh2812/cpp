/*ejercicio 3 - parcial 2018 programacion i*/

#include <iostream>
using namespace std;

void dibujar (int);
int pedirNumero();

int main(){
    int n = pedirNumero();
    dibujar(n);
    return 0;
}
void imprimirEspacios(int q){
    for (int i = 1; i<=q; i++) cout << "  ";
}

void dibujar(int n){
    for(int i=0;i<=2*n-2;i++){
        if (i==0||i==2*n-2) {
            for (int j=1;j<=n;j++) cout << n << " ";
        }
        else{
            imprimirEspacios(i<=n-1?i:2*n-2-i);
            cout << n << " ";
            imprimirEspacios(n-2);
            cout << n << " ";
        }
        cout << endl;
    }
}


int pedirNumero(){
    int n = 0;
    while (n<1 || n>15){
        cout << "Ingrese el valor de n: ";
        cin >> n;
    }
    return n;
}
