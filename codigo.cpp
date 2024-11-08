#include <iostream>
using namespace std;

class Camion{
    //atributos
    private:
        string marca;
        string modelo;
        float gasolina; // en litros
        int gasolina_max = 100; // en litros
    //métodos
    public:
        // Constructor
        Camion(string _marca, string _modelo, float _gasolina){
            marca = _marca;
            modelo = _modelo;
            gasolina = _gasolina;
        }
        void print_atributos(){
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl; 
            cout << "gasolina: " << gasolina << endl; 
            cout << "gasolina_max: " << gasolina_max << endl; 
        }
        //metodos especiales
        void restock(){
            gasolina = gasolina_max;
        }
};

class Moto{
    //atributos
    private:
        string marca;
        string modelo;
        float gasolina; // en litros
        int gasolina_max = 8; // en litros
    //métodos
    public:
        // Constructor
        Moto(string _marca, string _modelo, float _gasolina){
            marca = _marca;
            modelo = _modelo;
            gasolina = _gasolina;
        }
        void print_atributos(){
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl; 
            cout << "gasolina: " << gasolina << endl; 
            cout << "gasolina_max: " << gasolina_max << endl; 
        }
        //metodos especiales
        void restock(){
            gasolina = gasolina_max;
        }
};

class Coche{
    //atributos
    private:
        string marca;
        string modelo;
        float gasolina; // en litros
        int gasolina_max = 50; // en litros
    //métodos
    public:
        // Constructor
        Coche(string _marca, string _modelo, float _gasolina){
            marca = _marca;
            modelo = _modelo;
            gasolina = _gasolina;
        }
        void print_atributos(){
            cout << "marca: " << marca << endl;
            cout << "modelo: " << modelo << endl; 
            cout << "gasolina: " << gasolina << endl; 
            cout << "gasolina_max: " << gasolina_max << endl; 
        }
        //metodos especiales
        void restock(){
            gasolina = gasolina_max;
        }
};

int main (){
    string marca_;
    string modelo_;
    float gasolina_;

    cout << "¿cuál es la marca del camion? ";
    cin >> marca_;
    cout << "¿cual es el modelo? ";
    cin >> modelo_;
    cout << "¿cuantos litros de gasolina tiene? ";
    cin >> gasolina_;
    Camion Camion_1 = Camion(marca_, modelo_, gasolina_);
    Camion_1.print_atributos();

    cout << endl << "¿cuál es la marca del coche? ";
    cin >> marca_;
    cout << "¿cual es el modelo? ";
    cin >> modelo_;
    cout << "¿cuantos litros de gasolina tiene? ";
    cin >> gasolina_;
    Coche Coche_1 = Coche(marca_, modelo_, gasolina_);
    Coche_1.print_atributos();

    cout << endl << "¿cuál es la marca de la moto? ";
    cin >> marca_;
    cout << "¿cual es el modelo? ";
    cin >> modelo_;
    cout << "¿cuantos litros de gasolina tiene? ";
    cin >> gasolina_;
    Moto Moto_1 = Moto(marca_, modelo_, gasolina_);
    Moto_1.print_atributos();
    return 0;
}