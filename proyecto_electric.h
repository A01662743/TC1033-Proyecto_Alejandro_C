#include <iostream>
#include "proyecto_vehiculo.h"
using namespace std;

#ifndef ELECTRIC
#define ELECTRIC

class Electric: public Vehiculo{
    //atributos
    private:
        float energy;
        float max_energy;
        float energy_per_km;
    //métodos
    public:
        // Constructores
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
        //metodos sobreescritos por polimorfismo
        void print(){
            vehiculo_print();
            cout << "porcentaje de carga: " << energy << "%" << endl;
        }
        void restock(float percent){
            if (percent > 100 || percent <= 0 || percent < energy) {
                cout << "no es posible cargar al " << percent << "%" << endl;
            }
            else{
                energy = percent;
                cout << energy << "% de pila";
            }
        }
        void stock_loss(float _km){
            if (_km == 0 || _km*energy_per_km > (energy/100)*max_energy){
                cout << "no se puede realizar el viaje con la energia actual" << endl;
            }
            else {
                ride(_km);
                energy = energy - ((_km*energy_per_km)/max_energy)*100;
                cout << endl << energy << "% de pila";
            }
        }
};

#endif ELECTRIC
