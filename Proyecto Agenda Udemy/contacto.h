#ifndef CONTACTO_H
#define CONTACTO_H

#include <iostream>
#include <string>
using namespace std;

class Contacto{
    public:
    char nombre[20];
    char apellido[20];
    int edad;
    int dni;
    char correo[30];
};

void mostrar(Contacto c){
    cout<<endl;
    cout<<"\t\t\t NOMBRE   : "<<c.nombre<<endl;
    cout<<"\t\t\t APELLIDO : "<<c.apellido<<endl;
    cout<<"\t\t\t DNI      : "<<c.dni<<endl;
    cout<<"\t\t\t EDAD     : "<<c.edad<<endl;
    cout<<"\t\t\t CORREO   : "<<c.correo<<endl;
    cout<<endl;
}

#endif // CONTACTO_H
