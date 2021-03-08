#include <iostream>

using namespace std;

int main() {
	int val3 = 2, n, val2 = 1, temp;
	cin >> n;
	if (n > 3) {
		for (int i = 0; i < n - 3; i++) {
			temp = val3;
			val3 = val3 + val2;
			val2 = temp;
		}
	}
	else if (n == 1 || n == 2) {
		val3 = 1;
	}

	cout << val3 << endl;
}