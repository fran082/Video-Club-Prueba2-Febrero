///Ejercicio:
///Autor:
///Fecha:
///Comentario:

# include<iostream>
#include <unordered_map>
#include <vector>
#include <iomanip>
# include<cstdlib>
//Las dos siguientes son para cadena de caracteres
# include<conio.h>
# include<string.h>

using namespace std;

#include "ArchivoPalabraClave.h"
#include "PalabraClave.h"
#include "ArchivoVideo.h"

ArchivoPalabraClave::ArchivoPalabraClave(){
            strcpy(nombre , "PalabrasClave.dat");
        }

void ArchivoPalabraClave::agregarRegistro(){
    PalabraClave obj;
    FILE *pIng;
    pIng=fopen(nombre, "ab");
    if(pIng==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

      int total = 0;
    total = cantidadRegistros();
    if(total != -1){
    obj.setIDPalabraClave(total + 1);
    }else{
    obj.setIDPalabraClave( 1);
    }

    obj.cargar();

	fwrite(&obj, sizeof(obj), 1, pIng);
	fclose(pIng);
}


void ArchivoPalabraClave::mostrarRegistros(){
    PalabraClave obj;
    ArchivoPalabraClave ArcPalabraClave;
    ArchivoVideo ArcVideo;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }
///NECESITO UN ALGORITMO QUE ORDENE EL ARCHIVO
    int idFalso;
    bool bandera=true;
    bool flag2=true;
	while(fread(&obj, sizeof(obj), 1, p)==1){
        if(obj.getEstado() == true){
    cout<<"El ID de la PalabraClave es : "<<obj.getIDPalabraClave()<<endl;
            if(bandera == true){
            idFalso = obj.getIDVideo();
            bandera= false;
            }
             if(flag2 == true){
                cout<<"La pelicula '"<<ArcVideo.devuelveNombrePeliculaACambioDeID(idFalso);
                cout<<"' con el ID: "<<idFalso<<endl;
                 flag2 = false;
                }
            if(idFalso != obj.getIDVideo() ){
                cout<<"La pelicula '"<<ArcVideo.devuelveNombrePeliculaACambioDeID(idFalso);

    cout<<"' con el ID: "<<idFalso<<endl;
    bandera= true;

            }else{
             idFalso = obj.getIDVideo();
            flag2= true;
            }
        obj.mostrar();

        }
	}
	fclose(p);
}


int ArchivoPalabraClave::mostrarListadoCompletoPeliculas(){
ArchivoPalabraClave ArcPalabraClave;
PalabraClave KeyWord;
ArchivoVideo ArcVideo;
Video Pelicula;

 int IDMAXIMO = ArcVideo.devolverIDMaximo();
int cant_max_KeyWord = ArcPalabraClave.cantidadRegistros();

 PalabraClave *vecPalabraClave;
vecPalabraClave = new PalabraClave[cant_max_KeyWord];

if(vecPalabraClave == NULL){return -1;}

char copia[50];
for(int i=0 ; i< cant_max_KeyWord ; i++){
    KeyWord = ArcPalabraClave.leerPalabraClave(i);
vecPalabraClave[i].setEstado(KeyWord.getEstado());
vecPalabraClave[i].setIDPalabraClave(KeyWord.getIDPalabraClave());
vecPalabraClave[i].setIDVideo(KeyWord.getIDVideo());
strcpy( copia , KeyWord.getPalabraClave());
vecPalabraClave[i].setPalabraClave( copia );

}
bool bandera = true;
for(int k=0 ; k<IDMAXIMO ; k++ ){
    Pelicula = ArcVideo.leerPelicula(k);
for(int v=0 ; v< cant_max_KeyWord ; v++){
    if(vecPalabraClave[v].getEstado() == true
       && vecPalabraClave[v].getIDVideo() == k+1){
    if(bandera == true){
        cout<<endl;
    cout<<"La Pelicula '"<<Pelicula.getNombreChar();
cout<<"' con ID: "<<vecPalabraClave[v].getIDVideo();
cout<<" posee la palabra clave:"<<endl;
 bandera = false;
    }
cout<<"\t#"<<vecPalabraClave[v].getPalabraClave()<<endl;
       }
        }
        bandera = true;
    }
delete[] vecPalabraClave;

return 1;
}

