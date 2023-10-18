#include <fstream> //biblioteca utilizada para manipulacao de arquivos
#include <vector> //biblioteca utilizada para manipulacao de vetores
#include <iostream> //biblioteca utilizada para manipulacao de entradas e saidas
#include <string> //biblioteca utilizada para manipulacao de strings
#include <math.h> //biblioteca utilizda para operacoes matematicas
using namespace std;

class Contato{
    static int cont; //contador
    string nome;
    string telefone;
    string email;
    int cod; //codigo

    public:
    //construtor
    Contato(){
        cod = Contato::getContador(); //codigo recebe o valor do contador
        Contato::incContador(); //contador é incrementado
    }
    //quando se chama um metodo ou atributo que é static utiliza-se a sintaxe "Classe::metodo/atributo"
    //obtem valor do contador
    static int getContador(){
        return Contato::cont;
    }
    //incrementa contador
    static void incContador(){
        Contato::cont+=1;
    }
    //obtendo o codigo do contato
    int getCodigo(){
        return this->cod;
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
            cout << "Codigo: " << c->getCodigo() << endl;
            cout << "Nome: " << c->getNome() << endl; //imprimindo o nome do contato
            cout << "Telefone: " << c->getTelefone() << endl; //imprimindo o telefone do contato
            cout << "Email: " << c->getEmail() << endl; //imprimindo o email do contato
        }
    }
    //pesquisando um contato dentro da lista de contatos
    static int pesquisarContato(vector<Contato*> contatos, int codigo){
        int posicao = -1; //indicará a posicao do contato na lista
        int aux = -1; //variavel auxiliar
        for(Contato *contato: contatos){
            aux++; //contará a posicao que estamos no vector
            if(contato->getCodigo() == codigo){ //verifica se o codigo do contato é igual ao codigo do contato que se procura
                posicao = aux; //caso o contato tenha sido encontrado é indicado a posicao do vector para a variavel 'posicao'
                return posicao; //retorna posicao
            }
        }
        return posicao; //quando não foi encontrado o contato retorna -1
    }
    
};
class Amizade{
    int cod1, cod2; //codigo dos amigos
    public:
    //construtor
    Amizade(int _cod1, int _cod2){
        this->cod1 = _cod1;
        this->cod2 = _cod2;
    }
    //obtem codigo do amigo1
    int getCod1(){
        return this->cod1;
    }
    //obtem codigo do amigo2
    int getCod2(){
        return this->cod2;
    }
    //listando amigos
    static void listarAmigos(Contato *c, vector<Amizade*> amizades, vector<Contato*> contatos){
        int codigo = c->getCodigo(); //obtem o codigo do contato que deseja-se listar os amigos
        int posicao; //indicara a posicao na lista que seus amigos estarao
        for(Amizade *amigos: amizades){ //percorrendo a lista de amizades
            Contato *contAmigo; //declarando um ponteiro para o contato que é amigo do contato 'c'
            if(amigos->getCod1() == codigo){ //verifica se o codigo do amigo1 entre a amizade é igual ao codigo de 'c'
                posicao = Contato::pesquisarContato(contatos, amigos->getCod2()); //obtem a posicao no vector de contatos do contato amigo de 'c'
                contAmigo = contatos.at(posicao); //obtem o amigo de 'c'
                cout << "Nome: " << contAmigo->getNome() << endl; //imprimindo o nome do amigo
                cout << "Telefone: " << contAmigo->getTelefone() << endl; //imprimindo o telefone do amigo
                cout << "Email: " << contAmigo->getEmail() << endl; //imprimindo o email do amigo
            }
            if(amigos->getCod2() == codigo){ //verifica se o codigo do amigo2 entre a amizade é igual ao codigo de 'c'
                posicao = Contato::pesquisarContato(contatos, amigos->getCod1()); //obtem a posicao no vector de contatos do contato amigo de 'c'
                contAmigo = contatos.at(posicao); //obtem o amigo de 'c'
                cout << "Nome: " << contAmigo->getNome() << endl; //imprimindo o nome do amigo
                cout << "Telefone: " << contAmigo->getTelefone() << endl; //imprimindo o telefone do amigo
                cout << "Email: " << contAmigo->getEmail() << endl; //imprimindo o email do amigo
            }
        }
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
    //metodo que obtem uma string e retorna o valor em inteiro
    static int getCodigo(string str){
        int codigo = 0;
        int tam = str.length();
        for (int i = 0; i <tam; i++){
            codigo += pow(10, tam-i-1) * (str[i] - '0');
        }
        return codigo;
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
    //obtendo lista de amigos
    static vector<Amizade *> getAmizades(){
        vector<Amizade *> amizades; //criando um vector de ponteiros de Amizades
        ifstream lista; //declarando um arquivo de texto para leitura
        lista.open("Lista_Amigos.txt"); //abrindo o arquivo de texto
        if(lista.is_open()){ //verificando se o arquivo está aberto
            string linha; //declarando uma variavel auxiliar do tipo string
            while(!lista.eof()){ //verifica se não está no fim do arquivo; mesmo que while(lista.eof() == false)
                Amizade *amigos; //declarando uma nova dupla de amigos
                getline(lista, linha); //obtendo a linha do arquivo
                if(linha == "") break; //verificando se a linha está vazia, caso a linha esteja vazia encerra o loop
                int cod1 = Persistencia::getCodigo(Persistencia::split(linha, "Codigo1: ")); //obtendo o codigo do amigo1
                int cod2 = Persistencia::getCodigo(Persistencia::split(linha, "Codigo2: ")); //obtendo o codigo do amigo2
                amigos = new Amizade(cod1, cod2); //inicializando a amizade
                amizades.push_back(amigos); //adicionando a amizade no vector
            }
            lista.close(); //fechando o arquivo de leitura
        }
        else{ //caso o arquivo não tenha sido aberto, logo houve erro e deve-se criar um arquivo inicial
            ofstream nova_Lista; //declarando um arquivo de escrita
            nova_Lista.open("Lista_Amigos.txt"); //abrindo o arquivo de escrita
            nova_Lista.close(); //fechando o arquivo de escrita
        }
        
        return amizades; //retornando o vector
    }
    //salvando a lista de amizades
    static void salvaAmizades(vector<Amizade *> amizades){
        ofstream lista; //declarando um arquivo de escrita 
        lista.open("Lista_Amigos.txt"); //abrindo o arquivo de escrita
        if(lista.is_open()){ //verificando se o arquivo está aberto
            for(Amizade * a : amizades){ //percorrendo o vector de contatos
            lista << "Codigo1: " << a->getCod1() << endl; //escrevendo o codigo do primeiro amigo
            lista << "Codigo2: " << a->getCod2() << endl; //escrevendo o codigo do segundo amigo
            }
        }
        else  cout << "Não foi possivel criar o arquivo." << endl; //houve algum erro
        lista.close(); //fechando o arquivo
    }
};
int Contato::cont = 0;
int main(){
    vector<Contato *> contatos = Persistencia::getLista(); //declarando o vector de contatos e adicionando os contatos existentes na lista
    vector<Amizade *> amizades = Persistencia::getAmizades();
    char opcao; //declarando uma variavel auxiliar do tipo char
    do{
        cout << "<------------Menu------------>" << endl; //iniciando o menu
        cout << "1- Adicionar contato" << endl; //opcao 1
        cout << "2- Listar contatos" << endl; //opcao 2
        cout << "3- Salvar lista de contatos" << endl; //opcao 3
        cout << "4- Fazer amizade" << endl; //opcao 4
        cout << "5- Listar amigos" << endl; //opcao 5
        cout << "6- Salvar lista de amigos" << endl; //opcao 6
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
            cin >> a >> b; //obtem o codigo dos contatos
            Amizade *amigos = new Amizade(a, b); //declara e inicializa uma nova amizade
            amizades.push_back(amigos); //adiciona a amizade no vetor de amizades
        }
        if(opcao == '5'){ //caso a opcao seja 5
            int codigo, posicao;
            cout << "Digite o codigo do contato que deseja verificar a lista de amigos" << endl;
            cin >> codigo; //obtem o codigo do contato
            posicao = Contato::pesquisarContato(contatos, codigo); //obtem a posicao do contato no vector
            if(posicao > -1){ //caso o contato esteja no vetor
                Amizade::listarAmigos(contatos.at(posicao), amizades, contatos); //lista amigos do contato
            }
            else{ //caso não tenha sido encontrado o contato no vector
                cout << "Contato nao encontrado" << endl;
            }
        }
        if(opcao == '6'){ //caso a opcao seja 6
            Persistencia::salvaAmizades(amizades); //salvando a lista de amizades em um arquivo de texto
        }
    }while(opcao != '0'); //caso a opcao seja 0 o loop é encerrado, caso contrario o menu reaparece
    return 0;
}
