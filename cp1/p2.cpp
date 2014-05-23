//Alexandre Perez
//2005-0427
#include <iostream>



using namespace std;



int main(){
	
	int n = 0;
	int a = 0;
	int b = 1;
	int c = 0;
	cout << "Introduzca el numero de elementos: ";
	cin >> n;

	cout << a << endl << b << endl;
	for(int i=0; i<n; i++){
		c = a + b;
		a = b;
		b = c;
		cout << c << endl;
	}

}