void ArchivoPalabraClave::buscarPorIDPelicula(){
 PalabraClave obj;
    ArchivoPalabraClave ArcPalabraClave;
    ArchivoVideo ArcVideo;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }

    int idVideoWordClave;
    cout<<"Ingrese un ID de pelicula para mostrar sus #hashtag. Y sus correspondientes id de cada palabra clave: ";
    cin>>idVideoWordClave;
    cout<<"El nombre de la pelicula es: '";
    cout<< ArcVideo.devuelveNombrePeliculaACambioDeID(idVideoWordClave);
    cout<<"' y su ID-Pelicula  es (";

    bool no_existio=false;
    bool bandera=1;

    while(fread(&obj, sizeof(obj), 1, p)==1){

    if(obj.getIDVideo() == idVideoWordClave
       && obj.getEstado() == true){
            no_existio = true;
        if(bandera==1){
           cout<<obj.getIDVideo()<<")."<<endl;
        bandera = 0;
        }
        cout<<setw(52)<<"#"<<obj.getPalabraClave()<<"\t\t ID-PalabraClave("<<obj.getIDPalabraClave()<<")"<<endl;
    }

    }

    if(no_existio == 0){
        system("cls");
         cout<<endl<<endl<<endl;
        cout<<"Usuario, la pelicula: '";
            cout<< ArcVideo.devuelveNombrePeliculaACambioDeID(idVideoWordClave);
cout<<"' no tiene ninguna palabra clave asignada."<<endl<<endl<<endl;
    }
    cout<<endl;
    fclose(p);

}


int ArchivoPalabraClave::cantHashtag(int idVideoElegido){
   PalabraClave obj;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return 0;
    }
   int c=0;
while(fread(&obj, sizeof(obj), 1, p)==1){
if(obj.getIDVideo() == idVideoElegido ) {
 c++;
}
	}
	fclose(p);
return c;
}

PalabraClave ArchivoPalabraClave::leerPalabraClave(int pos){
    PalabraClave obj;
    if(pos<0){
        obj.setIDVideo(-3);
        return obj;
    }
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setIDVideo(-2);
        return obj;
    }
    fseek(p, sizeof obj * pos, 0); ///0: desde el principio, 1: desde la posicion actual, 2: desde el eof
    int aux=fread(&obj, sizeof obj, 1, p);
    fclose(p);
    if(aux==0){
        obj.setIDVideo(-1);
    }
    return obj;
}


