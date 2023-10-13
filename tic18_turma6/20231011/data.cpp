#include <iostream>
#include <ctime>

using namespace std;

// Programação estruturada
struct Data{
    int dia; //1 - 31
    int mes; //1 - 12
    int ano; //1 ... 2023++

    int hora; // 0 - 23
    int minuto; // 0 - 59
    int segundos; // 0 - 59
};
typedef struct Data Data;

void imprimir_data(Data _data){
    cout << _data.dia << "/";
    cout << _data.mes << "/";
    cout << _data.ano << endl;
}

struct Professor{
    string nome;
    Data dt_nascimento;
    string cpf;
    string matricula;
    string salario;
};
typedef struct Professor Professor;

struct Aluno{
    string nome;
    Data dt_nascimento;
    string cpf;
    string matricula;
    string craa;
    Professor professor;
};
typedef struct Aluno Aluno;

void imprimir_aluno(Aluno _aluno){
    cout << "Nome: " << _aluno.nome << endl;
    cout << "CPF: " << _aluno.cpf << endl;
    cout << "Nascimento: ";
    imprimir_data(_aluno.dt_nascimento);
    cout << "Matricula: " << _aluno.matricula << endl;
    cout << "CRAA: " << _aluno.craa << endl;
    cout << "Professor: " << _aluno.professor.nome << endl;
}

// Equivalente, mas em Orientação a Objeto
class ClasseData{
    public:
        int dia; //1 - 31
        int mes; //1 - 12
        int ano; //1 ... 2023++

        int hora; // 0 - 23
        int minuto; // 0 - 59
        int segundos; // 0 - 59

        void imprimir_data(){
            cout << dia << "/";
            cout << mes << "/";
            cout << ano << endl;
        }
};

class ClasseProfessor{
    public:
        string nome;
        ClasseData *dt_nascimento;
        string cpf;
        string matricula;
        string salario;
};

class ClasseAluno{
    public:
        string nome;
        ClasseData *dt_nascimento;
        string cpf;
        string matricula;
        string craa;
        ClasseProfessor *professor;

        void imprimir(){
            cout << "Nome: " << nome << endl;
            cout << "CPF: " << cpf << endl;
            cout << "Nascimento: ";
            dt_nascimento->imprimir_data();
            cout << "Matricula: " << matricula << endl;
            cout << "CRAA: " << craa << endl;
            cout << "Professor: " << professor->nome << endl;
        }

        int calcularIdade(){
            // Obtém o ano atual
            time_t agora;
            struct tm *infoTempo;
            time(&agora);

            // Converte o tempo atual em uma estrutura tm para acessar o ano
            infoTempo = localtime(&agora);

            // Obtém o ano atual da estrutura tm
            int anoAtual = infoTempo->tm_year + 1900;
            int mesAtual = infoTempo->tm_mon+1;
            int diaAtual = infoTempo->tm_mday;

            // Calcula a idade
            int idade = anoAtual - dt_nascimento->ano;
            if(dt_nascimento->mes < mesAtual)
                idade--;
            if(dt_nascimento->mes == mesAtual){
                if(dt_nascimento->dia < diaAtual)
                    idade--;
            }

            return idade;
            
            /*
                1 - conhecer a data atual
                    1.1 conhecer o ano
                    1.2 conhecer o mes
                    1.3 conhecer o dia
                2 - conhecer o ano de nascimento
                3 - se o mes de nascimento é maior que atual
                    3.1 - idade = ano atual - nascimento
                4 - se o mes de nascimento é menor
                    4.1 - idade = ano atual - nascimento -1
                5 - se o mes de nasimento é igual ao atual
                    5.1 - se o dia de nascimento é maior ou igual que o atual
                        5.1.1 - idade = ano atual - nascimento
                    4 - se o dia de nascimento é menor
                        5.1.2 - idade = ano atual - nascimento -1
            */
        }
};



int main(){
    Aluno alu_1;
    Professor prof_1;

    alu_1.nome = "Caio";
    alu_1.dt_nascimento.ano = 1997;
    alu_1.dt_nascimento.mes = 3;
    alu_1.dt_nascimento.dia = 4;
    
    imprimir_aluno(alu_1);

    prof_1.nome = "Hélder";
    prof_1.dt_nascimento.ano = 1987;
    prof_1.dt_nascimento.mes = 9;
    prof_1.dt_nascimento.dia = 24;

    cout << prof_1.nome << endl;
    imprimir_data(prof_1.dt_nascimento);


    ClasseProfessor *prof_OO = new ClasseProfessor();
    prof_OO->nome = "Degas";

    ClasseAluno *aluno_oo = new ClasseAluno();
    aluno_oo->nome = "Rafaela";
    aluno_oo->matricula = "20232163";
    aluno_oo->professor = prof_OO;
    aluno_oo->dt_nascimento = new ClasseData();
    aluno_oo->dt_nascimento->ano = 1994;
    aluno_oo->dt_nascimento->mes = 10;
    aluno_oo->dt_nascimento->dia = 23;
    aluno_oo->imprimir();

    prof_OO->nome = "Álvaro Coelho";

    aluno_oo->imprimir();

    cout << "Idade: ";
    cout << aluno_oo->calcularIdade() << endl;

    return 0;
}