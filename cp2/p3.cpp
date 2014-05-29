//Alexandre Perez
//2005-0427

#include <iostream>

using namespace std;

int maxMinDiff(int *arr, int N){
    int min = arr[0];
    int max = arr[0];

    for (int i=0; i<N; i++){
        if(arr[i] < min)
            min = arr[i];

        if(arr[i] > max)
            max = arr[i];
    }
    return max - min;
}

int main(){
    int *lista = new int[1];
    int n = 0;
    int arraysize = 1;


    while (cin >> lista[n]){
        n++;
        if (n >= arraysize){
            arraysize++;
            int* temp = new int[arraysize];

            for (int i=0; i<n; i++){
                temp[i] = lista[i];
            }

            delete [] lista;
            lista = temp;

        }

    }


    cout << maxMinDiff(lista, n) << endl;

}
