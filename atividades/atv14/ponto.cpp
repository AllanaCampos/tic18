#include <iostream>
#include <math.h>
using namespace std;
struct ponto
{
    int X;
    int Y;
};
double calcularDistancia(ponto a, ponto b){
        double distancia;
        distancia = sqrt(pow(b.X - a.X, 2) + pow(b.Y - a.Y, 2));
        return distancia;
    }
int main(){
    ponto p1, p2;
    p1.X = 2;
    p1.Y = -3;
    p2.X = 4;
    p2.Y = 5;
    cout << calcularDistancia(p1, p2);
    return 0;
}