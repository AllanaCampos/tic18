#include <iostream>
#include <string>

using namespace std;

class Carro{
    protected:
    int numPortas;
    bool numPortasIsValid(int _numPortas){
        bool flag = false;
        flag = (_numPortas >= 1 && _numPortas <= 7);
        return flag;
    }
    public:
    string tipo;
    string cor;
    string placa;
    
    void setNumPortas (int _numPortas){
        this->numPortas = (this->numPortasIsValid(_numPortas)) ? _numPortas : 1;
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
class Hatch : public Carro{
    public:
    void imprimirNumPortas(){
        cout << numPortas << endl;
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

    Hatch carro1;
    carro1.setNumPortas(4);
    carro1.imprimirNumPortas();
    return 0;
}

