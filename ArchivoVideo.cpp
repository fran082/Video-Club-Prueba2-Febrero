///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>
#include <vector>
#include <string>

using namespace std;

#include "ArchivoVideo.h"
#include "ArchivoCategoria.h"
#include "video.h"
#include "ArchivoPalabraClave.h"
#include "validaciones.h"
#include "ArchivoGenero.h"

 ArchivoVideo::ArchivoVideo(){
            strcpy(nombre , "Videos.dat");
        }

 ArchivoVideo::ArchivoVideo(bool backup){
     if(backup == 1){
            strcpy(bkp , "VideosBackup.bkp");
        }
 }



void ArchivoVideo::agregarRegistro(){
    Video obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
    int total=0;

    total = cantidadRegistros();
    if(cantidadRegistros() == -1){
    obj.setIDVideo(1);
    }else{
    obj.setIDVideo(total + 1);
    }
    obj.cargar();

	fwrite(&obj, sizeof (obj), 1, pIng);

	fclose(pIng);
}

bool ArchivoVideo::guardar(Video *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Video), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoVideo::guardarBackup(Video *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("VideosBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(Video), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoVideo::leer(Video *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("Videos.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Video), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoVideo::leerBackup(Video *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("VideosBackup.bkp" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(Video), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoVideo::cantidadRegistros(){
    FILE *p;
    p=fopen("Videos.dat","rb");
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Video);
}



int ArchivoVideo::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "VideosBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'VideosBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(Video);
}

void ArchivoVideo::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoVideo::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoVideo::mostrarRegistros(){
    Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        obj.mostrar();

        }
	}
	fclose(p);
}

void ArchivoVideo::buscarPeliculaPorIDVideo(){
 Video obj;
 ArchivoVideo ArcVideo;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Videos.dat'. Por favor, restaure el Backup."<<endl;
        return;
    }
int maxIDVideo, minIDVideo;
 maxIDVideo = ArcVideo.devolverIDMaximo();
 minIDVideo = ArcVideo.devolverIDMinimo();
int idVideo;
int valor_funcion_video;
cout<<"Ingrese el ID-Video de la pelicula que quiere mostrar"<<endl;
 idVideo = getIntegerSinComa( minIDVideo , maxIDVideo );

  valor_funcion_video = ArcVideo.buscarPeliculaPorIDVideoParametro(idVideo) ;
   while( valor_funcion_video != 1 && valor_funcion_video != -1){
    cout<<"ID-Pelicula inexistente"<<endl;
     idVideo =  getIntegerSinComa( minIDVideo , maxIDVideo );
    valor_funcion_video = ArcVideo.buscarPeliculaPorIDVideoParametro(idVideo) ;
   }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDVideo()  == idVideo){
        cout<<endl<<endl;
cout<<"------------------------------------------------------------------------------------------"<<endl;
        obj.mostrar();
	fclose(p);
    return;
        }
	}
	cout<<"El ID no corresponde a ninguna pelicula del inventario."<<endl;
	fclose(p);
}



int ArchivoVideo::buscarPeliculaPorIDVideoParametro(int idVideo){
 Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }

	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true
           && obj.getIDVideo()  == idVideo){
       // cout<<endl;
//cout<<"......................................................................................................."<<endl;
       // obj.mostrar();

	fclose(p);
    return 1;
        }
	}
	//cout<<"El ID no corresponde a ninguna pelicula del inventario."<<endl;
	fclose(p);
	return -2;
}


void ArchivoVideo::buscarPeliculaPorNombre(){
 Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
cout<<"Cual es el nombre de la pelicula?"<<endl;
char name_pelicula[50];
cargarCadena(name_pelicula, 50);
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true
           && (strcmp(obj.getNombreChar(), name_pelicula) == 0)){
    cout<<endl<<endl;
cout<<"------------------------------------------------------------------------------------------"<<endl;
    obj.mostrar();
	fclose(p);
	return;

        }
	}
	cout<<endl;
	cout<<"Ese titulo no corresponde a ninguna pelicula del inventario. Revise que este bien escrito el nombre de la pelicula ingresado."<<endl;
