///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
#include <cstring>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "ArchivoEmpleado.h"
#include "Empleado.h"
#include "cargarCadena.h"
#include "validaciones.h"


 ArchivoEmpleado::ArchivoEmpleado(){
            strcpy(nombre , "Empleados.dat");
        }

void ArchivoEmpleado::agregarRegistro(){
    Empleado obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO 'Empleados.dat'"<<endl;
        return;
    }
    int total = 0;
    total = cantidadRegistros();
    if(total != -1){
    obj.setIDEmpleado(total + 1);
    }else{
    obj.setIDEmpleado( 1);
    }
    obj.cargar();
	fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
}

/*
int ArchivoEmpleado::cantidadRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Empleado);
}
*/



int ArchivoEmpleado::devolverIDMaximo(){
 Empleado obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Empleados.dat'"<<endl;
        return -1;
    }
int maximo=0;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDEmpleado() > maximo){
        maximo=  obj.getIDEmpleado();
            }
        }
	}
	fclose(p);
    return maximo;
}



int ArchivoEmpleado::devolverIDMinimo(){
  Empleado obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Empleados.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int minimo=1500;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDEmpleado() < minimo){
        minimo=  obj.getIDEmpleado();
            }
        }
	}
	fclose(p);
    return minimo;
}


void ArchivoEmpleado::mostrarRegistros(){
    Empleado obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true){
        obj.mostrar();
cout<<"-------------------------------------------------------------";        cout<<endl;

        }
	}
	fclose(p);
}


void ArchivoEmpleado::buscarEmpleadoPorID(){
  Empleado obj;
  ArchivoEmpleado ArcEmpleado;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Empleados.dat'. Por favor, restaure el Backup."<<endl;
        return;
    }
int maximo;
maximo = ArcEmpleado.devolverIDMaximo();
if(maximo == -1){ return;}
int id_empleado;
cout<<"Ingrese el ID-Empleado que desea buscar: ";
id_empleado = getIntegerSinComa( 0 , maximo);

 id_empleado = getIDEmpleado(id_empleado);

if( id_empleado == -1){
 fclose(p);
return;
}
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDEmpleado()  ==  id_empleado){
        cout<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        obj.mostrar();
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<endl<<endl;
        fclose(p);
        return ;
            }
        }
	fclose(p);

	}




void ArchivoEmpleado::buscarEmpleadoPorName(){
  Empleado obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

char name[50];
cout<<"Ingrese el nombre y apellido del empleado que desea buscar: ";
cargarCadena(name, 50);
char correcto;
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && (strcmp( obj.getApellidoYNombre() , name) == 0)){
        cout<<"El Empleado que esta buscando es '"<<obj.getApellidoYNombre()<<"' "<<endl;
        cout<<"y su ID-Empleado es: "<<obj.getIDEmpleado()<<"."<<endl;
        cout<<endl<<endl;
        cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

        cout<<endl<<endl;
        obj.mostrar();
        cout<<endl<<endl;
        return;

}
         break;
        }
	}
    system("cls");
	cout<<endl;
	cout<<"No existe un empleado con ese nombre y apellido. "<<endl<<endl;
	fclose(p);
    return;
}


int ArchivoEmpleado::bajaLogicaRegistro(){
  Empleado obj;
  ArchivoEmpleado objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
int id_Empleado;
cout<<"Para eliminar un Empleado ingrese el ID-Cliente: ";
cin>>id_Empleado;
int c=-1;
char correcto;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDEmpleado() == id_Empleado
           && obj.getEstado() == true){
           cout<<"El Empleado que desea eliminar es: '"<<obj.getApellidoYNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

        obj.setEstado(0);
        objAModificar.guardarCambioDeProp(obj, c , id_Empleado);
        fclose(p);
        return 1;
}
        }
	}
	fclose(p);
    return -2;
}



int ArchivoEmpleado::empleadoExiste(int id_empleado){
  Empleado obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Empleados.dat. Por favor, restaure el backup.'"<<endl;
        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDEmpleado()  ==  id_empleado){
        fclose(p);
        return 1;
        }
    }

	fclose(p);
    return -2;
}


int ArchivoEmpleado::modificarRegistro(){
  Empleado obj;
  ArchivoEmpleado objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
int id_Empleado;
cout<<"Por favor, ingrese el ID-Empleado que quiere Modificar: ";
cin>>id_Empleado;
int c=-1;
char correcto;

 id_Empleado = getIDEmpleado(id_Empleado);

if( id_Empleado == -1){
 fclose(p);
return -2;
}
//bool si = true;
//while(si == true){
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDEmpleado() == id_Empleado
           && obj.getEstado() == true){
           cout<<"El Empleado que desea Modificar es: '"<<obj.getApellidoYNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

       break;
}else{
cout<<"Por favor, ingrese de nuevo el ID-Empleado que quiere Modificar: ";
cin>>id_Empleado;
}
        }
	}


