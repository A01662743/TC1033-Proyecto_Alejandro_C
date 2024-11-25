#include <iostream>
#include <vector>
#include "proyecto_clase_agregacion.h"
using namespace std;

int main (){
    //menú
    Cochera cochera = Cochera();
    int opcion;
    cout << "1 - vehiculo nuevo\n2 - añadir kilómetros a vehículo\n3 - recargar vehículo\n4 - eliminar vehíulo" << endl;
    cin >> opcion;

    //agregar vehiculo
    if (opcion == 1){
        string marca_;
        string modelo_;
        float recurso;
        float energy;
        float max;
        float per_km;
        cout << "1 = Eléctrico\n2 = A base de gasolina\n3 = Ecológico" << endl;
        cin >> opcion;

        //agregar vehiculo tipo eléctrico
        if (opcion == 1){
            cout << endl << "¿Cuál es la marca del vehículo eléctrico? ";
            cin >> marca_;
            cout << "¿Cual es el modelo? ";
            cin >> modelo_;
            cout <<"¿Cual es su porcentaje de carga actual? (omitir el simbolo '%') ";
            cin >> recurso;
            cout << "¿Cual es su capacidad máxima en Watts? ";
            cin >> max;
            cout << "¿Cuanta energia gasta por kilómetro? ";
            cin >> per_km;

            Electric electric_1 = Electric(marca_, modelo_, recurso, max, per_km);
            cochera.aniadir(electric_1);
            electric_1.print();
        }

        //agregar vehiculo a abse de gasolina
        else if (opcion == 2){
            cout << endl << "¿Cuál es la marca del vehículo a base de gasolina? ";
            cin >> marca_;
            cout << "¿Cual es el modelo? ";
            cin >> modelo_;
            cout << "¿Cuantos litros de gasolina tiene actualmente? ";
            cin >> recurso;
            cout << "¿Cual es su capacidad máxima de gasolina en litros? ";
            cin >> max;
            cout << "¿Cuantos litros de gasolina gasta por kilómetro? ";
            cin >> per_km;

            Gas gas_1 = Gas(marca_, modelo_, recurso, max, per_km);
            cochera.aniadir(gas_1);
            gas_1.print();
        }

        //agregar vehiculo tipo ecológico
        else if (opcion == 3){
            cout << endl << "¿Cuál es la marca del vehiculo ecológico? ";
            cin >> marca_;
            cout << "¿Cual es el modelo? ";
            cin >> modelo_;

            Eco eco_1 = Eco(marca_, modelo_);
            cochera.aniadir(eco_1);
            eco_1.print();
        }
        else{
            cout << "opcion invalida, cerrando programa" << endl;
        }
    }

    //añadir km a vehículo
    else if (opcion == 2){
        //verificar que hayan vehículos
        if (cochera.get_vehiculos().empty()){
            cout << "no hay vehiculos todavia" << endl;
        }
        //elegír vehiculo
        else {
            int index;
            cochera.print();
            cout << "número del vehículo al quieres añadir km: ";
            cin >> index;
        }
    }
    return 0;
}
