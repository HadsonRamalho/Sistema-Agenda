#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Produto {
private:
    string nome;
    int id;
    float preco;
public:
    Produto() {
        this->nome = "default";
        this->id = 0;
        this->preco = 0;
    };
    void atribui_nome(string nome);
    void atribui_id(int id);
    void atribui_preco(float preco);
    void cadastra_produto(Produto Prod);
};

void Produto::atribui_nome(string nome) {
    this->nome = nome;
}

void Produto::atribui_id(int id) {
    this->id = id;
}

void Produto::atribui_preco(float preco) {
    this->preco = preco;
}

class Conta_Comerciante {
private:
    string nome_empresa;
    Produto Prod;
    int qtd_produtos;
    string categoria;
public:
    Conta_Comerciante() {
        this->nome_empresa="default";
        this->qtd_produtos = 0;
        this->categoria = "default";

        this->Prod.atribui_id(0);
        this->Prod.atribui_preco(0);
        this->Prod.atribui_nome("default");
        this->qtd_produtos = 1;
    }
    void cadastra_produto(Produto Prod);
    void remove_produto(int id);
    Produto busca_produto(Produto Prod);
    void atribui_nome(string nome_empr);
    void modifica_qtd(int qtd);
    int retorna_qtd();
    string retorna_nome_empresa();
    void prod_atribui_nome(string nome);
    void prod_atribui_preco(float preco);
    void prod_atribui_id(int id);
    string retorna_categoria();
    void atribui_categoria(string categoria);
};

void Conta_Comerciante::atribui_categoria(string categoria) {
    this->categoria = categoria;
}

string Conta_Comerciante::retorna_categoria() {
    return this->categoria;
}

string Conta_Comerciante::retorna_nome_empresa() {
    return this->nome_empresa;
}

void Conta_Comerciante::prod_atribui_nome(string nome){
	this->Prod.atribui_nome(nome);
}

void Conta_Comerciante::prod_atribui_id(int id){
	this->Prod.atribui_id(id);
}

void Conta_Comerciante::prod_atribui_preco(float preco){
	this->Prod.atribui_preco(preco);
}

void Conta_Comerciante::atribui_nome(string nome_empr){
	this->nome_empresa = nome_empr;
}

void Produto::cadastra_produto(Produto Prod) {
    this->id = Prod.id;
    this->preco = Prod.preco;
    this->nome = Prod.nome;
}

class Conta {
private:
    string nome;
    string email;
    string senha;
    string tipo_de_conta;
    bool primeiro_login;
public:
    Conta() {
        this->nome = "default";
        this->email = "default";
        this->senha = "default";
        this->tipo_de_conta = "undefined";
        this->primeiro_login = true;
    }
    void adicionar_conta(string nome, string email, string senha);
    string retorna_nome();
    string retorna_email();
    string retorna_senha();
    string retorna_tipo_conta();
    void atribui_nome(string nome);
    void atribui_email(string email);
    void atribui_senha(string senha);
};

string Conta::retorna_nome() {
    return this->nome;
}

string Conta::retorna_email() {
    return this->email;
}

string Conta::retorna_senha() {
    return this->senha;
}

string Conta::retorna_tipo_conta() {
    return this->tipo_de_conta;
}

void Conta::adicionar_conta(string nome, string email, string senha) {
    this->nome = nome;
    this->email = email;
    this->senha = senha;

}

void Conta::atribui_email(string email) {
    this-> email = email;
}

void Conta::atribui_nome(string nome) {
    this-> nome = nome;
}

void Conta::atribui_senha(string senha) {
    this->senha = senha;
}

bool email_valido(string email);

Conta criar_conta() {
    Conta Usuario_Temporario;
    cout << "\tMENU DE CRIACAO DE CONTA" << endl
         << " | Insira seu nome: " << endl;
    string nome_usuario;
    cin >> nome_usuario;
    cout << " | Insira seu email: " << endl;
    string email_usuario;
    cin >> email_usuario;
    email_valido(email_usuario);
    string senha_usuario_parte1;
    string senha_usuario_parte2;
    bool senha_valida = false;
    do {
        cout << " | Insira sua senha: " << endl;
        cin >> senha_usuario_parte1;
        cout << " | Confirme sua senha: " << endl;
        cin >> senha_usuario_parte2;
        if (senha_usuario_parte1.compare(senha_usuario_parte2) != 0) {
            cerr << "Senhas diferentes. Digite novamente!" << endl;
            senha_valida = false;
        }
        else {
            senha_valida = true;
        }
    } while (!senha_valida);
    string senha_usuario = senha_usuario_parte1;
    Usuario_Temporario.adicionar_conta(nome_usuario, email_usuario, senha_usuario);
    cout << " Sucesso na criacao da conta!" << endl
         << " | Nome: " << nome_usuario << endl
         << " | Email: " << email_usuario << endl;
    return Usuario_Temporario;
}

