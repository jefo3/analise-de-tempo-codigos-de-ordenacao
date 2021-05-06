//Jeferson Gonçalves Noronha Soriano - 471110
#include <iostream>
#include "ordenacaoVetor.h"
#include "analiseTempoExec.h"

using namespace std;

int main() { 
	AnaliseExec *ana = new AnaliseExec();
	
	// Os tamanhos dos vetores a serem testados estao
	// guardados neste vetor 'tam'
	const int tam[] = {500,1000,2000,3000,4000,5000,6000,7000,8000,9000,
	10000,11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
	
	int TOTAL_N = sizeof(tam)/sizeof(tam[0]); // determina tamanho do vetor 'tam'
	
	// Etapa 1: Gerar arquivos contendo numeros aleatorios
	// Os arquivos sao gerados e salvos na pasta dados
	ana->gera_dados(TOTAL_N, tam);
	

	Ordenacao *ord = new Ordenacao();

	// ------------------------------------------------------------
	// Etapa 2 - Execucao do MergeSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ana->tempoExec(tam,TOTAL_N, "resultadoMerge", ord, "MergeSort");
	// ------------------------------------------------------------
	// Etapa 3 - Execução do QuickSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ana->tempoExec(tam,TOTAL_N, "resultadoQuick", ord, "QuickSort");

	// ------------------------------------------------------------
	// Etapa 4 - Execução do InsertionSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ana->tempoExec(tam,TOTAL_N, "resultadoInsertion", ord, "InsertionSort");

	// ------------------------------------------------------------
	// Etapa 5 - Execução do SelectionSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ana->tempoExec(tam,TOTAL_N, "resultadoSelection", ord, "SelectionSort");

	// ------------------------------------------------------------
	// Etapa 6 - Execução do ShellSort
	// Para cada arquivo gerado na etapa 1, ler o arquivo e popular
	// um vetor de inteiros com os dados lidos.
	ana->tempoExec(tam,TOTAL_N, "resultadoShell", ord, "ShellSort");
	
	return 0;
}
