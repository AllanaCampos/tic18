#include <iostream>

using namespace std;

#define N 10

int main(){
    string alunoNome;
    string colecaoAlunos[N];
    int quantidadeNotas;
    int quantidadeAlunos;
    float notas;
    float colecaoNotas[N][N];
    float media;
    float somaNotas=0;
    int i = 1,contAlunos=0;


    cout << "Informe a quantidade de alunos: ";
    cin >> quantidadeAlunos;

    cout << "Quantas notas serão cadastradas? ";
    cin >> quantidadeNotas;

    if(quantidadeNotas > N){
        cout << "Erro! Maior que capacidade do vetor" << endl;
        exit(-1);
    }

    for(contAlunos=0;contAlunos<quantidadeAlunos;contAlunos++,somaNotas=0){
        
        cout << "Informe o nome do aluno: ";
        getline(cin >> ws, colecaoAlunos[contAlunos]);

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
        for(i=1;i<=quantidadeNotas;i++){
            cout << "Informe a nota " << i << " :";
            cin >> notas;
            colecaoNotas[i-1][contAlunos] = notas;
            somaNotas = somaNotas+notas;
        }

        media = somaNotas/quantidadeNotas;

        cout << "A média das notas é: " << media << endl;

    }

    for(contAlunos=0;contAlunos<quantidadeAlunos;contAlunos++){
        cout << "Notas do Aluno " << colecaoAlunos[contAlunos] << endl;
        for(i=0;i<quantidadeNotas;i++){
            cout << colecaoNotas[i][contAlunos] << endl;
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