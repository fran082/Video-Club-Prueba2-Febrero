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
#include "ArchivoCategoria.h"
#include "cargarCadena.h"
#include "validaciones.h"

 ArchivoCategoria::ArchivoCategoria(){
            strcpy(nombre , "CategoriasYIntereses.dat");
        }

void ArchivoCategoria::agregarRegistro(){
    Categoria obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int total=0;
    total = cantidadRegistros();
    if(cantidadRegistros() == -1){
    obj.setIDCategoria(1);
    }else{
    obj.setIDCategoria(total + 1);
    }

    obj.cargar();
  //  obj.set_Id(ultimoPelicula()+1);
	fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
}


int ArchivoCategoria::cantidadRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Categoria);
}


 Categoria ArchivoCategoria::leerRegistro(int pos){
        Categoria reg;
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return reg;
        fseek(p, sizeof reg*pos,0);
        fread(&reg, sizeof reg,1, p);
        fclose(p);
        return reg;
    }

void ArchivoCategoria::mostrarRegistros(){
    Categoria obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true){
        obj.mostrar();
        cout<<"------------------------------------------------------------------------------------------------"<<endl;

        }
	}
	fclose(p);
}



int ArchivoCategoria::modificarRegistro(){
Categoria obj;
  ArchivoCategoria objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"No existe el archivo 'CategoriasYIntereses.dat'. Por favor, restaure el backup."<<endl;
        return -1;
    }
int id_Categoria;
int minIDCategoria, maxIDCategoria;
minIDCategoria = objAModificar.devolverIDMinimo();
maxIDCategoria = objAModificar.devolverIDMaximo();
cout<<"Por favor, ingrese el ID-Categoria que quiere Modificar: ";
id_Categoria = -102;
id_Categoria = getIntegerSinComa ( minIDCategoria , maxIDCategoria );
int c=-1;
//bool si = true;
//while(si == true){
cout<<endl;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDCATEG() == id_Categoria
           && obj.getEstado() == true){
           cout<<"La Categoria que desea Modificar es: '"<<obj.getNombreCategoria()<<"'."<<endl;
       break;
        }
	}
//}
cout<<endl;

   float PrecioPorCategoria;
  // int DiaDeDemoraPorCategoria;
   float InteresComun;
   float InteresCompuesto;

bool salir=true;
int opc;
while(salir==true){
cout<<"********************************************************************************************"<<endl;
                                cout<<"\tMODIFICACION DE CLIENTE:"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"1. Modificar Precio por Categoria."<<endl;
cout<<"2. Modificar Interes Comun."<<endl;
cout<<"3. Modificar Interes Compuesto."<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"\t0. Salir del programa"<<endl<<endl;

     cout << "Elija una opcion: ";
        cin >> opc;

        switch (opc) {


                case 1:
                system("cls");
cout<<"A continuacion va a ingresar el nuevo Importe de la Categoria: ";
PrecioPorCategoria = getFloat(100, 10000);
obj.setPrecioPorCategoria(PrecioPorCategoria);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Categoria);
fclose(p);

                break;

                case 2:
                system("cls");
cout << "Ingrese el nuevo Interes Comun para la categoria." << endl;
InteresComun = getFloat( 0.01 , 1 );

obj.setInteresComun(InteresComun);

guardarCambioDeProp(obj, c , id_Categoria);
fclose(p);

system("pause");
system("cls");

                break;

                case 3:
                system("cls");
cout << "Ingrese el nuevo Interes Compuesto para la categoria." << endl;
InteresCompuesto = getFloat( 0.01 , 1 );

obj.setInteresCompuesto(InteresCompuesto);

guardarCambioDeProp(obj, c , id_Categoria);
fclose(p);

system("pause");
system("cls");

    case 0:
                salir = false;
                break;
            default:
     cout << "Opcion no valida. Por favor, elija una opcion valida." << endl;
                break;
        }
    system("cls");
    }

