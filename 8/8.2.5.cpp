#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k = 0;
	cin >> n;
	vector <int> A(n);
	vector <int> D(n);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		D[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[i] % A[j] == 0 && D[j] + 1 > D[i]) {
				D[i] = D[j] + 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		k = max(k, D[i]);
	}
	cout << k << endl;
}