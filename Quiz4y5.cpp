/*

Quiz 4 y 5
Fiorella Zelaya Coto
2021453615

*/

#include <iostream>
#include <list>
#include <math.h>
using namespace std;


/*

a) f(n)
        = 5 + (3 + 6 + 2)*n + 1 + 3 + 3 + 2 + 1
        = 5 + 11n + 10
        = 11n + 15
b) O grande
        = O(n)
c) el loop invariant
        = j < max(m-1, n-1) 

*/
int costo(int* arrx, int* arry, int n, int m) {
    int costoH = 0;
    int costoV = 0;
    int aux;
    int j = 0;
    int auxm = m, auxn = n;                        //5 +

    while (auxn != 1 || auxm != 1) {               //( 3
        if (auxm != 1) {                           //1
            costoH += arry[j];                     //3
            auxm--;                                //2
        }
        if (auxn != 1) {                           //1
            costoV += arrx[j];                     //3
            auxn--;                                //2
        }
        j++;                                       //2 )n
    }

    aux = costoH;                                  //1
    costoH = ((m)*costoV) + costoH;                //3
    costoV = ((n)*aux) + costoV;                   //3
    if (costoH <= costoV) {                        //1
        return costoH;                             //1
    }
    return costoV;                                 //1
}


/*

a) f(n)
        = 4 + k(16 + n(13) + 3(n(18)))
        = 4 + k(16 + 13n + 3*18n)
        = 4 + k(16 + 13n + 54n)
        = 4 + 16k + 13kn + 54+kn
        = 68kn + 16k + 4
        
b) O grande
        = O(kn)
c) el loop invariant: En cada iteración, los numeros están ordenados según el dígito 1 al dígito i

*/
void radixSort(int* arr, int n, int max) {
    int i, j, m, p = 1, index, temp, count = 0;                              // 2 +
    list<int> pocket[10];      //radix of decimal number is 10               // 1

    for (i = 0; i < max; i++) {                                              // 1 + (3k +    se ejecuta max veces
        m = pow(10, i + 1);                                                  // 5k
        p = pow(10, i);                                                      // 5k
        //cout << "\nm: " << m << " p: " << p << endl;

        for (j = 0; j < n; j++) {                                            // 1k * (3n +    recorre el array e inserta los digitos en el pocket
            temp = arr[j] % m;                                               // 3n
            index = temp / p;     //find index for pocket array              // 2n
            pocket[index].push_back(arr[j]);                                 // 5n)
            //cout << "arr[j]" << arr[j] << " temp: " << temp << "  index: " << index << /* "  pocket[index]: " << (pocket[index]) */ endl;
        }

        count = 0;                                                           // 1k

        for (j = 0; j < 10; j++) {                                           // 1k * (3k +    se ejecuta 10 veces
           //delete from linked lists and store to array

            //cout << "for" << endl;

            while (!pocket[j].empty()) {                                     // *(4n          reemplaza los elementos del pocket ordenados en el array
                //cout << *(pocket[j].begin()) << " ";
                arr[count] = *(pocket[j].begin());                           // 5n
                pocket[j].erase(pocket[j].begin());                          // 7n
                count++;                                                     // 2n)
            }
        }
    }
}

int main() {
    cout << "Ejercicio 1 función costo. \n\na) f(n) = 11n + 15 \nb) O grande = O(n) \nc) Loop invariant: j < max(m-1, n-1) " << endl;
    cout << "\nEjemplo 1" << endl;
    int arrayx1[3] = { 4, 2, 9 };
    int arrayy1[2] = { 8, 1 };

    cout << "El costo mínimo de partir la siguiente barra de chocolate 4x3 \n   4 2 9\n8\n1\nes de: " << costo(arrayx1, arrayy1, 4, 3) << endl;
    
    cout << "\nEjemplo 2" << endl;
    int arrayx12[5] = { 1, 2, 3, 4, 5 };
    int arrayy12[3] = { 1, 2, 5 };

    cout << "El costo mínimo de partir la siguiente barra de chocolate 6x4 \n   1 2 3 4 5 \n1\n2\n3\nes de: " << costo(arrayx12, arrayy12, 6, 4) << endl;

    cout << "\n-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\nEjercicio 2 Radix Sort. \n\na) f(n) = 68kn + 16k + 4 \nb) O grande = O(kn) \nc) Loop invariant: En cada iteración, los numeros están ordenados según el dígito 1 al dígito i" << endl;
    cout << "\n\nEjemplo 1: [2, 5, 40, 123, 1, 10, 3, 13] \nOrdenando... Listo!" << endl;
     int list[8]= {2,5, 40, 123 ,1,10,3, 13};
     radixSort(list, 8, 3);

     for(int i = 0; i < 8; i++){
         cout << list[i] << " ";
     }
     cout << "\n";

     return 0;
}