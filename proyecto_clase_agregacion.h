#include <iostream>
#include <vector>
#include "proyecto_clases_hijas.h"
using namespace std;

#ifndef COCHERA
#define COCHERA

class Cochera {
    //atributos
    private:
        int vehiculos_num;
        vector<Vehiculo> vehiculos;
    //métodos
    public:
        //consturctor
        Cochera(){
            vehiculos_num = 0;
        }
        //getters
        vector<Vehiculo> get_vehiculos(){
            return vehiculos;
        }
        int get_vehiculos_num(){
            return vehiculos_num;
        }
        //métodos especiales
        void aniadir(Vehiculo nuevo){
            vehiculos_num = vehiculos_num + 1;
            vehiculos.push_back(nuevo);
        }
        void eliminar(int index){
            vehiculos.erase(index);
        }
        void print(){
            cout << "número de vehículos: " << vehiculos_num << endl;
            cout << "vehiculos: " << vehiculos << endl;
        }
};

#endif COCHERA
