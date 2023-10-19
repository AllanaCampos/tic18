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
class teste{
    map<Produto *, int> estoque;
    public:
    //Verificar a quantidade no estoque de determinado produto
    int getQuantidadeProduto(Produto *_produto){
        for(auto tupla: this->estoque){
            if(tupla.first->getNome() == _produto->getNome()){
                return tupla.second;
            }
        }
        return 0;
    }
    //Definir a quantidade no estoque para um determinado produto
    void setQuantidadeProduto(Produto *_produto, int quantidade){
        for(auto tupla: this->estoque){
            if(tupla.first->getNome() == _produto->getNome()){
                tupla.second = quantidade;
            }            
        }
    }
    //listar
    void listarEstoque(){
        for(auto tupla: this->estoque){
            cout << tupla.first->getNome() << ", " << tupla.second << endl;          
        }
    }
    //Incluir um produto no estoque informando a quantidade de produtos a serem armazenados
    void incluirProdutoNoEstoque(Produto * _produto, int quantidade){
        int find = 0;
        for(auto tupla: this->estoque){
            if(tupla.first->getNome() == _produto->getNome()){
                tupla.second += quantidade;
                find = 1;
                break;
            }         
        }
        //Caso o produto nao exista adicionar o produto e a quantidade informada
        if(find == 0)
            estoque.insert(make_pair(_produto, quantidade));
    }
    //Verificar se existe produto o suficiente no estoque para venda
    bool permitirRetirada(Produto* _produto, int quantidade){
        for(auto tupla: this->estoque){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == _produto->getNome()){
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
class Estoque{
    vector <Produto> produtos;
    vector <int> quantidades;
    public:
    Estoque(){}
    //Verificar a quantidade no estoque de determinado produto
    int getQuantidadeProduto(Produto produto){
        for(int i = 0; i< produtos.end()-produtos.begin(); i++){
        if(produto.getNome() == produtos.at(i).getNome())
            return quantidades.at(i);
        }
        return 0;
    }
    //Definir a quantidade no estoque para um determinado produto
    void setQuantidadeProduto(Produto produto, int quantidade){
        for(size_t i = 0; i < produtos.size(); ++i){
        if(strcmp(produto.getNome().c_str(), produtos.at(i).getNome().c_str()) == 0){
            quantidades.at(i) = quantidade; 
            break;
        }
            
        }
    }
    //Incluir um produto no estoque informando a quantidade de produtos a serem armazenados
    void incluirProdutoNoEstoque(Produto produto, int quantidade){
        //Caso o produto já exista apenas alterar a quantidade
        for(size_t i = 0; i < produtos.size(); ++i){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(strcmp(produto.getNome().c_str(), produtos.at(i).getNome().c_str()) == 0){
                quantidades.at(i) += quantidade; break;
            }
        }
        //Caso o produto nao exista adicionar o produto e a quantidade informada
        produtos.push_back(produto);
        quantidades.push_back(quantidade);
    }
    //Verificar se existe produto o suficiente no estoque para venda
    bool permitirRetirada(Produto produto, int quantidade){
        for(size_t i = 0; i < produtos.size(); ++i){
        //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
        if(strcmp(produto.getNome().c_str(), produtos.at(i).getNome().c_str()) == 0){
            //Caso a quantidade existente no estoque seja maior que a desejada, permite e retira a quantidade desejada
            if(quantidades.at(i) >= quantidade){
                quantidades.at(i) -= quantidade;
                return true;
            }
        }
        }
        return false;
    }
    //Inventario do estoque
    void verificarEstoque(){
        cout << "O estoque contem: " << endl;
        for(size_t i = 0; i < produtos.size(); ++i){
            cout << produtos.at(i).getNome() << " X " << quantidades.at(i) << endl;
        }
    }
};
class Supermercado{
    vector<Produto> produtos;
    Estoque estoque;
    public:
    Supermercado(vector<Produto> _produtos, Estoque _estoque){
        produtos = _produtos;
        estoque = _estoque;
    }
    //Indica a quantidade disponivel de um produto para compra
    int permitirCompra(Produto produto, int quantidade){
        //Caso o estoque não possua quantidade de produto que supra o desejo do cliente ele fornece a maior quantidade possivel exitente no estoque
        while((!estoque.permitirRetirada(produto, quantidade)) && (quantidade > 0)){
            quantidade--;
        }
        return quantidade;
    }
    //Devolvendo produtos ao estoque que nao foram comprados
    void devolverProduto(Produto produto, int quantidade){
        estoque.incluirProdutoNoEstoque(produto, quantidade);
    }

    //Adicionar produtos no mercado
    void adicionarProdutos(Produto produto, int quantidade){
        produtos.push_back(produto);
        estoque.incluirProdutoNoEstoque(produto, quantidade);
    }

    //Repor estoque do mercado mantendo todos os produtos com 20 qantidades cada
    void reporEstoque(){
        for(size_t i = 0; i < produtos.size(); ++i){
            estoque.setQuantidadeProduto(produtos.at(i), 20);
        }
    }
    //Verificar o inventario
    void inventario(){
        estoque.verificarEstoque();
    }
};

class CarrinhoDeCompras{
    map<Produto*, int> meuCarrinho;
    vector <Produto> produtos;
    vector <int> quantidades;
    vector <Produto>::iterator it;
    public:
    CarrinhoDeCompras(){}
    //Adicionando produtos ao carrinho
    void adicionarProduto(Produto * _produto, int quantidade){ 
        bool add = true;
        for(auto tupla: this->meuCarrinho){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == _produto->getNome()){
                //existindo o produto no carrinho apenas aumenta a quantidade do mesmo
                tupla.second += quantidade;
                add = false;
                break;
            }
        }
        //nao existindo o produto no carrinho adiciona o produto e a quantidade ao mesmo
        if(add){
            this->meuCarrinho.insert(make_pair(_produto, quantidade));
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
    void removerProduto(Produto* _produto, int quantidade){
        for(auto tupla: this->meuCarrinho){
        //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(tupla.first->getNome() == _produto->getNome()){
                if(tupla.second > quantidade){
                    //Caso a quantidade de produto existente no carrinho seja igual a quantidade de produto que se deseja retirar, apaga o produto do carrinho
                    if(tupla.second == quantidade){
                        //this->meuCarrinho.erase(tupla);
                        //this->meuCarrinho.extract(tupla);
                        //this->meuCarrinho.
                        //produtos.erase(produtos.begin()+i);
                        //quantidades.erase(quantidades.begin()+i);
                    }
                    //Caso a quantidade de produto existente no carrinho seja maior a que se deseja retirar, apenas diminui a quantidade existente
                    //else quantidades.at(i) -= quantidade;
                }
                break;
            }
        }
    }
    void esvaziarCarrinho(){
        produtos.clear();
        quantidades.clear();
    }
    //retorna a quantidade de produto existente em um carrinho
    int getQuantidadeProduto(Produto produto){
        for(size_t i = 0; i < produtos.size(); ++i){
            //Comparando as strings referentes aos nomes dos produtos, caso forem iguais a funcao strcmp retorna 0
            if(strcmp(produto.getNome().c_str(), produtos.at(i).getNome().c_str()) == 0){
                return quantidades.at(i);
            }
        }
        return 0;
    }
    //Exibe os produtos e as quantidades de cada um presente no carrinho
    void exibirCarrinho(){
        cout << "Carrinho de compras: " << endl;
        for(size_t i = 0; i < produtos.size(); ++i){
            cout << " - " << produtos.at(i).getNome() << " ("<< produtos.at(i).getPreco() <<") X " << quantidades.at(i) << endl;
        }
    }
};  

/*int main(){
    vector<Produto> produtos;
    Estoque estoque;
    Supermercado mercadinho(produtos, estoque);
    Produto p1("Maca", 2.5);
    Produto p2("Arroz", 10.0);
    Produto p3("Leite", 4.0);
    Produto p4("Chocolate", 3.0);
    mercadinho.adicionarProdutos(p1, 20); 
    mercadinho.adicionarProdutos(p2, 20); 
    mercadinho.adicionarProdutos(p3, 20); 
    mercadinho.adicionarProdutos(p4, 5);
    
    CarrinhoDeCompras carrinho;
    int quantidade = mercadinho.permitirCompra(p1, 3);
    carrinho.adicionarProduto(p1, quantidade);
    quantidade = mercadinho.permitirCompra(p2, 2);
    carrinho.adicionarProduto(p2, quantidade);
    quantidade = mercadinho.permitirCompra(p3, 1);
    carrinho.adicionarProduto(p3, quantidade);

    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total da compra: " << valorTotal << endl;

    carrinho.removerProduto(p2, 1);
    mercadinho.devolverProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total apos remocao: " << valorTotal << endl;

    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total apos esvaziar o carrinho: " << valorTotal << endl;
    
    quantidade = mercadinho.permitirCompra(p4, 10);
    carrinho.adicionarProduto(p4, quantidade);
    cout << "Quantidade de chocolate no carrinho: " << carrinho.getQuantidadeProduto(p4) << endl;

    carrinho.esvaziarCarrinho();
    mercadinho.reporEstoque();

    quantidade = mercadinho.permitirCompra(p1, 2);
    carrinho.adicionarProduto(p1, quantidade);
    quantidade = mercadinho.permitirCompra(p2, 3);
    carrinho.adicionarProduto(p2, quantidade);
    quantidade = mercadinho.permitirCompra(p3, 1);
    carrinho.adicionarProduto(p3, quantidade);
    quantidade = mercadinho.permitirCompra(p4, 2);
    carrinho.adicionarProduto(p4, quantidade);
    carrinho.exibirCarrinho();
    return 0;
}*/
int main(){
    Produto *p1 = new Produto("arroz", 5);
    teste *testezinho = new teste();
    testezinho->incluirProdutoNoEstoque(p1, 5);
    testezinho->listarEstoque();
    return 0;
}