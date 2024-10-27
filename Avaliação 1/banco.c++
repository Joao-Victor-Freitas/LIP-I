#include <iostream>
#include <string>
using namespace std;

class Cliente
{
private:
    string nome;
    string cpf;

public:
    // Construtor do cliente
    Cliente(string nome, string cpf) : nome(nome), cpf(cpf) {}

    // Método get utilizado para acessar o nome e o CPF
    string getNome() const { return nome; }
    string getCpf() const { return cpf; }
};

class ContaBancaria
{
private:
    int numero;
    double saldo;
    Cliente titular;

public:
    // Construtor da Conta Bancária
    ContaBancaria(int numero, Cliente titular, double saldo = 0.0) : numero(numero), titular(titular), saldo(saldo) {}

    // Método para realizar um deposito na conta
    void depositar(double valor)
    {
        saldo += valor;
    }

    // Método para sacar valor da conta
    void sacar(double valor)
    {
        if (saldo >= valor)
        {
            saldo -= valor;
            cout << "Sacado: R$ " << valor << " da conta " << numero << endl;
        }
        else
        {
            cout << "Saldo insuficiente para saque na conta " << numero << endl;
        }
    }

    // Método para realizar a transferência entre contas
    void transferir(double valor, ContaBancaria &destino)
    {
        if (saldo >= valor)
        {
            saldo -= valor;
            destino.depositar(valor);
            cout << "Transferido: R$ " << valor << " da conta " << numero << " para a conta " << destino.numero << endl;
        }
        else
        {
            cout << "Saldo insuficiente para transferência da conta " << numero << endl;
        }
    }

    // Método para realizar a transferência para duas contas ao mesmo tempo
    void transferir(double valor, ContaBancaria &destino1, ContaBancaria &destino2)
    {
        if (saldo >= valor)
        {
            double metade = valor / 2;
            saldo -= valor;
            destino1.depositar(metade);
            destino2.depositar(metade);
            cout << "Transferido: R$ " << metade << " para cada conta (" << destino1.numero << " e " << destino2.numero << ") da conta " << numero << endl;
        }
        else
        {
            cout << "Saldo insuficiente para transferência da conta " << numero << endl;
        }
    }

    // Método para exibir o saldo atual da conta
    void exibirSaldo() const
    {
        cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
    }

    // Método para exibir as informações do titular e da conta
    void exibirInformacoes() const
    {
        cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() << endl;
        cout << "Número da Conta: " << numero << ", Saldo: R$ " << saldo << endl;
    }
};

int main()
{
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2, 832.50);
    ContaBancaria conta3(1003, cliente3, 1531.10);

    // Exibe o saldo inicial da conta
    conta1.exibirSaldo();
    conta2.exibirSaldo();
    conta3.exibirSaldo();

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Bruno transfere R$135,50 para Carla
    conta2.transferir(135.50, conta3);

    // Carla transfere R$530 para Ana
    conta3.transferir(531.13, conta1);

    // Ana transfere R$300 divididos entre Bruno e Carla
    conta1.transferir(300.0, conta2, conta3);

    // Bruno transfere R$355 divididos entre Ana e Carla
    conta2.transferir(355.0, conta1, conta3);

    // Carla transfere R$831,70 divididos entre Ana e Bruno
    conta3.transferir(831.70, conta1, conta2);

    // Exibição dos saldos finais
    cout << endl;
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}