cout<<endl<<endl;
	fclose(p);
}


int ArchivoVideo::bajaLogicaRegistro(){
  Video obj;
  ArchivoVideo objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }
int id_Pelicula;
cout<<"Por favor, ingrese el ID-Pelicula que quiere eliminar: ";
cin>>id_Pelicula;
int c=-1;
char correcto;
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDVideo() == id_Pelicula
           && obj.getEstado() == true){
           cout<<"La pelicula que quiere eliminar es: '"<<obj.getNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

        obj.setEstado(0);
        objAModificar.guardarCambioDeProp(obj, c , id_Pelicula);
        return 1;
}
        }
	}
	fclose(p);
    return -2;
}


int ArchivoVideo::hacerCopiaDeSeguridad(){
    ArchivoVideo ArcVideo;
  int cantidad_registros = cantidadRegistros();
  Video *vec = new Video[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup: 'VideosBackup.bkp'." << endl;
    return -1;
  }

  ArcVideo.leer(vec, cantidad_registros);
  ArcVideo.vaciarBackup();
  if ( ArcVideo.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'VideosBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'VideosBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoVideo::restaurarBackup(){
ArchivoVideo ArcVideo;
  int cantidad_registros = ArcVideo.cantidadRegistrosBackup();
  Video *vec = new Video[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup: 'VideosBackup.bkp'." << endl;
    return -1;
  }
  ArcVideo.leerBackup(vec, cantidad_registros);
  ArcVideo.vaciar();
  if (ArcVideo.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'VideosBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar backup: 'VideosBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;


}


int ArchivoVideo::modificarRegistro(){
Video obj;
  ArchivoVideo objAModificar;
    FILE *p;
    p=fopen(nombre, "rb+");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Videos.dat'. Por favor, restaure el backup."<<endl;
        return -1;
    }
int id_Pelicula;
cout<<"Por favor, ingrese el ID-Pelicula que quiere Modificar: ";
cin>>id_Pelicula;
int c=-1;
char correcto;
//bool si = true;
//while(si == true){
	while(fread(&obj, sizeof obj, 1, p)==1){
            c++;
        if(obj.getIDVideo() == id_Pelicula
           && obj.getEstado() == true){
           cout<<"La pelicula que quiere Modificar es: '"<<obj.getNombre()<<"'."<<endl;
           cout<<"Ingrese S/N si es correcto "<<endl;
             cin>>correcto;
while(correcto != 's' && correcto != 'S' && correcto != 'n' && correcto != 'N' ){
           cin>>correcto;
           }
if(correcto == 's' || correcto == 'S'  ){

       break;
}else{
cout<<"Por favor, ingrese de nuevo el ID-Pelicula que quiere Modificar: ";
cin>>id_Pelicula;
}
        }
	}
//}


int stock_viejo , stockLimite_viejo;
int nuevo_stock;
int stockLimite;
    char nombre[50];
    char descripcion[1500];
   // int anioEstreno;
   // int duracion;
    int tipoDeCategoria; //Del 1 al 4 desde la m�s barata
   // int tipoDeInteres; //Puede ser interes comun(4) o interes compuesto(4)
int tipoDeGenero;

bool salir=true;
int opc;
while(salir==true){
cout<<"********************************************************************************************"<<endl;
                                cout<<"\tMODIFICACION DE PELICULA:"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"1. Modificar el titulo de la pelicula"<<endl;
cout<<"2. Modificar Descripcion."<<endl;
cout<<"3. Modificar Anio de Estreno."<<endl;
cout<<"4. Modificar la cantidad de peliculas que existen en el inventario."<<endl;
cout<<"5. Modificar la duracion de la pelicula en minutos."<<endl;
cout<<"6. Modificar el tipo de Categoria ('Viejo= 1' ,'Normal= 2' ,'Clasico= 3' ,'Estreno= 4')"<<endl;
cout<<"7. Modificar el tipo de Genero ('Accion= 1' ,'Romance= 2' ,'Comedia= 3' ,'Drama= 4' ,'Aventura= 5')"<<endl;
cout<<"********************************************************************************************"<<endl;
cout<<"\t0. Salir del programa"<<endl<<endl;

     cout << "Elija una opcion: ";
        cin >> opc;

        switch (opc) {

            case 1:
                system("cls");
                cout<<"Titulo del Film: ";
cargarCadena(nombre, 50);
obj.setNombre(nombre);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);
                break;
            case 2:
                system("cls");
cout<<"Descripcion: ";
cargarCadena(descripcion, 1500);
obj.setDescripcion(descripcion);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);

                break;

                case 3:
                system("cls");
cout<<"Anio de Estreno: ";
obj.setAnioEstreno(getIntegerSinComa(1900, 2050));
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);

                break;

                case 4:
                system("cls");
cout << "Ingrese la nueva cantidad maxima en inventario para la pelicula. Esta cantidad representa el limite o maximo de existencias para la pelicula." << endl;
stockLimite = getIntegerSinComa(1,10);

stockLimite_viejo = obj.getStockLimite();
stock_viejo = obj.getStock();
if(stockLimite_viejo == stock_viejo){
nuevo_stock = stockLimite - stock_viejo;
nuevo_stock = nuevo_stock + stock_viejo;
}
if(stock_viejo < stockLimite_viejo ){
nuevo_stock = stockLimite - stockLimite_viejo;
nuevo_stock = nuevo_stock + stock_viejo;
}
if(stockLimite < stockLimite_viejo ){
nuevo_stock = stock_viejo  -  (stockLimite_viejo - stockLimite) ;

}

obj.setStockLimite( stockLimite);
obj.setStock(nuevo_stock);
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);

                break;

                case 5:
                system("cls");
cout << "Ingrese la duracion de la pelicula en minutos" << endl;
obj.setDuracion(getIntegerSinComa(29 , 241));
cout<<endl;
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);

                break;

                 case 6:
                system("cls");
   cout<<"Ingrese el nuevo tipo de Categoria que desea que tenga la pelicula ('Viejo= 1' ,'Normal= 2' ,'Clasico= 3' ,'Estreno= 4'): ";
