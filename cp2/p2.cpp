//Alexandre Perez
//2005-0427

#include <iostream>

using namespace std;

int Fn(int n){
    if(n==0 || n==1)
        return 1;
    else
        return Fn(n - Fn(n-1)) + Fn(n - Fn(n-2));
}

int main(){
    int n = 0;
    cout << "Introduzca N: " ;
    cin >> n;
    cout << "El resultado es: " << Fn(n) << endl;
}
