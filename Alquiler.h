#ifndef ALQUILER_H
#define ALQUILER_H

#include "Fecha.h"
#include "FechaHorario.h"
#include "Horario.h"

class Alquiler
{//MISMA CANTIDAD DE FUNCIONES EN EL 'H' Y 'CPP'
    public:
        Alquiler();
        Alquiler(bool estado );
        Alquiler(Fecha fecha, Horario horario);

     // void  cargar();
      void  cargarAlquiler( int &idCliente , int &id_aux );
      void  cargarDevolucion();
      void  mostrarAlquilerMenosInfo();
      void  mostrarAlquilerMasInfo();
      void  mostrarObjetoCompleto();

     void setFechaDeAlquiler(FechaHorario momento_de_alquiler);
     void setFechaHorarioDevolucion(FechaHorario dia_devolucion);
     void setFechaDeAlquilerSoloConDia(int dia);
     FechaHorario getFechaHorarioAlquiler();
     FechaHorario getFechaHorarioDevolucion();
     void setIDAlquiler(int idAlquiler);
     int getIDAlquiler();
     void setIDEmpleado(int idEmpleado);
     int getIDEmpleado();
     void setInteresComun(float interes_comun);
     float getInteresComun();
     void setInteresCompuesto(float interes_compuesto);
     float getInteresCompuesto();
     void setImporte(float dinero);
     float getImporte();
     void setRetraso(bool retraso);
     bool getRetraso();
     void setDevolucion(bool devolucion);
     bool getDevolucion();
     void setApellidoYNombre(char apellidoYNombre[50]);
     const char* getApellidoYNombre();
     void setIDCliente(int id);
     int getIDCliente();
     void setIDVideoAlquilado(int id);
     int getIDVideoAlquilado();
     void setEstado(bool estado);
     bool getEstado();

    private:
    FechaHorario _fechaDeAlquiler;
    FechaHorario _fechaDeDevolucion;
    int _idAlquiler;
    int _idEmpleado;
    float _interes; /// El interes se calcula por categoria y el retraso (fecha de devolucion)
    float _interesCompuesto;
    float _importe;
    bool _retraso;
    bool _devolucion;
    char _nombreYapellido[50];
    int _idCliente;
    int _idVideoAlquilado; //Este dato se obtiene luego de filtrar la pelicula en la base del sistema
    bool _estado;
};

#endif // ALQUILER_H