cin>>tipoDeCategoria;
tipoDeCategoria = getIDCategoria(tipoDeCategoria);
if( tipoDeCategoria == -1){
    return -2;
}else{
 obj.setTipoDeCategoria( tipoDeCategoria );
 obj.setTipoDeInteres( tipoDeCategoria );
    }
cout<<"Tenga en cuenta que modificar la categoria no afectara el inventario. Para realizar cambios en el stock, debe llevar a cabo la modificacion de manera individual a traves de la opcion 'MENU --> MODIFICACION DE PELICULA'."<<endl;
 ///Falta
system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
fclose(p);
                break;

                 case 7:
                system("cls");
 cout<<"Ingrese el nuevo Genero para la pelicula ('Accion= 1' ,'Romance= 2' ,'Comedia= 3' ,'Drama= 4' ,'Aventura= 5') : ";
cin>>tipoDeGenero;
tipoDeGenero = getIDGenero( tipoDeGenero );
if( tipoDeGenero == -1){
    return -3;
}else{
 obj.setTipoDeGenero( tipoDeGenero );
    }
 system("pause");
system("cls");

guardarCambioDeProp(obj, c , id_Pelicula);
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


return -2;
}




int ArchivoVideo::buscarVideo(int d){
    Video obj;
    int pos=0;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getIDVideo() == d
            && obj.getEstado()  == true  ){
            fclose(p);
            ///
            return pos;
        }
        pos++;
	}
	fclose(p);
	return -1;
}


