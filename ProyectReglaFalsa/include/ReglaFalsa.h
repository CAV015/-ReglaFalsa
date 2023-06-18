#pragma once
#ifndef REGLAFALSA_H
#define REGLAFALSA_H

#include <iostream>
#include <iomanip> // setprecision de los resultados
#include <cmath>   // fabs |VA|

#define PRECISION 8   //cantidad de decimales a mostrar en los resultados
#define INTERVALOS 6  //número de intervalos para tabular la función.(modificado de 10-6)

using namespace std;

class ReglaFalsa {
public:
    ReglaFalsa(double a, double b, double tolerancia);

    void tabula(); // Tabula la función en el intervalo inicial
    void calcularRaiz(); // Calcula la raíz utilizando el método de regla falsa
    double f(double x); // Función cuyas raíces se están buscando.

private:
    double a; // Extremo izquierdo del intervalo
    double b; // Extremo derecho del intervalo
    double tolerancia; // Tolerancia para la aproximación de la raíz

    double xr; // La solución aproximada
    double xa; // Solución anterior

    void mostrarTablaEncabezado();
    void mostrarIteracion(double a, double b, double xr, double fa, double fb, double fc, double error);
};

#endif

