#include <iostream>

using namespace std;

void menu();
double toFarenheit(double celsius);
int main(){
    menu();
    return 0;
}

double toFahrenheit(double celsius){
    double F = celsius * 1.8 + 32;
    return F;
}

void menu(){
    int opcao, temp;
    do{
        cout << "1- Converter em Fahrenheit" << endl;
        cout << "2- Sair" << endl;
        cin >> opcao;
        if(opcao == 1){
            cout << "Digite a temperatura em Celsius" << endl;
            cin >> temp;
            cout << "A temperatura " << temp << " em Fahrenheit eh: " << toFahrenheit(temp) << endl;
        }
    }while(opcao != 2);
    

}