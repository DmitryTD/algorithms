#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool comp(pair <double, double> a,
	pair <double, double> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

int main() {
	int n, l, r, m, kol = 0, tempval, tempkol = 0;
	bool f = 0;
	vector <int> dots;
	vector < pair <int, int>> a;
	vector <int> val;
	pair <int, int> temp;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l >> r;
		temp = { l,r };
		a.push_back(temp);
	}

	sort(a.begin(), a.end(), comp);


	tempval = a[0].second;
	for (int i = 0; i < n - 1; i++) {
		if (tempval >= a[i + 1].first) {
			if (i == n - 2) {
				kol++;
				val.push_back(tempval);
			}
		}
		else {
			kol++;
			val.push_back(tempval);
			tempval = a[i + 1].second;
			if (i == n - 2) {
				kol++;
				val.push_back(tempval);
			}
		}
	}
	cout << kol << endl;
	for (int i = 0; i < val.size(); i++) {
		cout << val[i] << " ";
	}
}