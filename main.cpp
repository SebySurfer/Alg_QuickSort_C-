
#include "main.h"
#include<iostream>
#include <chrono> // Chronometer
#include <iomanip> // Set Second precision
#include <cstdlib> // Generare random numbers
#include <ctime>   // Needed for time()



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

    srand(time(0));
    int randomNum;

    float arreglo[5000];

    for(int i = 0; i < 5000; i++){
        randomNum = rand() % 100 + 1;
        arreglo[i] = randomNum;

    }

    cout << "Arreglo desordenado: " << "{";
    for(int i = 0; i < 4999; i++){
        cout << arreglo[i] << " ";
    }
    cout << "}" << endl;


    quickSort(arreglo, 0, 4999);

    cout << "Arreglo ordenado ascendente: " << "{";
    for(int i = 0; i < 4999; i++){
        cout << arreglo[i] << " ";
    }
    cout << "}" << endl;

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
//Runtime: 0.036108885 seconds before print deletion
//Runtime: 0.000545878 seconds after print deletion
