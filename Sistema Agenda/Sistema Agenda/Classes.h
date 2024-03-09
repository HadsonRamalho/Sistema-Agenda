#pragma once
#include <string>
#include <vector>

/*struct Conta_Comum {
    std::string email;
    std::string nome;
    std::string senha;
    std::string tipo_de_conta;
};*/

class Produto {
private:
    std::string nome;
    int id;
    float preco;
public:
    Produto() {
        this->nome = "undefined";
        this->id = 0;
        this->preco = 0;
    }
    void atribui_nome(std::string nome) {
        this->nome = nome;
    }
    void atribui_id(int id) {
        this->id = id;
    }
    void atribui_preco(float preco) {
        this->preco = preco;
    }

    void cadastra_produto(Produto Prod) {
        this->nome = Prod.nome;
        this->id = Prod.id;
        this->preco = Prod.preco;
    }

    int retorna_id() {
        return this->id;
    }

    std::string retorna_nome() {
        return this->nome;
    }

    float retorna_preco() {
        return this->preco;
    }
};

class Conta {
private:
    std::string nome_empresa;
    std::string nome;
    std::string email;
    std::string senha;
    std::string tipo_de_conta;
    std::vector<Produto> Prods;
    Produto Temp;
    std::string cnpj;
    int qtd_produtos = 0;
    std::string categoria;
public:
    Conta() {
        this->nome = "undefined";
        this->nome_empresa = "undefined";
        this->qtd_produtos = 0;
        this->categoria = "undefined";
        this->cnpj = "undefined";
        this->tipo_de_conta = "undefined";
        
        this->Temp.atribui_id(0);
        this->Temp.atribui_preco(0);
        this->Temp.atribui_nome("undefined");
        this->Prods.push_back(Temp);
    }

    void atribui_cnpj(std::string cnpj) {
        this->cnpj = cnpj;
    }

    void atribui_nome_empr(std::string nome_empr) {
        this->nome_empresa = nome_empr;
    }

    void modifica_qtd(int qtd);
    int retorna_qtd();
    std::string retorna_nome_empresa() {
        return this->nome_empresa;
    }

    void prod_atribui_nome(std::string nome) {
        this->Prods[qtd_produtos].atribui_nome(nome);
    }

    void prod_atribui_preco(float preco) {
        this->Prods[qtd_produtos].atribui_preco(preco);
    }

    void prod_atribui_id(int id) {
        this->Prods[qtd_produtos].atribui_id(id);
    }
    std::string retorna_categoria() {
        return this->categoria;
    }

    void atribui_categoria(std::string categoria) {
        this->categoria = categoria;
    }

    void cadastra_produto(Produto Prod) {
        this->Prods[qtd_produtos].cadastra_produto(Prod);
    }
    void remove_produto(int id);

    bool busca_produto(Produto Prod) {
        Produto Temp;
        std::string nome_produto;
        for (int i = 0; i < this->qtd_produtos; i++) {
            Temp = Prods.back();
            nome_produto = Temp.retorna_nome();
            if (nome_produto.compare(Prod.retorna_nome()) == 0) {
                return true;
            }
        }
        return false;
    }


    /////////////////////////////////////

    void adicionar_conta(std::string nome, std::string email, std::string senha) {
        this->nome = nome;
        this->email = email;
        this->senha = senha;

    }
    std::string retorna_nome() {
        return this->nome;
    }
    std::string retorna_email() {
        return this->email;
    }

    std::string retorna_senha() {
        return this->senha;
    }
    std::string retorna_tipo_conta() {
        return this->tipo_de_conta;
    }
    void atribui_nome(std::string nome) {
        this->nome = nome;
    }
    void atribui_email(std::string email) {
        this->email = email;
    }
    void atribui_senha(std::string senha) {
        this->senha = senha;
    }

    void atribui_tipo_conta(std::string tipo_conta) {
        this->tipo_de_conta = tipo_conta;
    }


};


class ContaCliente {
private:
    std::string nome;
    std::string email;
    std::string senha;
    std::string tipo_de_conta;
    bool primeiro_login;
public:
    ContaCliente() {
        this->nome = "default";
        this->email = "default";
        this->senha = "default";
        this->tipo_de_conta = "undefined";
        this->primeiro_login = true;
    }
    void adicionar_conta(std::string nome, std::string email, std::string senha) {
        this->nome = nome;
        this->email = email;
        this->senha = senha;

    }
    std::string retorna_nome() {
        return this->nome;
    }
    std::string retorna_email() {
        return this->email;
    }

    std::string retorna_senha() {
        return this->senha;
    }
    std::string retorna_tipo_conta() {
        return this->tipo_de_conta;
    }
    void atribui_nome(std::string nome) {
        this->nome = nome;
    }
    void atribui_email(std::string email) {
        this->email = email;
    }
    void atribui_senha(std::string senha) {
        this->senha = senha;
    }

    void atribui_tipo_conta(std::string tipo_conta) {
        this->tipo_de_conta = tipo_conta;
    }
};

