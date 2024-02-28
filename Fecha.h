#ifndef FECHA_H
#define FECHA_H

#include <string>

class Fecha{
     public:
        Fecha();
        Fecha(int dia, int mes, int anio);

        int getDia();
        int getMes();
        int getAnio();
        std::string getNombreDia();
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        std::string toString();


    private:
        int _dia, _mes, _anio;
        int _diaSemana;
};

#endif // FECHA_H
