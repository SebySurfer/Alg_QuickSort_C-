
#include "main.h"
#include<iostream>
#include <chrono>
#include <iomanip>

using namespace std;

void intercambio(float &x, float &y){
    float aux;
    aux = x;
    x = y;
    y = aux;
}

void quickSort(float a[], int primero, int ultimo) {
    int i, j, central;
    float pivote;

    central = (primero + ultimo) / 2;
    pivote = a[central];
    i = primero;
    j = ultimo;

    do {
        while (a[i] < pivote) {
            i++;
        }
        while (a[j] > pivote) {
            j--;
        }

        if (i <= j) {
            intercambio(a[i], a[j]);
            i++;
            j--;
        }
    } while(i <= j);

    if(primero < j) {
        quickSort(a, primero, j);
    }
    if(i < ultimo){
        quickSort(a, i, ultimo);
    }

}


int main(){
    // *** Timer Start ***
    auto start = chrono::high_resolution_clock::now();

    float arreglo[] = {3, 5, 7, 3, 2, 5, 9, 7, 1};
    quickSort(arreglo, 0, 8);

    cout << "Arreglo ordenado ascendente: " << endl;

    for(int i = 0; i < 9; i++){
        cout << arreglo[i];
    }

    // *** Timer end ***
    auto end = chrono::high_resolution_clock::now();

    //Timer difference
    chrono::duration<double> duration = end - start;

    //Duration
    cout << endl ;
    cout << fixed << setprecision(9);
    cout << "Runtime: " << duration.count() << " seconds" << endl;


    return 0;
}