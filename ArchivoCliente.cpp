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
#include "ArchivoCliente.h"
#include "Cliente.h"
#include "cargarCadena.h"
#include "validaciones.h"


 ArchivoCliente::ArchivoCliente(){
            strcpy(nombre , "Clientes.dat");
        }

void ArchivoCliente::agregarRegistro(){
    Cliente obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int total = 0;
    total = cantidadRegistros();
    if(total != -1){
    obj.setIDCliente(total + 1);
    }else{
    obj.setIDCliente( 1);
    }
    obj.cargar();

	fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
}

/*
int ArchivoCliente::cantidadRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Cliente);
}
*/

void ArchivoCliente::mostrarRegistros(){
    Cliente obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true){
        obj.mostrar();
cout<<"-------------------------------------------------------------";
        cout<<endl;

        }
	}
	fclose(p);
}



void ArchivoCliente::buscarClientePorID(){
  Cliente obj;
  ArchivoCliente ArcCliente;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    int maximo;
maximo = ArcCliente.devolverIDMaximo();
if(maximo == -1){ return;}
int id_cliente;
cout<<"Ingrese el ID-Cliente que desea buscar: ";
 id_cliente = getIntegerSinComa ( 0 , maximo);

 id_cliente = getIDCliente(id_cliente);

 if( id_cliente == -1){
     fclose(p);
    return;
 }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDCliente()  ==  id_cliente){

        cout<<endl<<endl;
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





int ArchivoCliente::clienteExiste(int id_cliente){
  Cliente obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Clientes.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDCliente()  ==  id_cliente
           && obj.getBaneado() == false){
        fclose(p);
        return 1;
        }
    }

	fclose(p);
    return -2;
}


int ArchivoCliente::devolverIDMaximo(){
 Cliente obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"No existe el archivo 'Clientes.dat'"<<endl;
        return -1;
    }
int maximo=0;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDCliente() > maximo){
        maximo=  obj.getIDCliente();
            }
        }
	}
	fclose(p);
    return maximo;
}



int ArchivoCliente::devolverIDMinimo(){
  Cliente obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Clientes.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int minimo=1500;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDCliente() < minimo){
        minimo=  obj.getIDCliente();
            }
        }
	}
	fclose(p);
    return minimo;
}



void ArchivoCliente::buscarClientePorName(){
  Cliente obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

char name[50];
cout<<"Ingrese el nombre y apellido del Cliente que desea buscar: ";
cargarCadena(name, 50);
char correcto;
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true
           && (strcmp( obj.getApellidoYNombre() , name) == 0)){
        cout<<"El Cliente que esta buscando es '"<<obj.getApellidoYNombre()<<"' "<<endl;
        cout<<"y su ID-Cliente es: "<<obj.getIDCliente()<<"."<<endl;
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
	cout<<"No existe un Cliente con ese nombre y apellido. "<<endl<<endl;
	fclose(p);
    return;
}

 int ArchivoCliente::banearCliente(){
 Cliente obj;
  ArchivoCliente objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO 'Clientes.dat'"<<endl;
        return -1;
    }
int id_Cliente;
bool opcion;
cout<<"Desea Banear o Desbanear un Cliente ( Banear = 1 | Desbanear = 0)"<<endl;
cin>>opcion;
while(opcion != 1 && opcion != 0){
    cin>>opcion;
}
cout<<"Ingrese el ID-Cliente: ";
cin>>id_Cliente;
int c=-1;
char correcto;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDCliente() == id_Cliente
           && obj.getEstado() == true){
    cout<<"El Cliente que quiere seleccionar es: '"<<obj.getApellidoYNombre()<<"'."<<endl;
    cout<<endl;
    cout<<"Ingrese S/N si es correcto "<<endl;
        cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){
    if(opcion == 1){
       obj.setBaneado(1);
        objAModificar.guardarCambioDeProp(obj, c , id_Cliente);
        fclose(p);
        return 1;
    }else{
       obj.setBaneado(0);
        objAModificar.guardarCambioDeProp(obj, c , id_Cliente);
        fclose(p);
        return 2;
    }

}
        }
	}
	fclose(p);
    return -2;
 }

int ArchivoCliente::bajaLogicaRegistro(){
  Cliente obj;
  ArchivoCliente objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
int id_Cliente;
cout<<"Para eliminar un Cliente ingrese el ID-Cliente: ";
cin>>id_Cliente;
int c=-1;
char correcto;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDCliente() == id_Cliente
           && obj.getEstado() == true){
           cout<<"El Cliente que desea eliminar es: '"<<obj.getApellidoYNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

        obj.setEstado(0);
        objAModificar.guardarCambioDeProp(obj, c , id_Cliente);
        fclose(p);
        return 1;
}
        }
	}
	fclose(p);
    return -2;
}




