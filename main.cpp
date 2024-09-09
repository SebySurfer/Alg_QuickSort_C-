
#include "main.h"
#include<iostream>

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

    float arreglo[] = {3, 5, 7, 3, 2, 5, 9, 7, 1};
    quickSort(arreglo, 0, 8);

    cout << "Arreglo ordenado ascendente: " << endl;

    for(int i = 0; i < 9; i++){
        cout << arreglo[i];
    }



    return 0;
}