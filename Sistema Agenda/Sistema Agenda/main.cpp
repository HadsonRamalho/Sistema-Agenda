#include <iostream>
#include <string>

using namespace std;

class Conta {
private:
	string nome;
	string email;
	string senha;
	string tipo_de_conta;
public:
	Conta() {
		this->nome = "default";
		this->email = "default";
		this->senha = "default";
		this->tipo_de_conta = "undefined";
	}
	void adicionar_conta(string nome, string email, string senha);
	string retorna_nome();
	string retorna_email();
	string retorna_senha();
	string retorna_tipo_conta();
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
	this->tipo_de_conta = tipo_de_conta;
}

Conta criar_conta() {
	Conta Usuario_Temporario;
	cout << "\tMENU DE CRIACAO DE CONTA" << endl
		<< " | Insira seu nome: " << endl;
	string nome_usuario;
	cin >> nome_usuario;
	cout << " | Insira seu email: " << endl;
	string email_usuario;
	cin >> email_usuario;
	string senha_usuario_parte1;
	string senha_usuario_parte2;
	bool senha_valida = false;
	do{
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
		cout << Contas[i].retorna_nome() << endl;
	}
}

void menu_login(Conta Contas[], int &cadastros) {
	string opcao;
	Conta Conta_Temp;
	//do {
		cout << "\tMENU DE LOGIN" << endl
			<< " 1 | Tenho conta" << endl
			<< " 2 | Nao tenho conta" << endl
			<< " [DEV] 3 | Listar contas" << endl
			<< " [DEV] 4 | Sair" << endl;
		cin >> opcao;
		switch (opcao[0]) {
		case '1':
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

	//} while (opcao[0] == '4' || opcao[0] == '-1');

}

int main() {
	int max_cadastros = 100;
	Conta *Contas = new Conta[max_cadastros];
	int qtd_cadastros = 0;
	menu_login(Contas, qtd_cadastros);
	menu_login(Contas, qtd_cadastros);
	listar_contas(Contas, qtd_cadastros);
	delete[] Contas;
	return 0;
}