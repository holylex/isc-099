#include <iostream>

using namespace std;

int main(){
    int top = 100;
    bool prime;
    cout << "2" << " es primo" << endl;
    for(int i=3; i<top; i++){
        prime = true;
        for(int j=2; j<i; j++){
            if(i%j == 0){
                prime = false;
            }
        }
        if(prime){
            cout << i << " es primo" << prime<<endl;
        }

    }

}
