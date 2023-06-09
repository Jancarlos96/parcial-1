#include "Funciones.h"
unsigned int Cantidad_Materias()
{
    char *kk;
    fstream texto;
    texto.open("prueba.csv",ios_base::in | ios_base::binary);
    unsigned int cantidadL = 0;

    if(texto.is_open()){
        while (!texto.eof()){
            kk = Leer_linea(texto);
            cantidadL ++;
            delete []kk;
        }
    }
    return cantidadL;
}

void materias_codigo()
{
    char *kk, **hj;
    fstream texto;
    int u=0;
    texto.open("prueba.csv",ios_base::in | ios_base::binary);
    if(texto.is_open()){
        while (!texto.eof()){
            kk = Leer_linea(texto);
            hj = separador(kk,';');
            if(u==0){
                cout<<" ______________________________________________"<<endl;
                cout<<"|      CODIGO    |            "<<hj[1]<<"          |"<<endl;
                cout<<"|________________|_____________________________|"<<endl;
                u=u+1;
            }
            else{
                cout<<"|"<<u<<". [ "<<hj[0]<<" ]=  "<<hj[1]<<endl;
                u=u+1;
            }



            delete []kk;
        }
        cout<<"|___________________________________________|"<<endl;
    }
}


int verificador(char *codigo)
{
    char *kk, **hj;
    int i=1;
    fstream texto;
    texto.open("prueba.csv",ios_base::in | ios_base::binary);
    if(texto.is_open()){
        while (!texto.eof()){
            kk = Leer_linea(texto);
            hj = separador(kk,';');
            if(codigo == hj[0]){
                cout<<"----------Codigo Verificado------"<<endl;
                cout<<endl;
                cout<<"Materia Registrada: "<<"["<<hj[1]<<"]"<<"Creditos: "<<"["<<hj[2]<<"]"<<endl;
                cout<<" "<<endl;
                delete []hj;
                return i;

            }
        }
    }
    return 3;
}

char *Leer_linea(fstream &k)
{
    char u = ' ', *linea;
    unsigned int tam = Extremos(k), i=0, cursor; //My_lenght
    linea = new char [tam+1];

    while (u!='\r'){
        u = k.get();
        linea[i] = u;
        i++;
    }
    linea[tam] = '\0';
    cursor = k.tellg();
    k.seekg(cursor+1);
    k.get();
    if(!k.eof()) k.seekg(cursor+1);

    return linea;
}

unsigned int Extremos(fstream &k)
{
    char u = ' ';
    unsigned int tam=0,cursor;
    while (u!='\r'){
        u=k.get();
        tam++;
    }
    cursor = k.tellg();
    k.seekg(cursor-tam);
    return tam-1;
}

void Materias(char **Datos)
{
    char *kk;
    fstream texto;
    texto.open("cursos.txt",ios_base::in | ios_base::binary);
    unsigned int cursos = 0;

    if(texto.is_open()){
        while (!texto.eof()){
            kk = Leer_linea(texto);
            *(Datos+cursos)=kk;
            cursos ++;
            delete []kk;
        }
    }
}

//funciones de strings

int Longitud_del_texto(char *i)
{
    int contador = 0;
    while (*(i+contador)!='\0') {
        contador++;
    }
    return contador;
}

int contar_caracter(char *i, char caracter)
{
  int longi = Longitud_del_texto(i);
  int contador = 0;
  for (int j = 0; j < longi; ++j) {
      if (i[j]==caracter){
        contador++;
      }
    }
  return contador;
}

char *Eliminar_Posicion_de_Caracter(char *i, int posicion)
{
    int longi = Longitud_del_texto(i);
    char *nueva = new char [longi];

    for (int j = 0,k=0; j < longi; ++j) {
      if(j!=posicion){
          nueva[k] = i[j];
          k++;
      }
    }
    nueva[longi-1] = '\0';
    return nueva;
}

char *Eliminar_Caracter(char *i, char caracter)
{
    int longi = Longitud_del_texto(i);
    char *nueva=i, *nueva2;

    for (int j = 0; j < longi; ++j) {
        if (nueva[j]==caracter) {
           nueva2 = Eliminar_Posicion_de_Caracter(nueva,j);
           delete []nueva;
           nueva=nueva2;
           longi=longi-1;
        }
    }
    return nueva;
}

