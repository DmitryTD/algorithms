#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	do {
		if (a > b) {
			a = a % b;
		}
		else {
			b = b % a;
		}
	} while (a != 0 && b != 0);
	if (a == 0) {
		cout << b << endl;
	}
	else {
		cout << a << endl;
	}
}