/*

int ArchivoPalabraClave::comparacionDeHashtagPrueba2(Video obj){
 ArchivoPalabraClave ArcWord;
 PalabraClave Word;
 ArchivoVideo ArcPelicula;


    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }

  std::vector<std::string> hashtag;
  std::vector<std::string> TodosLoshashtag;
  int *vIDVideos;

 int topeWord = ArcWord.cantidadRegistros();
 int nroPelicula = obj.getIDVideo();

 ///int hashtagSeleccionados = ArcWord.cantHashtag(nroPelicula);


  vIDVideos = new int[topeWord];

  if(vIDVideos == NULL){return -1;}


    int contador=0;

  for(int i=0;i<topeWord;i++){
  Word = ArcWord.leerPalabraClave(i);
  if(nroPelicula == Word.getIDVideo()){
     contador++;
    hashtag.push_back( Word.getPalabraClave() );
    cout<<"#"<<hashtag[contador-1]<<endl; //#1
  }
  vIDVideos[i] = Word.getIDVideo();
  TodosLoshashtag.push_back(  Word.getPalabraClave() );

  }

  int *vRepetidos;
int cont_solo_repetidos=0;
  vRepetidos = new int[cont_solo_repetidos];
  if(vRepetidos == NULL){return -1;}

  int cont=0;
  for(int g=0; g<contador;g++){
  for(int k=0;k<topeWord;k++){
    if(hashtag[g] == TodosLoshashtag[k]){
    cont_solo_repetidos++;

    vRepetidos[k] = vIDVideos[k];
    cout<<"ID: "<<vRepetidos[k]<<endl; //#2
    cont++;

    }

  }
  }

  cout<<endl<<endl<<endl;
   std::unordered_map<int, int> conteo;

    // Contar la frecuencia de cada número en el vector
    for (int i_1=0;i_1<cont;i_1++) {
        conteo[vRepetidos[i_1]]++;
    }

    // Marcar como cero los números que aparecen más de una vez
    for (int i_2=0; i_2<cont ;i_2++) {
        if (conteo[vRepetidos[i_2]] > 1) {
            vRepetidos[i_2] = 0;
        }
    }

     for (int i=0;i<cont;i++) {
      cout<<"El vRepetidos vale : "<<vRepetidos[i]<<endl;
        }



 // bool bandera=false;
  for(int h=0;h<cont;h++){
  for(int q=0 ;q<cont;q++){
   //     if(q== cont-1){
    //    bandera = true;}
    if( h != q &&
       vRepetidos[h] == vRepetidos[q] ){
    cout<<"El valor del indice 'h' es << "<<h<<endl;
    cout<<"El valor S/M vRepetidos: "<<vRepetidos[h]<<endl;
    vRepetidos[q] = 0;
    cout<<"El valor del indice 'q' es << "<<q<<endl;
  //  cout<<"El valor C/M vRepetidos: "<<vRepetidos[q]<<endl;

    }
  }
 //   cout<<"vRepetidos :  "<<vRepetidos[h]<<endl;
//  bandera= false;
  }



 // int idVolatil;
  bool verdadero=false;
  for(int x=0;x<cont;x++){
  for(int z=0;z<topeWord;z++){
    if(vRepetidos[x] == vIDVideos[z] ){
    cout<<"#"<<hashtag[x];
    cout<<"     ";
    verdadero= true;
    }

  }
  if(verdadero == true){
 // idVolatil = vRepetidos[x];
    ArcPelicula.buscarPeliculaPorIDVideoParametro(vRepetidos[x]);
  }
  verdadero=false;

  }

   delete vIDVideos;
   delete vRepetidos;

  fclose(p);
  return 1;
}

*/



int ArchivoPalabraClave::comparacionDeHashtagPrueba4(Video obj){
 ArchivoPalabraClave ArcWord;
 PalabraClave Word;
 ArchivoVideo ArcPelicula;


    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return -1;
    }

  std::vector<std::string> hashtag;
  std::vector<std::string> TodosLoshashtag;

  int *vIDVideos;

 int topeWord = ArcWord.cantidadRegistros();
 int nroPelicula = obj.getIDVideo();

/// int hashtagSeleccionados = ArcWord.cantHashtag(nroPelicula);


  vIDVideos = new int[topeWord];

  if(vIDVideos == NULL){return -2;}


    int contador=0;

  for(int i=0;i<topeWord;i++){
  Word = ArcWord.leerPalabraClave(i);
  if(nroPelicula == Word.getIDVideo()
     && Word.getEstado() == true){
     contador++;
    hashtag.push_back( Word.getPalabraClave() );
    cout<<"#"<<hashtag[contador-1]<<endl; //#1
  }
  vIDVideos[i] = Word.getIDVideo();
  TodosLoshashtag.push_back(  Word.getPalabraClave() );

  }