void listar_contas(Conta Contas[], const int cadastros) {
    for (int i = 0; i < cadastros; i++) {
        cout << "-------------------" << endl;
        cout << Contas[i].retorna_nome() << endl;
        cout << Contas[i].retorna_email() << endl;
    }
}

void redefinir_senha_login() {
    cout << "\tMENU DE REDEFINICAO DE SENHA" << endl
         << " | Digite seu email: " << endl;
    string email_recuperacao;
    cin >> email_recuperacao;
    int codigo_verificacao[5];
    cout << " | Codigo de verificacao: " << endl;
    srand((unsigned)time(NULL));
    for (int i = 0; i < 5; i++) {
        codigo_verificacao[i] = 0 + (rand() % 10);
        cout << codigo_verificacao[i];
        if (i != 4) {
            cout << " | ";
        }
    }
    cout << " | Digite o codigo de verificao: ";
    int codigo_usuario[5];
    for (int i = 0; i < 5; i++) {
        cin >> codigo_usuario[i];
    }
    bool codigo_valido = false;
    for (int i = 0; i < 5; i++) {
        if (codigo_usuario[i] != codigo_verificacao[i]) {
            codigo_valido = false;
            cerr << " | Codigo invalido" << endl;
            break;
        }
        cout << " | Codigo valido! " << endl;
    }
}

int verifica_cadastro_email(Conta Contas[], int &cadastros, string email) {
    for(int i = 0; i < cadastros; i++) {
        if(Contas[i].retorna_email().compare(email) == 0) {
            return i;
        }
    }
    return -1;
}

bool email_existe(Conta Contas[], int &cadastros, string email) {
    for(int i = 0; i < cadastros; i++) {
        if(Contas[i].retorna_email().compare(email) == 0) {
            return true;
        }
    }
    return false;
}

bool email_valido(string email) {
    int indice = email.find("@gmail.com");
    while(indice == -1) {
        cerr << " | Email invalido. Digite novamente: ";
        cin >> email;
        indice = email.find("@gmail.com");
    }
    return true;
}

int verifica_cadastro_senha(Conta Contas[], int&cadastros, string senha) {
    for(int i = 0; i < cadastros; i++) {
        if(Contas[i].retorna_senha().compare(senha) == 0) {
            return i;
        }
    }
    return -1;
}

void menu_login(Conta Contas[], int &cadastros) {
    string opcao;
    string email_login;
    string senha_login;
    Conta Conta_Temp;
    do {
        cout << "\tMENU DE LOGIN" << endl
             << " 1 | Tenho conta" << endl
             << " 2 | Nao tenho conta" << endl
             << " [DEV] 3 | Listar contas" << endl
             << " [DEV] 4 | Sair" << endl;
        cin >> opcao;
        switch (opcao[0]) {
        case '1':
            cout << " | Insira seu email: ";
            cin >> email_login;
            email_valido(email_login);
            while (!email_existe(Contas, cadastros, email_login)) {
                cerr << " | Email incorreto! Digite novamente: ";
                cin >> email_login;
                email_valido(email_login);
                email_existe(Contas, cadastros, email_login);
            }
            cout << " | Insira sua senha [-1 para 'Esqueci minha senha']: ";
            cin >> senha_login;
            if (senha_login.compare("-1") == 0) {
                redefinir_senha_login();
            }
            else {
                if(verifica_cadastro_senha(Contas, cadastros, senha_login) != -1) {
                    cout << " | Login realizado com sucesso!" << endl;
                }
                else {
                    // while(verifica_cadastro_senha(Contas, cadastros, senha_login) != -1){
                    cerr << " | Senha incorreta. Digite novamente: ";
                    cin >> senha_login;
                }
            }
            break;
        case '2':
            Conta_Temp = criar_conta();
            Contas[cadastros].adicionar_conta(Conta_Temp.retorna_nome(), Conta_Temp.retorna_email(), Conta_Temp.retorna_senha());
            cadastros++;
            break;
        case '3':
            listar_contas(Contas, cadastros);
            break;
        default:
            cerr << "Opcao invalida. Saindo!" << endl;
            opcao[0] = '-1';
        }

    } while (opcao[0] == '4' || opcao[0] == '-1');

}

