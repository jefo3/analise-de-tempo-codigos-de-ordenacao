//Jeferson Gonçalves Noronha Soriano - 471110
#ifndef ORDENACAO_H
#define ORDENACAO_H

class Ordenacao {
     
    public:
        void insertionSort(int *vetor, int tam);
        void selectionSort(int *vetor, int tam);
        void mergeSort(int *vetor, int p, int r);
        void quickSort(int *vetor, int p, int r);
        void shellSort(int *vetor, int tam);
};

#endif
