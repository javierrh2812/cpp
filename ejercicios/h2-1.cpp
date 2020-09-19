#include "util.h"
#include <string>
/*
 * Ejercicio 1 
		   * 
Elabora una clase CONTRASEÑA con las siguientes condiciones:
-Atributos longitud y contraseña . Por defecto, longitud será de 8.
-Un constructor por defecto.
-Un constructor con la longitud que se pasará como parámetro. 
-Generará una contraseña aleatoria con esa longitud.
-Los métodos son:
 * función esSeguro(): devuelve un booleano si es fuerte o no, 
 para que sea fuerte debe tener mas de 2 mayúsculas, mas de 1 minúscula y mas de 5 números.
 * función generarContrasena():  genera la contrasena del objeto con la longitud que tenga.
 * Método get para contraseña y longitud.
 * Método set para longitud.

 El programa debe hacer lo siguiente
-Crea un arreglo dinámico de Contraseñas con un tamaño aleatorio entre 5 y 10
-En otro arreglo booleano guardar la información de si la contraseñas del arreglo deContraseñas es o no fuerte
-Muestra en pantalla  la contraseña y al costado mostrar V si es fuerte, de lo contrario F 
 * Ejemplo
 * contraseña1 : Fuerte: V o F (V de verdad o F de falso)
 * contraseña2 : Fuerte: V o F (V de verdad o F de falso)
 * contraseña1 : Fuerte: V o F (V de verdad o F de falso)
 * contraseña2 : Fuerte: V o F (V de verdad o F de falso)
 * */
class Password{
private:
		  int size;
		  char password[100]; 
public:
		  Password(){
					 size=8;
					 generarContrasena();
		  }
		  
		  Password(int size){
					 this->size = size; 
					 generarContrasena();
		  }
  
		  void generarContrasena(){
					 char c;
					 for (int i=0; i<size; i++){
								//BUCLE PARA VALIDAR QUE SEA DIGITO VALIDO
					 			do{
										  c = (char)numeroAleatorio(48,122);
								}while(!(esNumero(c) || esMinuscula(c) || esMayuscula(c)));
								
								password[i]= c;
								cout << "el digito c es: " << c<<" y p[i]: " << password[i]<<",";
					 } 

					 cout << "La contrasena generada es: " << password<< "\n"; 
		  }
		  bool esSeguro(){
					 int min=0, may=0, num=0;
					 for (int i=0; i<size; i++){
								if(esNumero(password[i]))num++;
								else if(esMinuscula(password[i]))min++;
								else may++;
					 }
					 if (may>2 && min >1 && num>5) return true;
					 return false;
		  }
		  void setLongitud(int size){
					 this->size=size; 
					 generarContrasena();
		  }
		  string getContrasena(){
					 return this->password;
		  }
		  int getLoongitud(){
					 return this->size;
		  }
};





int main(){
  //for (int i=33; i<=126; i++)
  // cout << "char "<<i<<":"<<(char)i << endl;
  //
		  int n = numeroAleatorio(5,10);
		  Password **contrasenas = new Password*[n];
		  bool *esSeguro = new bool[n];
		  
		  for (int i=0; i<n; i++){
					 contrasenas[i] = new Password();
		  }
}
