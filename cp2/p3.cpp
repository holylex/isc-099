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
    int n=0;
    
    cout << "Introduzca el numero de elementos de la lista: ";
    cin >> n;

    int *lista = new int[n];

    cout << "Introduza los elementos separados por espacios: ";
    for (int i=0; i<n; i++){
        cin >> lista[i];
    }

    cout << "La diferencia es:" << maxMinDiff(lista, n) << endl;

}