char **separador(char *i, char caracter)
{
    int cantidad_ca = contar_caracter(i,caracter);
    int longui = Longitud_del_texto(i);
        char **nueva = new char *[cantidad_ca];

        int posicion_init = 0, contador;

        for (contador = 0; contador < cantidad_ca; ++contador) {
            int posicion = Buscador(i,posicion_init,caracter);
            nueva[contador] = new char [posicion-posicion_init+1];
            for (int j = posicion_init; j < posicion; ++j) {
                nueva[contador][j-posicion_init] = i[j];
            }
            nueva[contador][posicion-posicion_init] = '\0';
            posicion_init=posicion+1;
        }
        nueva[contador] = new char [longui-posicion_init+1];
        for (int j = posicion_init; j<longui; ++j) {
            nueva[contador][j-posicion_init] = i[j];
        }
        nueva[contador][longui-posicion_init] = '\0';

        return nueva;
}

int Buscador(char *i, int posicion, char elemento)
{
    int longui = Longitud_del_texto(i);
    for (int j = posicion; j < longui; ++j) {
        if (i[j]==elemento){
          return j;
        }
    }
}

void mostrarMenu(){

        cout<<"**bienvenido al area de matriculas***"<<endl;
        cout << "Seleccione una opcion:" << endl;
        cout << "1. Matricular materia" << endl;
        cout << "2. Ver materias matriculadas" << endl;
        cout << "3. Guardar en archivo" << endl;
        cout << "4. Salir" << endl;


}

void matricular(){
        const int MAX_MATERIAS = 80;
        char nombres[MAX_MATERIAS][50]; // Arreglo de arreglos de caracteres para almacenar los nombres de las materias
        int codigos[MAX_MATERIAS]; // Arreglo de enteros para almacenar los códigos de las materias
        int creditos[MAX_MATERIAS]; // Arreglo de enteros para almacenar los créditos de las materias
        int numMaterias = 0; // Variable para llevar la cuenta del número de materias matriculadas
        int opcion;

        do {
            mostrarMenu();
            cin >> opcion;

            switch (opcion) {
                case 1: {
                    if (numMaterias == MAX_MATERIAS) {
                        cout << "Se ha alcanzado el límite máximo de materias matriculadas." << endl;
                    } else {
                        cout << "Ingrese el nombre de la materia: ";
                        cin.ignore();
                        cin.getline(nombres[numMaterias], 50);
                        cout << "Ingrese el codigo de la materia: ";
                        cin >> codigos[numMaterias];
                        cout << "Ingrese la cantidad de creditos de la materia: ";
                        cin >> creditos[numMaterias];
                        numMaterias++;
                        cout << "Materia matriculada exitosamente." << endl;
                    }
                    break;
                }
                case 2: {
                    if (numMaterias == 0) {
                        cout << "No hay materias matriculadas." << endl;
                    } else {
                        cout << "Materias matriculadas:" << endl;
                        for (int i = 0; i < numMaterias; i++) {
                            cout << "Nombre: " << nombres[i] << ", Codigo: " << codigos[i] << ", Creditos: " << creditos[i] << endl;
                        }
                    }
                    break;
                }
                case 3: {
                    if (numMaterias == 0) {
                        cout << "No hay materias matriculadas para guardar en el archivo." << endl;
                    } else {
                        ofstream archivo("materias.txt"); // Crear y abrir el archivo en modo de escritura
                        if (archivo.is_open()) {
                            for (int i = 0; i < numMaterias; i++) {
                                archivo << "Nombre: " << nombres[i] << ", Codigo: " << codigos[i] << ", Creditos: " << creditos[i] << endl;
                            }
                            archivo.close(); // Cerrar el archivo
                            cout << "Datos de materias guardados en el archivo 'materias.txt'." << endl;
                        } else {
                            cout << "No se pudo abrir el archivo para escritura." << endl;
                        }
                    }
                    break;
                }
                case 4: {
                    break;
                    }
                    default: {
                        cout << "Opción inválida. Por favor ingrese una opción válida." << endl;
                    break;
                        }
                            }

                } while (opcion != 4);

}

