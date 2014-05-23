#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int suma = 0;
	int tmp;

	for (int i=0; i<n; i++){
		cin >> tmp;
		if(tmp % 2 == 0)
			suma += tmp;
	}
	cout << suma << '\n';

	return 0;
}
