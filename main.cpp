
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

void print(float a[]){
    for(int i = 0; i < 4999; i++){
        cout << a[i] << " ";
    }
    cout << "}" << endl;

}


int main(){
    // *** Timer Start ***
    auto start = chrono::high_resolution_clock::now();

    srand(time(0));

    float arreglo[5000];

    for(int i = 0; i < 5000; i += 4) {
        arreglo[i] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+1] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+2] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+3] = (rand() / (RAND_MAX / 100 + 1)) + 1;
    }

    cout << "Arreglo desordenado: " << "{";



    quickSort(arreglo, 0, 4999);

    cout << "Arreglo ordenado ascendente: " << "{";
    print(arreglo);

    // *** Timer end ***
    auto end = chrono::high_resolution_clock::now();
    print(arreglo);

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

//Runtime: < 0.030000000 seconds after opt random
//Runtime: < 0.025000000 seconds after using print statements as classes