int horario(){
    const int NUM_DIAS = 5;
    const int NUM_HORAS = 16;
    const int MAX_LONGITUD_MATERIA = 20;
    char diasSemana[NUM_DIAS][20] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};
    char horas[NUM_HORAS][20]={"6-7","7-8","8-9","9-10","10-11","11-12","12-13","13-14","14-15","15-16","16-17","17-18","18-19","19-20","20-21","21-22"};
    char horario[NUM_DIAS][NUM_HORAS][50]; // Arreglo para almacenar las materias
    char materia[MAX_LONGITUD_MATERIA];
        char dia[20];
        char hora[20];
        int opcion=0;
        do {
            cout<<"  ________________________________________________"<<endl;
            cout<<" |                   ***horarios***               |"<<endl;
            cout<<" |________________________________________________|"<<endl;
            cout << "Seleccione una opcion:" << endl;
            cout << "1. registrar horario" << endl;
            cout << "2. salir" << endl;
            cin >> opcion;
            cin.ignore();
            if(opcion!=2){
                cout << "Ingrese el codigo  de la materia: ";
                cin.getline(materia, MAX_LONGITUD_MATERIA);
                cin.ignore();
                cout << "Ingrese el día de la semana (Lunes, Martes, Miercoles, Jueves, Viernes): ";
                cin.getline(dia, 20);
                cout << "Ingrese la hora (ej. 6-7, 7-8): ";
                cin.getline(hora, 20);
                // Buscar el índice del día de la semana ingresado*/
                int diaIndex = -1;
                for (int i = 0; i < NUM_DIAS; i++) {
                    int j = 0;
                    while (diasSemana[i][j] != '\0' && dia[j] != '\0' && diasSemana[i][j] == dia[j]) {
                        j++;
                    }
                    if (diasSemana[i][j] == '\0' && dia[j] == '\0') {
                        diaIndex = i;
                        break;
                    }
                }

                // Verificar si se encontró el día de la semana ingresado
                if (diaIndex == -1) {
                    cout << "Dia de la semana no valido." << endl;
                    return 0;
                }

                // Buscar el índice de la hora ingresada
                int horaIndex = -1;
                for (int i = 0; i < NUM_HORAS; i++) {
                    int j = 0;
                    while (horas[i][j] != '\0' && hora[j] != '\0' && horas[i][j] == hora[j]) {
                        j++;
                    }
                    if (horas[i][j] == '\0' && hora[j] == '\0') {
                        horaIndex = i;
                        break;
                    }
                }

                // Verificar si se encontró la hora ingresada
                if (horaIndex == -1) {
                    cout << "Hora no valida." << endl;
                    return 0;
                }

                // Almacenar la materia en el horario
                for (int i = 0; i < 50; i++) {
                    horario[diaIndex][horaIndex][i] = materia[i];
                    if (materia[i] == '\0') {
                        break;
                    }
                }

                // Imprimir la tabla
                cout << "|       |";
                for (int i = 0; i < NUM_DIAS; i++) {
                    cout.width(10);
                    cout << left << diasSemana[i] << "|";
                }
                cout << endl;
                for (int i = 0; i < NUM_HORAS; i++) {
                    cout << "|" << horas[i] << "|";
                            for (int j = 0; j < NUM_DIAS; j++) {
                        cout.width(10);
                        cout << left << horario[j][i] << "|";
                    }
                    cout << endl;
                }
            }
            else{
                opcion=2;
                cout<<"**ha salido de ingresar horarios**"<<endl;
                //break;
            }

                } while (opcion != 2);

                int si_no;
                cout<<"  ___________________________________________________________________________________"<<endl;
                cout<<" | desea ingresar horas de estudio independiente en los espacios vacios[1.si 2.no] : |"<<endl;
                cout<<" |___________________________________________________________________________________|"<<endl;
                cin>>si_no;
                cin.ignore();
                if (si_no==1){
                   for (int i = 0; i < NUM_DIAS; i++) {
                    for (int j = 0; j < NUM_HORAS; j++) {
                        if (horario[i][j][0] == '\0') {
                            cout << "Espacio vacio encontrado en el dia " << diasSemana[i]<< ", hora " << horas[j] << endl;
                            cout << "Ingrese el nombre de la materia: ";
                            cin.getline(horario[i][j], MAX_LONGITUD_MATERIA);
                            cin.ignore();
                        }
                    }
                }
                cout << "|       |";
                for (int i = 0; i < NUM_DIAS; i++) {
                    cout.width(10);
                    cout << left << diasSemana[i] << "|";
                }
                cout << endl;
                for (int i = 0; i < NUM_HORAS; i++) {
                    cout << "|" << horas[i] << "|";
                            for (int j = 0; j < NUM_DIAS; j++) {
                        cout.width(10);
                        cout << left << horario[j][i] << "|";
                    }
                    cout << endl;
                }
                }




}


