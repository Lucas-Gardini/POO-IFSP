#include <iostream>

using namespace std;

class ContaBancaria {
private:
  static int _lastIndex;
  static int _totalAccounts;
  static float _globalBalance;

  int _id;
  float _totalBalance;

public:
  ContaBancaria(float initialBalance) {
    ContaBancaria::_lastIndex++;

    this->_id = ContaBancaria::_lastIndex;
    this->_totalBalance = initialBalance;

    ContaBancaria::_globalBalance += initialBalance;
    ContaBancaria::_totalAccounts++;
  }
  ~ContaBancaria() {
    ContaBancaria::_globalBalance -= this->_totalBalance;
    ContaBancaria::_totalAccounts--;
  }

  void Deposit(float amount) {
    this->_totalBalance += amount;
    ContaBancaria::_globalBalance += amount;
  }

  bool Withdraw(float amount) {
    if (this->_totalBalance <= amount)
      return false;

    this->_totalBalance -= amount;
    ContaBancaria::_globalBalance -= amount;

    return true;
  }

  float GetAccountBalance() { return this->_totalBalance; }

  static float GetTotalBalance() { return ContaBancaria::_globalBalance; }

  static int GetTotalOpenedAccounts() { return ContaBancaria::_totalAccounts; }
};

int ContaBancaria::_lastIndex = 0;
int ContaBancaria::_totalAccounts = 0;
float ContaBancaria::_globalBalance = 0;

int main() {
  ContaBancaria *conta1 = new ContaBancaria(500);
  ContaBancaria *conta2 = new ContaBancaria(100);
  ContaBancaria *conta3 = new ContaBancaria(2700);

  conta1->Deposit(200);
  bool success = conta2->Withdraw(150);

  if (success)
    std::cout << "Saque concluido!" << endl;
  else
    std::cout << "Saldo indisponivel!" << endl;

  float total = ContaBancaria::GetTotalBalance();
  std::cout << "Saldo total: " << total << endl;

  float accounts = ContaBancaria::GetTotalOpenedAccounts();
  std::cout << "Total de contas abertas: " << accounts << endl;

  delete conta3;

  float totalAfter = ContaBancaria::GetTotalBalance();
  std::cout << "Saldo total (depois de fechar a conta 3): " << totalAfter
            << endl;

  float accountsAfter = ContaBancaria::GetTotalOpenedAccounts();
  std::cout << "Total de contas abertas: " << accountsAfter << endl;
}