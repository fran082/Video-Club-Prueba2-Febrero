#ifndef VIDEO_H
#define VIDEO_H

#include <clocale>
#include <vector>
#include <string>

#include "cargarCadena.h"
#include "Categoria.h"
#include "Interes.h"
#include "Genero.h"

class Video
{   //REVISAR. MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y EL 'CPP'
    //REVISAR SI SE USAN LAS ULTIMAS FUNCIONES
    public:
        Video();

       void cargar();
       void mostrar();

       void MenosStock(int menosuno);
       void MasStock(int masuno);

       int getStockLimite();
       void setStockLimite(int stockLimite);
        void setNombre(char nombre[50]);
        const char* getNombreChar();
       std::string getNombre() const;
        void setDescripcion(char descripcion[1500]);
        const char* getDescripcion();
        int getAnioEstreno();
        void setAnioEstreno(int anioEstreno);
        int getIDVideo();
        void setIDVideo(int id_video);
       void setStock(int stock);
       int getStock();
        void setDuracion(int duracion);
        int getDuracion();
        int getTipoDeCategoria();
        void setTipoDeCategoria(int tipodeCategoria);
        int getTipoDeInteres();
        void setTipoDeInteres(int tipo_de_interes);
        void setTipoDeGenero(int tipodeGenero);
        int getTipoDeGenero();
        void setEstado(bool estado);
        bool getEstado();


      int obtenerDiasDeRetraso()  ;

      int obtenerIDCategoria();
    float obtenerImporteCategoria();

     // float obtenerInteresCompuesto();
     // float obtenerInteresComun();

    private:
    int _stockLimite;
    char _nombre[50];
    char _descripcion[1500];
    int _anioEstreno;
    int _idVideo;
    int _stock;
    int _duracion;
    int _tipoDeCategoria; //Del 1 al 4 desde la más barata
    int _tipoDeInteres;
    int _tipoDeGenero; //Son 5
    bool _estado;


};

#endif // VIDEO_H
