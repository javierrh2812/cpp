/*Ejercicio 2 - Parcial 2018 - 1*/

#include <iostream>
#include <ctype.h>
#include <list>
using namespace std;

char pedirArtefacto(char *str){
    char c;
    while(c!='S'&&c!='N'){
        cout << "Tiene "<<str<< " (S:si; N:no): ";
        cin >> c;
        c = toupper(c);
    }
    return c;
}

class Cliente{
    float consumo;
    bool noTieneTodo;
};

int main(){
    list<Cliente> clientes;


    return 0;

}