///FALTA MODIFICAR EL STOCK DEL ARCHIVO PARA REGISTRAR LA CANTIDAD DE PELICULAS DISPONIBLES (CUANDO SE ALQUILA UNA)
int ArchivoVideo::alquilerPorID(int id){
    Video obj;
    int pos=-1;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
            cout<<"ERROR AL LEER EL ARCHIVO"<<endl;
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){
            pos++;
        if(obj.getIDVideo() == id
            && obj.getEstado()  == true  ){
            ///
            if(obj.getStock()>0){
        //Cuidado con las reglas de signos . Menos por menos es más (termina devolviendo en vez de recibir una pelicula)
            cout<<endl;
            cout<<"El stock de la Pelicula '"<<obj.getNombre()<<"'  , con ID: "<<obj.getIDVideo()<<" . Tiene un stock de '"<<obj.getStock()<<"/"<<obj.getStockLimite()<<"'."<<endl<<endl;
                obj.MenosStock(1);
                cout<<"EL STOCK POR EL ALQUILER FUE MODIFICADO A : ";
                cout<<obj.getStock()<<"/"<<obj.getStockLimite()<<"!!!"<<endl<<endl<<endl;
            guardarCambioDeProp(obj , pos, id);
            fclose(p);
            return obj.getIDVideo();
            } else{
             if(obj.getStock() == 0){
  	cout<<endl;
 cout<<"Para la pelicula '"<<obj.getNombre()<<"' el STOCK se agoto. Su ID correspondiente es: "<<obj.getIDVideo()<<" . Tiene un stock de '"<<obj.getStock()<<"/"<<obj.getStockLimite()<<"'."<<endl<<endl;
          fclose(p);
          return -3;
            }
        }
	}
}
	cout<<" 'ID' de pelicula invalido. No existe."<<endl;

	fclose(p);
	return -1;
}

int ArchivoVideo::devolucionPorID(int idVideo){
    Video obj;
    int pos=-1;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){
            pos++;
        if(obj.getIDVideo() == idVideo
            && obj.getEstado()  == true
           && obj.getStockLimite() != obj.getStock() ){

            ///

        //Cuidado con las reglas de signos . Menos por menos es más (termina devolviendo en vez de recibir una pelicula)
                obj.MasStock(1);
          if(  guardarCambioDeProp(obj , pos , idVideo) == idVideo){
cout<<"El stock de la Pelicula '"<<obj.getNombre()<<"'  , con ID: "<<obj.getIDVideo()<<" . Tiene un stock de '"<<obj.getStock()<<"/"<<obj.getStockLimite()<<"'."<<endl<<endl;

       //     cout<<"El stock de la película se ha actualizado por la devolución."<<endl;
         fclose(p);
         return 1;
          }

        }
	}
	cout<<" 'ID' de pelicula invalido. No existe."<<endl;

	fclose(p);
	return -1;
}


std::string ArchivoVideo::devuelveNombrePeliculaACambioDeID(int id){
    Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return "Error al abrir el archivo";
    }
    while(fread(&obj, sizeof obj, 1, p)==1){

        if(obj.getIDVideo() == id
            && obj.getEstado()  == true  ){
            fclose(p);
            ///
            return obj.getNombre();

        }
	}

	fclose(p);
 return "'ID' no encontrado.";
}



Video ArchivoVideo::leerPelicula(int pos){
    Video obj;
    if(pos<0){
        obj.setTipoDeGenero(-3);
        return obj;
    }
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
       obj.setTipoDeGenero(-2);
        return obj;
    }
    fseek(p, sizeof obj * pos, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, p);
    fclose(p);
    if(aux==0){
        obj.setTipoDeGenero(-1);
    }
    return obj;
}


