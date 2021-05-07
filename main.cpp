
#include "funciones.h"




int main() {

    Grupo *humanos = new Grupo;
    Grupo *zombis = new Grupo;
    Grupo *vampiros = new Grupo;
    Grupo *agua = new Grupo;
    Grupo *cruces = new Grupo;
    Grupo *estacas = new Grupo;
    Grupo *escopetas = new Grupo;
    Grupo *balas = new Grupo;


    cout << "LA TABLA" << endl;
    leer_y_cargar(humanos, zombis, vampiros, agua, cruces, estacas, escopetas, balas);
    mostrar_objetos(humanos, zombis, vampiros, agua, cruces, estacas, escopetas, balas);
    menu(humanos, zombis, vampiros, agua, cruces, estacas, escopetas, balas);

    delete humanos;
    delete zombis;
    delete vampiros;
    delete agua;
    delete cruces;
    delete estacas;
    delete escopetas;
    delete balas;

}





