#include <fstream>
#include <vector>
#include <iostream>
#include "Classes.h"

std::ofstream fout;
std::ifstream fin;

void inicializa_empresas(std::vector<Conta>& Conta_Param, int max_inicializacoes) {
	Conta Temp;
	Produto T;
	std::string nome_empresa = "Empresa ";
	std::string tipo_de_conta = "Empresa";
	std::string email = "Empresa @gmail.com";
	std::string senha = "Empresa ";
	std::string cnpj = "000 ";

	std::string prod_nome = "Produto ";
	int prod_id;
	float prod_preco;

	char ch[1];
	ch[0] = '0';
	for (int i = 0; i < max_inicializacoes; i++) {
		int indice = i;
		if (indice >= 10) {
			indice %= 10;
		}
		ch[0] = '0' + indice;
		prod_nome[7] = ch[0];
		prod_preco = 1 * i * 3.5;
		cnpj[3] = ch[0];
		nome_empresa[7] = ch[0];
		T.atribui_id(i);
		T.atribui_nome(prod_nome);
		T.atribui_preco(prod_preco);
		Temp.cadastra_produto(T);
		Temp.atribui_cnpj(cnpj);
		Temp.atribui_nome_empr(nome_empresa);
		Temp.atribui_tipo_conta(tipo_de_conta);
		
		char num[2];
		if (i < 10) {
			num[0] = '0' + indice;
		}
		else {
			num[0] = '0' + indice;
			num[1] = '0' + indice;
		}
		senha[7] = num[0];
		email[7] = num[0];
		Temp.atribui_email(email);
		Temp.atribui_senha(senha);
		if (num[0] == '6') {
			Temp.atribui_categoria("Artesanato");
		}
		else if (num[0] == '2') {
			Temp.atribui_categoria("Bar");
		}
		else if (num[0] == '3' || num[0] == '8') {
			Temp.atribui_categoria("Roupas");
		}
		else if (num[0] == '4' || num[0] == '7') {
			Temp.atribui_categoria("Servicos");
		}
		else if (num[0] == '5') {
			Temp.atribui_categoria("Sorveterias");
		}
		else {
			Temp.atribui_categoria("Outros");
		}
		Conta_Param.push_back(Temp);
	}	
}

void inicializa_nomes(std::vector<Conta>&Conta_Param, int max_inicializacoes) {
	char ch[1];
	std::string nome_inicial = "Cliente ";
	std::string email_inicial = "Cliente @gmail.com";
	std::string senha_inicial = "Cliente ";
	std::string tipo_de_conta = "Cliente";
	Conta Temp;
	ch[0] = '0';
	for (int i = 0; i < max_inicializacoes; i++) {
		ch[0] = '0' + i;
		nome_inicial[7] = ch[0];
		email_inicial[7] = ch[0];
		senha_inicial[7] = ch[0];
		Temp.atribui_nome(nome_inicial);		
		Temp.atribui_email(email_inicial);
		Temp.atribui_senha(senha_inicial);
		Temp.atribui_tipo_conta(tipo_de_conta);
		if (i == 0) {
			Temp.atribui_nome("DEV");
			Temp.atribui_email("DEV@GMAIL.COM");
			Temp.atribui_senha("DEV");
			Temp.atribui_tipo_conta("DEV");
		}	
		Conta_Param.push_back(Temp);
	}
	inicializa_empresas(Conta_Param, max_inicializacoes);
}

void le_dados(std::vector<Conta>& Conta, int max_inicializacoes) {
	fin.open("dados_agenda.dat");
	std::string nome, email, senha, tipo_de_conta;
	for (int i = 0; i < Conta.size(); i++) {
		fin >> nome >> email >> senha >> tipo_de_conta;
		if (Conta[i].retorna_tipo_conta().compare("Empresa") != 0) {
			Conta[i].atribui_nome(nome);
		}
		else {
			Conta[i].atribui_nome_empr(nome);
		}
		Conta[i].atribui_email(email);
		Conta[i].atribui_senha(senha);
		Conta[i].atribui_tipo_conta(tipo_de_conta);
	}
	fout.close();
}

void escreve_dados(std::vector<Conta>&Conta, int max_inicializacoes) {
	fout.open("dados_agenda.dat");
	for (int i = 0; i < Conta.size(); i++) {
		if (Conta[i].retorna_tipo_conta().compare("Empresa") != 0){
			fout << Conta[i].retorna_nome() << std::endl;
		}
		else {
			fout << Conta[i].retorna_nome_empresa() << std::endl;
		}
		fout << Conta[i].retorna_email() << std::endl << Conta[i].retorna_senha() << std::endl << Conta[i].retorna_tipo_conta() << std::endl;		
	}
	fout.close();
}

void exibe_dados(std::vector<Conta> Conta) {
	for (int i = 0; i < Conta.size(); i++) {
		if (Conta[i].retorna_tipo_conta().compare("Empresa") != 0) {
			std::cout << "Nome: " << Conta[i].retorna_nome() << std::endl;
		}
		else {
			std::cout << "Nome: " << Conta[i].retorna_nome_empresa() << std::endl;
		}
		std::cout << "Email: " << Conta[i].retorna_email() << std::endl
			<< "Senha: " << Conta[i].retorna_senha() << std::endl
			<< "-------------" << std::endl;
	}
}

void inicia_dados(std::vector<Conta> &Contas, int max_inicializacoes) {

	inicializa_nomes(Contas, max_inicializacoes);
	inicializa_empresas(Contas, max_inicializacoes);
	escreve_dados(Contas, max_inicializacoes);
	le_dados(Contas, max_inicializacoes);
}