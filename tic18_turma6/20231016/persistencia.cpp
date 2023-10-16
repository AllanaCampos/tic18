#include <fstream>
#include <vector>
#include <iostream>
using namespace std;

class Contato{
    string nome;
    string telefone;
    string email;

    public:

    string getNome(){
        return this->nome;
    }
    string getTelefone(){
        return this->telefone;
    }
    string getEmail(){
        return this->email;
    }

    void setNome(string nome){
        this->nome = nome;
    }
    void setTelefone(string telefone){
        this->telefone = telefone;
    }
    void setEmail(string email){
        this->email = email;
    }

    static Contato * adicionar(){
        Contato *c = new Contato();
        string nome, email, telefone;
        cout << "Digite o nome" << endl;
        cin.ignore();
        getline(cin, nome);
        cout << "Digite o telefone" << endl;
        getline(cin, telefone);
        cout << "Digite o email" << endl;
        getline(cin, email);
        c->setNome(nome);
        c->setEmail(email);
        c->setTelefone(telefone);
        return c;
    }

};

int main(){
    vector<Contato *> contatos;
    Contato *contato = Contato::adicionar();
    
    contatos.push_back(contato);
    for(Contato * c :contatos){

    }
    
    return 0;
}