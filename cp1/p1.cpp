//Alexandre Perez
//2005-0427
#include <iostream>



using namespace std;



int main(){

	const int maximo = 10;
	int n;
	cout << "Introduzca la longitud de la lista: ";
	cin >> n;
	
	int lista[n];
	int valores[maximo + 1] = { 0 };
	cout << "Introduzca la lista, separada por espacios:";

	for (int i=0; i<n; i++){
		cin >> lista[i];

	}

	for(int i=0; i<n; i++){
		valores[lista[i]]++;
	}

	int aux = 0;
	for(int i=0; i<maximo; i++){
		while(valores[i]--){
			lista[aux++] = i;
		}
	}
	
	cout << "La lista ordenada es: ";	
	for(int i=0; i<n; i++){
		cout << lista[i] << ' ';
	}	
	cout << endl;
	return 0;

}
