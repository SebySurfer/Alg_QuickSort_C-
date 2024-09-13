
#include<iostream>
#include <chrono> // Chronometer
#include <iomanip> // Set Second precision
#include <ctime>   // Needed for time()
#include <future> // Threads
#include <sstream> //Fast print
#include <random>


using namespace std;


void quickSort(int a[], int primero, int ultimo) {
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

void print(int a[]){
    stringstream ss;
    ss << "Arreglo desordenado: ";
    for(int i = 0; i < 5000; i++){
        ss << a[i] << " ";
    }
    ss << endl;

    ss << "Arreglo ordenado: ";
    for(int i = 5000; i < 10000; i++){
        ss << a[i] << " ";
    }

    cout << ss.str();

}


int main(){
    // *** Timer Start ***
    auto start = chrono::high_resolution_clock::now();


    int arreglo[10000];

    future <void> asyncPrint = async(&print, arreglo);


    // Set up random number generator
    mt19937 rng(time(0)); // Seed with current time
    uniform_int_distribution<int> dist(1, 100);

    for (int i = 0; i < 5000; i += 8) {
        int r1 = dist(rng);
        int r2 = dist(rng);
        int r3 = dist(rng);
        int r4 = dist(rng);
        int r5 = dist(rng);
        int r6 = dist(rng);
        int r7 = dist(rng);
        int r8 = dist(rng);

        arreglo[i] = r1;
        arreglo[i + 1] = r2;
        arreglo[i + 2] = r3;
        arreglo[i + 3] = r4;
        arreglo[i + 4] = r5;
        arreglo[i + 5] = r6;
        arreglo[i + 6] = r7;
        arreglo[i + 7] = r8;

        arreglo[i + 5000] = r1;
        arreglo[i + 5001] = r2;
        arreglo[i + 5002] = r3;
        arreglo[i + 5003] = r4;
        arreglo[i + 5004] = r5;
        arreglo[i + 5005] = r6;
        arreglo[i + 5006] = r7;
        arreglo[i + 5007] = r8;
    }


    quickSort(arreglo, 5000, 9999);


    //Finish subthread
    asyncPrint.get();

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
//Runtime: 0.004776484 seconds - Using future threads
//Runtime: 0.004437304 seconds - Second try future threads
//Runtime: 0.004289457 seconds - Third try future threads