int cont_solo_repetidos=0;

  int cont=0;
  for(int g=0; g<contador;g++){
  for(int k=0;k<topeWord;k++){
    if(hashtag[g] == TodosLoshashtag[k]){
    cont_solo_repetidos++;
    }
  }
  }

    int *vRepetidos;
  vRepetidos = new int[cont_solo_repetidos];
  if(vRepetidos == NULL){return -3;}

  int cont_seguido=0;
   for(int g=0; g<contador;g++){
  for(int k=0;k<topeWord;k++){
    if(hashtag[g] == TodosLoshashtag[k]){

    vRepetidos[cont_seguido] = vIDVideos[k];
    cout<<"ID: "<<vRepetidos[cont_seguido]<<endl; //#2
    cont++;

    cont_seguido++;
    }else{
    vRepetidos[cont_seguido] = 0;
    }

  }
  }



  cout<<endl<<endl<<endl;
  int contFinal=0;
  bool limite=false;
    for(int ikea = 0;ikea<cont;ikea++){
  for(int iko = 0;iko<cont;iko++){
    if(vRepetidos[ikea] == vRepetidos[iko]){
    contFinal++;
    limite=true;
    }else{limite =false;}
    if(contFinal > 1 && limite == true){     // && iko > ikea
        vRepetidos[iko] = 0;
    }
  }
    cout<<"El vRepetidos es : "<<vRepetidos[ikea]<<endl;
  contFinal = 0;
    }


 int variable_aux;
  bool verdadero=false;
  for(int x=0;x<cont;x++){
  for(int z=0;z<topeWord;z++){
    if(vRepetidos[x] == vIDVideos[z] ){
    cout<<"#"<<TodosLoshashtag[z];
    cout<<"     ";
    verdadero= true;
    }

  }
  if(verdadero == true){
    if(vRepetidos[x] != 0){
    variable_aux = vRepetidos[x];
   // ArcPelicula.buscarPeliculaPorIDVideoParametro(variable_aux);
   cout<<endl<<endl;
  ArcPelicula.devolverObjVideo(variable_aux).mostrar();
  verdadero=false;
    }
  }

  }


   delete[] vIDVideos;
   delete[] vRepetidos;

  fclose(p);
  return 1;
}


/*
int ArchivoPalabraClave::listadoPeliculasSinHashtag(){
    PalabraClave obj;
    ArchivoVideo ArcVideo;
    FILE *p;
    p=fopen(nombre, "rb");
    if(p==NULL){
    cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
    return -1;
    }

  int total_Peliculas = ArcVideo.devolverIDMaximo();

 int *vDePalabrasClave;
 vDePalabrasClave = new int[total_Peliculas];

   if(vDePalabrasClave == NULL){return -2;}

	while(fread(&obj, sizeof(obj), 1, p)==1){
    vDePalabrasClave[obj.getIDVideo() -1] = 0;
        if(obj.getEstado() == true){
    vDePalabrasClave[obj.getIDVideo() -1] = obj.getIDVideo();
        }
	}

ordenarDeMenorAMayorVector(vDePalabrasClave, total_Peliculas);
bool *vSiSeEncuentra;
int falso_i=0;
bool bandera=false;
 vSiSeEncuentra = new bool[total_Peliculas];
	  for(int i=0;i<total_Peliculas;i++){
   // cout<<"El vDePalabrasClave vale: "<<vDePalabrasClave[i]<<endl;
    vSiSeEncuentra[i] = false;
           if(i == vDePalabrasClave[falso_i ]){
        cout<<"El valor de 'i' es: "<<i<<" El valor de vDePalabraClave es:: "<<vDePalabrasClave[i]<<endl;
            vSiSeEncuentra[ i ] = false;
            bandera =false;
            falso_i++;
       if(bandera==0){
         if(falso_i < i ) {
            falso_i = falso_i + ( i - falso_i );
                    }
                }
           }else{
        cout<<"El valor de 'i' es: "<<i<<" El valLlLlLor de vDePalabraClave es:: "<<vDePalabrasClave[i]<<endl;
            vSiSeEncuentra[falso_i ] = true;
            bandera= true;
           }
        cout<<"El valor BOOLEANO ES : "<<vSiSeEncuentra[i]<<" !!!!!!!!!!!"<<endl;
         }

bool no_existe=false;
     for(int i=0;i<total_Peliculas;i++){
           if(vSiSeEncuentra[i] == true){
    cout<<"La pelicula '"<<ArcVideo.devuelveNombrePeliculaACambioDeID(i)<<"' no tiene una palabra clave asignada."<<endl;
    no_existe = true;
           }
         }

if(no_existe==false){
    system("cls");
    cout<<"TODAS LAS PELICULAS TIENEN ASIGNADO PALABRA/S CLAVE"<<endl;
}
   delete[] vDePalabrasClave;
   delete[] vSiSeEncuentra;

   return 1;
}

*/

