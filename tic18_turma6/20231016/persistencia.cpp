#include <fstream> //biblioteca utilizada para manipulacao de arquivos
#include <vector> //biblioteca utilizada para manipulacao de vetores
#include <iostream> //biblioteca utilizada para manipulacao de entradas e saidas
#include <string> //biblioteca utilizada para manipulacao de strings
using namespace std;

class Contato{
    static int cont;
    string nome;
    string telefone;
    string email;
    int cod;

    public:
    Contato(){
        cod = Contato::getContador();
        Contato::incContador();
    }
    static int getContador(){
        return Contato::cont;
    }
    static void incContador(){
        Contato::cont+=1;
    }
    //obtendo nome do contato
    string getNome(){
        return this->nome;
    }
    //obtendo telefone do contato
    string getTelefone(){
        return this->telefone;
    }
    //obtendo email do contato
    string getEmail(){
        return this->email;
    }
    //definindo nome do contato
    void setNome(string nome){
        this->nome = nome;
    }
    //definindo telefone do contato
    void setTelefone(string telefone){
        this->telefone = telefone;
    }
    //definindo email do contato
    void setEmail(string email){
        this->email = email;
    }
    /*void makeFriend(Contato * amigo){
        amigos.push_back(amigo);
        if(amigo->searchFriend(this)){
            amigo->makeFriend(this);
        }
    }

    bool searchFriend(Contato * amigo){
        bool existe = false;
        for (Contato * c : this->amigos){
            if(c == amigo){
                existe = true;
                break;
            }
        }
        return existe;
    }
    void listarAmigos(){
        int contador = 0;
        for(Contato *amigo:this->amigos){
            contador++;
            cout << "Amigo " << contador << endl; //indicando qual contato será informado
            cout << "Nome: " << amigo->getNome() << endl; //imprimindo o nome do contato
            cout << "Telefone: " << amigo->getTelefone() << endl; //imprimindo o telefone do contato
            cout << "Email: " << amigo->getEmail() << endl;
        }
    }*/
    //criando um novo contato 
    static Contato * criar(){
        /*como esta sendo declarado um ponteiro para o contato,
        deve-se utilizar a sintaxe "new Class()" referindo-se 
        ao tipo de objeto que se esta alocando espaço na memoria*/
        Contato *c = new Contato();
        string nome, email, telefone;
        cin.ignore(); //limpando o buffer
        cout << "Digite o nome" << endl;
        getline(cin, nome);
        cout << "Digite o telefone" << endl;
        getline(cin, telefone);
        cout << "Digite o email" << endl;
        getline(cin, email);
        c->setNome(nome); //definindo o nome do novo contato
        c->setEmail(email); //definindo o email do novo contato
        c->setTelefone(telefone); //definindo o telefone do novo contato
        return c;
    }
    //listando os contatos
    static void listar(vector<Contato *> contatos){
        int contador = 0; //definindo um contador
        for(Contato *c : contatos){ //percorrendo o vetor de contatos 
            /*talvez fique mais facil entender o 'for' com este pensamento:
            para cada ponteiro 'c' (que aponta para um espaço da memoria ao qual
            esta alocado um objeto do tipo Contato) presente no vector contatos deve-se
            seguir as instruções abaixo*/
            contador++; //incrementando o contador
            cout << "Contato " << contador << endl; //indicando qual contato será informado
            cout << "Nome: " << c->getNome() << endl; //imprimindo o nome do contato
            cout << "Telefone: " << c->getTelefone() << endl; //imprimindo o telefone do contato
            cout << "Email: " << c->getEmail() << endl; //imprimindo o email do contato
        }
    }
    static Contato * pesquisarContato(vector<Contato*> contatos, int codigo){
        for(Contato *contato: contatos){
            if(contato->getContador() == codigo){
                return contato;
            }
        }
        cout << "Contato não existe" <<endl;
    }
    //listando amigos
    void listarAmigos(vector<Amizade*> amizades, vector<Contato*> contatos){
        cout << "<----------Meus Amigos---------->" << endl;
        for(Amizade *amigos: amizades){
            Contato *contAmigo;
            if(amigos->getCod1() == this->cod){
                contAmigo = Contato::pesquisarContato(contatos, amigos->getCod2());
                cout << "Nome: " << contAmigo->getNome() << endl; //imprimindo o nome do contato
                cout << "Telefone: " << contAmigo->getTelefone() << endl; //imprimindo o telefone do contato
                cout << "Email: " << contAmigo->getEmail() << endl; //imprimindo o email do contato
            }
            if(amigos->getCod2() == this->cod){
                contAmigo = Contato::pesquisarContato(contatos, amigos->getCod2());
                cout << "Nome: " << contAmigo->getNome() << endl; //imprimindo o nome do contato
                cout << "Telefone: " << contAmigo->getTelefone() << endl; //imprimindo o telefone do contato
                cout << "Email: " << contAmigo->getEmail() << endl; //imprimindo o email do contato
            }
        }
    }
};
class Amizade{
    int cod1, cod2;
    public:
    Amizade(int _cod1, int _cod2){
        this->cod1 = _cod1;
        this->cod2 = _cod2;
    }
    int getCod1(){
        return this->cod1;
    }
    int getCod2(){
        return this->cod2;
    }
};
class Persistencia{
    public:
    //metodo que divide uma string em duas e retorna a segunda parte
    static string split(string str, string separator){ //str = string que será dividida; separator = substring de str que será descartada
        int posIni = separator.size(); //calcula o tamanho da string 'separator'
        int tam = str.size() - posIni; //calcula a quantidade de caracteres que a string final obterá
        return str.substr(posIni, tam); //retorna a substring desejada
    }
    //obtendo lista de contatos
    static vector<Contato *> getLista(){
        vector<Contato *> contatos; //criando um vector de ponteiros de Contatos
        ifstream lista; //declarando um arquivo de texto para leitura
        lista.open("Lista_Contatos.txt"); //abrindo o arquivo de texto
        if(lista.is_open()){ //verificando se o arquivo está aberto
            string linha; //declarando uma variavel auxiliar do tipo string
            while(!lista.eof()){ //verifica se não está no fim do arquivo; mesmo que while(lista.eof() == false)
                Contato *c = new Contato(); //declarando um novo contato
                getline(lista, linha); //obtendo a linha do arquivo
                if(linha == "") break; //verificando se a linha está vazia, caso a linha esteja vazia encerra o loop
                c->setNome(Persistencia::split(linha, "Nome: ")); //declarando o nome do contato
                getline(lista, linha);
                c->setTelefone(Persistencia::split(linha, "Telefone: ")); //declarando o telefone do contato
                getline(lista, linha);
                c->setEmail(Persistencia::split(linha, "Email: ")); //declarando o email do contato
                contatos.push_back(c); //adicionando o contato no vector
            }
            lista.close(); //fechando o arquivo de leitura
        }
        else{ //caso o arquivo não tenha sido aberto, logo houve erro e deve-se criar um arquivo inicial
            ofstream nova_Lista; //declarando um arquivo de escrita
            nova_Lista.open("Lista_Contatos.txt"); //abrindo o arquivo de escrita
            nova_Lista.close(); //fechando o arquivo de escrita
        }
        
        return contatos; //retornando o vector
    }
    //salvando a lista de contatos
    static void salvaLista(vector<Contato *> contatos){
        ofstream lista; //declarando um arquivo de escrita 
        lista.open("Lista_Contatos.txt"); //abrindo o arquivo de escrita
        if(lista.is_open()){ //verificando se o arquivo está aberto
            for(Contato * c : contatos){ //percorrendo o vector de contatos
            lista << "Nome: " << c->getNome() << endl; //escrevendo o nome do contato
            lista << "Telefone: " << c->getTelefone() << endl; //escrevendo o telefone do contato
            lista << "Email: " << c->getEmail() << endl; //escrevendo o email do contato
            }
        }
        else  cout << "Não foi possivel criar o arquivo." << endl; //houve algum erro
        lista.close(); //fechando o arquivo
    }

};
int main(){
    vector<Contato *> contatos = Persistencia::getLista(); //declarando o vector de contatos e adicionando os contatos existentes na lista
    vector<Amizade *> amizades;
    char opcao; //declarando uma variavel auxiliar do tipo char
    do{
        cout << "<------------Menu------------>" << endl; //iniciando o menu
        cout << "1- Adicionar contato" << endl; //opcao 1
        cout << "2- Listar contatos" << endl; //opcao 2
        cout << "3- Salvar lista de contatos" << endl; //opcao 3
        cout << "4- Fazer amizade" << endl;
        cout << "0- Sair" << endl; //opcao 0
        cin >> opcao; //obtendo a opcao desejada pelo usuario
        if(opcao == '1'){ //caso a opcao seja 1
            Contato *contato = Contato::criar(); // criando um novo contato
            contatos.push_back(contato); //adicionando o contato na lista
        }
        if(opcao == '2'){ //caso a opcao seja 2
            Contato::listar(contatos); //listando os contatos presentes na lista
        }
        if(opcao == '3'){ //caso a opcao seja 3
            Persistencia::salvaLista(contatos); //salvando a lista de contatos em um arquivo de texto
        }
        if(opcao == '4'){ //caso a opcao seja 4
            int a, b;
            cout << "Digite o codigo dos contatos que farao amizade" << endl;
            cin >> a >> b;
            Amizade *amigos = new Amizade(a, b);
            //contatos.at(a-1)->makeFriend(contatos.at(b-1));
            //contatos.at(a-1)->listarAmigos();
        }
    }while(opcao != '0'); //caso a opcao seja 0 o loop é encerrado, caso contrario o menu reaparece
    return 0;
}
