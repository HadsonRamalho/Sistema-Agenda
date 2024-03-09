#include<stdlib.h>
#include<time.h>
#include "Dev-Dados.h"

using namespace std;

Conta criar_conta() {
    Conta Usuario_Temporario;
    std::cout << "\tMENU DE CRIACAO DE CONTA" << endl
         << " | Insira seu nome: " << endl;
    string nome_usuario;
    cin >> nome_usuario;
    cout << " | Insira seu email: " << endl;
    string email_usuario;
    cin >> email_usuario;
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

void listar_contas(vector<Conta> Contas, const int cadastros) {
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

bool email_existe(vector<Conta> Contas, int &cadastros, string email) {
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

int verifica_cadastro_senha(vector<Conta> Contas, int&cadastros, string senha) {
    for(int i = 0; i < cadastros; i++) {
        if(Contas[i].retorna_senha().compare(senha) == 0) {
            return i;
        }
    }
    return -1;
}

void menu_login(vector<Conta> Contas, int &cadastros) {
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
                if() { //Comparar senhas
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
            //Contas[cadastros].adicionar_conta(Conta_Temp.retorna_nome(), Conta_Temp.retorna_email(), Conta_Temp.retorna_senha());
            Contas.push_back(Conta_Temp);
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

void inicializaLista(vector<Conta> &Contas, int max_contas, int &qtd_cadastros) {
    string initEm = "user @gmail.com";
    string initNo = "nome ";
    string initSe = "senha ";
    char indice[1];
    Conta Conta_Temp;
    for(int i = 0; i < 4; i++) {
        indice[0] = i + 48;
        initEm[4] = indice[0];
        initNo[4] = indice[0];
        initSe[5] = indice[0];
        Conta_Temp.atribui_email(initEm);
        Conta_Temp.atribui_nome(initNo);
        Conta_Temp.atribui_senha(initSe);
        Contas.push_back(Conta_Temp);
        cout << "Nome: " << Contas[i].retorna_nome() << endl;
        cout << "Email: " << Contas[i].retorna_email() << endl;
        cout << "Senha: " << Contas[i].retorna_senha() << endl;
        cout << "----------------" << endl;
        qtd_cadastros = i;
    }
}

// inicializar C_C, PROD
void inicializaContaComerc(Conta Contas[], int &qtd_cadastros){
        for(int i = 0; i < 5; i++){
           // cria_produto(Contas[i]);
        	Contas[i].atribui_nome("Conta" + i + 48);
    }
}

void Conta::modifica_qtd(int qtd){
	this->qtd_produtos += qtd;
}

int Conta::retorna_qtd(){
	return this->qtd_produtos;
}

void cria_produto(Conta &Conta) {
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

void inicializaContasC(vector<Conta> &Contas, int qtd_cadastros){
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
    categorias[5] = "Outros";
}

void interface_inicial_sistema(vector<Conta> &ContasC) {
    cout << "\tCATEGORIAS" << endl;
    const int qtd_categorias = 6;
    string categorias[qtd_categorias];
    inicializa_categorias(categorias);
    for (int i = 0; i < qtd_categorias; i++) {
        cout << categorias[i] << endl << "-------------" << endl;
       for(int j = 0; j < ContasC.size(); j++){
           if (categorias[i].compare(ContasC[j].retorna_categoria()) == 0) {
                  cout << " | " << ContasC[j].retorna_nome_empresa() << endl << "------------" << endl;
              }
           }
    }
}

int main() {
    int max_cadastros = 100;
    vector<Conta> Contas;
   // Conta *Contas = new Conta[max_cadastros];
    //Conta_Comerciante* ContasC = new Conta_Comerciante[max_cadastros];
    int qtd_cadastrosC = 0;
    const int inicializacao = 19; //8
    int qtd_cadastros = inicializacao;
    inicia_dados(Contas, inicializacao);
    interface_inicial_sistema(Contas);
    //inicializaLista(Contas, max_cadastros, qtd_cadastros);
    //inicializaContasC(ContasC, qtd_cadastrosC);
    menu_login(Contas, qtd_cadastros);
    
    //menu_login(Contas, qtd_cadastros);
    //interface_inicial_sistema(Contas);
    return 0;
}