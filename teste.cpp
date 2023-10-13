#include <iostream>

using namespace std;

int main(){
    char ch;
    cin >> ch;
    int ch1 = int(ch);

    if (ch1 >= 'A' && ch1<='Z'){
        ;cout << "Letra maiuscula" << endl;
    }else if(ch1 >= 'a' && ch1<='z'){
        cout << "Letra maiuscula" << endl;
    }else if(ch1 >= '0' && ch1<='9'){
        cout << "numero" << endl;
    }else cout << "outro" << endl;
    return 0;
}