#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum eStatusPedido { Aguardando, EmProcesso, Concluido };

// Exercício 2 (aula anterior)
class Produto {
private:
  string _nome;
  float _preco;
  int _qtdEstoque;

public:
  Produto(string nome, float preco, int qtdEstoque) {
    this->_nome = nome;
    this->_preco = preco;
    this->_qtdEstoque = qtdEstoque;
  }

  string GetNome() { return this->_nome; }

  float GetPreco() { return this->_preco; }
  void SetPreco(float novoPreco) { this->_preco = novoPreco; }

  int GetEstoque() { return this->_qtdEstoque; }
  void SetEstoque(int novoEstoque) { this->_qtdEstoque = novoEstoque; }
};

class Pedido {
private:
  string _dataCompra;
  string _cpfCliente;
  vector<Produto> _produtos;
  eStatusPedido _status = eStatusPedido::Aguardando;

public:
  Pedido(string cpfCliente, string dataCompra) {
    this->_cpfCliente = cpfCliente;
    this->_dataCompra = dataCompra;
  }

  void PushProduto(Produto *novoProduto) {
    if (novoProduto->GetEstoque() >= 1) {
      novoProduto->SetEstoque(novoProduto->GetEstoque() - 1);
      std::cout << "Adicionado " << novoProduto->GetNome() << " no carrinho!"
                << endl;
    } else {
      std::cout << "Quantidade indisponivel de: " << novoProduto->GetNome()
                << endl;
      return;
    }

    this->_produtos.push_back(*novoProduto);
  }

  void IniciarProcessamento() { this->_status = eStatusPedido::EmProcesso; }
  void FinalizarProcessamento() { this->_status = eStatusPedido::Concluido; }

  eStatusPedido GetStatus() { return this->_status; }

  float GetVlrTotal() {
    float total;
    for (int i = 0; i < this->_produtos.size(); i++) {
      total += this->_produtos[i].GetPreco();
    }

    return total;
  }
};

int main() {
  Produto *arroz = new Produto("arroz", 13.50, 10);
  Produto *agua = new Produto("Agua", 2.50, 3);
  Pedido *pedido = new Pedido("346.479.360-58", "25/08/2023");

  pedido->PushProduto(arroz);
  pedido->PushProduto(arroz);
  pedido->PushProduto(arroz);

  pedido->PushProduto(agua);
  pedido->PushProduto(agua);

  std::cout << "Status pedido: " << pedido->GetStatus() << endl;

  pedido->IniciarProcessamento();

  std::cout << "Status pedido: " << pedido->GetStatus() << endl;

  pedido->FinalizarProcessamento();

  std::cout << "Status pedido: " << pedido->GetStatus() << endl;

  float totalCompra = pedido->GetVlrTotal();

  std::cout << "\nTotal da compra: " << totalCompra << endl;

  return 0;
}