///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>
#include <limits>
#include <cctype>
#include <sstream>

using namespace std;

#include "ArchivoVideo.h"
#include "ArchivoCategoria.h"
#include "ArchivoGenero.h"
#include "ArchivoCliente.h"
#include "ArchivoEmpleado.h"


int getInteger(int minimo = INT_MIN, int maximo = INT_MAX){
	int input;

	while(true){
		cin >> input;
		if (cin.fail() || input < minimo || input > maximo){
			cin.clear();
			cin.ignore();
		}
		else{
			cin.ignore();
			return input;
		}
	}
}

int getIntegerSinComa(int minimo, int maximo) {
    int num;

    while (true) {
    //    std::cout << "Ingrese un numero entero entre " << minimo+1 << " y " << maximo << ": ";
        if (std::cin >> num) {
            if (num >= minimo && num <= maximo) {
                if (std::cin.peek() != '\n') {
                    std::cout << "Entrada no valida. Ingrese un numero entero." << std::endl;
                    std::cin.clear();  // Limpiar el estado de error
                    while (std::cin.get() != '\n');  // Descartar la entrada incorrecta
                } else {
                    return num;
                }
            } else {
                std::cout << "Entrada no valida. El numero debe estar entre " << minimo << " y " << maximo << "." << std::endl;
                std::cin.clear();  // Limpiar el estado de error
                while (std::cin.get() != '\n');  // Descartar la entrada incorrecta
            }
        } else {
            std::cout << "Entrada no valida. Ingrese un numero entero." << std::endl;
            std::cin.clear();  // Limpiar el estado de error
            while (std::cin.get() != '\n');  // Descartar la entrada incorrecta
        }
    }
}


/*
float getFloat( float minimo , float maximo = INT_MAX){
	float input;

std::cout << "Ingrese un valor con coma entre '" << minimo << "' y '" << maximo << "': ";
	while(true){
		cin >> input;
		if (cin.fail() || input < minimo || input > maximo){
			cin.clear();
			cin.ignore();
		}
		else{
			cin.ignore();
			return input;
		}
	}
}
*/


float getFloat(float minimo, float maximo = INT_MAX) {
    float input;
    std::string inputStr;

    while (true) {
        std::cout << "Ingrese un valor con coma entre '" << minimo << "' y '" << maximo << "': ";
        getline(std::cin, inputStr);

        // Verificar si la cadena contiene comas
        if (inputStr.find(',') != std::string::npos) {
            std::cout << "Entrada no válida. Utilice '.' en lugar de ',' para separar decimales." << std::endl;
            continue;
        }

        // Intentar convertir la cadena a float
        std::istringstream iss(inputStr);
        if (iss >> input && iss.eof() && input >= minimo && input <= maximo) {
            return input;
        }

        std::cout << "Entrada no válida. Ingrese un valor numérico válido." << std::endl;
    }
}


int getIDVideo(int idVideo){
ArchivoVideo ArcVideo;
int maxIDVideo;
 maxIDVideo = ArcVideo.devolverIDMaximo();
 if( maxIDVideo == -1 ){
     system("cls");
     system("pause");
    cout<<"ERROR AL ABRIR EL ARCHIVO 'Videos.dat'. Por favor, restaure el backup."<<endl<<endl<<endl;
 return -1;
 }
 if( ArcVideo.buscarPeliculaPorIDVideoParametro(idVideo) == 1 ){return idVideo;}
 cout<<"Ingrese un ID-Pelicula valido:";
  int funcion_video;
 funcion_video = ArcVideo.buscarPeliculaPorIDVideoParametro(idVideo);
    while( funcion_video == -2 ){
 idVideo = getIntegerSinComa( 0 , maxIDVideo );
  funcion_video = ArcVideo.buscarPeliculaPorIDVideoParametro(idVideo);
 }
 return idVideo;
}



int getIDCategoria(int idCategoria){
ArchivoCategoria ArcCatYInt;

int maxIDCategoria , minIDCategoria;
 maxIDCategoria = ArcCatYInt.devolverIDMaximo();
 minIDCategoria = ArcCatYInt.devolverIDMinimo();

 if( maxIDCategoria == -1 || minIDCategoria == -1 ){
     system("cls");
     system("pause");
    cout<<"ERROR AL ABRIR EL ARCHIVO 'CategoriasYIntereses.dat'. Por favor, restaure el backup."<<endl<<endl<<endl;
 return -1;
 }
 if( ArcCatYInt.buscarIDCategoriaPorParametro(idCategoria) == 1 ){return idCategoria;}
 cout<<"Ingrese un ID-Categoria valido:";
  int funcion_categoria;
 funcion_categoria = ArcCatYInt.buscarIDCategoriaPorParametro(idCategoria);
    while( funcion_categoria == -2 ){
 idCategoria = getIntegerSinComa( minIDCategoria , maxIDCategoria );
  funcion_categoria = ArcCatYInt.buscarIDCategoriaPorParametro(idCategoria);
 }
 return idCategoria;
}




int getIDGenero(int idGenero){
ArchivoGenero ArcGenero;
int maxIDGenero , minIDGenero;
 maxIDGenero = ArcGenero.devolverIDMaximo();
 minIDGenero = ArcGenero.devolverIDMinimo();

 if( maxIDGenero == -1  || minIDGenero == -1){
     system("cls");
     system("pause");
    cout<<"ERROR AL ABRIR EL ARCHIVO 'Generos.dat'. Por favor, restaure el backup."<<endl<<endl<<endl;
 return -1;
 }
  int funcion_genero;
 funcion_genero = ArcGenero.buscarIDGeneroPorParametro(idGenero);
 if( funcion_genero == 1 ){return idGenero;}
 cout<<"Ingrese un ID-Genero valido:";
    while( funcion_genero == -2 ){
 idGenero = getIntegerSinComa( minIDGenero , maxIDGenero );
  funcion_genero = ArcGenero.buscarIDGeneroPorParametro(idGenero);
 }
 return idGenero;
}


