#include <iostream>
#include "proyecto_clase_padre.h"
using namespace std;

#ifndef ELECTRIC
#ifndef GAS
#ifndef ECO
#define ELECTRIC
#define GAS
#define ECO

class Electric: public Vehiculo{
    //atributos
    private:
        float energy;
        float max_energy;
        float energy_per_km;
    //métodos
    public:
        // Constructor
        Electric(): Vehiculo(){
            energy = 0;
            max_energy = 0;
            energy_per_km = 0;
        }
        Electric(string _marca, string _modelo, float _energy, int _max_energy, float _energy_per_km): Vehiculo(_marca, _modelo){
            energy = _energy;
            max_energy = _max_energy;
            energy_per_km = _energy_per_km;
        }
        //getters
        float get_energy(){
            return energy;
        }
        float get_max_energy(){
            return max_energy;
        }
        float get_energy_per_km(){
            return energy_per_km;
        }
        //setters
        void set_energy(float _energy){
            energy = _energy;
        }
        void set_max_energy(float _max_energy){
            max_energy = _max_energy;
        }
        void set_energy_per_km(float _energy_per_km){
            energy_per_km = _energy_per_km;
        }
        void print(){
            vehiculo_print();
            cout << "porcentaje de carga: " << energy << "%" << endl;
        }
        //metodos especiales
        void charge(float percent){
            if (percent > 100 || percent <= 0 || percent < energy) {
                cout << "no es posible cargar al " << percent << "%" << endl;
            }
            else{
                energy = percent;
            }
        }
        void discharge(float _km){
            if (_km == 0 || _km*energy_per_km > (energy/100)*max_energy){
                cout << "no se puede realizar el viaje con la energia actual" << endl;
            }
            else {
                ride(_km);
                energy = energy - ((_km*energy_per_km)/max_energy)*100;
            }
        }
};

class Gas: public Vehiculo{
    //atributos
    private:
        float gas; // en litros
        int gas_max; // en litros
        float gas_per_km;
    //métodos
    public:
        Gas(): Vehiculo(){
            gas = 0;
            gas_max = 0;
            gas_per_km = 0;
        }
        // Constructor
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
        void set_gas_max(float _gas_max){
            gas_max = _gas_max;
        }
        void set_gas_per_km(float _gas_per_km){
            gas_per_km = _gas_per_km;
        }
        void print(){
            vehiculo_print();
            cout << "tanque: " << gas << " L" << endl;
        }
        //metodos especiales
        void refuel(float liters){
            if (liters <= 0 || liters + gas > gas_max) {
                cout << "no es posible añadirle al tanque " << liters << " L" << endl;
            }
            else{
                gas = gas + liters;
            }
        }
        void gas_loss(float _km){
            if (_km == 0 || _km*gas_per_km > gas){
                cout << "no se puede realizar el viaje con la gasolina actual" << endl;
            }
            else{
                ride(_km);
                gas = gas - (_km*gas_per_km);
            }
        }
};

class Eco: public Vehiculo{
    //métodos
    public:
        // Constructor
        Eco(): Vehiculo(){
        }
        Eco(string _marca, string _modelo): Vehiculo(_marca, _modelo){
        }
        void print(){
            vehiculo_print(); 
        }
};

#endif ELECTRIC
#endif GAS
#endif ECO
