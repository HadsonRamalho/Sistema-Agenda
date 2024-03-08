#include <fstream>
#include <vector>
#include <iostream>
#include "Classes.h"

std::ofstream fout;
std::ifstream fin;

void inicializa_nomes(std::vector<Conta_Comum>& Conta, int max_inicializacoes) {
	char ch[1];
	std::string nome_inicial = "Cliente ";
	std::string email_inicial = "Cliente @gmail.com";
	std::string senha_inicial = "Cliente ";
	std::string tipo_de_conta = "Cliente";
	ch[0] = '0';
	Conta_Comum Conta_Temp;
	for (int i = 0; i < max_inicializacoes; i++) {
		ch[0] = '0' + i;
		nome_inicial[7] = ch[0];
		email_inicial[7] = ch[0];
		senha_inicial[7] = ch[0];
		Conta_Temp.nome = nome_inicial;
		Conta_Temp.email = email_inicial;
		Conta_Temp.senha = senha_inicial;
		Conta_Temp.tipo_de_conta = tipo_de_conta;
		if (i == 0) {
			Conta_Temp.nome = "DEV";
			Conta_Temp.email = "DEV@GMAIL.COM";
			Conta_Temp.senha = "DEV";
			Conta_Temp.tipo_de_conta = "DEV";
		}
		Conta.push_back(Conta_Temp);
	}
}

void le_dados(std::vector<Conta_Comum>& Conta, int max_inicializacoes) {
	fin.open("dados_agenda.dat");
	for (int i = 0; i < max_inicializacoes; i++) {
		fin >> Conta[i].nome >> Conta[i].email >> Conta[i].senha >> Conta[i].tipo_de_conta;
	}
	fout.close();
}

void escreve_dados(std::vector<Conta_Comum>& Conta, int max_inicializacoes) {
	fout.open("dados_agenda.dat");
	for (int i = 0; i < max_inicializacoes; i++) {
		fout << Conta[i].nome << std::endl << Conta[i].email << std::endl << Conta[i].senha << std::endl << Conta[i].tipo_de_conta << std::endl;
	}
	fout.close();
}

void exibe_dados(std::vector<Conta_Comum> Conta, int max_inicializacoes) {
	for (int i = 0; i < max_inicializacoes; i++) {
		std::cout << "Nome: " << Conta[i].nome << std::endl << "Email: " << Conta[i].email << std::endl
			<< "Senha: " << Conta[i].senha << std::endl << "Tipo: " << Conta[i].tipo_de_conta
			<< std::endl << std::endl << " ---------------" << std::endl;
	}
}

void inicia_dados(int max_inicializacoes) {
	std::vector<Conta_Comum> Contaa;

	inicializa_nomes(Contaa, max_inicializacoes);
	escreve_dados(Contaa, max_inicializacoes);
	le_dados(Contaa, max_inicializacoes);
	exibe_dados(Contaa, max_inicializacoes);
}