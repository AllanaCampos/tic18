#include <iostream>

using namespace std;
double fatorial(double x);

int main(){
    cout << "O fatorial de 3 é: " << fatorial(3) << endl;
    cout << "O fatorial de 7 é: " << fatorial(7) << endl;
    cout << "O fatorial de 12 é: " << fatorial(12) << endl;
    return 0;
}

double fatorial(double x){
    if(x == 1){
        return 1;
    }
    else{
        return x *= fatorial(x-1);
    }
    
}