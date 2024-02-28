#ifndef FECHAHORARIO_H
#define FECHAHORARIO_H

#include "Fecha.h"
#include "Horario.h"

class FechaHorario
{   //MISMA CANTIDAD DE FUNCIONES EN 'H' Y 'CPP'
     public:
        Fecha getFecha();
        Horario getHorario();

        FechaHorario();
        FechaHorario(Fecha fecha, Horario horario);
        FechaHorario(int dia, int mes, int anio, int segundo, int minuto, int hora);

        void setFecha(Fecha fecha);
        void setHorario(Horario horario);
        void setFecha(int dia, int mes, int anio);
        void setHorario(int segundo, int minuto, int hora);
        void setFechaHorario(FechaHorario fechahorario);

        std::string toString();
        std::string toStringSinHorario();

        int DiferenciaDeDias(FechaHorario FechaAlquiler, FechaHorario FechaDevolucion);


    private:
        Fecha _fecha;
        Horario _horario;
};

#endif // FECHAHORARIO_H
