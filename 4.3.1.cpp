#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	vector <int> q;
	int n, x, kol = -1, f = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n + 1; i++) {
		getline(cin, s);
		if (s[0] == 'I') {
			s.erase(0, 7);
			x = atoi(s.c_str());
			q.push_back(x);
			kol++;
			f = 0;
		}
		if (s[0] == 'E') {
			if (f == 0) {
				sort(q.begin(), q.end());
			}
			cout << q[kol] << endl;
			q.pop_back();
			kol--;
			f = 1;
		}
	}
}