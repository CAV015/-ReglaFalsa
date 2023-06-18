#include "ReglaFalsa.h"
#include "colors.h"

ReglaFalsa::ReglaFalsa(double a, double b, double tolerancia)
    : a(a), b(b), tolerancia(tolerancia), xr(0), xa(0)
{
}

void ReglaFalsa::tabula()
{
    int puntos = INTERVALOS + 1;
    double ancho = (b - a) / INTERVALOS;

    cout <<LBLUE<< "\n\tx\tf(x) " << endl;
    for (int i = 0; i < puntos; i++) {
        cout << "\t" << a << "\t" << f(a) << endl;
        a = a + ancho;
    }
}

void ReglaFalsa::calcularRaiz()
{
    // Selección del intervalo adecuado
    cout <<WHITE<< "\nEscoja el intervalo adecuado" << endl;
    cout << "\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    double error = 0;

    // Verificar si se puede aplicar el método (que exista un cambio de signo dentro del intervalo de tabulacion)
    if (f(a) * f(b) > 0) {
        cout <<RED<< "\nNo se puede aplicar el metodo de la falsa posicion\n";
        cout << "porque f(" << a << ") y f(" << b << ") tienen el mismo signo" << endl;
        return;
    }

    // Mostrar encabezado de la tabla de iteraciones
    mostrarTablaEncabezado();

    // Iterar hasta encontrar la raíz dentro de la tolerancia
    do {
        // Calcular la aproximación de la raíz
        xr = b - f(b) * ((b - a) / (f(b) - f(a)));
        error = fabs((xr - xa) / xr);
        mostrarIteracion(a, b, xr, f(a), f(b), f(xr), error);

        if (fabs(xr - xa) / fabs(xr) <= tolerancia) {
            cout <<WHITE<< "\n\nPara una tolerancia de " << tolerancia << " la raiz de f es: " <<LBLUE<< xr << endl;
            break;
        }
        else {
            xa = xr; // Se guarda el valor de la aproximación anterior
            if (f(xr) * f(a) > 0) {
                a = xr;
            }
            else if (f(xr) * f(b) > 0) {
                b = xr;
            }
        }
    } while (true);
}

double ReglaFalsa::f(double x)
{
    //return sqrt(x) - cos(x);
    //return exp(-1 * x) - log(x);
    return pow(x, 2) - cos(x);
}

void ReglaFalsa::mostrarTablaEncabezado()
{
    cout << "\n\ta\t\tf(a)\t\t\tb\t\t\tf(b)\t\t\t\tc\t\t\tf(c)\t\t\t\t|E|\n" << endl;
}

void ReglaFalsa::mostrarIteracion(double a, double b, double xr, double fa, double fb, double fc, double error)
{
    cout <<LBLUE<< right << setw(10) << a << right << setw(20) << fa << right << setw(20) << b << right << setw(25) << fb << right << setw(30) << xr << right << setw(30) << fc << right << setw(35) << error << endl;
}
