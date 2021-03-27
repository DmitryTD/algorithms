#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool comp(pair <double, double> a,
	pair <double, double> b) {
	return a.first / a.second > b.first / b.second;
}

int main() {
	int n, W, j = 0;
	double maxPrice = 0, Wtemp = 0;
	pair <double, double> c_w;
	cin >> n >> W;

	vector <pair <double, double>> cANDw;
	for (int i = 0; i < n; i++) {
		cin >> c_w.first >> c_w.second;
		cANDw.push_back(c_w);
	}
	sort(cANDw.begin(), cANDw.end(), comp);


	while (W > Wtemp && j < n) {
		if (Wtemp + cANDw[j].second <= W) {
			maxPrice = maxPrice + cANDw[j].first;
			Wtemp = Wtemp + cANDw[j].second;
		}
		else if (Wtemp + cANDw[j].second > W) {
			maxPrice = maxPrice + (double(W - Wtemp)) / cANDw[j].second * cANDw[j].first;
			Wtemp = Wtemp + cANDw[j].second;
		}
		j++;
	}
	cout << fixed << setprecision(3) << maxPrice << endl;
}