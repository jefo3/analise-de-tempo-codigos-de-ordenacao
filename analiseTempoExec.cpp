//Jeferson Gonçalves Noronha Soriano - 471110
#include <iostream>
#include <fstream>
#include <chrono>
#include <sstream>
#include "analiseTempoExec.h"
#include "ordenacaoVetor.h"

using namespace std;

/// Determina se o `vetor` informado, com `tamanho_vetor` elementos,
/// está ordenado em ordem não-decrescente.
bool AnaliseExec::verificar_ordenacao(int vetor[], unsigned int tamanho_vetor) {
    for(unsigned int i = 1; i < tamanho_vetor; ++i) {
        if(vetor[i-1] > vetor[i]) {
            return false;
        }
    }

    return true;
}

/** 
 * Funcao que gera arquivos binarios, cada um contendo numeros aleatorios
 * Essa funcao recebe um array 'vetor_tam' que contem todos os tamanhos N
 * de vetores aleatorios que serao gerados. O parametro 'num_iteracoes' eh
 * o tamanho do array 'vetor_tam' 
 */
void AnaliseExec::gera_dados(int num_iteracoes, const int vetor_tam[]){
	for(int n = 0; n < num_iteracoes; n++) {
		// para cada tamanho n, sao gerados 20 vetores de tamanho n aleatorios
		for(int semente = 0; semente < 20; semente++) {	
			std::string nome_arquivo = "dados/random"+std::to_string(n)+"_"+std::to_string(semente)+".dat";
			ofstream fout(nome_arquivo.c_str(), ios::binary);
			srand(time(NULL)); // gera semente
			int r;
			int tamanho_vetor = vetor_tam[n];
			for(int i = 0; i < tamanho_vetor; i++) 
			{
				r = rand(); // gera numero aleatorio
				fout.write((char*)&r, sizeof(r));
			}
			fout.close();
		}
	}
}

// ------------------------------------------------------------------

/*
 * Recebe um vetor de inteiros A[0..n-1] como argumento e o preenche
 * com os n inteiros contidos no arquivo binario de mesmo nome que a 
 * string nomeArquivo
 */
void AnaliseExec::ler_dados(int n, int A[], const char *nomeArquivo){	
	ifstream fin(nomeArquivo, ios::binary); // abre arquivo para leitura
	for (int i = 0; i < n; i++){
		fin.read((char*)&A[i], sizeof(int)); // ler os inteiros do arquivo e guarda no vetor A
	}
	fin.close(); // fecha o arquivo de leitura
}




void AnaliseExec::tempoExec(const int tam[], int TOTAL_N, std::string nomeArquivoResult, Ordenacao * ord, std::string nomeOrdenacao){
		std::ofstream ofs("resultados/"+nomeArquivoResult+".txt", std::ofstream::out ); // abre arquivo
		
		for(int iteracao = 0; iteracao < TOTAL_N; iteracao++){
		
		long double duracao_media = 0.0;
		int tamanho_vetor = tam[iteracao]; // pega o tamanho do vetor para esta iteracao
		int vetor[tamanho_vetor]; // cria vetor a ser ordenado
		
		// Para cada tamanho de vetor, a funcao gera_dados() gerou 20 vetores diferentes. 
		// Cada um usou uma semente diferente. Agora, vamos ler cada um desses vetores, 
		// Chamar para ordena-los e, entao, calcular o tempo medio de 
		// execucao dessas cinco chamadas e depois salvar esse tempo medio em arquivo.
		for(int semente = 0; semente < 20; semente++){	
			string nome_arquivo = "dados/random"+std::to_string(iteracao)+"_"+std::to_string(semente)+".dat";
		
			AnaliseExec::ler_dados(tamanho_vetor, vetor, nome_arquivo.c_str());
			
			
			// obtendo o tempo inicial
			auto ini = std::chrono::high_resolution_clock::now();

			ord->mergeSort(vetor, 0, tamanho_vetor);//ordena o vetor
		
			// obtendo o tempo final
			auto fim = std::chrono::high_resolution_clock::now();
		
			// obtendo a duração total da ordenação
			auto duracao = std::chrono::duration_cast<std::chrono::microseconds>(fim - ini).count();
			
			duracao_media += duracao;
			
			//cout << "ordenado? " << verificar_ordenacao(vetor, tamanho_vetor) << endl;
		}
		
		duracao_media = duracao_media / 20.0;
		cout << "["<< nomeOrdenacao << "] N = " << tamanho_vetor << ", tempo médio de execução = " << duracao_media << " microssegundos" << endl;
		ofs << tamanho_vetor << " " << duracao_media << "\n"; // grava no arquivo de resultados

	}
	
	ofs.close(); // fecha arquivo de resultados
}
