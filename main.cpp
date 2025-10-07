    #include <iostream>
    #include <stdlib.h>
    void agregardatosfila(int *&, int &, int);
    void agregardatosfila(float *&, int &, float);
    void agregardatosfila(char *&, int &, char);
    void agregardatospila(int *&, int &, int);
    void agregardatospila(float *&, int &, float);
    void agregardatospila(char *&, int &, char);
    void eliminardato1(int *&original,int &contador);
    void eliminardato1(float *&original,int &contador);
    void eliminardato1(char *&original,int &contador);
    void ordenar(int *&original,int &contador);
    int main(){

        //primero pila despues fila
        
        //array1 pila
        int *id_paquete;
        id_paquete=nullptr;
        id_paquete = new int[50]();
        //array2 pila
        float *peso_paquete;
        peso_paquete=nullptr;
        peso_paquete = new float[50]();
        //array3 pila
        int *prioridad_paquete;
        prioridad_paquete=nullptr;
        prioridad_paquete = new int[50]();
        //array4 pila
        char *destino_paquete;
        destino_paquete=nullptr;
        destino_paquete = new char[50]();

        //array 5 pila
        char *estado_paquete;
        estado_paquete=nullptr;
        estado_paquete = new char[50]();

        //array1 pila
        int *id_paquete_fila;
        id_paquete_fila=nullptr;
        id_paquete_fila = new int[50]();
        //array2 pila
        float *peso_paquete_fila;
        peso_paquete_fila=nullptr;
        peso_paquete_fila = new float[50]();
        //array3 pila
        int *prioridad_paquete_fila;
        prioridad_paquete_fila=nullptr;
        prioridad_paquete_fila = new int[50]();
        //array4 pila
        char **destino_paquete_fila;
        destino_paquete_fila=nullptr;
        destino_paquete_fila = new char*[50]();
        //array5 pila
        char *estado_paquete_fila;
        estado_paquete_fila=nullptr;
        estado_paquete_fila = new char[50]();
        int numero_elementos=1;
        int numero_elementos_activos=0;
        int opcion=1;
        int prioridad=0;
        int valor=0;
        float peso=.1f;
        char lugar[50];
        int contador_elementos_fila=0;
        while(opcion!=5){
            std::cout<<"pila"<<std::endl;
            for(int i=0;i<numero_elementos;i++){
                if(estado_paquete[i]=='R')
                std::cout<<"id: "<<id_paquete[i]<<" peso: "<<peso_paquete[i]<<"kg. destino: "<<destino_paquete[i]<<" prioridad:"<<prioridad_paquete[i]<<" estado:"<<estado_paquete[i]<<std::endl;
            }
            std::cout<<"fila"<<std::endl;
            for(int i=0;i<numero_elementos;i++){
                if(estado_paquete_fila[i]=='E')
                std::cout<<"id: "<<id_paquete_fila[i]<<" peso: "<<peso_paquete_fila[i]<<"kg. destino: "<<destino_paquete_fila[i]<<" prioridad:"<<prioridad_paquete_fila[i]<<" estado:"<<estado_paquete_fila[i]<<std::endl;
                if(estado_paquete_fila[i]=='D'){
                    std::cout<<"despachado";
                std::cout<<"id: "<<id_paquete_fila[i]<<" peso: "<<peso_paquete_fila[i]<<"kg. destino: "<<destino_paquete_fila[i]<<" prioridad:"<<prioridad_paquete_fila[i]<<" estado:"<<estado_paquete_fila[i]<<std::endl;
                }

            }
            std::cout<<"1.-Agregar valor a la pila"<<std::endl;
            std::cout<<"2.-despachar en pila y poner a fila"<<std::endl;
            std::cout<<"3.-despachar con prioridad"<<std::endl;
            std::cout<<"4.-buscar paquetes por lugar de destino"<<std::endl;
            std::cout<<"5.-salir"<<std::endl;
            std::cout<<"opcion seleccionada ";
            std::cin>>opcion;
            int posicion; // Declare posicion before switch to avoid bypassing initialization
            switch(opcion){
                case 1:
                {
                    numero_elementos_activos++;
                    std::cout<<"Ingrese la Peso: ";
                    std::cin>>peso;
                        if(std::cin.fail() || peso <= 0) {
                            std::cin.clear(); // Limpiar el estado de error
                            std::cin.ignore(10000, '\n'); // Descartar entrada
                            std::cout << "Error: Peso inválido. Operación cancelada.\n";
                            numero_elementos_activos--;
                            break;
                        }
                    std::cout<<"ingresa el destino ";
                    std::cin>>lugar;
                    if(std::cin.fail() || prioridad ==NULL) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "nombre imposibles.\n";
                        numero_elementos_activos--;
                        break;
                    }
                    std::cout<<"ingresa una prioridad de 1-3";
                    std::cin>>prioridad;
                    if(std::cin.fail() || prioridad < 1 || prioridad > 3) {
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Error: Prioridad inválida. Debe ser 1, 2 o 3.\n";
                        numero_elementos_activos--;
                        break;
                    }
                    agregardatospila(prioridad_paquete,numero_elementos,prioridad);
                    agregardatospila(estado_paquete,numero_elementos,'R');
                    agregardatospila(id_paquete,numero_elementos,numero_elementos_activos);
                    agregardatospila(destino_paquete,numero_elementos,'a');//test
                    agregardatospila(peso_paquete,numero_elementos,peso);
                    std::cout<<"capacidad en la pila "<<numero_elementos_activos<<"/"<<numero_elementos<<"\n";
                    break;
                }
                case 2:{
                    if(id_paquete==nullptr)break;
                    for(int i=0;i<numero_elementos;i++){
                        //si el array esta vacio rompe el bucle
                        if(estado_paquete[i]=='R'){//si el estado no es EnCola no lo muestra
                        std::cout<<"ID: "<<id_paquete[i]<<" ,peso: "<<peso_paquete[i]<<" ,Destino: "<<destino_paquete[i]<<" ,Prioridad: "<<prioridad_paquete[i]<<" ,estado: "<<estado_paquete[i]<<std::endl;
                        posicion=i;
                        break;
                        }
                    }
                    agregardatosfila(prioridad_paquete_fila,numero_elementos,prioridad_paquete[0]);
                    std::cout<<"paso error";
                    agregardatosfila(estado_paquete_fila,numero_elementos,'E');
                    std::cout<<"paso error";
                    agregardatosfila(id_paquete_fila,numero_elementos,id_paquete[0]);
                    std::cout<<"paso error";
                    agregardatosfila(destino_paquete_fila,numero_elementos,destino_paquete[0]);//test
                    std::cout<<"paso error";
                    agregardatosfila(peso_paquete_fila,numero_elementos,peso_paquete[0]);
                    std::cout<<"paso error";
                    eliminardato1(prioridad_paquete,numero_elementos);
                    std::cout<<"paso error";
                    eliminardato1(estado_paquete,numero_elementos);
                    std::cout<<"paso error";
                    eliminardato1(id_paquete,numero_elementos);
                    std::cout<<"paso error";
                    eliminardato1(destino_paquete,numero_elementos);
                    std::cout<<"paso error";
                    eliminardato1(peso_paquete,numero_elementos);
                    std::cout<<"paso error";


                    std::cout<<"despachando el: "<<id_paquete[posicion]<<std::endl;
                    estado_paquete[posicion]='D';//cambia el estado a despachado
                    contador_elementos_fila++;
                    numero_elementos_activos--;
                    std::cout<<"capacidad en la fila "<<numero_elementos_activos<<"/"<<numero_elementos<<"\n";
                    break;
                }
                case 3:
                {
                    int salir=0;
                    if(id_paquete==nullptr)break;
                    for(int i=0;i<contador_elementos_fila;i++){
                        if(estado_paquete_fila[i]=='E'){
                            if(prioridad_paquete_fila[i]==1){
                                std::cout<<"despachando prioridad 1"<<std::endl;
                                std::cout<<"ID: "<<id_paquete_fila[i]<<" ,peso: "<<peso_paquete_fila[i]<<" ,Destino: "<<destino_paquete_fila[i]<<" ,Prioridad: "<<prioridad_paquete_fila[i]<<" ,estado: "<<estado_paquete_fila[i]<<std::endl;
                                posicion=i;
                                estado_paquete_fila[i]='D';
                                salir=1;
                                break;
                            }
                        }
                    }
                    if(salir!=0)break;
                    for(int i=0;i<contador_elementos_fila;i++){
                        if(estado_paquete_fila[i]=='E'){
                            if(prioridad_paquete_fila[i]==2){
                                std::cout<<"despachando prioridad 2"<<std::endl;
                                std::cout<<"ID: "<<id_paquete_fila[i]<<" ,peso: "<<peso_paquete_fila[i]<<" ,Destino: "<<destino_paquete_fila[i]<<" ,Prioridad: "<<prioridad_paquete_fila[i]<<" ,estado: "<<estado_paquete_fila[i]<<std::endl;
                                posicion=i;
                                estado_paquete_fila[i]='D';
                                salir=1;
                                break;
                            }
                        }
                    }
                    if(salir!=0)break;
                    for(int i=0;i<contador_elementos_fila;i++){
                        if(estado_paquete_fila[i]=='E'){
                            if(prioridad_paquete_fila[i]==3){
                                std::cout<<"despachando prioridad 3"<<std::endl;
                                std::cout<<"ID: "<<id_paquete_fila[i]<<" ,peso: "<<peso_paquete_fila[i]<<" ,Destino: "<<destino_paquete_fila[i]<<" ,Prioridad: "<<prioridad_paquete_fila[i]<<" ,estado: "<<estado_paquete_fila[i]<<std::endl;
                                posicion=i;
                                estado_paquete_fila[i]='D';
                                salir=1;
                                break;
                            }
                        }
                    }
                    if(salir!=0)break;
                    break;
                }
                case 4:
                {
                    float pesototal=0.0f;
                    int contador_paquetes_destino=0;
                    std::cout<<"Dame la ciudad a buscar"<<std::endl;
                    std::cin>>lugar;
                    for(int i=0;i<numero_elementos;i++){
                        if(destino_paquete[i]=='a' && estado_paquete[i]=='E'){
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
    void eliminardato1(int *&original,int &contador){
    if(original==nullptr){
        return;
    }else{
        int *aux;
        aux=new int[contador-1];
        //se empieza en 1 para saltar el primer valor
        for(int i=1;i<contador;i++){
        aux[i-1]=original[i];
        }
        delete[] original;
        original=aux; 
        aux=nullptr;
    }
    }
    void eliminardato1(float *&original,int &contador){
    if(original==nullptr){
        return;
    }else{
        float *aux;
        aux=new float[contador-1];
        //se empieza en 1 para saltar el primer valor
        for(int i=1;i<contador;i++){
        aux[i-1]=original[i];
        }
        delete[] original;
        original=aux; 
        aux=nullptr;
    }
    }
    void eliminardato1(char *&original,int &contador){
    if(original==nullptr){
        return;
    }else{
        char *aux;
        aux=new char[contador-1];
        //se empieza en 1 para saltar el primer valor
        for(int i=1;i<contador;i++){
        aux[i-1]=original[i];
        }
        delete[] original;
        original=aux; 
        aux=nullptr;
    }
    }
    void agregardatospila(int *&original, int &capacidad, int valor) {
        if(original == nullptr) {
            original = new int[50];
            original[0] = valor;
            capacidad = 50;
            return;
        }
        
        // Buscar posición vacía
        for(int i = 0; i < capacidad; i++) {
            if(original[i]==NULL) {
                int *aux = new int[capacidad];
                for(int i = 0; i < capacidad; i++) {
                    aux[i+1] = original[i];
                }
                aux[0] = valor;
                original = aux;
                return;
            }
        }

        int nueva_capacidad = capacidad + 50;
        int *aux = new int[nueva_capacidad];
        
        for(int i = 0; i < capacidad; i++) {
            aux[i+1] = original[i];
        }
        aux[capacidad] = valor;
        
        delete[] original;
        original = aux;
        capacidad = nueva_capacidad;
    }

void agregardatospila(float *&original, int &capacidad, float valor) {
        if(original == nullptr) {
            original = new float[50];
            original[0] = valor;
            capacidad = 50;
            return;
        }
        
        // Buscar posición vacía
        for(int i = 0; i < capacidad; i++) {
            if(original[i]==NULL) {
                float *aux = new float[capacidad];
                for(int i = 0; i < capacidad; i++) {
                    aux[i+1] = original[i];
                }
                aux[0] = valor;
                original = aux;
                return;
            }
        }

        int nueva_capacidad = capacidad + 50;
        float *aux = new float[nueva_capacidad];
        
        for(int i = 0; i < capacidad; i++) {
            aux[i+1] = original[i];
        }
        aux[capacidad] = valor;
        
        delete[] original;
        original = aux;
        capacidad = nueva_capacidad;
        delete[] aux;
    }

    void agregardatospila(char *&original, int &capacidad, char valor) {
        if(original == nullptr) {
            original = new char[50];
            original[0] = valor;
            capacidad = 50;
            return;
        }
        
        // Buscar posición vacía
        for(int i = 0; i < capacidad; i++) {
            if(original[i]==NULL) {
                char *aux = new char[capacidad];
                for(int i = 0; i < capacidad; i++) {
                    aux[i+1] = original[i];
                }
                aux[0] = valor;
                original = aux;
                return;
            }
        }

        int nueva_capacidad = capacidad + 50;
        char *aux = new char[nueva_capacidad];
        
        for(int i = 0; i < capacidad; i++) {
            aux[i+1] = original[i];
        }
        aux[capacidad] = valor;
        
        delete[] original;
        original = aux;
        capacidad = nueva_capacidad;
    }