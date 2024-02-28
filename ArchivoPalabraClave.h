#ifndef ARCHIVOPALABRACLAVE_H
#define ARCHIVOPALABRACLAVE_H

#include "PalabraClave.h"
#include "video.h"

class ArchivoPalabraClave
{   //MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EN EL 'CPP'
    public:
    ArchivoPalabraClave();

    void agregarRegistro();
    void mostrarRegistros();
    int mostrarListadoCompletoPeliculas();
    void buscarPorIDPelicula();
    PalabraClave leerPalabraClave(int pos);

         bool guardar(PalabraClave *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(PalabraClave *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(PalabraClave *vec, int cantidadRegistrosALeer);
         void leerBackup(PalabraClave *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

    int cantHashtag(int idVideoElegido);
  //  int comparacionDeHashtagPrueba2(Video obj);
    int comparacionDeHashtagPrueba4(Video obj);

     void ordenarDeMenorAMayorVector(int *vecID, int dimension);
     int listadoPeliculasSinHashtag();
     int listadoPeliculasSinHashtag2();

    private:
     char nombre[30];
     char bkp[30]="PalabrasClaveBackup.bkp";
};

#endif // ARCHIVOPALABRACLAVE_H
