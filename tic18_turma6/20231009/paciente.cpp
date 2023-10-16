#include <iostream>

using namespace std;

class Data{
    int dia;
    int mes;
    int ano;
    public:
    void setDia(int _dia){
        this->dia = _dia;
    }
    void setMes(int _mes){
        this->mes = _mes;
    }
    void setAno(int _ano){
        this->ano = _ano;
    }
    int getDia(){
        return this->dia;
    }
    int getMes(){
        return this->mes;
    }
    int getAno(){

        return this->ano;
    }
    int idade (Data *atual){
        int idade = atual->ano - this->ano;
        if (atual->mes < this->mes){
            idade --;
        }
        if((atual->mes == this->mes)&& (atual->dia < this->dia)){
            idade --;
        }
        return idade;
    }

    bool dataValida(int dia, int mes, int ano){
        if ((mes < 1) || (mes > 12))
            return false;
        int diaMax = 31;
        if(mes == 2){
            diaMax = 28;
            if(ano%4==0)
                diaMax = 29;
        }
        if((mes==4) || (mes == 6)|| (mes == 9) || (mes ==11))
            diaMax = 30;
        if((dia >= 1) && (dia <= diaMax))
            return true;
        else return false;
        
    }

    void leData(){
        int _dia, _mes, _ano;
        do {
            cout << "Digite o dia, o mes e o ano: " << endl;
            cin >> _dia >> _mes >> _ano;
        } while(!dataValida(_dia, _mes, _ano));
        dia = _dia;
        mes = _mes;
        ano = _ano;
    }
};

class Paciente{
    string nome;
    string cpf;
    Data dataNascimento;
    public:
    string getNome(){
        return this->nome;
    }
    void setNome(string _nome){
        this->nome = _nome;
    }
    string getCpf(){
        return this->cpf;
    }
    void setCpf(string _cpf){
        this->cpf = _cpf;
    }
    Data getDataNascimento(){
        return this->dataNascimento;
    }
    void setDataNascimento(Data _data){
        this->dataNascimento = _data;
    }
};



int main(){
    Data *dataAtual = new Data();
    dataAtual->setDia(9);
    dataAtual->setMes(10);
    dataAtual->setAno(2023);
    Paciente *paciente;
    string nome, cpf;
    cout << "Digite o nome do paciente:" << endl;
    getline(cin, nome);
    paciente->setNome(nome);
    cout << "Digite o cpf do paciente:" << endl;
    cin >> cpf;
    paciente->setCpf(cpf);
    paciente->getDataNascimento();//dataNascimento->leData();
    //cout << "O paciente tem " << paciente->dataNascimento.idade(dataAtual);
    return 0;
}