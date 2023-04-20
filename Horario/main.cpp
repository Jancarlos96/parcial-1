#include <iostream>
#include "Funciones.h"

int main()
{
        int m = Cantidad_Materias();
        materias_codigo();
        cout<<endl;
        cout<<endl;

        cout<<"  ______________________________________"<<endl;
        cout<<" |     Ingresar Materias a Matricular   |"<<endl;
        cout<<" |______________________________________|"<<endl;
        cout<<" | Numero Maximo de Creditos |  24      |"<<endl;
        cout<<" |___________________________|__________|"<<endl;
        cout<<" | Numero Minimo de Creditos |   8      |"<<endl;
        cout<<" |___________________________|__________|"<<endl;
        cout<<endl;
        cout<<endl;

        char codigo_ingresado[7]="";
        char *kk;
        char respuesta;
        int mod,  correc=0;

        cout<<"  ________________________________________________"<<endl;
        cout<<" | Ingrese el Codigo de la Materia a Matricular   |"<<endl;
        cout<<" |________________________________________________|"<<endl;
        while (correc<22){
            cout<<" |"<<endl;
            cout<<" |Codigo: ";cin>>codigo_ingresado;
            kk=codigo_ingresado;
            mod= verificador(kk);
            if(mod==0){
                cout<<endl;
                cout<<"--------------El Codigo de la Materia Ingresada [No] Fue Encontado----------------- "<<endl;
                cout<<endl;
            }

            if(m!=0){
                correc=correc+mod;
                cout<<" [Cantidad de Creditos Actuales ]= ["<<correc<<"]"<<endl;
                cout<<endl;
            }
            cout<<" [Desea Salir de La Matricula [S] o [N] ]:";cin>>respuesta;
            if (respuesta=='S' || respuesta=='s'){
                break;
            }

        }





    horario();

    return 0;
}
