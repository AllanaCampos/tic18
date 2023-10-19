#include <iostream>
#include <vector>
#include <map>
#include <string.h>
using namespace std;

class Produto{
    string nome;
    double preco;
    public:
    Produto (string _nome, double _preco){
        this->nome = _nome;
        this->preco = _preco;
    }
    string getNome() {
        return this->nome;
    }
    void setNome(string _nome){
        this->nome = _nome;
    }
    double getPreco() {
        return this->preco;
    }
    void setPreco(double _preco){
        this->preco = _preco;
    }
};
class Estoque{
    map<Produto *, int> estoque;
    public:
    //Verificar a quantidade no estoque de determinado produto
    int getQuantidadeProduto(Produto *produto){
        for(auto tupla : this->estoque){
            if(tupla.first->getNome() == produto->getNome()){
                return tupla.second;
            }
        }
        return 0;
    }
    //Definir a quantidade no estoque para um determinado produto
    void setQuantidadeProduto(Produto *produto, int quantidade){
        for(auto tupla : this->estoque){
            if(tupla.first->getNome() == produto->getNome()){
                tupla.second = quantidade;
            }            
        }
    }
    //listar
    void listarEstoque(){
        for(auto tupla : this->estoque){
            cout << tupla.first->getNome() << ", " << tupla.second << endl;          
        }
    }
    //Incluir um produto no estoque informando a quantidade de produtos a serem armazenados
    void incluirProdutoNoEstoque(Produto * produto, int quantidade){
        int find = 0;
        for(auto tupla : this->estoque){
            if(tupla.first->getNome() == produto->getNome()){
                tupla.second += quantidade;
                find = 1;
                break;
            }         
        }
        //Caso o produto nao exista adicionar o produto e a quantidade informada
        if(find == 0)
            estoque.insert(make_pair(produto, quantidade));
    }
    //Verificar se existe produto o suficiente no estoque para venda
    bool permitirRetirada(Produto* produto, int quantidade){
        for(auto tupla : this->estoque){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == produto->getNome()){
                //Caso a quantidade existente no estoque seja maior que a desejada, permite e retira a quantidade desejada
                if(tupla.second >= quantidade){
                    tupla.second -= quantidade;
                    return true;
                }
            }
        }
        return false;
    }

};
class Supermercado{
    vector<Produto *> produtos;
    Estoque *estoque;
    public:
    Supermercado(){}
    //Indica a quantidade disponivel de um produto para compra
    int permitirCompra(Produto * produto, int quantidade){
        //Caso o estoque não possua quantidade de produto que supra o desejo do cliente ele fornece a maior quantidade possivel exitente no estoque
        while((!estoque->permitirRetirada(produto, quantidade)) && (quantidade > 0)){
            quantidade--;
        }
        return quantidade;
    }
    //Devolvendo produtos ao estoque que nao foram comprados
    void devolverProduto(Produto *produto, int quantidade){
        estoque->incluirProdutoNoEstoque(produto, quantidade);
    }

    //Adicionar produtos no mercado
    void adicionarProdutos(Produto *produto, int quantidade){
        produtos.push_back(produto);
        estoque->incluirProdutoNoEstoque(produto, quantidade);
    }