void inicializaLista(Conta Contas[], int max_contas, int &qtd_cadastros) {
    string initEm = "user @gmail.com";
    string initNo = "nome ";
    string initSe = "senha ";
    char indice[1];
    for(int i = 0; i < 4; i++) {
        indice[0] = i + 48;
        initEm[4] = indice[0];
        initNo[4] = indice[0];
        initSe[5] = indice[0];
        Contas[i].atribui_email(initEm);
        Contas[i].atribui_nome(initNo);
        Contas[i].atribui_senha(initSe);
        cout << "Nome: " << Contas[i].retorna_nome() << endl;
        cout << "Email: " << Contas[i].retorna_email() << endl;
        cout << "Senha: " << Contas[i].retorna_senha() << endl;
        cout << "----------------" << endl;
        qtd_cadastros = i;
    }
}

// inicializar C_C, PROD
void inicializaContaComerc(Conta_Comerciante Contas[], int &qtd_cadastros){
        for(int i = 0; i < 5; i++){
           // cria_produto(Contas[i]);
        	Contas[i].atribui_nome("Conta" + i + 48);
    }
}

void Conta_Comerciante::modifica_qtd(int qtd){
	this->qtd_produtos += qtd;
}

int Conta_Comerciante::retorna_qtd(){
	return this->qtd_produtos;
}

void cria_produto(Conta_Comerciante &Conta) {
    cout << " | Digite o nome do produto: ";
    string nome_prod;
    cin >> nome_prod;
    cout << " | Digite o valor do produto: ";
    float preco_prod;
    cin >> preco_prod;
    while(preco_prod < 0) {
        cerr << " | Valor do produto nao pode ser menor que zero. Digite novamente: ";
        cin >> preco_prod;
    }
    Conta.prod_atribui_nome(nome_prod); //Prod.atribui_nome(nome_prod);
    Conta.prod_atribui_preco(preco_prod);
    Conta.modifica_qtd(1);
    Conta.prod_atribui_id(Conta.retorna_qtd());
}

void inicializaContasC(Conta_Comerciante Contas[], int qtd_cadastros){
	for(int i = 0; i < qtd_cadastros; i++){
        Contas[i].atribui_nome("Empr");
        Contas[i].atribui_categoria("Artesanato");
    }
}

void inicializa_categorias(string categorias[]) {
    categorias[0] = "Artesanato";
    categorias[1] = "Bar";
    categorias[2] = "Roupas";
    categorias[3] = "Servicos";
    categorias[4] = "Sorveterias";
}

void interface_inicial_sistema(Conta_Comerciante ContasC[]) {
    cout << "\tCATEGORIAS" << endl;
    string categorias[5];
    inicializa_categorias(categorias);
    ContasC[0].atribui_categoria("Artesanato");
    ContasC[0].atribui_nome("Empresa0");
    for (int i = 0; i < 5; i++) {
        cout << categorias[i] << endl << "-------------" << endl;
        if (categorias[i].compare(ContasC[i].retorna_categoria()) == 0) {
            cout << " | " << ContasC[i].retorna_nome_empresa() << endl << "------------" << endl;
        }
    }
}

int main() {
    int max_cadastros = 100;
    Conta *Contas = new Conta[max_cadastros];
    Conta_Comerciante* ContasC = new Conta_Comerciante[max_cadastros];
    int qtd_cadastros = 0;
    int qtd_cadastrosC = 0;
    inicializaLista(Contas, max_cadastros, qtd_cadastros);
    inicializaContasC(ContasC, qtd_cadastrosC);
    //menu_login(Contas, qtd_cadastros);
   // menu_login(Contas, qtd_cadastros);
    interface_inicial_sistema(ContasC);
    delete[] Contas;
    return 0;
}