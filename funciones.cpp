//

#include "funciones.h"



//
// Created by ydsas on 27/4/2021.
void inicializar_grupo(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* E, Grupo* P, Grupo* B){
    
    H -> nombre_grupo = "Humanos";
    Z -> nombre_grupo = "Zombis";
    V -> nombre_grupo = "Vampiros";
    A -> nombre_grupo ="Agua bendita";
    C -> nombre_grupo ="Cruces";
    E -> nombre_grupo = "Estacas";
    P -> nombre_grupo = "Escopetas";
    B -> nombre_grupo = "Balas";

}

bool es_hombre(string word){
    if (word.compare("humanoCV") == 0 || word.compare("humano") == 0  || word.compare("Vanesa") == 0){
        return true;
    }else{
        return false;
    }
}

bool es_zombie(string word){
    if (word.compare("zombi") == 0 ){
        return true;
    }else{
        return false;
    }
}

bool es_vampiro(string word){
    if (word.compare("vampiro") == 0  || word.compare("Nosferatu") == 0 || word.compare("Vampirella") == 0 ){
        return true;
    }else{
        return false;
    }
}

bool es_agua(string word){
    if (word.compare("agua") == 0 ){
        return true;
    }else{
        return false;
    }
}

bool es_cruz(string word){
    if (word.compare("cruz") == 0 ){
        return true;
    }else{
        return false;
    }
}

bool es_estaca(string word){
    if (word.compare("estaca") == 0 ){
        return true;
    }else{
        return false;
    }
}

bool es_escopeta(string word){
    if (word.compare("escopeta") == 0 ){
        return true;
    }else{
        return false;
    }
}



bool es_bala(string word){
    if (word.compare("bala") == 0 ){
        return true;
    }else{
        return false;
    }
}

void cargar_grupo(Grupo* grupo, Objeto* objeto){
    int tope_viejo = grupo -> tope;
    Objeto** nuevo_vector_objetos = new Objeto*[tope_viejo + 1];

    for (int i = 0; i < grupo -> tope; i++) {
        nuevo_vector_objetos[i] = grupo -> objetos[i];
        //cout << grupo ->objetos[i]->nombre << "." << endl;
    }
    nuevo_vector_objetos[tope_viejo] = objeto;

    if (es_agua(objeto -> nombre) || es_bala(objeto -> nombre)){
        grupo -> total_elemento = grupo -> total_elemento + objeto -> cantidad_elemento;
        //cout << "total elemento: " << grupo -> total_elemento << endl;
        //grupo -> total_elemento = grupo -> total_elemento + grupo->objetos[grupo->tope]->cantidad_elemento;
    } else{
        grupo ->total_elemento = grupo ->tope + 1;
    }

    if(grupo -> tope != 0){
        delete[] grupo -> objetos;
    }

    grupo -> objetos = nuevo_vector_objetos;
    grupo -> tope++;


    /*for (int i = 0; i < grupo -> tope; i++) {
        cout << grupo->objetos[i]->nombre << " " << grupo->objetos[i]->x << " " << grupo->objetos[i]->y << " ";
    }*/

}


