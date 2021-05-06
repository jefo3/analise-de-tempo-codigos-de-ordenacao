//Jeferson Gonçalves Noronha Soriano - 471110

#include <iostream>
#include <fstream>
#include <sstream>
#include "ordenacaoVetor.h"

using namespace std;

void Ordenacao::insertionSort(int *vetor, int tam){
    int i, j, aux;
    for(i = 1; i < tam; i++){
        aux = vetor[i];

        for(j = i-1; j >= 0 && vetor[j] > aux; j--){
            vetor[j+1] = vetor[j];
        }

        vetor[j+1] = aux;
    }
}

void Ordenacao::selectionSort(int *vetor, int tam){
    int i, j, min;
    for(i = 0; i < tam-1; i++){
        min = i;

        for(j = i+1; j < tam; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        
        int aux = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = aux;
    }
}

void Ordenacao::mergeSort(int *vetor, int p, int r){
    if(p < r){
        int q = (p+r)/2;

        //dividir
        Ordenacao::mergeSort(vetor, p, q);
        Ordenacao::mergeSort(vetor, q+1, r);

        //alocando um vetor aux
        int *vetAux = new int[r-p+1];
        int i = p;
        int j = q+1;
        int k = 0;

        //intercalar no vetor vetor[p..q](a primeira metade) e vetor[q+1...r](segunda metade)
        while(i <= q && j <= r){
            if(vetor[i] <= vetor[j]){
                vetAux[k] = vetor[i];
                i++;
                k++;
            }else{
                vetAux[k] = vetor[j];
                j++;
                k++; 
            }
        }

        //se sobrar alguma parte, copia para o vetor aux 
        while(i <= q){
            vetAux[k] = vetor[i];
            i++;
            k++;
        }

        while(j <= r){
            vetAux[k] = vetor[j];
            j++;
            k++; 
        }

        //agora copia o vetAux( ja q ele ta ordenado) para vetor
        for(i = p; i <= r; i++){
            vetor[i] = vetAux[i-p];
        }

        //por fim liberar a memoria alocada do vetAux
        delete[] vetAux;
    }
}

void Ordenacao::quickSort(int *vetor, int p, int r){

    if(p < r){
       
       //pivo sempre sera o ultimo elemento do vetor
        int pivo = vetor[r];
        int j = p;

        for(int k = p; k < r; k++){
            if(vetor[k] <= pivo){
                int aux = vetor[k];
                vetor[k] = vetor[j];
                vetor[j] =  aux;

                j++;
            }
        }
        vetor[r] = vetor[j];
        vetor[j] = pivo;

        int i = j;
        //dividir
        Ordenacao::quickSort(vetor, p, i-1);
        Ordenacao::quickSort(vetor, i+1, r);
    }
}

void Ordenacao::shellSort(int *vetor, int tam){
    int i, j, aux;
    int h = 1;
    //primeiro vamos calcular os saltos q será o H
    while(h < tam){
        h *= 3 + 1;
    }
    //vai dividir os saltos por 3. ate q o salto seja 1 e realize um insetionSort normal
    for(; h > 0; h /= 3){
        
        for(i = h; i < tam; i++){
            aux = vetor[i];

            for(j = i-h; j >= 0 && vetor[j] > aux; j -= h){
                vetor[j+h] = vetor[j];
            }

            vetor[j+h] = aux;
        }

    }

}