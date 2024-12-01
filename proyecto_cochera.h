#include <iostream>
#include <vector>
#include "proyecto_electric.h"
#include "proyecto_gas.h"
#include "proyecto_eco.h"
using namespace std;

#ifndef COCHERA
#define COCHERA

class Cochera {
    //atributos
    private:
        int vehiculos_num;
        vector<Vehiculo*> vehiculos;
    //métodos
    public:
        //consturctor
        Cochera(){
            vehiculos_num = 0;
        }
        //getters
        vector<Vehiculo*> get_vehiculos(){
            return vehiculos;
        }
        int get_vehiculos_num(){
            return vehiculos_num;
        }
        //métodos especiales

        //añadir objetos tipo vehiculo*
        void aniadir(Vehiculo* nuevo){
            vehiculos_num = vehiculos_num + 1;
            vehiculos.push_back(nuevo);
        }
        //buscar y verificar existencia de objeto en base a su marca y modelo
        int buscar_por_nombre(string _marca, string _modelo){
            for(size_t i = 0; i < vehiculos.size(); i++){
                Vehiculo* x = vehiculos[i];
                if (x -> get_marca() == _marca){
                    if (x -> get_modelo() == _modelo){
                        return(i);
                    }
                }
            }
            return -1;
        }
        //eliminar y verificar existencia de objeto en base a su marca y modelo
        void eliminar(string _marca, string _modelo){
            int i = buscar_por_nombre(_marca, _modelo);
            string text;
            if (i == -1){
                text = "elemento no encontrado";
            }
            else{
                vehiculos_num = vehiculos_num -1;
                vehiculos.erase(vehiculos.begin() + i);
                text = "elemento eliminado";
            }
            cout << endl << text << endl;
        }
        //imprimir marca y modelo de cada vehiculo
        void print(){
            cout << endl << "número de vehículos: " << vehiculos_num << endl;
            cout << "vehiculos: ";
            for(size_t i = 0; i < vehiculos.size(); i++){
                Vehiculo* x = vehiculos[i];
                cout << x -> get_marca() << " " << x -> get_modelo() << ", ";
            }
            cout << endl;
        }
};

#endif COCHERA