void leer_y_cargar(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* E, Grupo* P, Grupo* B) {


    inicializar_grupo(H, Z, V, A, C, E, P, B);
    ifstream archivo;
    archivo.open(NOMBRE_ARCHIVO);
    if (!archivo) {
        cout << "No se pudo abrir el archivo..." << endl;
    } else {
        string word;
        bool rol = false;
        string x, y, cant;
        string basura;
        Objeto* objeto;
        int cantp = 0;

        while (getline(archivo, word, ' ')) {
            /*if (es_agua(word) || es_bala(word)){
                //getline(archivo, basura, ' ');
                getline(archivo, cant, '(');

            }else if (es_hombre(word)){

                getline(archivo, rol, '(');
                if (rol == "CV "){
                    objeto -> rol = true;
                }
                //getline(archivo, basura, '');
            } else{
                getline(archivo, rol, '(');
            }*/
            getline(archivo, cant, '(');
            getline(archivo, x, ',');
            getline(archivo, y, ')');
            //archivo.seekg(2, ios_base::cur);
            getline(archivo, basura);


            objeto = new Objeto;
            objeto -> nombre = word;
            objeto -> rol = false;
            //objeto -> nombre = objeto -> nombre + rol;
            objeto -> x = stoi(x, nullptr);
            objeto -> y = stoi(y, nullptr);

            //cout << word << "." << c <<"." << y << "."<< endl;
            if (es_agua(word) || es_bala(word)){
                objeto ->cantidad_elemento = stoi(cant, nullptr);
            }else if (es_hombre(word)) {

                if (cant == "CV ") {
                    objeto->rol = true;
                    cout << cant ;
                }
            }

            cantp++;
            if (es_hombre(word)){
                cargar_grupo(H, objeto);
            }
            else if (es_zombie(word)){
                cargar_grupo(Z, objeto);
            }
            else if (es_vampiro(word)){
                cargar_grupo(V, objeto);
            }
            else if (es_agua(word)){
                cargar_grupo(A, objeto);
            }
            else if (es_cruz(word)){
                cargar_grupo(C, objeto);
            }
            else if (es_estaca(word)){
                cargar_grupo(E, objeto);
            }
            else if (es_escopeta(word)){
                cargar_grupo(P, objeto);
            }
            else{
                cargar_grupo(B, objeto);
            }


        }
        cout << cantp ;
        archivo.close();
    }
}

void mostrar_objeto(Grupo* objeto, float total){
    cout << "---------------------------------" << endl
         << objeto -> nombre_grupo << "    " << objeto -> total_elemento
         << "    " << objeto->total_elemento / total * 100 << " %" << endl
    //<< objeto->objetos[objeto->total_elemento - 1]->nombre << endl
    << "---------------------------------" << endl;


}

void mostrar_objetos(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* E, Grupo* P, Grupo* B){

    cout << " OBJETOS " << endl;

    float total_objeto = H -> total_elemento + Z -> total_elemento + V -> total_elemento;
    float total_elemento =  A -> total_elemento + C ->total_elemento + E -> total_elemento;
    mostrar_objeto(H, total_objeto);
    mostrar_objeto(Z, total_objeto);
    mostrar_objeto(V, total_objeto);
    mostrar_objeto(A, total_elemento);
    mostrar_objeto(C, total_elemento);
    mostrar_objeto(E, total_elemento);
    mostrar_objeto(P, B -> total_elemento);
    mostrar_objeto(B, P -> total_elemento);

}

int inicio_x(string zona){

    int x;
    if (zona[1] == 'O'){
        x = 1;
    }else{
        x = 501;
    }

    return x;
}

int inicio_y(string zona){

    int y;
    if (zona[0] == 'N'){
        y = 1;
    }else{
        y = 301;
    }

    return y;
}

