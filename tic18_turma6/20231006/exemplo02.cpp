#include <iostream>
#include <vector>

using namespace std;

int main(){
    string alunoNome;
    vector<string> colecaoAlunos;
    int quantidadeNotas;
    int quantidadeAlunos;
    float notas;
    vector<vector<float>> colecaoNotas;
    float media;
    float somaNotas=0;
    int i = 1,contAlunos=0;


    cout << "Informe a quantidade de alunos: ";
    cin >> quantidadeAlunos;

    cout << "Quantas notas serão cadastradas? ";
    cin >> quantidadeNotas;

    for(contAlunos=0;contAlunos<quantidadeAlunos;contAlunos++,somaNotas=0){
        
        cout << "Informe o nome do aluno: ";
        getline(cin >> ws, alunoNome);
        colecaoAlunos.push_back(alunoNome);

    /*
        do{
            cout << "Informe a nota " << i << " :";
            cin >> notas;
            i = i+1;
        }while(i <= quantidadeNotas);

    /*
        while(i <= quantidadeNotas){
            cout << "Informe a nota " << i << " :";
            cin >> notas;
            i = i+1;
        }
    */
        vector<float> notasTemp;
        for(i=1;i<=quantidadeNotas;i++){
            cout << "Informe a nota " << i << " :";
            cin >> notas;
            notasTemp.push_back(notas);
            somaNotas = somaNotas+notas;
        }
        colecaoNotas.push_back(notasTemp);

        media = somaNotas/quantidadeNotas;

        cout << "A média das notas é: " << media << endl;

    }

    for(contAlunos=0;contAlunos<quantidadeAlunos;contAlunos++){
        cout << "Notas do Aluno " << colecaoAlunos.at(contAlunos) << endl;
        for(i=0;i<quantidadeNotas;i++){
            cout << colecaoNotas.at(contAlunos).at(i) << endl;
        }
    }

    /*
        Armazenar as notas de um aluno, calcular a média e exibir tudo
            Quantas notas? Informado pelo usuário
            Qual tipo de nota? 0.0 .. 10.0

            1 - Informar o nome do aluno

            2 - Informar a quantidade de notas

            3 - Coletar todas as notas

            4 - Calcular a média e exibir

            5 - Exibir todas as notas novamente

            6 - Adaptar o problema para n alunos guardando o histórico
    */

    return 0;
}