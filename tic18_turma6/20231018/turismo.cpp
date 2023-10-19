#include <iostream>
#include <vector>

using namespace std;

class Cliente{
    string nome, cpf;
    
    public:
        Cliente(string _nome, string _cpf){
            this->nome = _nome;
            this->cpf  = _cpf;
        }
        
        string getNome(){
            return this->nome;
        }

        void setNome(string _nome){
            this->nome = _nome;
        }

        void setCpf(string _cpf){
            this->cpf = _cpf;
        }

        string getCpf(){
            return this->cpf;
        }
};

class Dependente{
    string nome;
    Cliente *responsavel;
    public:
        Dependente(string _nome, Cliente *_responsavel){
            this->nome = _nome;
            this->responsavel = _responsavel;
        }
        string getNome(){
            return this->nome;
        }
        void setNome(string _nome){
            this->nome = _nome;
        }
        Cliente* getResponsavel(){
            return this->responsavel;
        }
        void setResponsavel(Cliente *_responsavel){
            this->responsavel = _responsavel;
        }
};

class Evento{
    protected:
        int duracao;

        Evento(int _duracao){
            this->duracao = _duracao;
        }

        void setDuracao(int _duracao){
            this->duracao = _duracao;
        }

        int getDuracao(){
            return this->duracao;
        }
    public:
        virtual void imprimir()=0;
};

class Roteiro : public Evento{
    string titulo;
    int ordem;
    public:
        Roteiro(int _duracao, string _titulo, int _ordem):Evento(_duracao){
            this->titulo = _titulo;
            this->ordem = _ordem;
        }
        string getTitulo(){
            return this->titulo;
        }
        void setTitulo(string _titulo){
            this->titulo = _titulo;
        }
        int getOrdem(){
            return this->ordem;
        }
        void setOrdem(int _ordem){
            this->ordem = _ordem;
        }
        void imprimir() override{
            cout << "<----------Roteiro---------->" << endl;
            cout << "Titulo: " << this->titulo << endl;
            cout << "Ordem: " << this->ordem << endl;
            cout << "Duracao: " << this->duracao << endl;
        }

};

class Deslocamento : public Evento{
    string origem;
    string destino;
    public:
        Deslocamento(int _duracao, string _origem, string _destino):Evento(_duracao){
            this->origem = _origem;
            this->destino = _destino;
        }
        string getOrigem(){
            return this->origem;
        }
        void setOrigem(string _origem){
            this->origem = _origem;
        }
        string getDestino(){
            return this->destino;
        }
        void setDestino(string _destino){
            this->destino = _destino;
        }
        void imprimir() override{
            cout << "<----------Deslocamento---------->" << endl;
            cout << "Origem: " << this->origem << endl;
            cout << "Destino: " << this->destino << endl;
            cout << "Duracao: " << this->duracao << endl;
        }

};

class Pernoite : public Evento{
    string local;
    public:
        Pernoite(int _duracao,string _local=""):Evento(_duracao){
            this->local = _local;
        }
        string getLocal(){
            return this->local;
        }
        void setLocal(string _local){
            this->local = _local;
        }
        void imprimir() override{
            cout << "<----------Pernoite---------->" << endl;
            cout << "Local: " << this->local << endl;
            cout << "Duracao: " << this->duracao << endl;
        }
};

class Pacote{
    private:
        vector<Evento*> listaEventos;
    
    public:
        Pacote(Evento *_evento){
            listaEventos.push_back(_evento);
        }

        void inserirEvento(Evento *_evento){
            listaEventos.push_back(_evento);
        }

        void listarEventos(){
            for(Evento *evento:listaEventos){
                evento->imprimir();
            }
        }
};

class Reserva{
    Cliente *cliente;
    Pacote *pacote;
    public:
        Reserva(Cliente *_cliente, Pacote *_pacote){
            this->cliente = _cliente;
            this->pacote = _pacote;
        }
        Cliente *getCliente(){
            return this->cliente;
        }
        void setCliente(Cliente *_cliente){
            this->cliente = _cliente;
        }
        Pacote *getPacote(){
            return this->pacote;
        }
        void setPacote(Pacote *_pacote){
            this->pacote = _pacote;
        }
};

int main(){
    
    Cliente *cli01 = new Cliente("Bruno","111111");
    Dependente *dep01 = new Dependente("Leane",cli01);
    Dependente *dep02 = new Dependente("Vinicius", cli01);

    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    cli01->setNome("Bruno Santana");
    
    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    Roteiro *r1 = new Roteiro(4,"Noite no Parque do Povo",1);

    Deslocamento *d1 = new Deslocamento(1,"Hotel","Noite Parque do Povo");

    Pernoite *p1 = new Pernoite(10, "Hotelzinho");

    Pacote *bronze = new Pacote(r1); //polimorfismo
    bronze->inserirEvento(d1);
    bronze->inserirEvento(p1);

    Reserva *reserva01 = new Reserva(cli01,bronze);

    bronze->listarEventos();
    
    return 0;
}