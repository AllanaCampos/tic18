#include <iostream>
#include <string>

using namespace std;

class Carro{
    int numPortas;
    public:
    string tipo;
    string cor;
    string placa;
    
    void setNumPortas (int _numPortas){
        if(_numPortas < 1){
            cout << "Numero invalido de portas, atribuindo 1";
            this->numPortas = 1;
        }
        else this->numPortas = _numPortas;
    }
    int getNumPortas(){
        return this->numPortas;
    }
    void acelerar (float _velocidade){
        cout << "Acelerando para " << _velocidade << " km/h" << endl;
    }

    void frear (){
        cout << "Freando" << endl;
    }
};

int main(){
    Carro *civic = new Carro();
    civic->tipo = "sedan";
    civic->setNumPortas(1);
    cout << civic->tipo << endl;
    //cout << civic->cor << endl;
    cout << "O numero de portas e: " << civic->getNumPortas() << endl;
    civic->acelerar(30);
    civic->frear();
    return 0;
}

