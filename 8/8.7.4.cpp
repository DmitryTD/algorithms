#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, b;
	cin >> n;
	vector <int> a(n + 1);
	cin >> a[1];
	a[0] = 0;
	if (n < 2) {
		cout << a[1];
		return 0;
	}

	for (int i = 2; i <= n; i++) {
		cin >> b;
		a[i] = max(a[i - 1], a[i - 2]) + b;
	}
	cout << a[n];
}