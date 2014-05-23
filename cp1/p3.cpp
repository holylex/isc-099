//Alexandre Perez
//2005-0427
#include <iostream>
#include <string>

using namespace std;

int main(){
	string input = "";
	cout << "Introduzca un numero: ";
   	getline(cin, input);

	char cnumber = input[input.length()-1];
	int number = cnumber - '0';

	if(number%2 == 0){
		cout << "Par" << endl;
	}else{
		cout << "Impar" << endl;
	}
}
