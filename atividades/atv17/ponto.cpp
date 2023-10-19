#include <iostream>
#include <math.h>
using namespace std;

class Ponto{
    float x;
    float y;

    public:
    Ponto(){
        x = 0;
        y = 0;
    }
    Ponto (float _x, float _y){
        x = _x;
        y = _y;
    }
    
    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    void setCoordenadas(double _x, double _y){
        x = _x;
        y = _y;
    }

    double calcularDistancia(){
        double distancia;
        distancia = sqrt(pow(x, 2) + pow(y, 2));
        return distancia;
    }
};

int main(){
    double distancia, distancia_p3, distancia_p4;
    Ponto p1(3, 4);
    Ponto p2(-2, 7);
    Ponto p3(0, 3);
    Ponto p4(4, 0);
    Ponto p5;
    Ponto pontos[3];
    p2.setCoordenadas(1, 1);
    distancia = p1.calcularDistancia();
    cout << "A distancia do ponto (" << p1.getX() << ", " << p1.getY() << ") ate a origem e aproximadamente " << distancia << "." << endl;
    distancia = p2.calcularDistancia();
    cout << "A distancia do ponto (" << p2.getX() << ", " << p2.getY() << ") ate a origem e aproximadamente " << distancia << "." << endl;
    distancia_p3 = p3.calcularDistancia();
    distancia_p4 = p4.calcularDistancia();
    cout << "A distancia do ponto (" << p3.getX() << ", " << p3.getY() << ") ate a origem e " << distancia_p3 << " e do ponto (" << p4.getX() << ", " << p4.getY() << ") ate a origem e " << distancia_p4 << "." << endl;
    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);
    for (int i = 0; i < 3; i++){
        distancia = pontos[i].calcularDistancia();
        cout << "Distancia do ponto " << i+1 << " ate a origem: " << distancia << endl;
    }
    cout << "Coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")." << endl;
    p5.setCoordenadas(8, -3);
    cout << "Novas coordenadas do ponto p5: (" << p5.getX() << ", " << p5.getY() << ")." << endl;
    
    return 0;
}