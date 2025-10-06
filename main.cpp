#include <iostream>
#include <stdlib.h>
#include <string.h>
void agregardatosfila(int *&, int &, int);
void agregardatosfila(float *&, int &, float);
void agregardatosfila(std::string *&, int &, std::string);
void agregardatosfila(char *&, int &, char);
void eliminardato1(int *&original,int &contador);
void ordenar(int *&original,int &contador);

int main(){
    //array1
    int *id_paquete;
    id_paquete=nullptr;
    id_paquete = new int[50]();
    //array2
    float *peso_paquete;
    peso_paquete=nullptr;
    peso_paquete = new float[50]();
    //array3
    int *prioridad_paquete;
    prioridad_paquete=nullptr;
    prioridad_paquete = new int[50]();
    //array4
    std::string *destino_paquete;
    destino_paquete=nullptr;
    destino_paquete = new std::string[50]();
    //array5
    char *estado_paquete;
    estado_paquete=nullptr;
    estado_paquete = new char[50]();
    int numero_elementos=50;
    int numero_elementos_activos=0;
    int opcion=1;
    int prioridad=0;
    int valor=0;
    float peso=.1f;
    std::string lugar="";
    while(opcion!=5){
        std::cout<<"1.-Agregar valor a la fila"<<std::endl;
        std::cout<<"2.-despachar en fila"<<std::endl;
        std::cout<<"3.-visualizar el frente de la fila"<<std::endl;
        std::cout<<"4.-buscar paquetes por lugar de destino"<<std::endl;
        std::cout<<"5.-salir"<<std::endl;
        std::cout<<"opcion seleccionada ";
        std::cin>>opcion;
        int posicion; // Declare posicion before switch to avoid bypassing initialization
        switch(opcion){
            case 1:
            {
                numero_elementos_activos++;
                agregardatosfila(id_paquete,numero_elementos,numero_elementos_activos);
                std::cout<<"Ingrese la Peso: ";
                std::cin>>peso;
                agregardatosfila(peso_paquete,numero_elementos,peso);
                std::cout<<"ingresa el destino ";
                std::cin>>lugar;
                agregardatosfila(destino_paquete,numero_elementos,lugar);
                std::cout<<"ingresa una prioridad de 1-3\n 1 es más alto";
                std::cin>>prioridad;
                agregardatosfila(prioridad_paquete,numero_elementos,prioridad);
                agregardatosfila(estado_paquete,numero_elementos,'E');
                std::cout<<"capacidad en la fila "<<numero_elementos_activos<<"/"<<numero_elementos<<"\n";
                break;
            }
            case 2:{
                if(id_paquete==nullptr)break;
                for(int i=0;i<numero_elementos;i++){
                    //si el array esta vacio rompe el bucle
                    if(estado_paquete[i]=='E'){//si el estado no es EnCola no lo muestra
                    std::cout<<"ID: "<<id_paquete[i]<<" ,peso: "<<peso_paquete[i]<<" ,Destino: "<<destino_paquete[i]<<" ,Prioridad: "<<prioridad_paquete[i]<<" ,estado: "<<estado_paquete[i]<<std::endl;
                    posicion=i;
                    break;
                    }
                }
                std::cout<<"despachando el: "<<id_paquete[posicion]<<std::endl;
                estado_paquete[posicion]='D';//cambia el estado a despachado
                numero_elementos_activos--;
                std::cout<<"capacidad en la fila "<<numero_elementos_activos<<"/"<<numero_elementos<<"\n";
                break;
            }
            case 3:
            {
                if(id_paquete==nullptr)break;
                for(int i=0;i<numero_elementos;i++){
                    if(estado_paquete[i]=='E'){
                    std::cout<<"ID: "<<id_paquete[i]<<" ,peso: "<<peso_paquete[i]<<" ,Destino: "<<destino_paquete[i]<<" ,Prioridad: "<<prioridad_paquete[i]<<" ,estado: "<<estado_paquete[i]<<std::endl;
                    posicion=i;
                    break;
                    }
                }
                break;
            }
            case 4:
            {
                float pesototal=0.0f;
                int contador_paquetes_destino=0;
                std::cout<<"Dame la ciudad a buscar"<<std::endl;
                std::cin>>lugar;
                for(int i=0;i<numero_elementos;i++){
                    if(destino_paquete[i]==lugar && estado_paquete[i]=='E'){
                        pesototal+=peso_paquete[i];
                        contador_paquetes_destino++;
                    }
                }
                if(contador_paquetes_destino == 0){
                    std::cout << "no hay paquete a ese destino, regresando..." << std::endl;
                } else {
                    std::cout << "Reporte de destino a " << lugar << std::endl;
                    std::cout << "La cantidad de paquetes: " << contador_paquetes_destino << std::endl;
                    std::cout << "Peso total: " << pesototal/contador_paquetes_destino << std::endl;
                }
    break;
            }
            case 5:
            {
                std::cout<<"saliendo"<<std::endl;
                break;
            }
            default:
                std::cout<<"Saliendo del sistema"<<std::endl;
        }
    }
    delete[] id_paquete;
    delete[] peso_paquete;
    delete[] prioridad_paquete;
    delete[] destino_paquete;
    delete[] estado_paquete;
}

