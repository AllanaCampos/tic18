#include <iostream>
#include <vector>
using namespace std;

struct  Set
{
    vector<string> items;
    
    int putItem(string item){
        if(existeItem(item)){
            return 0;
        }
        items.push_back(item);
        return 1;
    }
    bool existeItem(string item){
        for(string i : items){
            if(i == item){
                return true;
            }
        }
        return false;
    }
    int delItem(string item){
        int aux = 0;
        for(string i : items){
            if(i == item){
                items.erase(items.begin() + aux);
                return 1;
            }
            aux++;
        }
        return 0;
    }
    void showItems(){
        cout << "Exibindo elementos da lista: " << endl;
        for(string i : items){
            cout << i << endl;
        }
    }
    Set Union(Set b){
        Set c;
        c.items = items;
        for(string i : b.items){
            if(!c.existeItem(i)){
                c.putItem(i);
            }
        }
        return c;
    }

    Set intersection(Set b){
        Set c;
        for(string i : b.items){
            if(existeItem(i)){
                c.putItem(i);
            }
        }
        return c;
    }
    Set diference(Set b){
        Set c;
        for(string i : items){
            if(!b.existeItem(i)){
                c.putItem(i);
            }
        }
        return c;
    }
    void emptySet(){
        items.clear();
    }

    bool isEmpty(){
        if(items.size() == 0){
            return true;
        }
        return false;
    }

    bool isEqual(Set b){
        if(items.size() == b.items.size()){
            for(string i : items){
                if(!b.existeItem(i)){
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    Set symetricDifference(Set b){
        Set Ub, Ib;
        Ub = Union(b);
        Ib = intersection(b);
        return Ub.diference(Ib);
    }
};


int main(){
    Set c1, c2, c3, c4, c5;
    c1.putItem("a");
    c1.putItem("b");
    c1.putItem("c");
    c1.putItem("d");

    c2.putItem("d");
    c2.putItem("e");
    c2.putItem("b");
    c2.putItem("c");

    cout << "Uniao" << endl;
    c3 = c1.Union(c2);
    c3.showItems();

    cout << "Intersecao" << endl;
    c4 = c1.intersection(c2);
    c4.showItems();

    cout << "Diferenca" << endl;
    c5 = c1.diference(c4);
    c5.showItems();

    cout << "Empty" << endl;
    c5.emptySet();
    if(c5.isEmpty()){
        cout<< "Vazio" << endl;
    }
    c5.showItems();

    cout << "Igual" << endl;
    c5 = c4;
    if(c5.isEqual(c4)){
        cout<< "Igualzin" << endl;
    }
    c5.showItems();

    cout << "Simetrico" << endl;
    c5 = c1.symetricDifference(c2);
    c5.showItems();


    return 0;
}