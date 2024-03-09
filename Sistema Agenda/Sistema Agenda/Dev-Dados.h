#pragma once
#include <iostream>
#include "Classes.h"

void exibe_dados(std::vector<Conta> Conta);
void inicializa_nomes(std::vector<Conta>& Conta, int max_inicializacoes);
void le_dados(std::vector<Conta>& Conta, int max_inicializacoes);
void escreve_dados(std::vector<Conta>& Conta, int max_inicializacoes);
void inicia_dados(std::vector<Conta> &Contas, int max_inicializacoes);
void inicializa_empresas(std::vector<Conta>& Conta_Param, int max_inicializacoes);