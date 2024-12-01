#include <iostream>
#include "proyecto_vehiculo.h"
using namespace std;

#ifndef GAS
#define GAS

class Gas: public Vehiculo{
    //atributos
    private:
        float gas; // en litros
        int gas_max; // en litros
        float gas_per_km;
    //métodos
    public:
        // Constructores
        Gas(): Vehiculo(){
            gas = 0;
            gas_max = 0;
            gas_per_km = 0;
        }
        Gas(string _marca, string _modelo, float _gas, int _gas_max, float _gas_per_km): Vehiculo(_marca, _modelo){
            gas = _gas;
            gas_max = _gas_max;
            gas_per_km = _gas_per_km;
        }
        //getters
        float get_gas(){
            return gas;
        }
        int get_gas_max(){
            return gas_max;
        }
        float get_gas_per_km(){
            return gas_per_km;
        }
        //setters
        void set_gas(float _gas){
            gas = _gas;
        }
        void set_gas_max(int _gas_max){
            gas_max = _gas_max;
        }
        void set_gas_per_km(float _gas_per_km){
            gas_per_km = _gas_per_km;
        }
        //metodos sobreescritos por
        void print(){
            vehiculo_print();
            cout << "tanque: " << gas << " L" << endl;
        }
        void restock(float liters) {
            if (liters <= 0 || liters + gas > gas_max) {
                cout << "no es posible añadirle al tanque " << liters << " L" << endl;
            }
            else{
                gas = gas + liters;
                cout << "tu tanque contiene ahora " << gas << " L";
            }
        }
        void stock_loss(float _km) {
            if (_km == 0 || _km*gas_per_km > gas){
                cout << "no se puede realizar el viaje con la gasolina actual" << endl;
            }
            else{
                ride(_km);
                gas = gas - (_km*gas_per_km);
                cout << endl << "tu tanque contiene ahora " << gas << "L";
            }
        }
};

#endif GAS
