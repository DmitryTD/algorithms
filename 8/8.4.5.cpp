#include <iostream>
#include <vector>

using namespace std;

int main() {
	int W, n;
	cin >> W >> n;
	W++;
	vector <int> D(W);
	vector <int> w(n);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	D[0] = 1;
	for (int j = n - 1; j >= 0; j--) {
		for (int i = W - 1; i >= 0; i--) {
			if (D[i] == 1 && i + w[j] <= W - 1) {
				D[i + w[j]] = 1;
			}
		}
	}
	while (W != 0) {
		if (D[W - 1] == 1) {
			cout << W - 1 << endl;
			W = 1;
		}
		W--;
	}
}