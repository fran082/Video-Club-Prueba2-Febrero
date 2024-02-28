#ifndef ARCHIVOVIDEO_H
#define ARCHIVOVIDEO_H
#include "video.h"

class ArchivoVideo
{   //MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EN EL 'CPP'
    public:

         ArchivoVideo();
         ArchivoVideo( bool backup);

         void mostrarRegistros();
         void agregarRegistro();
         Video leerPelicula(int pos);
         int modificarRegistro();
         int bajaLogicaRegistro();

         void buscarPeliculaPorNombre();
         void buscarPeliculaPorIDVideo();
         int buscarPeliculaPorIDVideoParametro(int idVideo);

         bool guardar(Video *vec, int cantidadRegistrosAEscribir);
         bool guardarBackup(Video *vec, int cantidadRegistrosAEscribir);
         int hacerCopiaDeSeguridad();
         int restaurarBackup();
         void leer(Video *vec, int cantidadRegistrosALeer);
         void leerBackup(Video *vec, int cantidadRegistrosALeer);
         void vaciar();
         void vaciarBackup();
         int cantidadRegistros();
         int cantidadRegistrosBackup();

         int buscarVideo(int d);
       //  int devuelveIDClienteACambioDeName(char name);
        std::string devuelveNombrePeliculaACambioDeID(int id);

         int devolverIDMaximo();
         int devolverIDMinimo();

         void algRecomendacion();
         void comparacionDeHashtag(Video obj);

         int alquilerPorID(int id);
         int devolucionPorID(int idVideo);

         int guardarCambioDeProp(Video &obj, int pos , int idVideo); //Al ser un objeto cambiamos lo que queremos

        Video devolverObjVideo(int idVideo);

        int devolverObjVideoConDiasDeDemora(int idVideo);
        float devolverImporteAcambioIDVideo(int idVideo);

       //  float devolverPropInteresCompuesto(int idVideo);
      //   float devolverPropIntereseComun(int idVideo);

        int devolverIDGenero(int idVideo);
        int devolverIDCategoria(int idVideo);

        private:
        char nombre[30];
        char bkp[30];//="BackupVideos.bkp";

};

#endif // ARCHIVOVIDEO_H
