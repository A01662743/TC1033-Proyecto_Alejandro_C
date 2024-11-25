#include <iostream>
using namespace std;

#ifndef VEHICULO
#define VEHICULO

class Vehiculo {
    //atributos
    protected:
        string marca;
        string modelo;
        float km_recorridos;
    //métodos
    public:
        //constructores
        Vehiculo(){
            marca = "undefined";
            modelo = "undefined";
            km_recorridos = 0;
        }
        Vehiculo (string _marca, string _modelo){
            marca = _marca;
            modelo = _modelo;
            km_recorridos = 0;
        }
        //getters
        string get_marca(){
            return marca;
        }
        string get_modelo(){
            return modelo;
        }
        float get_km_recorridos(){
            return km_recorridos;
        }
        //setters
        void set_marca(string _marca){
            marca = _marca;
        }
        void set_modelo(string _modelo){
            modelo = _modelo;
        }
        void set_km_recorridos(float _km_recorridos){
            km_recorridos = _km_recorridos;
        }
        //métodos especiales
        void ride (float km){
            km_recorridos = km + km_recorridos;
        }
        void vehiculo_print(){
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl;
            cout << "kilómetros recorridos: " << km_recorridos << " km" << endl;
    }
};

#endif VEHICULO
