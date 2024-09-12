
#include "main.h"
#include<iostream>
#include <chrono> // Chronometer
#include <iomanip> // Set Second precision
#include <cstdlib> // Generare random numbers
#include <ctime>   // Needed for time()
#include <thread>



using namespace std;


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
            float aux = a[i];
            a[i] = a[j];
            a[j] = aux;
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
    cout << "Arreglo desordenado: " << "{";
    for(int i = 0; i < 5000; i++){
        cout << a[i] << " ";
    }
    cout << "}" << endl;

    cout << "Arreglo ordenado asc: " << "{";
    for(int i = 5000; i < 10000; i++){
        cout << a[i] << " ";
    }
    cout << "}" << endl;

}


int main(){
    // *** Timer Start ***
    auto start = chrono::high_resolution_clock::now();

    srand(time(0));

    float arreglo[10000];

    thread p(print, arreglo);

    for(int i = 0; i < 5000; i += 4) {
        arreglo[i] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+1] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+2] = (rand() / (RAND_MAX / 100 + 1)) + 1;
        arreglo[i+3] = (rand() / (RAND_MAX / 100 + 1)) + 1;

        arreglo[i+5000] = arreglo[i];
        arreglo[i+1+5000] = arreglo[i+1];
        arreglo[i+2+5000] = arreglo[i+2];
        arreglo[i+3+5000] = arreglo[i+3];


    }


    quickSort(arreglo, 5000, 9999);
    p.join();


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

//Runtime: < 0.030000000 seconds after opt random
//Runtime: < 0.025000000 seconds after using print statements as classes

//Runtime: 0.005414678 seconds - print to 4 pair
