//Jeferson Gonçalves Noronha Soriano - 471110
#ifndef ANALISEEXEC_H
#define ANALISEEXEC_H

#include "ordenacaoVetor.h"

class AnaliseExec {
     
    public:
        bool verificar_ordenacao(int vetor[], unsigned int tamanho_vetor);
        void gera_dados(int num_iteracoes, const int vetor_tam[]) ;
        void ler_dados(int n, int A[], const char *nomeArquivo) ;
        void tempoExec(const int tam[], int TOTAL_N, std::string nomeArquivoResult, Ordenacao * ord, std::string nomeOrdenacao);
};

#endif