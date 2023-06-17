#include "ReglaFalsa.h"

void ejecutarReglaFalsa()
{
    cout << setprecision(PRECISION);
    cout << "\nMETODO REGLA FALSA\n";
    cout << "\nIngrese el intervalo inicial para tabular [a,b]:" << endl;

    // Entrada del intervalo de tabulacion y tolerancia
    double a, b, tolerancia = 0.00000000;
    cout << "\na = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    ReglaFalsa metodo(a, b, tolerancia);
    metodo.tabula();
    metodo.calcularRaiz();

    cin.get();
    cin.get();
}

int main()
{
    ejecutarReglaFalsa();
    return 0;
}
