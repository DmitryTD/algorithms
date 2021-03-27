#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <vector>

using namespace std;

int comp(pair <char, string> c1, pair <char, string> c2) {
	return c1.second.size() < c2.second.size();
}

int main() {
	bool f = 0;
	int k, l, kol = 0, max_kol;
	string s, code, answer, temp, substr;
	vector <pair <char, string>> sym_and_code;

	cin >> k >> l;
	cin.ignore(256, '\n');

	sym_and_code.resize(k);
	for (int i = 0; i < k; i++) {
		getline(cin, s);
		sym_and_code[i].first = s[0];
		s.erase(0, 3);
		sym_and_code[i].second = s;
	}

	sort(sym_and_code.begin(), sym_and_code.end(), comp);
	max_kol = sym_and_code[sym_and_code.size() - 1].second.size();

	getline(cin, code);
	//делаем дешифровку, основываясь на том, что код беспрефиксный
	while (code != "") {
		if (kol > max_kol) {
			kol = 0;
		}
		kol++;
		substr = code.substr(0, kol);
		for (int i = 0; i < sym_and_code.size(); i++) {
			if (substr == sym_and_code[i].second) {
				code.erase(0, kol);
				answer = answer + sym_and_code[i].first;
				substr = code.substr(0, kol);
			}
		}
	}
	cout << answer << endl;
}
