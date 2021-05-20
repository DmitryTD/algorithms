#include <iostream>
#include <vector>

using namespace std;

int main() {
	int kol;
	cin >> kol;
	int kol_val[11] = { 0 };
	vector <int> output(kol);
	vector <int> input(kol);
	for (int i = 0; i < kol; i++) {
		cin >> input[i];
		kol_val[input[i]]++;
	}
	for (int i = 1; i < 11; i++) {
		kol_val[i] += kol_val[i - 1];
	}

	for (int j = kol - 1; j >= 0; j--) {
		output[kol_val[input[j]] - 1] = input[j];
		kol_val[input[j]]--;
	}

	for (int i = 0; i < kol; i++) {
		cout << output[i] << " ";
	}
}