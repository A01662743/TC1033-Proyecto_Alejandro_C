#include <iostream>
#include "proyecto_vehiculo.h"
using namespace std;

#ifndef ECO
#define ECO

class Eco: public Vehiculo{
    //métodos
    public:
        // Constructor
        Eco(): Vehiculo(){
        }
        Eco(string _marca, string _modelo): Vehiculo(_marca, _modelo){
        }
        //metodos sobreescritos por polimorfismo
        void print(){
            vehiculo_print(); 
        }
        void restock(float _ignore) {
            cout << endl << "no se puede recargar para este tipo de vehículo" << endl;
        }
        void stock_loss(float _km) {
            ride(_km);
            cout << endl << "kilometros agregados";
        }
};

#endif ECO
