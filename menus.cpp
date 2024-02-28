///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "ArchivoVideo.h"
#include "ArchivoAlquiler.h"
#include "ArchivoCliente.h"
#include "ArchivoEmpleado.h"
#include "ArchivoCategoria.h"
#include "ArchivoGenero.h"
#include "Alquiler.h"
#include "ArchivoPalabraClave.h"
#include "validaciones.h"


void menuAdministrarPeliculas() {
ArchivoVideo TodasLasPeliculas;

int i;

bool salir=true;
int opc;
int opc_Buscar_Film , opc_peliculas_backup;
system("cls");
while(salir==true){
        cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tMenu Administrar Peliculas:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Pelicula."<<endl;
cout<<"\t2. Buscar Pelicula."<<endl;
cout<<"\t3. Listar Peliculas."<<endl;
cout<<"\t4. Modificar Pelicula."<<endl;
cout<<"\t5. Eliminar Pelicula."<<endl;
cout<<"\t6. Backup."<<endl;
//cout<<"\t7. Restaurar Backup"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu administrar peliculas'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 6 );
system("cls");

        switch (opc) {
            case 1:
                for(i=0;i<1;i++){
                TodasLasPeliculas.agregarRegistro();
                }
             //   system("pause");
               // system("cls");
                break;

            case 2:
                cout<<endl;
                cout<<"Que tipo de busqueda quiere realizar? (1= ID-Pelicula | 2=Nombre de Pelicula)"<<endl;
                opc_Buscar_Film = getIntegerSinComa(1,2);
                switch(opc_Buscar_Film){
                 case 1:
                cout<<endl<<endl;
                TodasLasPeliculas.buscarPeliculaPorIDVideo();
                 system("pause");
                system("cls");
                 break;

                 case 2:
                     cout<<endl<<endl;
                TodasLasPeliculas.buscarPeliculaPorNombre();
                 system("pause");
                system("cls");
                  break;
                }
                break;

            case 3:
                cout<<endl<<endl;
                TodasLasPeliculas.mostrarRegistros();
                 system("pause");
                system("cls");
                break;

            case 4:
                TodasLasPeliculas.modificarRegistro();
                 system("pause");
                system("cls");
                break;

            case 5:
                TodasLasPeliculas.bajaLogicaRegistro();
                 system("pause");
                system("cls");
                break;

            case 6:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Peliculas:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Pelicula."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'sub-menu Backup peliculas'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_peliculas_backup = getIntegerSinComa(0,2);

            switch(opc_peliculas_backup){
            case 1:
                system("cls");
                TodasLasPeliculas.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( TodasLasPeliculas.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
                break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}


void menuAlquilarODevolver(){
ArchivoAlquiler TodasLosAlquileres;
Alquiler Venta;

int id_cliente, id_video, id_categoria, id_genero;
FechaHorario Inicio;
FechaHorario Final;
Horario Prueba;
int dia ,mes , anio;
int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };


int opc_alquileres_backup;
int i, k;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tMenu Alquilar o Devolver:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Alquiler."<<endl;
cout<<"\t2. Registrar Devolucion de Alquiler."<<endl;
//cout<<"\t2. Modificar pelicula."<<endl;
cout<<"\t3. Eliminar Alquiler."<<endl;
cout<<"\t4. Listar Alquileres Resumidos."<<endl; //Con menos datos
cout<<"\t5. Listar Alquileres con Mas Info."<<endl; //Con datos especificos
cout<<"\t6. Listar Alquileres por ID-Cliente."<<endl;
cout<<"\t7. Listar Alquileres por ID-Pelicula."<<endl;
cout<<"\t8. Listar Alquileres por ID-Categoria."<<endl;
cout<<"\t9. Listar Alquileres por ID-Genero."<<endl;
cout<<"\t10. Lista de Alquileres Pendientes."<<endl;
cout<<"\t11. Recaudacion."<<endl<<endl;

cout<<"\t12. Backup."<<endl;
cout<<"\t13. Ranking General."<<endl;
//Para el 4 hay otra opcion con datos menos especificos
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu Alquilar o Devolver'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa(0 , 13);
system("cls");

        switch (opc) {
            case 1:
               for(i=0;i<1;i++){
                TodasLosAlquileres.agregarRegistro();
                }
             //   system("pause");
             //   system("cls");
                break;

            case 2:
                for(k=0;k<1;k++){
                Venta.cargarDevolucion();
                }
             //   system("pause");
             //   system("cls");
                break;

            case 3:
                TodasLosAlquileres.bajaLogicaRegistro();
                system("pause");
                system("cls");
                break;

             case 4:
cout<<"  ID-ALQUILER";
cout<<"\tNomb. y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tRetraso";
cout<<"\t\tID-Pelicula"<<endl;
cout << "--------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarRegistrosMenosInfo();
                 system("pause");
                system("cls");
                break;

            case 5:
cout<<"ID-ALQUILER";
cout<<"\tNomb.y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tF-Alquiler";
cout<<"\tF-Devolucion";
cout<<"\tImporte";
cout<<"\t\t\tInt.";
cout<<"\t  Int.+1anio"<<endl;
cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarRegistrosMasInfo();
                 system("pause");
                system("cls");
                break;

                 case 6:
system("cls");
cout<<"Ingrese el ID-Cliente ";
cin>>id_cliente;
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setFechaHorario(Inicio);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setFechaHorario(Final);

system("cls");

cout<<"ID-ALQUILER";
cout<<"\tNomb.y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tF-Alquiler";
cout<<"\tF-Devolucion";
cout<<"\tImporte";
cout<<"\t\t\tInt.";
cout<<"\t  Int.+1anio"<<endl;
cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarAlquilerPorIDCliente(id_cliente, Inicio, Final);
                 system("pause");
                system("cls");
                break;

                 case 7:
system("cls");
cout<<"Ingrese el ID-Pelicula ";
cin>>id_video;
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setHorario( Prueba);
//Inicio.setFechaHorario(Inicio, Prueba);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setHorario( Prueba);
//Inicio.setFechaHorario(Final, Prueba);

system("cls");

cout<<"ID-ALQUILER";
cout<<"\tNomb.y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tF-Alquiler";
cout<<"\tF-Devolucion";
cout<<"\tImporte";
cout<<"\t\t\tInt.";
cout<<"\t  Int.+1anio"<<endl;
cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarAlquilerPorIDVideo(id_video, Inicio, Final);
                 system("pause");
                system("cls");
                break;

                 case 8:
system("cls");
cout<<"Ingrese el ID-Categoria ";
cin>>id_categoria;
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setHorario( Prueba);
//Inicio.setFechaHorario(Inicio, Prueba);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setHorario( Prueba);
//Inicio.setFechaHorario(Final, Prueba);

system("cls");

cout<<"ID-ALQUILER";
cout<<"\tNomb.y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tF-Alquiler";
cout<<"\tF-Devolucion";
cout<<"\tImporte";
cout<<"\t\t\tInt.";
cout<<"\t  Int.+1anio"<<endl;
cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarAlquilerPorCategoria(id_categoria, Inicio, Final);
                 system("pause");
                system("cls");
                break;

                 case 9:
system("cls");
cout<<"Ingrese el ID-Genero ";
cin>>id_genero;
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setHorario( Prueba);
//Inicio.setFechaHorario(Inicio, Prueba);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setHorario( Prueba);
//Inicio.setFechaHorario(Final, Prueba);

system("cls");

cout<<"ID-ALQUILER";
cout<<"\tNomb.y Apell.";
cout<<"\tID-Cliente";
cout<<"\tDevolucion";
cout<<"\tF-Alquiler";
cout<<"\tF-Devolucion";
cout<<"\tImporte";
cout<<"\t\t\tInt.";
cout<<"\t  Int.+1anio"<<endl;
cout << "-----------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                TodasLosAlquileres.mostrarAlquilerPorGenero(id_genero, Inicio, Final);
                 system("pause");
                system("cls");
                break;

             case 10:
                TodasLosAlquileres.listadoDeAlquileresPendientes();
                 system("pause");
                system("cls");
                break;

                  case 11:
system("cls");
cout<<"Ingrese Dos fechas para mostrar la recaudacion de alquileres en este periodo."<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setFechaHorario(Inicio);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setFechaHorario(Final);

system("cls");

                TodasLosAlquileres.mostrarRecaudacionDeAlquileres( Inicio, Final);
                 system("pause");
                system("cls");
                break;


                 case 13:
system("cls");
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setFechaHorario(Inicio);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setFechaHorario(Final);

system("cls");

                TodasLosAlquileres.RankingGenereral( Inicio, Final);
                 system("pause");
                system("cls");
                break;

                case 12:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Alquileres:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Alquileres."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Alquileres'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_alquileres_backup = getIntegerSinComa(0,2);

            switch(opc_alquileres_backup){
            case 1:
                system("cls");
                TodasLosAlquileres.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( TodasLosAlquileres.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
            break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}


void menuAdministrarEmpleados(){
ArchivoEmpleado NuevoEmpleado;


int opc_Buscar_Empleado, opc_empleados_backup;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tMenu Administrar Empleados:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Empleado."<<endl;
cout<<"\t2. Buscar Empleado."<<endl;
cout<<"\t3. Listar Empleados."<<endl;
cout<<"\t4. Modificar Empleado."<<endl;
cout<<"\t5. Eliminar Empleado."<<endl;
cout<<"\t6. Backup."<<endl;
//cout<<"\t7. Restaurar Backup"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu Administrar Empleados'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 6 );
system("cls");

        switch (opc) {
            case 1:
                NuevoEmpleado.agregarRegistro();
                system("pause");
                system("cls");
                break;

            case 2:
                cout<<"Que tipo de busqueda quiere realizar? (1= ID-Empleado | 2=Nombre de Empleado)"<<endl;
                opc_Buscar_Empleado = getIntegerSinComa(1,2);
                switch(opc_Buscar_Empleado){
                 case 1:
                NuevoEmpleado.buscarEmpleadoPorID();
                 system("pause");
                system("cls");
                 break;

                 case 2:
                NuevoEmpleado.buscarEmpleadoPorName();
                 system("pause");
                system("cls");
                  break;
                }
                break;


            case 3:
                NuevoEmpleado.mostrarRegistros();
                 cout<<endl<<endl;
                system("pause");
                system("cls");
                break;

            case 4:
                NuevoEmpleado.modificarRegistro();
                system("pause");
                system("cls");
                break;

            case 5:
                NuevoEmpleado.bajaLogicaRegistro();
                 system("pause");
                system("cls");
                break;

                case 6:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Empleados:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Empleados."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Empleados'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_empleados_backup = getIntegerSinComa(0,2);

            switch(opc_empleados_backup){
            case 1:
                system("cls");
                NuevoEmpleado.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( NuevoEmpleado.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
            break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }


}



void menuAdministrarClientes(){
ArchivoCliente NuevoCliente;

int valor_fui_baneado;
int opc_Buscar_Cliente, opc_cliente_backup;
int i;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tMenu Administrar Clientes:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Cliente."<<endl;
cout<<"\t2. Buscar Cliente."<<endl;
cout<<"\t3. Listar Clientes."<<endl;
cout<<"\t4. Modificar Cliente."<<endl;
cout<<"\t5. Banear/Desbanear Cliente."<<endl;
cout<<"\t6. Eliminar Cliente."<<endl;
cout<<"\t7. Backup."<<endl;
//cout<<"\t8. Restaurar Backup"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu Administrar Clientes'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 7 );
system("cls");

        switch (opc) {
            case 1:
                for(i=0;i<20;i++){
                NuevoCliente.agregarRegistro();
                }
               // system("pause");
               // system("cls");
                break;


            case 2:
                cout<<"Que tipo de busqueda quiere realizar? (1= ID-Cliente | 2=Nombre de Cliente)"<<endl;
                opc_Buscar_Cliente = getIntegerSinComa(1,2);
                switch(opc_Buscar_Cliente){
                 case 1:
                NuevoCliente.buscarClientePorID();
                 system("pause");
                system("cls");
                 break;

                 case 2:
                NuevoCliente.buscarClientePorName();
                 system("pause");
                system("cls");
                  break;
                }
                break;

            case 3:
                NuevoCliente.mostrarRegistros();
                cout<<endl<<endl;
                system("pause");
                system("cls");
                break;

            case 4:
                NuevoCliente.modificarRegistro();
                system("pause");
                system("cls");
                break;

            case 5:
 valor_fui_baneado =  NuevoCliente.banearCliente();
               if( valor_fui_baneado == 1 ){
                    cout<<endl;
                system("pause");
                system("cls");
    cout<<"El Cliente fue Baneado."<<endl<<endl;
                system("pause");
                system("cls");
               }
               if( valor_fui_baneado == 2 ){
                   cout<<endl;
                system("pause");
                system("cls");
               cout<<"El Cliente fue Desbaneado."<<endl<<endl;
                  system("pause");
                system("cls");
               }
               if(  valor_fui_baneado == -2 ){
                 system("pause");
                system("cls");
            cout<<"ID-Cliente inexistente"<<endl<<endl;
               system("pause");
                system("cls");
               }
                break;

            case 6:
                NuevoCliente.bajaLogicaRegistro();
                 system("pause");
                system("cls");
                break;

                 case 7:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Clientes:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Clientes."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Clientes'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_cliente_backup = getIntegerSinComa(0,2);

            switch(opc_cliente_backup){
            case 1:
                system("cls");
                NuevoCliente.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( NuevoCliente.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
        break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}


void menuAlgRecomendacion(){
ArchivoPalabraClave ArcWordClave;
ArchivoVideo ArcVideo;

int opc_palabraclave_backup;
int i;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"\tMenu algoritmo de recomendacion:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Agregar Palabra Clave a una Pelicula."<<endl;
cout<<"\t2. Buscar palabra clave por ID-Pelicula."<<endl;
cout<<"\t3. Listar todas las palabra/s Clave de las Peliculas."<<endl;
cout<<"\t4. Listar Peliculas que aun No Poseen una Asignacion de Palabra Clave."<<endl;
cout<<"\t5. Algoritmo de Recomendacion."<<endl;
cout<<"\t6. Backup."<<endl;
//cout<<"\t7. Restaurar Backup"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu algoritmo de recomendacion'." << endl<<endl;

     cout << "Elija una opcion: ";
         opc = getIntegerSinComa( 0 , 6 );
system("cls");

        switch (opc) {
            case 1:
                for(i=0;i<1 ;i++){
                ArcWordClave.agregarRegistro();
                }
             //   system("pause");
              //  system("cls");
                break;

            case 2:
              ArcWordClave.buscarPorIDPelicula();
                 system("pause");
                system("cls");
                break;

            case 3:
               // ArcWordClave.mostrarRegistros();
                ArcWordClave.mostrarListadoCompletoPeliculas();
cout<<"------------------------------------------------------------------------------------------------"<<endl;
                system("pause");
                system("cls");
                break;

            case 4:
   // cout<<"INGRESE EL ID DE LA PELICULA PARA RECOMENDARLE OTRA/S SIMILARES:   ";
              ArcWordClave.listadoPeliculasSinHashtag2();
                system("pause");
                system("cls");
                break;

            case 5:
                  system("cls");
    cout<<"INGRESE EL ID DE LA PELICULA PARA RECOMENDARLE OTRA/S SIMILARES:   ";
                ArcVideo.algRecomendacion();
                system("pause");
                system("cls");
                break;


                 case 6:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Palabras Clave:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Palabras Clave."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Palabras Clave'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_palabraclave_backup = getIntegerSinComa(0,2);

            switch(opc_palabraclave_backup){
            case 1:
                system("cls");
                ArcWordClave.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( ArcWordClave.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
        break;

            case 0:
                salir = false;
                break;

            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }


}




void menuAccesosDirectos(){
ArchivoVideo ArcVideo;
ArchivoAlquiler ArcAlquiler;

FechaHorario Inicio;
FechaHorario Final;
int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int anio, mes ,dia;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                    cout<<"\tMenu de Accesos Directos:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Listado de Alquileres Pendientes."<<endl;
cout<<"\t2. Algoritmo de Recomendacion de Peliculas."<<endl;
cout<<"\t3. Ranking de Peliculas mas Alquiladas."<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu accesos directos'." << endl<<endl;

     cout << "Elija una opcion: ";
         opc = getIntegerSinComa( 0 , 3 );
system("cls");

        switch (opc) {

            case 1:
                ArcAlquiler.listadoDeAlquileresPendientes();
                 system("pause");
                system("cls");
                break;

            case 2:
                  system("cls");
    cout<<"INGRESE EL ID DE LA PELICULA PARA RECOMENDARLE OTRA/S SIMILARES:   ";
                ArcVideo.algRecomendacion();
                system("pause");
                system("cls");
                break;

            case 3:
system("cls");
cout<<"Ingrese Dos fechas para su rango. Primero la de tiempos anteriores"<<endl;
cout<<"Fecha de Inicio."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Inicio.setFecha(dia, mes, anio);
Inicio.setFechaHorario(Inicio);
cout<<"Fecha de Final."<<endl;
cout<<"Anio:";
 anio = getIntegerSinComa(1900 , 2050) ;
cout<<"Mes:";
 mes = getIntegerSinComa(1 , 12) ;
if(esBisiesto(anio) && mes == 2){
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_biesto[ mes - 1 ]) ;
}else{
cout<<"Dia:";
 dia = getIntegerSinComa(1 , v_normal[ mes - 1 ]) ;
}
Final.setFecha(dia, mes, anio);
Final.setFechaHorario(Final);

system("cls");

                ArcAlquiler.RankingGenereral( Inicio, Final);
                 system("pause");
                system("cls");
                break;

            case 0:
                salir = false;
                break;

            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }


}





void sub_menuAdministrarGeneros(){
ArchivoGenero TodosLosGeneros;

int opc_generos_backup;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tSub-Menu Administrar Generos:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Genero."<<endl;
cout<<"\t2. Listar Generos."<<endl;
cout<<"\t3. Backup."<<endl;
//cout<<"\t2. Modificar pelicula."<<endl;
//cout<<"\t3. Eliminar pelicula."<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'Sub-Menu Administrar Generos'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 3 );
system("cls");

        switch (opc) {

            case 1:
                TodosLosGeneros.agregarRegistro();
                system("pause");
                system("cls");
                break;

            case 2:
            cout<<"\t\t ID-Genero \t Genero \t"<<endl;
            cout<<"------------------------------------------------------------------------------------------------"<<endl;
                TodosLosGeneros.mostrarRegistros();
                cout<<endl<<endl<<endl;
                system("pause");
                system("cls");
                break;

                 case 3:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Generos:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Generos."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Generos'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_generos_backup = getIntegerSinComa(0,2);

            switch(opc_generos_backup){
            case 1:
                system("cls");
                TodosLosGeneros.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( TodosLosGeneros.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
        break;
            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}






void sub_menuAdministrarCatYInt(){
ArchivoCategoria TodosLasCategoriasYIntereses;

int opc_catYint_backup;
bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tSub-Menu Administrar Categorias y Interes:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t1. Registrar Categorias y Interes."<<endl;
cout<<"\t2. Listar Categorias (Incluido el Interes)."<<endl;
cout<<"\t3. Modificar Categorias (Incluido los Intereses y los Importes)."<<endl;
cout<<"\t4. Backup."<<endl;
//cout<<"\t2. Modificar pelicula."<<endl;
//cout<<"\t3. Eliminar pelicula."<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'Sub-Menu Administrar Categorias y Interes'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 4 );
system("cls");

        switch (opc) {

            case 1:
                TodosLasCategoriasYIntereses.agregarRegistro();
                system("pause");
                system("cls");
                break;

            case 2:
                TodosLasCategoriasYIntereses.mostrarRegistros();
                cout<<endl<<endl<<endl;
                system("pause");
                system("cls");
                break;

            case 3:
                TodosLasCategoriasYIntereses.modificarRegistro();
                cout<<endl<<endl<<endl;
               // system("pause");
                system("cls");
                break;

                 case 4:
                system("cls");
                cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\tSub-Menu Administrar Backup Categorias:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t1. Realizar Backup Categorias."<<endl;
                cout<<"\t2. Restaurar Backup"<<endl;
                cout<<"--------------------------------------------------------------------------------"<<endl;
                cout<<"\t0. Salir del 'Sub-Menu Backup Categorias'." << endl<<endl;

                cout << "Elija una opcion: ";
                opc_catYint_backup = getIntegerSinComa(0,2);

            switch(opc_catYint_backup){
            case 1:
                system("cls");
                TodosLasCategoriasYIntereses.hacerCopiaDeSeguridad();
                 system("pause");
                system("cls");
                break;

            case 2:
               system("cls");
               if( TodosLasCategoriasYIntereses.restaurarBackup() == 1){
                system("pause");
                system("cls");
                break;
                }
            case 0:
              //  system("pause");
                system("cls");
                break;
            }
        break;
            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}







void menuAdministrarCatIntGen(){
ArchivoCategoria TodosLasCategoriasYIntereses;
ArchivoGenero TodosLosGeneros;


bool salir=true;
int opc;
system("cls");
while(salir==true){
    cout<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
                                cout<<"\tMenu categorias, intereses y genero de peliculas:"<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;

cout<<"\t1. Administrar Generos."<<endl;
cout<<"\t2. Administrar Categorias."<<endl;
/*
cout<<"\t1. Registrar Genero."<<endl;
cout<<"\t2. Registrar Categoria."<<endl;
cout<<"\t3. Listar Categorias (Incluido el Interes)."<<endl;
cout<<"\t4. Listar Generos."<<endl;
cout<<"\t5. Modificar Categorias (Incluido el Interes y Importe)."<<endl;
*/
//cout<<"\t2. Modificar pelicula."<<endl;
//cout<<"\t3. Eliminar pelicula."<<endl;
cout<<"--------------------------------------------------------------------------------"<<endl;
cout<<"\t0. Salir del 'menu categorias, intereses y genero de peliculas'." << endl<<endl;

     cout << "Elija una opcion: ";
        opc = getIntegerSinComa( 0 , 2 );
system("cls");

        switch (opc) {

            case 1:
                sub_menuAdministrarGeneros();
               // system("pause");
                system("cls");
                break;

            case 2:
                sub_menuAdministrarCatYInt();
               // system("pause");
                system("cls");
                break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

}

