//Alexandre Perez
//2005-0427
#include <iostream>

using namespace std;

void matrix_mul(int **A, int **B, int **C, int an, int bp, int am){
    for (int i=0; i<an; i++){
        for (int j=0; j<bp; j++){
            C[i][j] = 0;
            for (int k=0; k<am; k++){
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

int main(){
    int an = 0, am = 0;
    int bm = 0, bp = 0;

    cout << "Introduzca las dimensiones de A: ";
    cin >> an >> am;

    //crea la Matriz A, an*am
    int **A = new int*[an];
    for (int i=0; i<an; i++){
        A[i] = new int[am];
    }

    cout << "Introduzca la Matriz A: " << endl;
    //llena la matrix A, an*am
    for (int i=0; i<an; i++){
        for (int j=0; j<am; j++){
            cin >> A[i][j];
        }
    }

    cout << "Introduzca las dimensiones de B: ";
    cin >> bm >> bp;

    //revisa si estas se pueden multiplicar, si no termina el programa
    if (am != bm){
        cout << "Esta matriz no se puede multiplicar por A: Programa abortado" << endl;
        return 1;
    }

    //crea la Matriz B, bm*bp
    int **B = new int*[bm];
    for (int i=0; i<bm; i++){
        B[i] = new int[bp];
    }

    cout << "Introduzca la Matriz B: " << endl;
    //llena la Matriz B, bm*bp
    for (int i=0; i<bm; i++){
        for (int j=0; j<bp; j++){
            cin >> B[i][j];
        }
    }

    //crea la Matriz c, an*bp
    int **C = new int*[an];
    for (int i=0; i<an; i++){
        C[i] = new int[bp];
    }

    matrix_mul(A, B, C, an, bp, am);

    cout << endl << "AxB:" << endl;
    for (int i=0; i<an; i++){
        for (int j=0; j<bp; j++){
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

}
