#include <iostream>
#include <math.h>
using namespace std;

void pedirT1(int &t1){
    while(t1<1){
        cout << "Ingresar indice del primer termino: ";
        cin >> t1;
    }
}

void pedirT2(int &t1, int &t2){
    while(t2<=t1){
        cout << "Ingrear indice del ultimo termino: ";
        cin >> t2;
    }
}
double sumatoria(int &t1, int &t2){
    double suma=0;
    double num, den;
    int i=t1;
    cout << "Términos que suma: " ;
    for (i; i<=t2; i++){
        num = pow(-1,i)*(i+1);
        den = pow(i,3)+i+1;
        num>0? cout << " +": cout << " ";
        cout << num << "/"<<den;
        suma += num/den;
    }
    cout << endl;
    return suma;
}


int main(){
    int t1=0, t2=0;
    pedirT1(t1);
    pedirT2(t1, t2);
    cout << "La suma es: "<< sumatoria(t1,t2);

    return 0;
}