int ArchivoPalabraClave::listadoPeliculasSinHashtag2(){
ArchivoVideo ArcVideo;
Video Pelicula;
ArchivoPalabraClave ArcPalabraClave;
PalabraClave KeyWord;


int max_Pelicula_ID = ArcVideo.devolverIDMaximo();
int max_KeyWord_de_Pelicula = ArcPalabraClave.cantidadRegistros();

int *vecIDVIDEO;
bool *vecEstaVideo;

vecIDVIDEO = new int[max_Pelicula_ID];
if(vecIDVIDEO == NULL){
    cout<<"SYSTEM PAUSE -ERROR -2";
    system("pause");
        return -2;}

vecEstaVideo = new bool[max_Pelicula_ID];
if(vecEstaVideo == NULL){
    cout<<"SYSTEM PAUSE -ERROR -3";
    system("pause");
        return -3;}

    for(int i =0; i<max_Pelicula_ID ; i++){
     vecIDVIDEO[i] = 0;
     vecEstaVideo[i] = false;
    }

    for(int k=0 ; k<max_Pelicula_ID ; k++){
     Pelicula = ArcVideo.leerPelicula(k);
     for(int s=0; s<max_KeyWord_de_Pelicula ; s++){
     KeyWord = ArcPalabraClave.leerPalabraClave(s);
        if(KeyWord.getIDVideo() == Pelicula.getIDVideo()
           && KeyWord.getEstado() == true
           && Pelicula.getEstado() == true
           ){
    vecIDVIDEO[k] = Pelicula.getIDVideo();
    vecEstaVideo[k] = true;

           }
       }
    }
    ///
   for(int m=0 ; m<max_Pelicula_ID ; m++){
    Pelicula = ArcVideo.leerPelicula(m);
   cout<<"LA pelicula '"<<Pelicula.getNombre();
   cout<<"' y su id-Pelicula: "<<m+1<<" Si (1) - NO (0) -->   "<<vecEstaVideo[m]<<endl;
   }
    ///
    system("pause");
    system("cls");

    cout<<"LAS SIGUIENTES PELICULAS NO TIENEN ASIGNADAS NINGUNA PALABRA CLAVE (#)."<<endl<<endl;
    cout<<"\tID-Pelicula\t| Titulo de Pelicula"<<endl;
    cout<<"-----------------------------------------------------------------------"<<endl;

    for(int m=0 ; m<max_Pelicula_ID ; m++){
        if(vecEstaVideo[m] == false){
    Pelicula = ArcVideo.leerPelicula(m);
    cout<<"\t   "<<Pelicula.getIDVideo()<<"\t\t| ";
    cout<<Pelicula.getNombreChar()<<endl;
        }
    }
    cout<<endl<<endl;
delete[] vecIDVIDEO;
delete[] vecEstaVideo;

return 1;
cout<<"return 1";
system("pause");
}


 void ArchivoPalabraClave::ordenarDeMenorAMayorVector(int *vecID, int dimension) {
    for (int i = 0; i < dimension - 1; ++i) {
        for (int j = 0; j <dimension-i-1; ++j) {
            if (vecID[j] > vecID[j + 1]) {
                // Intercambiar elementos si están en el orden incorrecto
                std::swap(vecID[j], vecID[j + 1]);
            }
        }
    }
}














