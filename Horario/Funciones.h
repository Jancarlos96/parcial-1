#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>
using namespace std;

unsigned int Cantidad_Materias();
char * Leer_linea(fstream &k);
unsigned int Extremos(fstream &k);
void Materias(char **Datos);
char **crearmatriz(char **Datos, int m);
// simulacuiones clase string
int Longitud_del_texto(char *i);
int contar_caracter(char *i, char caracter);
//Posicionamiento
char * Eliminar_Posicion_de_Caracter(char *i, int posicion);//Elimina caracteres
char * Eliminar_Caracter(char *i, char caracter);//Elimina Posicion
char ** separador(char *i, char caracter);
int Buscador(char *i, int posicion,char elemento);
void materias_codigo();
int verificador(char *codigo);
#endif // FUNCIONES_H


