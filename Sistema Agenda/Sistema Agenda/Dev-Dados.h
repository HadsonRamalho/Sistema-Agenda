#pragma once
#include <iostream>
#include "Classes.h"

void exibe_dados(std::vector<Conta_Comum> Conta, int max_inicializacoes);
void inicializa_nomes(std::vector<Conta_Comum>& Conta, int max_inicializacoes);
void le_dados(std::vector<Conta_Comum>& Conta, int max_inicializacoes);
void escreve_dados(std::vector<Conta_Comum>& Conta, int max_inicializacoes);
void inicia_dados(int max_inicializacoes);