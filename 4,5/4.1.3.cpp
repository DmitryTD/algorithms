#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k = 0, sum = 0, i = 1, temp;
	vector <int> a;
	cin >> n;
	while (n > sum) {
		a.push_back(i);
		sum = sum + i;
		if (sum > n) {
			i = sum - n - 1;
			a.erase(a.begin() + i);
			k--;
		}
		k++;
		i++;
	}
	cout << k << endl;
	for (i = 0; i < k; i++) {
		cout << a[i] << " ";
	}
}