#include "contacto.h"
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <string>

const char DIR_ARCHIVO[] = "datos.dat";
Contacto c;

ifstream entrada;
ofstream temporal;
ofstream salida;

void guardarContacto();
void borrarContacto(int);
Contacto obtenerContacto(int);
Contacto leerContacto();
void listarContactos();
bool existeContacto(int);
void actualizarContacto(int);

void menuIngresar();
void menuBuscar();
void menuListado();
void menuEliminar();
void menuActualizar();

int main(){
    char op;
    do{
        system("cls");
        cout<<"\t\t\t\t\tAGENDA"<<endl;
        cout<<"\t\t\tIngresar contacto............[1]"<<endl;
        cout<<"\t\t\tBuscar contacto..............[2]"<<endl;
        cout<<"\t\t\tVer listado..................[3]"<<endl;
        cout<<"\t\t\tEliminar contacto............[4]"<<endl;
        cout<<"\t\t\tActualizar contacto..........[5]"<<endl;
        cout<<"\t\t\tSALIR........................[6]"<<endl;
        cout<<"\t\t\tIngrese una opcion ->:";
        cin >> op;
        cin.ignore();
        system("cls");

        switch(op){
            case '1' :  cout<<"\t\t\t\tINGRESO DE NUEVO CONTACTO"<<endl;
                        guardarContacto();
                        cout<<"\t\t\tContacto agregado con exito"<<endl;
                        break;

            case '2' :  menuBuscar();
                        break;

            case '3' :  cout<<"\t\t\t\tLISTA DE CONTACTOS"<<endl;
                        listarContactos();
                        break;
            case '4' : menuEliminar();                          break;
            case '5' : menuActualizar();                        break;
            case '6' : cout << "Saliendo..." << endl;           break;
            default  : cout<<"\t\t\tOpcion incorrecta"<<endl;   break;
        }
        getch();
    }while(op!='6');
    return 0;

}

void guardarContacto(){
    salida.open(DIR_ARCHIVO,ios::binary|ios::app);
    c = leerContacto();
    if (salida.good()){
        salida.write((char*)&c, sizeof(Contacto));
        salida.close();
    }
    else{
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
    }
}

void listarContactos(){
    entrada.open(DIR_ARCHIVO,ios::binary|ios::app);
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){
            mostrar(c);
        }
    }
    else{
        cout<<"No se puede leer el archivo"<<endl;
    }
    entrada.close();
}

Contacto leerContacto(){
    cout<<"\t\t\tNOMBRE   : "; cin.getline(c.nombre, 20);
    cout<<"\t\t\tAPELLIDO : "; cin.getline(c.apellido,20);
    cout<<"\t\t\tEDAD     : "; cin>>c.edad; cin.ignore();
    cout<<"\t\t\tDNI      : "; cin>>c.dni; cin.ignore();
    cout<<"\t\t\tCORREO   : "; cin.getline(c.correo,30);

    return c;
}

Contacto obtenerContacto(int dni){
    entrada.open(DIR_ARCHIVO,ios::binary);
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){
            if(dni==c.dni){
                entrada.close();
                return c;
            }
        }
    }
    else{
        cout <<"No se puede leer el archivo"<< endl;
    }
}

bool existeContacto(int dni){
    entrada.open(DIR_ARCHIVO,ios::binary);
    if(entrada.good()){
            cout << "entro al ciclo" << endl;
            while(entrada.read((char*)&c,sizeof(Contacto))){
            if(c.dni==dni){
                entrada.close();
                return true;
            }
        }
        entrada.close();
        return false;
    }
    else{
        cout << "No se pudo leer entrada"<< endl;
        entrada.close();
        return false;
    }
}

void borrarContacto(int dni){
    entrada.open(DIR_ARCHIVO,ios::binary);
    temporal.open("temp.dat",ios::binary);
    Contacto c;
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){

            if(dni!=c.dni){
                temporal.write((char*)&c,sizeof(Contacto));
            }
        }
    }
    entrada.close();
    temporal.close();
    remove(DIR_ARCHIVO);
    rename("temp.dat",DIR_ARCHIVO);
}

void actualizarContacto(int dni){
    entrada.open(DIR_ARCHIVO,ios::binary);
    temporal.open("temp.dat",ios::binary);
    Contacto c;
    if(entrada.good()){
        while(entrada.read((char*)&c,sizeof(Contacto))){
            if(dni!=c.dni){
                temporal.write((char*)&c,sizeof(Contacto));
            }
            else{
                cout << "Ingrese nuevos datos: "<< endl;
                Contacto actualizado = leerContacto();
                temporal.write((char*)&actualizado,sizeof(Contacto));
            }
        }
    }
    entrada.close();
    temporal.close();
    remove(DIR_ARCHIVO);
    rename("temp.dat",DIR_ARCHIVO);
}

void menuBuscar(){
    cout<<"\t\t\t\tBUSCAR CONTACTO"<<endl;
    int dni;
    cout<<"\t\t\tIngrese DNI de Contacto: ";
    cin>> dni;
    if(existeContacto(dni)){
        cout << "Contacto encontrado: "<< endl;
        Contacto buscado = obtenerContacto(dni);
        mostrar(buscado);
    }
    else{
        cout<<"\t\t\tNO se encuentra ese contacto"<<endl;
    }
}

void menuEliminar(){
    cout<<"\t\t\t\tELIMINAR CONTACTO"<<endl;
    int dni;
    cout<<"\t\t\tIngrese los datos de eliminacion:"<<endl;
    cout<<"\t\t\tDNI  : ";
    cin >> dni;
    cin.ignore();
    if(existeContacto(dni)){
        Contacto contacto = obtenerContacto(dni);
        int op;
        cout<<"\t\t\tSeguro que desea eliminar el siguiente contacto?";
        mostrar(contacto);
        do{
            cout<<"\t\t\tSI[1]....NO[2]:";
            cin>>op;
            switch(op){
                case 1: borrarContacto(dni);
                        cout<<"\t\t\tContacto eliminado con exito"<<endl;
                        break;
                case 2: break;
                default: cout<<"\t\t\tOPCION INCORRECTA"<<endl;
            }
        }while(op!=1 && op!=2);
    }
    else{
        cout<<"\t\t\tNO EXISTE EL CONTACTO"<<endl;
    }
}

void menuActualizar(){
    cout<<"\t\t\t\tACTUALIZAR CONTACTO"<<endl;
    int dni;
    cout<<"\t\t\tIngrese los datos de modificacion:"<<endl;
    cout<<"\t\t\tDNI   : ";
    cin>>dni;
    cin.ignore();
    if(existeContacto(dni)){
        Contacto buscado = obtenerContacto(dni);
        cout<<"\t\t\tRegistro a modificar:"<<endl;
        mostrar(buscado);

        actualizarContacto(dni);
        cout<<"\t\t\tSE ACTUALIZO EL REGISTRO"<<endl;
    }
    else{
        cout<<"\t\t\tNO EXISTE EL CONTACTO"<<endl;
    }
}

