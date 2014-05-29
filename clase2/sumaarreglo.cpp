#include <iostream>
using namespace std;

int suma(int *p, int N){
    int suma = 0;
    for (int i=0; i<N; i++){
        suma += *(p+i);
    }

    return suma;
}

int main(){

    int arr[] = {2, 3, 5, 6, 1};
    int result = suma(arr, 5);
    cout << result;

    return 0;

}
