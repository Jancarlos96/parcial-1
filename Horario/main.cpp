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
    cout<<m<<endl;
    cout<<endl;
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
//    int m=0, correc=0;

//    cout<<"  ________________________________________________"<<endl;
//    cout<<" | Ingrese el Codigo de la Materia a Matricular   |"<<endl;
//    cout<<" |________________________________________________|"<<endl;
//    while (correc<24){
//        cout<<" |Codigo: ";cin>>codigo_ingresado;
//        kk=codigo_ingresado;
//        m= verificador(codigo_ingresado);
//        if(m==3){
//            cout<<"-----El Codigo de la Materia ingresada [No] fue Encontado------- "<<endl;
//        }

//        if(m!=3){
//            correc=correc+m;
//        }
//    }
//    cout<<" |Codigo: ";cin>>codigo_ingresado;




    //cout<<*nueva<<endl;

}


//#include <iostream>

//using namespace std;

//const int NUM_DIAS = 5;
//const int NUM_HORAS = 16;

//char diasSemana[NU,M_DIAS][20] = {"Lunes" "Martes", "Miercoles", "Jueves", "Viernes"};
//char horas[NUM_HORAS][20]={"6-7","7-8","8-9","9-10","10-11","11-12","12-13","13-14","14-15","15-16","16-17","17-18","18-19","19-20","20-21","21-22"};
//char horario[NUM_DIAS][NUM_HORAS][50]; // Arreglo para almacenar las materias

//int main() {
//    char materia[50];
//    char dia[20];
//    char hora[20];
//    int opcion=0;
//                while (opcion!=2)
//                {


//                // Solicitar datos al usuario
//                cout << "Ingrese el nombre de la materia: ";
//                cin.getline(materia, 50);
//                cout << "Ingrese el d�a de la semana (Lunes, Martes, Mi�rcoles, Jueves, Viernes): ";
//                cin.getline(dia, 20);
//                cout << "Ingrese la hora (ej. 6-7, 7-8): ";
//                cin.getline(hora, 20);
//                // Buscar el �ndice del d�a de la semana ingresado*/
//                int diaIndex = -1;
//                for (int i = 0; i < NUM_DIAS; i++) {
//                    int j = 0;
//                    while (diasSemana[i][j] != '\0' && dia[j] != '\0' && diasSemana[i][j] == dia[j]) {
//                        j++;
//                    }
//                    if (diasSemana[i][j] == '\0' && dia[j] == '\0') {
//                        diaIndex = i;
//                        break;
//                    }
//                }

//                // Verificar si se encontr� el d�a de la semana ingresado
//                if (diaIndex == -1) {
//                    cout << "D�a de la semana no v�lido." << endl;
//                    return 0;
//                }

//                // Buscar el �ndice de la hora ingresada
//                int horaIndex = -1;
//                for (int i = 0; i < NUM_HORAS; i++) {
//                    int j = 0;
//                    while (horas[i][j] != '\0' && hora[j] != '\0' && horas[i][j] == hora[j]) {
//                        j++;
//                    }
//                    if (horas[i][j] == '\0' && hora[j] == '\0') {
//                        horaIndex = i;
//                        break;
//                    }
//                }

//                // Verificar si se encontr� la hora ingresada
//                if (horaIndex == -1) {
//                    cout << "Hora no v�lida." << endl;
//                    return 0;
//                }

//                // Almacenar la materia en el horario
//                for (int i = 0; i < 50; i++) {
//                    horario[diaIndex][horaIndex][i] = materia[i];
//                    if (materia[i] == '\0') {
//                        break;
//                    }
//                }

//                // Imprimir la tabla
//                cout << "|       |";
//                for (int i = 0; i < NUM_DIAS; i++) {
//                    cout.width(10);
//                    cout << left << diasSemana[i] << "|";
//                }
//                cout << endl;
//                for (int i = 0; i < NUM_HORAS; i++) {
//                    cout << "|" << horas[i] << "|";
//                            for (int j = 0; j < NUM_DIAS; j++) {
//                        cout.width(10);
//                        cout << left << horario[j][i] << "|";
//                    }
//                    cout << endl;
//                }
//                }
//    return 0;
//}
