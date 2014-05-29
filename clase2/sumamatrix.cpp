#include <iostream>
using namespace std;

int main(){

    const int dimension = 4;
    int a[dimension][dimension], b[dimension][dimension], c[dimension][dimension];


    for (int fila = 0; fila < dimension; fila ++){
        cin >> a[fila][0] >> a[fila][1] >> a[fila][2] >> a[fila][3];

    }
    for (int fila = 0; fila < dimension; fila ++){
        cin >> b[fila][0] >> b[fila][1] >> b[fila][2] >> b[fila][3];

    }

    for (int fila = 0; fila < dimension; fila ++){
        for (int col = 0; col < dimension; col++){
            c[fila][col] = a[fila][col] + b[fila][col];
            cout << c[fila][col] << " ";
        }
        cout << endl;
    }

    return 0;

}
