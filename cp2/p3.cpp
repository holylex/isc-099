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
    int lista[] = {1, 6, 3, 2, 9, 0};
    int n = 6;

    cout << maxMinDiff(lista, n) << endl;

}