void ArchivoVideo::algRecomendacion(){
ArchivoPalabraClave ArcWord;
ArchivoVideo ArcPelicula;

    Video obj;
    int ID;
    int minIDVideo, maxIDVideo;
    minIDVideo = ArcPelicula.devolverIDMinimo();
    maxIDVideo = ArcPelicula.devolverIDMaximo();

    ID = getIntegerSinComa( minIDVideo , maxIDVideo );
    int pos=buscarVideo(ID);
    obj=leerPelicula(pos);
cout<<"La pos del archivo es :"<<pos+1<<endl;
//system("pause");
    cout<<endl;
    cout<<ArcPelicula.devuelveNombrePeliculaACambioDeID(ID);
    cout<<endl<<endl;
    ///Comparaci�n de hashtag
    if(pos != -1 && pos != -2 ){
   // comparacionDeHashtag(obj);
    cout<<ArcWord.comparacionDeHashtagPrueba4(obj)<<endl;
    }else{
    cout<<endl<<"El ID ingresado no es valido.";
    cout<<endl<<"Vuelvalo a intentar por favor."<<endl<<endl;
    }

}

void ArchivoVideo::comparacionDeHashtag(Video obj){
Video Pelicula;
ArchivoVideo DataPelicula;
ArchivoPalabraClave wordClave;
PalabraClave UnaPalabra;



 int id = obj.getIDVideo();
    std::vector<std::string> hashtag;
    int n = wordClave.cantHashtag(id);

    hashtag.resize(n);

    int cantReg_WordClave = wordClave.cantidadRegistros();

    bool unavez=true;
    int indice=0;
    for(int w=0; w<cantReg_WordClave ; w++){
         UnaPalabra =   wordClave.leerPalabraClave(w);
        if(id == UnaPalabra.getIDVideo()){
      if(unavez == true){
            cout<<"La pelicula es '"<<DataPelicula.devuelveNombrePeliculaACambioDeID(id)<<"'"<<endl;
     unavez = false;
      }
            hashtag[indice] = UnaPalabra.getPalabraClave();
            cout<<"y su palabra clave numero("<<indice+1<<") es: #"<<hashtag[indice]<<endl;
        indice++;
        }
    }
    system("pause");
    system("cls");

    int *vRepeticion;
    vRepeticion = new int[cantReg_WordClave];
     if(vRepeticion == NULL){
    return ;
     }

     for(int poner0 = 0 ; poner0 <cantReg_WordClave;poner0++){
        vRepeticion[poner0] = 0;
     }



     int idVideo;
    for(int x=0;x<2;x++){
  for(int d=0; d< n ; d++){
    for(int i=0; i<cantReg_WordClave ; i++){
   UnaPalabra = wordClave.leerPalabraClave(i);
     if(hashtag[d] == UnaPalabra.getPalabraClave()){

            vRepeticion[i] = UnaPalabra.getIDVideo();
      if(x==1){
        if(id != idVideo){
         if(vRepeticion[i] != 0){
       idVideo = vRepeticion[i];
        cout<<"La pelicula '"<<DataPelicula.devuelveNombrePeliculaACambioDeID(idVideo);
        cout<<"' ."<<endl;
        cout<<"#"<<UnaPalabra.getPalabraClave();
        cout<<endl;
        }
      }
     }


     }

    }
  }
}

cout<<endl;
delete vRepeticion;
}



 int ArchivoVideo::guardarCambioDeProp(Video &obj, int pos, int idVideo){

     FILE *p = fopen ("Videos.dat" , "rb+");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -1;
     }

   if( fseek(p, sizeof(Video) * pos, 0) == 0){
 //   cout<<" VERDADERO 001 "<<endl<<endl<<endl;
 if(fwrite(&obj, sizeof (obj), 1, p) == 1){
// cout<<" VERDADERO 002 "<<endl<<endl<<endl;

            cout<<"EL STOCK TENDRIA QUE HABERSE MODIFICADO CON EXITO :";
    cout<<obj.getStock()<<"/"<<obj.getStockLimite()<<"  !!! ??? !!!"<<endl<<endl<<endl;
        fclose(p);
        return obj.getIDVideo();
        }
   }