    //Repor estoque do mercado mantendo todos os produtos com 20 qantidades cada
    void reporEstoque(){
        for(Produto *p : produtos){
            estoque->setQuantidadeProduto(p, 20);
        }
    }
    //Verificar o inventario
    void inventario(){
        estoque->listarEstoque();
    }
};
class CarrinhoDeCompras{
    map<Produto*, int> meuCarrinho;
    public:
    CarrinhoDeCompras(){}
    //Adicionando produtos ao carrinho
    void adicionarProduto(Produto * produto, int quantidade){ 

        bool add = true;
        for(auto tupla: this->meuCarrinho){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == produto->getNome()){
                //existindo o produto no carrinho apenas aumenta a quantidade do mesmo
                this->meuCarrinho.at(tupla.first) += quantidade;
                add = false;
                break;
            }
        }
        //nao existindo o produto no carrinho adiciona o produto e a quantidade ao mesmo
        if(add){
            this->meuCarrinho.insert(make_pair(produto, quantidade));
        }
    }
    //Calcula o valor total das comprar do carrinho
    double calcularValorTotal(){
        double tot = 0;
        for(auto tupla: this->meuCarrinho){
            tot += tupla.first->getPreco() * tupla.second;
        }
        return tot;
    }
    //Remove um produto do carrinho
    void removerProduto(Produto* produto, int quantidade){
        for(auto tupla: this->meuCarrinho){
        //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == produto->getNome()){
                //Caso a quantidade de produto existente no carrinho seja igual a quantidade de produto que se deseja retirar, apaga o produto do carrinho
                if(tupla.second == quantidade){
                    this->meuCarrinho.erase(tupla.first);
                }
                if(tupla.second > quantidade){
                    //Caso a quantidade de produto existente no carrinho seja maior a que se deseja retirar, apenas diminui a quantidade existente
                    this->meuCarrinho.at(tupla.first) -= quantidade;
                }
                break;
            }
        }
    }
    void esvaziarCarrinho(){
        meuCarrinho.clear();
    }
    //retorna a quantidade de produto existente em um carrinho
    int getQuantidadeProduto(Produto * produto){
        for(auto tupla : meuCarrinho){
            if(tupla.first->getNome() == produto->getNome()){
                return tupla.second;
            }
        }
        return 0;
    }
    //Exibe os produtos e as quantidades de cada um presente no carrinho
    void exibirCarrinho(){
        cout << "Carrinho de compras: " << endl;
        for(auto tupla : meuCarrinho){
            cout << " - " << tupla.first->getNome() << " ("<< tupla.first->getPreco() <<") X " << tupla.second << endl;
        }
    }
};  

int main(){
    Supermercado *mercadinho = new Supermercado();
    Produto *p1 = new Produto("Maca", 2.5);
    Produto *p2 = new Produto("Arroz", 10.0);
    Produto *p3 = new Produto("Leite", 4.0);
    Produto *p4 = new Produto("Chocolate", 3.0);
    mercadinho->adicionarProdutos(p1, 20); 
    mercadinho->adicionarProdutos(p2, 20); 
    mercadinho->adicionarProdutos(p3, 20); 
    mercadinho->adicionarProdutos(p4, 5);
    
    CarrinhoDeCompras *carrinho = new CarrinhoDeCompras();
    int quantidade = mercadinho->permitirCompra(p1, 3);
    carrinho->adicionarProduto(p1, quantidade);
    quantidade = mercadinho->permitirCompra(p2, 2);
    carrinho->adicionarProduto(p2, quantidade);
    quantidade = mercadinho->permitirCompra(p3, 1);
    carrinho->adicionarProduto(p3, quantidade);

    double valorTotal = carrinho->calcularValorTotal();
    cout << "Valor total da compra: " << valorTotal << endl;
    
    carrinho->removerProduto(p2, 1);
    mercadinho->devolverProduto(p2, 1);
    valorTotal = carrinho->calcularValorTotal();
    cout << "Valor total apos remocao: " << valorTotal << endl;

    carrinho->esvaziarCarrinho();
    valorTotal = carrinho->calcularValorTotal();
    cout << "Valor total apos esvaziar o carrinho: " << valorTotal << endl;
    
    quantidade = mercadinho->permitirCompra(p4, 10);
    carrinho->adicionarProduto(p4, quantidade);
    cout << "Quantidade de chocolate no carrinho: " << carrinho->getQuantidadeProduto(p4) << endl;

    carrinho->esvaziarCarrinho();
    mercadinho->reporEstoque();

    quantidade = mercadinho->permitirCompra(p1, 2);
    carrinho->adicionarProduto(p1, quantidade);
    quantidade = mercadinho->permitirCompra(p2, 3);
    carrinho->adicionarProduto(p2, quantidade);
    quantidade = mercadinho->permitirCompra(p3, 1);
    carrinho->adicionarProduto(p3, quantidade);
    quantidade = mercadinho->permitirCompra(p4, 2);
    carrinho->adicionarProduto(p4, quantidade);
    carrinho->exibirCarrinho();
    return 0;
}
