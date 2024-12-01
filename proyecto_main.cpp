#include <iostream>
#include <vector>
#include "proyecto_cochera.h"
using namespace std;

int main (){
    //menú
    Cochera* cochera = new Cochera();
    int opcion;
    while (true){
        cout << endl << "1 - vehiculo nuevo\n2 - añadir kilómetros a vehículo\n3 - recargar vehículo\n4 - eliminar vehíulo\n5 - Mostrar vehículos\ncualquier otro número para finalizar el programa" << endl;
        cin >> opcion;

        //agregar vehiculo
        if (opcion == 1){
            string marca_;
            string modelo_;
            float recurso;
            float energy;
            float max;
            float per_km;
            cout << endl << "1 = Eléctrico\n2 = A base de gasolina\n3 = Ecológico" << endl;
            cin >> opcion;

            //agregar vehiculo tipo eléctrico
            if (opcion == 1){
                cout << endl << "¿Cuál es la marca del vehículo eléctrico? ";
                cin >> marca_;
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;
                cout <<"¿Cual es su porcentaje de carga actual? (omitir el simbolo '%') ";
                cin >> recurso;
                while (recurso > 100 || recurso < 0){
                    cout << "ingrese un valor valido: ";
                    cin >> recurso;
                }
                cout << "¿Cual es su capacidad máxima en Watts? ";
                cin >> max;
                while (max <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> max;
                }
                cout << "¿Cuanta energia gasta por kilómetro en watts? ";
                cin >> per_km;
                while (per_km > max || per_km <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> per_km;
                }

                Electric* electric_1 = new Electric(marca_, modelo_, recurso, max, per_km);
                cochera -> aniadir(electric_1);
                electric_1 -> print();
            }

            //agregar vehiculo a abse de gasolina
            else if (opcion == 2){
                cout << endl << "¿Cuál es la marca del vehículo a base de gasolina? ";
                cin >> marca_;
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;
                cout << "¿Cual es su capacidad máxima de gasolina en litros? ";
                cin >> max;
                while (max <= 0){
                    cout << "ingrese un valor válido: ";
                    cin >> max;
                }
                cout << "¿Cuantos litros de gasolina tiene actualmente? ";
                cin >> recurso;
                while (recurso > max || recurso < 0){
                    cout << "ingrese un valor válido: ";
                    cin >> recurso;
                }
                cout << "¿Cuantos litros de gasolina gasta por kilómetro? ";
                cin >> per_km;
                while (per_km <= 0 || per_km > max){
                    cout << "ingrese un valor válido: ";
                    cin >> per_km;
                }

                Gas* gas_1 = new Gas(marca_, modelo_, recurso, max, per_km);
                cochera -> aniadir(gas_1);
                gas_1 -> print();
            }

            //agregar vehiculo tipo ecológico
            else if (opcion == 3){
                cout << endl << "¿Cuál es la marca del vehiculo ecológico? ";
                cin >> marca_;
                cout << "¿Cual es el modelo? ";
                cin >> modelo_;

                Eco* eco_1 = new Eco(marca_, modelo_);
                cochera -> aniadir(eco_1);
                eco_1 -> print();
            }
            else{
                cout << "opcion invalida" << endl;
            }
        }
        //añadir km a vehículo o recargar vehiculo
        else if (opcion == 2 || opcion == 3){
            //verificar que hayan vehículos
            if (cochera -> get_vehiculos().empty()){
                cout << endl << "no hay vehiculos todavia" << endl;
            }
            //elegír vehiculo
            else {
                string _marca;
                string _modelo;
                cochera -> print();
                cout << endl << "Marca del vehiculo: ";
                cin >> _marca;
                cout << "Modelo del vehiculo: ";
                cin >> _modelo;
                //buscar vehiculo
                int index = cochera -> buscar_por_nombre(_marca, _modelo);
                //verificar que exista
                if (index == -1){
                    cout << endl << "Vehiculo no encontrado";
                }
                else{
                    Vehiculo* vehiculo = cochera -> get_vehiculos()[index];
                    //opción para agregar km
                    if (opcion == 2){
                        float _km;
                        cout << endl << "¿Cuántos kilómetros recorriste? ";
                        cin >> _km;
                        vehiculo -> stock_loss(_km);
                    }
                    //opcion para recargar
                    else{
                        float _percent;
                        cout << endl << "¿A que porcentaje recargaste el vehículo o cuantos litros de gasolina añadiste? ";
                        cin >> _percent;
                        vehiculo -> restock(_percent);
                    }
                }
            }

        }
        //eliminar coche
        else if (opcion == 4){
            //verificar que hayan vehículos
            if (cochera -> get_vehiculos().empty()){
                cout << "no hay vehiculos todavia" << endl;
            }
            //elegír vehiculo y eliminar
            else {
                string _marca;
                string _modelo;
                cochera -> print();
                cout << endl << "Marca del vehiculo que quieres eliminar: ";
                cin >> _marca;
                cout << "Modelo del vehiculo: ";
                cin >> _modelo;
                cochera -> eliminar(_marca, _modelo);
            }
        }
        //mostar vehiculos
        else if (opcion == 5){
            //verificarq ue hayan vehiculos
            if (cochera -> get_vehiculos().empty()){
                cout << endl << "Aún no hay ningún vehículo" << endl;
            }
            //mostrar vehiculos
            else{
                string opcion_2;
                cochera -> print();
                //solicitar mostrar vehiculo en específico
                cout << endl << "¿Quieres ver un vehículo en específico? (Y / N)";
                cin >> opcion_2;
                string _marca;
                string _modelo;
                //solicitar vehiculo a mostrar
                if (opcion_2 == "Y"){
                    cout << endl << "Marca del vehiculo: ";
                    cin >> _marca;
                    cout << "Modelo del vehiculo: ";
                    cin >> _modelo;
                    int valid;
                    valid = cochera -> buscar_por_nombre(_marca, _modelo);
                    //verificar existencia de vehiculo
                    if (valid != -1){
                        cochera -> get_vehiculos()[valid] -> print();
                    }
                    //mostrar vehiculo
                    else{
                        cout << endl << "no se ha encontrado el vehículo" << endl;
                    }
                }
            }
        }
        //finalizar programa
        else {
            cout << endl << "------------ finalizando programa -----------" << endl;
            break;
        }
    }
    return 0;
}