int getIDCliente(int idCliente){
    ArchivoCliente ArcCliente;
    int maxIDCliente , minIDCliente;
     maxIDCliente = ArcCliente.devolverIDMaximo();
     minIDCliente = ArcCliente.devolverIDMinimo();

 if( maxIDCliente == -1  || minIDCliente == -1){
     system("cls");
     system("pause");
    cout<<"ERROR AL ABRIR EL ARCHIVO 'Clientes.dat'. Por favor, restaure el backup."<<endl<<endl<<endl;
 return -1;
 }
  int funcion_cliente;
 funcion_cliente = ArcCliente.clienteExiste(idCliente);
 if( funcion_cliente == 1 ){return idCliente;}
 cout<<"Ingrese un ID-Cliente valido:";
    while( funcion_cliente == -2 ){
 idCliente = getIntegerSinComa( minIDCliente , maxIDCliente );
  funcion_cliente = ArcCliente.clienteExiste(idCliente);
 }
 return idCliente;
}


int getIDEmpleado(int idEmpleado){
    ArchivoEmpleado ArcEmpleado;
    int maxIDEmpleado , minIDEmpleado;
     maxIDEmpleado = ArcEmpleado.devolverIDMaximo();
     minIDEmpleado = ArcEmpleado.devolverIDMinimo();

 if( maxIDEmpleado == -1  || minIDEmpleado == -1){
     system("cls");
     system("pause");
    cout<<"ERROR AL ABRIR EL ARCHIVO 'Empleados.dat'. Por favor, restaure el backup."<<endl<<endl<<endl;
 return -1;
 }
  int funcion_empleado;
 funcion_empleado = ArcEmpleado.empleadoExiste(idEmpleado);
 if( funcion_empleado == 1 ){return idEmpleado;}
 cout<<"Ingrese un ID-Empleado valido:";
    while( funcion_empleado == -2 ){
 idEmpleado = getIntegerSinComa( minIDEmpleado , maxIDEmpleado );
  funcion_empleado = ArcEmpleado.empleadoExiste(idEmpleado);
 }
 return idEmpleado;
}



/*
std::string getNombrePropio() {
    std::string input;
    char ch;

    while (true) {
       // std::cout << "Ingrese un nombre ( hasta 50 caracteres): ";

        while (std::cin.get(ch) && ch != '\n') {
            if (std::isspace(ch) || std::isalpha(ch)) {
                input.push_back(ch);
            } else {
                std::cout << "Entrada no valida. Ingrese solo letras y espacios en blanco." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                input.clear();
                break;
            }
        }

        if (!input.empty() && input.length() <= 50) {
            return input;
        } else {
            std::cout << "Entrada no valida. El nombre debe tener hasta 50 caracteres." << std::endl;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            input.clear();
        }
    }
}

*/

/*
std::string getNombrePropio() {
    std::string input;
    char ch;

    while (true) {
        // std::cout << "Ingrese un nombre (hasta 50 caracteres): ";

        while (std::cin.get(ch) && ch != '\n') {
            if (std::isspace(ch) || std::isalpha(ch)) {
                input.push_back(ch);
            } else {
                std::cout << "Entrada no valida. Ingrese solo letras y espacios en blanco." << std::endl;
                std::cin.clear();  // Limpiar el estado de error
                while (std::cin.get() != '\n');  // Descartar la entrada incorrecta
                input.clear();
                break;
            }
        }

        if (!input.empty() && input.length() <= 50) {
            return input;
        } else {
            std::cout << "Entrada no valida. El nombre debe tener hasta 50 caracteres." << std::endl;
        }

        // Si la entrada no es válida, limpiar el flujo de entrada y descartar la entrada incorrecta
        std::cin.clear();
        while (std::cin.get() != '\n');
        input.clear();
    }
}
*/



std::string getNombrePropio() {
    std::string input;
    char ch;

    while (true) {
     //   std::cout << "Ingrese un nombre (hasta 50 caracteres): ";

        while (std::cin.get(ch) && ch != '\n') {
            if (std::isspace(ch) || std::isalpha(ch)) {
                input.push_back(ch);
            } else {
                std::cout << "Entrada no valida. Ingrese solo letras y espacios en blanco." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                input.clear();
                break;
            }
        }

        if (!input.empty() && input.length() <= 50) {
            return input;
        } else {
           // std::cout << "Entrada no valida. El nombre debe tener hasta 50 caracteres." << std::endl;
            input.clear();
        }
    }
}


std::string getDireccion() {
     std::string input;
    char ch;
    bool tieneNumero = false;

    while (true) {
   //     std::cout << "Ingrese texto (letras, espacios y al menos un numero): ";

        while (std::cin.get(ch) && ch != '\n') {
            if (std::isalnum(ch) || std::isspace(ch)) {
                input.push_back(ch);
                if (std::isdigit(ch)) {
                    tieneNumero = true;
                }
            } else {
            //   std::cout << "Dato invalido." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Descartar la entrada incorrecta
                input.clear();
                tieneNumero = false;
                break;
            }
        }

        if (!input.empty() && tieneNumero) {
            return input;
        } else {
         //   std::cout << "Dato Invalido." << std::endl;
            input.clear();
            tieneNumero = false;
        }
    std::cout << "Dato Invalido." << std::endl;
    }
}











  bool esBisiesto(int anio){
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
 }
