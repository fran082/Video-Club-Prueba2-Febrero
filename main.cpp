#include <iostream>
#include <clocale>

using namespace std;
#include "video.h"
#include "ArchivoVideo.h"
#include "ArchivoAlquiler.h"
#include "ArchivoCliente.h"
#include "ArchivoEmpleado.h"
#include "ArchivoCategoria.h"
#include "ArchivoGenero.h"
#include "Alquiler.h"
#include "Cliente.h"
#include "menus.h"
#include "validaciones.h"

int main(){

bool salir=true;
int opc;
while(salir==true){
        system("cls");
cout<<endl;
cout<<"********************************************************************************************"<<endl;
                                cout<<"\tMENU PRINCIPAL:"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"\t1. Alquilar o Devolver pelicula."<<endl;
cout<<"\t2. Accesos Directos."<<endl;
cout<<"\t3. Administrar Clientes."<<endl;
cout<<"\t4. Administrar Empleados."<<endl;
cout<<"\t5. Administrar Peliculas."<<endl;
cout<<"\t6. Administrar Categorias, Intereses y Genero de Peliculas."<<endl;
cout<<"\t7. Algoritmo de Recomendacion de Peliculas."<<endl;
//cout<<"\t7. Informes"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"\t0. Salir del programa."<<endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa(0 , 7);

        switch (opc) {

            case 1:
                system("cls");
                menuAlquilarODevolver();
                break;

            case 2:
                menuAccesosDirectos();
                break;

            case 3:
                menuAdministrarClientes();
                break;

            case 4:
                menuAdministrarEmpleados();
                 break;

            case 5:
                menuAdministrarPeliculas();
               break;

            case 6:
                menuAdministrarCatIntGen();
                break;

            case 7:
                menuAlgRecomendacion();
                break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }
    system("cls");
cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout << "\t\t\t...Saliendo del programa..." << endl;
    cout<<endl<<endl<<endl<<endl<<endl<<endl;

system("pause");
return 0 ;
}



