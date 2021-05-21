#include <iostream>
#include <vector>
#include <string>

using namespace std;

int min_3(int a, int b, int c) {
	if (a <= b) {
		if (a <= c) {
			return a;
		}
		else return c;
	}
	else if (b <= c) {
		return b;
	}
	else return c;
}

int main() {
	bool c;
	string A, B;
	cin >> A >> B;
	int n = A.size() + 1, m = B.size() + 1;
	vector < vector <int>> D(n, vector <int>(m));

	for (int i = 0; i < n; i++) {
		D[i][0] = i;
	}
	for (int j = 0; j < m; j++) {
		D[0][j] = j;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			c = (A[i - 1] != B[j - 1]);
			D[i][j] = min_3(D[i - 1][j] + 1,
				D[i][j - 1] + 1,
				D[i - 1][j - 1] + c);
		}
	}
	cout << D[n - 1][m - 1] << endl;
}