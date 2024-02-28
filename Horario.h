#ifndef HORARIO_H
#define HORARIO_H

#include <string>

class Horario
{
  public:
    //   bool operator==(const Horario& otroHorario);
        Horario();
        Horario(int segundo, int minuto, int hora);

        int getSegundo();
        int getMinuto();
        int getHora();
        void setSegundo(int segundo);
        void setMinuto(int minuto);
        void setHora(int hora);
        std::string toString();

    private:
        int _hora, _minuto, _segundo;
};

#endif // HORARIO_H
