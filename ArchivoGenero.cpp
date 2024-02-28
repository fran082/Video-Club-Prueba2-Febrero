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

#include "ArchivoGenero.h"
#include "Genero.h"


ArchivoGenero::ArchivoGenero(){
            strcpy(nombre , "Generos.dat" );
        }


void ArchivoGenero::agregarRegistro(){
    Genero obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO 'Generos.dat'"<<endl;
        return;
    }
    int total=0;
    total = cantidadRegistros();
    if(cantidadRegistros() == -1){
        obj.setIDGenero(1);
    }else{
    obj.setIDGenero(total + 1);
    }
   obj.cargar();
	fwrite(&obj, sizeof (obj), 1, pIng);
	fclose(pIng);
}


int ArchivoGenero::cantidadRegistros(){
    FILE *p;
    p=fopen(nombre,"rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Genero);
}



void ArchivoGenero::mostrarRegistros(){
    Genero obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO 'Generos.dat'. Por favor, restaure el backup."<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){

        obj.mostrar();
        cout<<endl;

        }
	}
	fclose(p);
}

 //const char* genero = obj.generoSeleccionado(id);
   //     if (genero != nullptr) {
      //  } else {
        //    return "GENERO NO valido, no ENCONTRADO"; // Devolver un mensaje de error apropiado


Genero ArchivoGenero::devolverUnObjetoGenero(int id){
     Genero obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
       // return "NO SE PUDO CREAR EL ARCHIVO";
cout<<"NO SE PUDO CREAR EL ARCHIVO";
system("pause");
    }

	while(fread(&obj, sizeof obj, 1, p)==1){

    ///Se puede verificar la siguiente funcion con
    ///el tope del for como "cantidad de registros". Tener en cuenta el rango!
    if(obj.getIDGenero() == id){
    fclose(p);
    return obj;

    }
	}
	obj.setIDGenero(-100);
    fclose(p);
    return obj; //Cambiar algo del obj para que se note la diferencia del error. Buscar una alternativa. Validaciones !
   }




int ArchivoGenero::buscarIDGeneroPorParametro(int idGenero){
  Genero obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Generos.dat'. Por favor, restaure el backup."<<endl;
        return -1;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDGenero()  == idGenero){

	fclose(p);
    return 1;
        }
	}
	fclose(p);
	return -2;
}


int ArchivoGenero::devolverIDMaximo(){
  Genero obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Generos.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int maximo=0;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDGenero() > maximo){
        maximo=  obj.getIDGenero();
            }
        }
	}
	fclose(p);
    return maximo;
}



int ArchivoGenero::devolverIDMinimo(){
  Genero obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Generos.dat'. Por favor, restaure el Backup."<<endl;
        return -1;
    }
int minimo=1500;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDGenero() < minimo){
        minimo=  obj.getIDGenero();
            }
        }
	}
	fclose(p);
    return minimo;
}






int ArchivoGenero::hacerCopiaDeSeguridad(){
    ArchivoGenero ArcGenero;
  int cantidad_registros = ArcGenero.cantidadRegistros();
  Genero *vec = new Genero[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup:'GenerosBackup.bkp'" << endl;
    return -1;
  }

  ArcGenero.leer(vec, cantidad_registros);
  ArcGenero.vaciarBackup();
  if ( ArcGenero.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'GenerosBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'GenerosBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoGenero::restaurarBackup(){
ArchivoGenero ArcGenero;
  int cantidad_registros = ArcGenero.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo Generos (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  Genero *vec = new Genero[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup:'GenerosBackup.bkp'" << endl;
    return -1;
  }

  for (int i = 0; i < cantidad_registros; ++i) {
    vec[i] = Genero();
}


  ArcGenero.leerBackup(vec, cantidad_registros);
  ArcGenero.vaciar();
  if (ArcGenero.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'GenerosBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'GenerosBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoGenero::guardar(Genero *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Genero), cantidadRegistrosAEscribir, p);
  fclose(p);
  if(cantidadRegistrosEscritos == cantidadRegistrosAEscribir){
    cout<<"Se escribieron todos los registros "<<endl<<endl<<endl;
    system("pause");
    system("cls");
  }
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoGenero::guardarBackup(Genero *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen( "GenerosBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Genero), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoGenero::leer(Genero *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("Generos.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Genero), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoGenero::leerBackup(Genero *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "GenerosBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Genero), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoGenero::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "GenerosBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'GenerosBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Genero);
}

void ArchivoGenero::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoGenero::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}





