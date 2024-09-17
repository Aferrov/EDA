#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <vector>
#include <algorithm> 
using namespace std;
#define MaxLength 1000001

void BubbleSort(float arr[], int tam){
    float s=0;
    for(int i=0; i<tam; i++){
        for(int j=0; j<tam; j++){
            if(arr[i]<arr[j]){
                s = arr[i];
                arr[i] = arr[j];
                arr[j] = s;
            }
        }
    }
}

void InsertionSort(float arr[], int tam){
    for (int i = 1; i < tam; ++i) {
        float s = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > s) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = s;
    }
}

void heapify(float arr[], int tam, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < tam && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < tam && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, tam, largest);
    }
}

void HeapSort(float arr[], int tam) {
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(arr, tam, i);
    }
    for (int i = tam - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void SelectionSort(float arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < tam; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

void ShellSort(float arr[], int tam) {
    for (int gap = tam / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < tam; i++) {
            float temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

void merge(float arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<float> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(float arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}


int partition(float arr[], int low, int high) {
    float pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(float arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void imprimir(float arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<endl;
    }
    cout<<endl;
}

int main(int argc, char *argv[]){
    float a[MaxLength];
    string nomArchivo = argv[1];
    ifstream archivo(nomArchivo.c_str());
    string linea;
    int n = 0;
    while(getline(archivo, linea)){
        a[n] = stof(linea);
        n++;
    }
    const auto start = std::chrono::high_resolution_clock::now();
    //BubbleSort(a,n);
    //InsertionSort(a,n);
    SelectionSort(a,n);
    const auto end = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> diff = end - start;
    
    //cout << "Tiempo de bubble sort "<< diff.count()<< '\n';
    //cout << "Tiempo de insertion sort "<< diff.count()<< '\n';
    cout << "Tiempo de selection sort "<< diff.count()<< '\n';
}