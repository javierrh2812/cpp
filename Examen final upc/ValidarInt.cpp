#include <iostream>
using namespace std;

int takeInt();
int parseInt(string);
bool isValidInt(string);

int main(){

    int numero;
    numero = takeInt();

    cout << "El entero ingresado es: "<< numero << endl;

}

int takeInt(){
    string numberStr;
    bool isValid = false;

    while(!isValid){
        try{
            cout << "Ingrese un nro entero: ";
            getline(cin, numberStr);
            isValid =  isValidInt(numberStr);

            if (!isValid) throw numberStr;
        }
        catch(string e){
            cout << "El entero: "<<e<< " no es valido" << endl;
        }
    }
    return parseInt(numberStr);
}
int parseInt(string number){
    int i=0;
    int intNumber;
    if (!isdigit(number[0])) i=1;

    intNumber = (int)number[i]-48; // ver tabla ascii
    i++;
    for (i;i<number.length();i++){
        intNumber *= 10;
        intNumber += (int)number[i]-48;
    }
    if (number[0]=='-')intNumber*=-1;
    return intNumber;
}
bool isValidInt(string numero){

    int i=0;
    if (numero.length()==0) return 0; //no es cadena vacia

    if (numero[0]=='-'||numero[0]=='+'){ //validar si empieza con signo
        i=1;
        if (numero.length()==1) return 0; //validar si puso numeros luego del signo
    }
    for (i; i<numero.length();i++){
            if(!isdigit(numero[i]))return 0;
        }
    return 1;
    }