int ArchivoCliente::modificarRegistro(){
Cliente obj;
  ArchivoCliente objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
int id_Cliente;
cout<<"Por favor, ingrese el ID-Cliente que quiere Modificar: ";
cin>>id_Cliente;
int c=-1;
char correcto;
//bool si = true;
//while(si == true){
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDCliente() == id_Cliente
           && obj.getEstado() == true){
           cout<<"El Cliente que desea Modificar es: '"<<obj.getApellidoYNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

       break;
}else{
cout<<"Por favor, ingrese de nuevo el ID-Cliente que quiere Modificar: ";
cin>>id_Cliente;
}
        }
	}
//}
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
                                cout<<"\tMODIFICACION DE CLIENTE:"<<endl;
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

guardarCambioDeProp(obj, c , id_Cliente);
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

guardarCambioDeProp(obj, c , id_Cliente);
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

guardarCambioDeProp(obj, c , id_Cliente);
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

guardarCambioDeProp(obj, c , id_Cliente);
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

guardarCambioDeProp(obj, c , id_Cliente);
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

guardarCambioDeProp(obj, c , id_Cliente);
fclose(p);

                break;

                 case 7:
                system("cls");
 cout<<"Ingrese el nuevo e-mail: ";
cargarCadena(email, 50);
obj.setEmail( email);
 system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Cliente);
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




 int ArchivoCliente::guardarCambioDeProp(Cliente &obj, int pos, int idCliente){

     FILE *p = fopen ("Clientes.dat" , "rb+");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -1;
     }

   if( fseek(p, sizeof(Cliente) * pos, 0) == 0){
 //   cout<<" VERDADERO 001 "<<endl<<endl<<endl;
 if(fwrite(&obj, sizeof (obj), 1, p) == 1){
// cout<<" VERDADERO 002 "<<endl<<endl<<endl;

        fclose(p);
        return obj.getIDCliente();
        }
   }

//cout<<" VERDADERO 003 "<<endl<<endl<<endl;

    fclose(p);
    return -2;
 }


int ArchivoCliente::devuelveIDClienteACambioDeName(const char* name){
    Cliente obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -2;
    }
    while(fread(&obj, sizeof(obj), 1, p)==1){
        if( strcmp(name , obj.getApellidoYNombre()) == 0){
            fclose(p);
            ///
            return obj.getIDCliente();
        }

	}
	fclose(p);
	return -1;
}



const char* ArchivoCliente::devuelveNombreYApellidoAcambioDeID(int id){
    Cliente obj;

    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return "NO SE PUDO CREAR EL ARCHIVO";
    }
    while(fread(&obj, sizeof(obj), 1, p)==1){
        if( id == obj.getIDCliente() ){
            fclose(p);
            ///
            return obj.getApellidoYNombre();
        }

	}
	fclose(p);
	return "EL ID-Cliente no pertenece a ningun cliente";
}










int ArchivoCliente::hacerCopiaDeSeguridad(){
    ArchivoCliente ArcCliente;
  int cantidad_registros = cantidadRegistros();
  Cliente *vec = new Cliente[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup 'ClientesBackup.bkp'." << endl;
    return -1;
  }

  ArcCliente.leer(vec, cantidad_registros);
  ArcCliente.vaciarBackup();
  if ( ArcCliente.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'ClientesBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'ClientesBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoCliente::restaurarBackup(){
ArchivoCliente ArcCliente;
  int cantidad_registros = ArcCliente.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo Cliente (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  Cliente *vec = new Cliente[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup 'ClientesBackup.bkp'." << endl;
    return -1;
  }
  ArcCliente.leerBackup(vec, cantidad_registros);
  ArcCliente.vaciar();
  if (ArcCliente.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'ClientesBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'ClientesBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoCliente::guardar(Cliente *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Cliente), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoCliente::guardarBackup(Cliente *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("ClientesBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Cliente), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoCliente::leer(Cliente *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("Clientes.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Cliente), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoCliente::leerBackup(Cliente *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "ClientesBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Cliente), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoCliente::cantidadRegistros(){
    FILE *p;
    p=fopen( "Clientes.dat" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Cliente);
}



int ArchivoCliente::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "ClientesBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'ClientesBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Cliente);
}

void ArchivoCliente::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoCliente::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}






