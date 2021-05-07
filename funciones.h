//
// Created by ydsas on 27/4/2021.
//

#ifndef MAIN_CPP_MOSTRAR_H
#define MAIN_CPP_MOSTRAR_H
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <string>

using std::copy;
using std::string;
using std::stoi;
using namespace std;;

const int MAX_NOMBRE = 15;
const string NOMBRE_ARCHIVO = "estado.txt";

struct Objeto{
    string nombre;
    bool rol = false;
    int x, y, cantidad_elemento;
};

struct Grupo{
    Objeto** objetos;
    string nombre_grupo;
    int tope = 0;
    int total_elemento = 0;
};
void cargar_grupo(Grupo* grupo, Objeto* objeto);

void leer_y_cargar(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* Estacas, Grupo* Escopetas, Grupo* B);

void mostrar_objetos(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* Estacas, Grupo* Escopetas, Grupo* B);

void menu(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* Estacas, Grupo* Escopetas, Grupo* B);
#endif //MAIN_CPP_MOSTRAR_H
