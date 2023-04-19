#include "Funciones.h"
unsigned int Cantidad_Materias()
{
    char *kk;
    fstream texto;
    texto.open("cursos.txt",ios_base::in | ios_base::binary);
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
    return 0;
}

