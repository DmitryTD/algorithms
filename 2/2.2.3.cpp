/*
http://espressocode.top/fibonacci-number-modulo-m-and-pisano-period/
https://ru.wikipedia.org/wiki/Период_Пизано

*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	__int64 n;
	int val3 = 2, val2 = 1, temp, m;
	vector <int> Pisano;
	cin >> n >> m;

	Pisano.push_back(0);
	Pisano.push_back(1);
	Pisano.push_back(1);

	//Период Пизано
	while (val3 % m != 1 || val2 % m != 0) {
		Pisano.push_back(val3 % m);
		temp = val3;
		val3 = (val3 + val2) % m;
		val2 = temp;
	}

	Pisano.erase(Pisano.begin() + Pisano.size() - 1);

	cout << Pisano[n % Pisano.size()] << endl;
}