bool esta_en_la_zona(Grupo* grupo, string zona, int i){
    if (grupo->objetos[i]->x >= inicio_x(zona)){
        if (grupo->objetos[i]->x <= inicio_x(zona) + 499){
            if (grupo->objetos[i]->y >= inicio_y(zona)){
                if (grupo->objetos[i]->y <= inicio_y(zona) + 299)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        else
            return false;
    } else
        return false;
    cout << grupo->objetos[i]->x << ", " << grupo->objetos[i]->y << endl;
}

void buscar_zona(Grupo* grupo, string zona, string nombre){

    int i = 0;
    int j = 0;
    inicio_x(zona);
    inicio_y(zona);
    cout << "Buscar: " << nombre << " si esta en la zona: " << zona << endl;
    while (i < grupo -> tope){
        if (grupo->objetos[i]->nombre.compare(nombre) == 0){
            if (esta_en_la_zona(grupo, zona, i))
                j++;
        }
            i++;

    }
    cout << "Hay " << j << " " << nombre << " en la zona " << zona << endl << endl;
}


bool zona_correcta(string zona){
    if (zona.compare("NE") == 0 || zona.compare("NO") == 0 || zona.compare("SE") == 0 || zona.compare("SO") == 0)
        return true;
    else
        return false;

}


void buscar(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* E, Grupo* P, Grupo* B){

    string nombre, zona;

    cout << "Escribe el objeto que desea encontrar: ";
    cin >> nombre;
    cout << endl;

    while (!es_hombre(nombre) && !es_vampiro(nombre) && !es_bala(nombre) && !es_agua(nombre) && !es_zombie(nombre) && !es_cruz(nombre) && !es_escopeta(nombre) && !es_estaca(nombre)){
        cout << "ERROR!!!! Escribe el objeto de nuevo que desea encontrar: ";
        cin >> nombre;
        cout << endl;
    }
    cout << endl << "Escribe la zona donde quiere buscar el objeto escrito anteriormente: ";
    cin >> zona;
    cout << endl;

    while (!zona_correcta(zona)){
        cout << "ERROR!!!! Escribe la zona del objetivo nuevamente: ";
        cin >> zona;
        cout << endl;
    }
    //cout << "Objeto a buscar: " << nombre << endl
    //        << "en la zona: " << zona << endl;


    if (es_hombre(nombre)){

        buscar_zona(H, zona, nombre);
    }
    else if (es_zombie(nombre)){
        buscar_zona(Z, zona, nombre);
    }
    else if (es_vampiro(nombre)){
        buscar_zona(V, zona, nombre);
    }
    else if (es_agua(nombre)){
        buscar_zona(A, zona, nombre);
    }
    else if (es_cruz(nombre)){
        buscar_zona(C, zona, nombre);
    }
    else if (es_estaca(nombre)){
        buscar_zona(E, zona, nombre);
    }
    else if (es_escopeta(nombre)){
        buscar_zona(P, zona, nombre);;
    }
    else if (es_bala(nombre)){
        buscar_zona(B, zona, nombre);
    }

}

string validar_respuesta(string &respuesta){
    while (respuesta.compare("si") != 0 && respuesta.compare("no") != 0){
        cout << "ERROR!!!! " << endl
             << "Desea buscar objetos en las zonas?" << endl
             << "Ingrese si o no para continuar: " ;
        cin >> respuesta;
        cout << endl;
    }
    return respuesta;
}

void liberar_vector(Grupo *grupo){

    int cant_objeto = grupo -> tope;
    for (int i = 0; i < cant_objeto; ++i) {
        delete grupo ->objetos[i];
        grupo -> tope --;
    }

    delete[] grupo -> objetos;
    grupo -> objetos = nullptr;
}

void menu(Grupo *H, Grupo *Z, Grupo *V, Grupo* A, Grupo* C, Grupo* E, Grupo* P, Grupo* B){

    string respuesta;
    cout << "Desea buscar objetos en las zonas?" << endl
         << "Ingrese si o no para continuar: " ;
    cin >> respuesta;
    cout << endl;

    validar_respuesta(respuesta);


    while (respuesta.compare("si") == 0){
        buscar(H, Z, V, A, C, E, P, B);
        cout << "Desea volver a buscar objetos en las zonas?" << endl
             << "Ingrese si o no para continuar: " ;
        cin >> respuesta;
        cout << endl;
        validar_respuesta(respuesta);
    }
    if (respuesta.compare("no") == 0){
        cout << "TERMINAR EL PROGRAMA";
        liberar_vector(H);
        liberar_vector(Z);
        liberar_vector(V);
        liberar_vector(A);
        liberar_vector(C);
        liberar_vector(E);
        liberar_vector(P);
        liberar_vector(B);

    }


}

