#include <iostream>
#include "Funciones.h"
using namespace std;

int main()
{
    int m = Cantidad_Materias();
    char prueba[] ="012345;info 1;55;ll;090\n0145;info 2;o;090\n0125;info 3;090";
    char **nueva = separador(prueba,'\n');

            cout<<nueva[0]<<endl;
         char **nombre = separador(nueva[0],';');
         cout<<nombre[0]<<endl;
    //cout<<nueva<<endl;
}