return 1;

}



 int ArchivoCategoria::guardarCambioDeProp(Categoria &obj, int pos, int idCategoria){

     FILE *p = fopen ("CategoriasYIntereses.dat" , "rb+");
     if(p == NULL){
        cout<<"No existe el archivo 'CategoriasYIntereses.dat'";
        return -1;
     }

   if( fseek(p, sizeof(Categoria) * pos, 0) == 0){
 //   cout<<" VERDADERO 001 "<<endl<<endl<<endl;
 if(fwrite(&obj, sizeof (obj), 1, p) == 1){
// cout<<" VERDADERO 002 "<<endl<<endl<<endl;

        fclose(p);
        return obj.getIDCATEG();
        }
   }

//cout<<" VERDADERO 003 "<<endl<<endl<<endl;

    fclose(p);
    return -2;
 }


int ArchivoCategoria::buscarIDCategoriaPorParametro(int idCategoria){
 Categoria obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'CategoriasYIntereses.dat. Por favor, restaure el backup."<<endl;
        return -1;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDCATEG()  == idCategoria){

	fclose(p);
    return 1;
        }
	}
	fclose(p);
	return -2;
}


int ArchivoCategoria::devolverIDMaximo(){
Categoria obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'CategoriasYIntereses.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int maximo=0;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDCATEG() > maximo){
        maximo=  obj.getIDCATEG();
            }
        }
	}
	fclose(p);
    return maximo;
}



int ArchivoCategoria::devolverIDMinimo(){
  Categoria obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'CategoriasYIntereses.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int minimo=1500;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDCATEG() < minimo){
        minimo=  obj.getIDCATEG();
            }
        }
	}
	fclose(p);
    return minimo;
}

/*
   Categoria ArchivoCategoria::unNombreDeCategoria(int id){
    Categoria obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
cout<<"NO SE PUDO CREAR EL ARCHIVO";
system("pause");
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){

    if(obj.getIDCATEG() == id){
    fclose(p);
    return obj;

    }
	}
    fclose(p);
    return obj; //Cambiar algo del obj para que se note la diferencia del error.
   }
*/


    Categoria ArchivoCategoria::devolverObjCategoriaYInteres(int id){
    ArchivoCategoria ArcCategoria;
    Categoria obj;

      FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return obj;
    }

	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getIDCATEG() == id){
        fclose(p);
        return obj;
	}
	}
	fclose(p);
	obj.setInteresComun(-100);
	return obj;
}




int ArchivoCategoria::hacerCopiaDeSeguridad(){
    ArchivoCategoria ArcCategoriaYInteres;
  int cantidad_registros = cantidadRegistros();
  Categoria *vec = new Categoria[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup:'CatYIntBackup.bkp'" << endl;
    return -1;
  }

  ArcCategoriaYInteres.leer(vec, cantidad_registros);
  ArcCategoriaYInteres.vaciarBackup();
  if ( ArcCategoriaYInteres.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'CatYIntBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'CatYIntBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoCategoria::restaurarBackup(){
ArchivoCategoria ArcCategoriaYInteres;
  int cantidad_registros = ArcCategoriaYInteres.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo CategoriaYintreses (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  Categoria *vec = new Categoria[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup:'CatYIntBackup.bkp'" << endl;
    return -1;
  }
  ArcCategoriaYInteres.leerBackup(vec, cantidad_registros);
  ArcCategoriaYInteres.vaciar();
  if (ArcCategoriaYInteres.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'CatYIntBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'CatYIntBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoCategoria::guardar(Categoria *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Categoria), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoCategoria::guardarBackup(Categoria *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("CatYIntBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Categoria), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoCategoria::leer(Categoria *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("CategoriasYIntereses.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Categoria), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoCategoria::leerBackup(Categoria *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "CatYIntBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Categoria), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoCategoria::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "CatYIntBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'CatYIntBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Categoria);
}

void ArchivoCategoria::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoCategoria::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}




