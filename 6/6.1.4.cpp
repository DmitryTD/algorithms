#include <iostream>
#include <vector>

using namespace std;

void find_val(int left, int right, vector <int>& a, int val) {
	int m = left + ((right - left) / 2);
	if (val > a[m] && m < right) {
		find_val(m + 1, right, a, val);
	}
	else if (val < a[m] && left < right) {
		find_val(left, m - 1, a, val);
	}
	else if (val == a[m]) {
		cout << (right + left) / 2 + 1 << " ";
	}
	else {
		cout << -1 << " ";
	}
}

int main() {
	int n, k, b;

	cin >> n;
	vector <int> A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> b;
		find_val(0, n - 1, A, b);
	}
}