int ArchivoPalabraClave::hacerCopiaDeSeguridad(){
    ArchivoPalabraClave ArcPalClv;
  int cantidad_registros = ArcPalClv.cantidadRegistros();
  PalabraClave *vec = new PalabraClave[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al realizar backup 'PalabrasClaveBackup.bkp'." << endl;
    return -1;
  }

  ArcPalClv.leer(vec, cantidad_registros);
  ArcPalClv.vaciarBackup();
  if ( ArcPalClv.guardarBackup(vec, cantidad_registros) ){
        cout<<endl;
    cout << "Backup: 'PalabrasClaveBackup.bkp' realizado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al realizar backup: 'PalabrasClaveBackup.bkp'" << endl;
    return -2;
  }

  delete []vec;
}

int ArchivoPalabraClave::restaurarBackup(){
ArchivoPalabraClave ArcPalClv;
  int cantidad_registros = ArcPalClv.cantidadRegistrosBackup();
  system("pause");
  cout<<"La cantidad de registros del archivo PalabraClave (base) es de : "<<cantidad_registros<<endl;
  system("pause");
  PalabraClave *vec = new PalabraClave[cantidad_registros];

  if (vec == nullptr){
    cout << "Falla al restaurar backup 'PalabrasClaveBackup.bkp'." << endl;
    return -1;
  }
  ArcPalClv.leerBackup(vec, cantidad_registros);
  ArcPalClv.vaciar();
  if (ArcPalClv.guardar(vec, cantidad_registros)){
        cout<<endl;
    cout << "Backup: 'PalabrasClaveBackup.bkp' restaurado correctamente" << endl <<endl<<endl;
    return 1;
  }
  else{
    cout << "Falla al restaurar el backup: 'PalabrasClaveBackup.bkp'." << endl;
    return -2;
  }

  delete []vec;


}

bool ArchivoPalabraClave::guardar(PalabraClave *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen(nombre, "ab");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(PalabraClave), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}


bool ArchivoPalabraClave::guardarBackup(PalabraClave *vec, int cantidadRegistrosAEscribir){
  FILE *p = fopen("PalabrasClaveBackup.bkp" , "wb");
  if (p == NULL)
  {
    return false;
  }

  int cantidadRegistrosEscritos = fwrite(vec, sizeof(PalabraClave), cantidadRegistrosAEscribir, p);
  fclose(p);
  return cantidadRegistrosEscritos == cantidadRegistrosAEscribir;
}

void ArchivoPalabraClave::leer(PalabraClave *vec, int cantidadRegistrosALeer){
  FILE *p = fopen("PalabrasClave.dat" , "rb");
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(PalabraClave), cantidadRegistrosALeer, p);
  fclose(p);
}

void ArchivoPalabraClave::leerBackup(PalabraClave *vec, int cantidadRegistrosALeer){
  FILE *p = fopen( "PalabrasClaveBackup.bkp" , "rb" );
  if (p == NULL)
  {
    return ;
  }

  fread(vec, sizeof(PalabraClave), cantidadRegistrosALeer, p);
  fclose(p);
}


int ArchivoPalabraClave::cantidadRegistros(){
    FILE *p;
    p=fopen( "PalabrasClave.dat" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(PalabraClave);
}



int ArchivoPalabraClave::cantidadRegistrosBackup(){
    FILE *p;
    p=fopen( "PalabrasClaveBackup.bkp" , "rb" );
    if(p==NULL){
    cout<<"NO SE PUDO LEER EL ARCHIVO 'PalabrasClaveBackup.bkp'"<<endl;
    return -1;
    }
    fseek(p, 0, SEEK_END);
    int bytes = ftell(p);
    fclose(p);

    return bytes / sizeof(PalabraClave);
}

void ArchivoPalabraClave::vaciar(){
  FILE *p = fopen(nombre, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}

void ArchivoPalabraClave::vaciarBackup(){
  FILE *p = fopen(bkp, "wb");
  if (p == NULL)
  {
    return ;
  }
  fclose(p);
}