//cout<<" VERDADERO 003 "<<endl<<endl<<endl;


    fclose(p);
    return -2;
 }


 /*
 float ArchivoVideo::devolverPropInteresCompuesto(int idVideo){
    Video obj;
    ArchivoCategoria ArcCateg;
     FILE *p = fopen ("Videos.dat" , "rb");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -3.14;

     }

     int aux;

     while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getIDVideo() == idVideo
            && obj.getEstado()  == true  ){
        aux = obj.getTipoDeCategoria();
        fclose(p);
return ArcCateg.devolverObjCategoriaYInteres(aux).getInteresCompuesto();


        }
     }
   //  obj.getInteresesGeneral().setIDInteresGeneral(-10);
   //  obj.getInteresesGeneral().setInteresCompuesto(-10.10);
   //  obj.getInteresesGeneral().setInteresComun(-10.10);
      fclose(p);
      return -3.41;
    }


float ArchivoVideo::devolverPropIntereseComun(int idVideo){
    Video obj;
    ArchivoCategoria ArcCateg;
     FILE *p = fopen ("Videos.dat" , "rb");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
        return -3.14;
     }

     int aux;
//ArcCateg.devolverObjCategoriaYInteres(aux).getIDCategoria()

     while(fread(&obj, sizeof obj, 1, p)==1){
       if(obj.getIDVideo() == idVideo
           && obj.getEstado()  == true  ){
            aux = obj.getTipoDeCategoria();

        fclose(p);
            return ArcCateg.devolverObjCategoriaYInteres(aux).getInteresComun();


        }
     }
      fclose(p);
            return -3.41;
     }
*/


int ArchivoVideo::devolverIDCategoria(int idVideo){

            return devolverObjVideo(idVideo).getTipoDeCategoria();
     }


int ArchivoVideo::devolverIDGenero(int idVideo){

    return devolverObjVideo(idVideo).getTipoDeGenero();

     }




float ArchivoVideo::devolverImporteAcambioIDVideo(int idVideo){
    Video obj;
     FILE *p = fopen ("Videos.dat" , "rb");
     if(p == NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO";
    return -3.14;
     }

     while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getIDVideo() == idVideo
            && obj.getEstado()  == true){
        fclose(p);
            return obj.obtenerImporteCategoria();

            }
        }
   //  obj.getInteresesGeneral().setIDInteresGeneral(-10);
    // obj.getInteresesGeneral().setInteresCompuesto(-10.10);
    // obj.getInteresesGeneral().setInteresComun(-10.10);
      fclose(p);
    return -3.41;
     }

Video ArchivoVideo::devolverObjVideo(int idVideo){
    Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return obj;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){

        if(obj.getIDVideo() == idVideo
            && obj.getEstado()  == true  ){
            fclose(p);
            ///
            return obj;

        }
	}
	fclose(p);
	return obj;
}


int ArchivoVideo::devolverObjVideoConDiasDeDemora(int idVideo){
    Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        return -1;
    }
    while(fread(&obj, sizeof obj, 1, p)==1){

        if(obj.getIDVideo() == idVideo
            && obj.getEstado()  == true  ){
            fclose(p);
            ///
            return obj.obtenerDiasDeRetraso();

        }
	}
	fclose(p);
	cout<<"No se encontro el 'ID'"<<endl;
	return -2;
}



int ArchivoVideo::devolverIDMaximo(){
 Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Videos.dat'."<<endl;
        return -1;
    }
int maximo=0;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(obj.getIDVideo() > maximo){
        maximo=  obj.getIDVideo();
            }
        }
	}
	fclose(p);
    return maximo;
}




int ArchivoVideo::devolverIDMinimo(){
 Video obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO 'Videos.dat'."<<endl;
        return -1;
    }
int minimo;
bool bandera=1;
	while(fread(&obj, sizeof obj, 1, p)==1){
        if(obj.getEstado() == true){
        if(bandera == 1){ minimo = obj.getIDVideo();
        bandera =0;}
        if(obj.getIDVideo() < minimo){
        minimo=  obj.getIDVideo();
            }
        }
	}
	fclose(p);
    return minimo;
}

