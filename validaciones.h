#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "validaciones.h"

int getInteger(int minimo = INT_MIN, int maximo = INT_MAX);

float getFloat(float minimo , float maximo = INT_MAX);

int getIntegerSinComa(int minimo, int maximo);

int getIDVideo(int idVideo);

int getIDCategoria(int idCategoria);

int getIDGenero(int idGenero);

int getIDEmpleado(int idEmpleado);

int getIDCliente(int idCliente);

std::string getNombrePropio();

std::string getDireccion();

bool esBisiesto(int anio);








#endif // VALIDACIONES_H_INCLUDED