int v_normal[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
int v_biesto[12] = { 31 , 29 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

 int dni;
    char sexo;
    char apellidoYNombre[50];
    Fecha nacimiento;
    int dia, mes ,anio;
    char domicilio[50];
    long long telefono;
char email[50];

bool salir=true;
int opc;
while(salir==true){
cout<<"********************************************************************************************"<<endl;
                                cout<<"\tMODIFICACION DE EMPLEADO:"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"1. Modificar Nombre y Apellido del Cliente."<<endl;
cout<<"2. Modificar Sexo."<<endl;
cout<<"3. Modificar DNI."<<endl;
cout<<"4. Modificar Fecha de Nacimiento."<<endl;
cout<<"5. Modificar Domicilio."<<endl;
cout<<"6. Modificar Telefono."<<endl;
cout<<"7. Modificar e-mail. "<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"\t0. Salir del programa"<<endl<<endl;

     cout << "Elija una opcion: ";
        cin >> opc;

        switch (opc) {

            case 1:
                system("cls");
                cout<<"Corregir Nombre y Apellido: ";
cargarCadena(apellidoYNombre, 50);
obj.setApellidoYNombre(apellidoYNombre);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);
                break;
            case 2:
                system("cls");
cout<<"Sexo: ";
cin>>sexo;
while(sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f') {
    cin>>sexo;
}
obj.setSexo(sexo);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

                case 3:
                system("cls");
cout<<"DNI: ";
dni = getIntegerSinComa(1000000, 60000001);
obj.setDNI(dni);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

                case 4:
                system("cls");
cout << "Fecha de nacimiento ." << endl;
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
obj.setNacimiento(dia, mes ,anio);

system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

                case 5:
                system("cls");
cout << "Ingrese el nuevo Domicilio " << endl;
cargarCadena(domicilio , 50);
obj.setDomicilio(domicilio);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

                 case 6:
                system("cls");
   cout<<"Ingrese el nuevo telefono: ";
cin>>telefono;
 obj.setTelefono(telefono);
 ///Falta
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

                 case 7:
                system("cls");
 cout<<"Ingrese el nuevo e-mail: ";
cargarCadena(email, 50);
obj.setEmail( email);
 system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Empleado);
fclose(p);

                break;

            case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    }

return 1;
}




 int ArchivoEmpleado::guardarCambioDeProp(Empleado &obj, int pos, int idEmpleado){

     FILE *p = fopen ("Empleados.dat" , "rb+");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -1;
     }

   if( fseek(p, sizeof(Empleado) * pos, 0) == 0){
 //   cout<<" VERDADERO 001 "<<endl<<endl<<endl;
 if(fwrite(&obj, sizeof (obj), 1, p) == 1){
// cout<<" VERDADERO 002 "<<endl<<endl<<endl;

        fclose(p);
        return obj.getIDEmpleado();
        }
   }

//cout<<" VERDADERO 003 "<<endl<<endl<<endl;

    fclose(p);
    return -2;
 }



const char* ArchivoEmpleado::devuelveNameACambioDeIDEmpleado(int id){
    Empleado obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
      return "Error al abrir el archivo";
    }
    while(fread(&obj, sizeof(obj), 1, p)==1){
        if( obj.getIDEmpleado() == id){
            fclose(p);
            ///
            return obj.getApellidoYNombre();
        }

	}
	fclose(p);
	  return "Empleado invalido.";
}













int ArchivoEmpleado::hacerCopiaDeSeguridad(){
    ArchivoEmpleado ArcEmpleado;
  int cantidad_registros = ArcEmpleado.cantidadRegistros();
  Empleado *vec = new Empleado[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup 'EmpleadosBackup.bkp'." << endl;
    return -1;
  }

  ArcEmpleado.leer(vec, cantidad_registros);
  ArcEmpleado.vaciarBackup();
  if ( ArcEmpleado.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'EmpleadosBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'EmpleadosBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoEmpleado::restaurarBackup(){
ArchivoEmpleado ArcEmpleado;
  int cantidad_registros = ArcEmpleado.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo Empleado (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  Empleado *vec = new Empleado[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup 'EmpleadosBackup.bkp'." << endl;
    return -1;
  }
  ArcEmpleado.leerBackup(vec, cantidad_registros);
  ArcEmpleado.vaciar();
  if (ArcEmpleado.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'EmpleadosBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'EmpleadosBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoEmpleado::guardar(Empleado *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Empleado), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoEmpleado::guardarBackup(Empleado *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("EmpleadosBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Empleado), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoEmpleado::leer(Empleado *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("Empleados.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Empleado), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoEmpleado::leerBackup(Empleado *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "EmpleadosBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Empleado), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoEmpleado::cantidadRegistros(){
    FILE *p;
    p=fopen("Empleados.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Empleado);
}



int ArchivoEmpleado::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "EmpleadosBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'EmpleadosBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Empleado);
}

void ArchivoEmpleado::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoEmpleado::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}