void agregardatosfila(int *&original, int &capacidad, int valor) {
    if(original == nullptr) {
        original = new int[50]();
        original[0] = valor;
        capacidad = 50;
        return;
    }
    int posicion_vacia = -1;
    for(int i = 0; i < capacidad; i++) {
        if(original[i] == 0) {
            posicion_vacia = i;
            break;
        }
    }
    
    if(posicion_vacia != -1) {
        original[posicion_vacia] = valor;
        return;
    }   
    int nueva_capacidad = capacidad + 50;
    int *aux = new int[nueva_capacidad]();
    
    for(int i = 0; i < capacidad; i++) {
        aux[i] = original[i];
    }
    aux[capacidad] = valor;
    
    delete[] original;
    original = aux;
    capacidad = nueva_capacidad;
}

void agregardatosfila(char *&original, int &capacidad, char valor) {
    if(original == nullptr) {
        original = new char[50]();
        original[0] = valor;
        capacidad = 50;
        return;
    }
    int posicion_vacia = -1;
    for(int i = 0; i < capacidad; i++) {
        if(original[i] == 0) {
            posicion_vacia = i;
            break;
        }
    }
    
    if(posicion_vacia != -1) {
        original[posicion_vacia] = valor;
        return;
    }
    int nueva_capacidad = capacidad + 50;
    char *aux = new char[nueva_capacidad]();
    
    for(int i = 0; i < capacidad; i++) {
        aux[i] = original[i];
    }
    aux[capacidad] = valor;
    
    delete[] original;
    original = aux;
    capacidad = nueva_capacidad;
}

void agregardatosfila(float *&original, int &capacidad, float valor) {
    if(original == nullptr) {
        original = new float[50]();
        original[0] = valor;
        capacidad = 50;
        return;
    }
    
    // Buscar posición vacía
    int posicion_vacia = -1;
    for(int i = 0; i < capacidad; i++) {
        if(original[i] == 0.0f) {
            posicion_vacia = i;
            break;
        }
    }
    
    if(posicion_vacia != -1) {
        original[posicion_vacia] = valor;
        return;
    }
    
    // Expandir array
    std::cout << "Expandiendo array de flotantes..." << std::endl;
    int nueva_capacidad = capacidad + 50;
    float *aux = new float[nueva_capacidad]();
    
    for(int i = 0; i < capacidad; i++) {
        aux[i] = original[i];
    }
    aux[capacidad] = valor;
    
    delete[] original;
    original = aux;
    capacidad = nueva_capacidad;
}
void agregardatosfila(std::string *&original, int &capacidad, std::string valor) {
    if(original == nullptr) {
        original = new std::string[50];
        original[0] = valor;
        capacidad = 50;
        return;
    }
    
    // Buscar posición vacía
    int posicion_vacia = -1;
    for(int i = 0; i < capacidad; i++) {
        if(original[i].empty()) {
            posicion_vacia = i;
            break;
        }
    }
    
    if(posicion_vacia != -1) {
        original[posicion_vacia] = valor;
        return;
    }
    int nueva_capacidad = capacidad + 50;
    std::string *aux = new std::string[nueva_capacidad];
    
    for(int i = 0; i < capacidad; i++) {
        aux[i] = original[i];
    }
    aux[capacidad] = valor;
    
    delete[] original;
    original = aux;
    capacidad = nueva_capacidad;
}
void ordenar(int *&original,int *&prioridades,int &contador){
    //si el original es solo un puntero vacio
    if(original==nullptr){
        return;
    }else{
        int aux;
        for(int i=0;i<contador;i++){//ciclo burbuja
            for(int j=0;j<contador-1;j++){
                if(prioridades[j]>prioridades[j+1]){
                    aux=original[j];
                    original[j]=original[j+1];
                    original[j+1]=aux;
                }
            }
        }
    }
}