/*
https://stepik.org/lesson/13249/step/6?auth=registration&discussion=1283584&unit=3434

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int find_kol_of_dot(int dot, vector <int>& x, vector <int>& y) {
	int N = 0;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] <= dot) {
			N++;
		}
	}
	int M = 0;
	for (int i = 0; i < y.size(); i++) {
		if (y[i] < dot) {
			M++;
		}
	}
	return N - M;
}


int main() {
	int n, m, N, M;
	cin >> n >> m;
	vector <int> x(n);
	vector <int> y(n);
	vector <int> A(m);
	vector <int> dots(m);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

	for (int i = 0; i < m; i++) {
		cin >> A[i];
		dots[i] = find_kol_of_dot(A[i], x, y);
	}

	for (int i = 0; i < dots.size(); i++) {
		cout << dots[i] << " ";
	}
	cout << endl;
}