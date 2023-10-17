#include <iostream> //biblioteca que permite a manipulaçao de entradas e saidas
#include <ctime> //biblioteca que permite a manipulacao de variaveis de tempo

using namespace std;

class Data{
    int dia;
    int mes;
    int ano;
    public:
    //Definindo o dia
    void setDia(int _dia){
        this->dia = _dia;
    }
    //Definindo o mes
    void setMes(int _mes){
        this->mes = _mes;
    }
    //Definindo o ano
    void setAno(int _ano){
        this->ano = _ano;
    }
    //Obtendo o dia
    int getDia(){
        return this->dia;
    }
    //Obtendo o mes
    int getMes(){
        return this->mes;
    }
    //Obtendo o ano
    int getAno(){
        return this->ano;
    }
    //Calculando a idade
    int idade(){
        time_t agora; //declarando uma variavel do tipo time_t
        struct tm *infoTempo; //struct propria da biblioteca time
        time(&agora); 

        // Converte o tempo atual em uma estrutura tm para acessar as variaveis
        infoTempo = localtime(&agora);
        
        int anoAtual = infoTempo->tm_year + 1900; // Obtém o ano atual da estrutura tm
        int mesAtual = infoTempo->tm_mon+1; // Obtém o mes atual da estrutura tm
        int diaAtual = infoTempo->tm_mday; // Obtém o dia atual da estrutura tm

        // Calcula a idade
        int idade = anoAtual - this->ano; //subtrai o ano de nascimento do ano atual
        if(this->mes < mesAtual) //se o mes de nascimento for menor que o mes atual
            idade--; //decrementa um da idade
        if(this->mes == mesAtual){ //se o mes atual e o mes de nascimento forem igual
            if(this->dia < diaAtual) //se o dia de nascimento for menor que o dia atual
                idade--; //decrementa um da idade
        }
        return idade; //retorna a idade do paciente
    }
    //verifica se a data é válida
    bool dataValida(int dia, int mes, int ano){
        if ((mes < 1) || (mes > 12)) //caso a variavel referente ao mes for menor que 1 ou maior que 12
            return false; // retorna false
        int diaMax = 31; //declara um dia maximo 
        if(mes == 2){ //se o mes for fevereiro
            diaMax = 28; //determina o dia maximo como 28
            if(ano%4==0) //se o ano for bissexto (utiliza-se % para obter o resto de uma divisao)
                diaMax = 29; //determina o dia maximo como 29
        }
        if((mes==4) || (mes == 6)|| (mes == 9) || (mes ==11)) //se o mes for abril, junho, setembro ou novembro
            diaMax = 30; //determina o dia maximo como 30
        if((dia >= 1) && (dia <= diaMax)) // verifica se o dia informado é maior ou igual a 1 e menor ou igual ao dia maximo permitido pelo mes
            return true; // retorna verdadeiro
        else return false; //caso contrario retorna falso
        
    }
    //obtendo a data
    Data * leData(){
        Data * novaData = new Data(); //declarando um ponteiro para a nova data
        int _dia, _mes, _ano; 
        do { //inicio do loop
            cout << "Digite o dia, o mes e o ano: " << endl;
            cin.ignore(); //limpa o buffer
            cin >> _dia >> _mes >> _ano; //obtem as variaveis do dia, mes e ano
        } while(!dataValida(_dia, _mes, _ano)); // caso a data informada não seja valida continua o loop
        novaData->setDia(_dia); //determina o dia da nova data
        novaData->setMes(_mes); //determina o mes da nova data
        novaData->setAno(_ano); //determina o ano da nova data
        return novaData; //retorna a data
        /*O professor estava utilizando algumas instruções semelhantes as seguintes:
        dia = _dia;
        mes = _mes;
        ano = _ano;
        porem quando passei de struct para classe algo não estava dando certo e nao descobri a razão por isso
        criei uma nova data para este método e retornei o ponteiro da mesma*/
    }
};

class Paciente{
    string nome;
    string cpf;
    Data *dataNascimento;
    public:
    //obtendo nome do paciente
    string getNome(){
        return this->nome;
    }
    //definindo nome do paciente
    void setNome(string _nome){
        this->nome = _nome;
    }
    //obtendo cpf do paciente
    string getCpf(){
        return this->cpf;
    }
    //definindo cpf do paciente
    void setCpf(string _cpf){
        this->cpf = _cpf;
    }
    //obtendo data de nascimento do paciente
    Data * getDataNascimento(){
        return this->dataNascimento;
    }
    //definindo data de nascimento do paciente
    void setDataNascimento(){
        this->dataNascimento = dataNascimento->leData(); //como o metodo leData retorna uma data igualei a data de nascimento com a data que será lida
    }
};


int main(){
    Paciente *paciente = new Paciente(); //declarando um objteto do tipo paciente
    string nome, cpf;
    cout << "Digite o nome do paciente:" << endl;
    cin.ignore(); //Limpando o buffer
    getline(cin, nome); //obtendo o nome do paciente
    paciente->setNome(nome); //declarando o nome do paciente
    cout << "Digite o cpf do paciente:" << endl;
    cin >> cpf; //obtendo o cpf do paciente
    paciente->setCpf(cpf); //declarando o cpf do paciente
    paciente->setDataNascimento(); //definindo uma data de nascimento
    cout << "O paciente tem " << paciente->getDataNascimento()->idade() << " anos."; //informando a idade do paciente
    //quando chama o metodo getDataNascimento da classe Paciente obtem como retorno um objeto do tipo Data e por isso pode ser acessado o metodo idade da classe Data
    return 0;
}
