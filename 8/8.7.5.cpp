/*
https://ru.stackoverflow.com/questions/475942/%D0%9D%D0%B5-%D0%BF%D0%BE%D0%BB%D1%83%D1%87%D0%B0%D0%B5%D1%82%D1%81%D1%8F-%D1%80%D0%B5%D1%88%D0%B8%D1%82%D1%8C-%D0%B7%D0%B0%D0%B4%D0%B0%D1%87%D1%83-%D0%BD%D0%B0-%D0%BF%D1%80%D0%BE%D0%B3%D1%80%D0%B0%D0%BC%D0%BC%D0%B8%D1%80%D0%BE%D0%B2%D0%B0%D0%BD%D0%B8%D0%B5-%D0%BA%D0%B0%D0%BB%D1%8C%D0%BA%D1%83%D0%BB%D1%8F%D1%82%D0%BE%D1%80

*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> steps(n + 1, INT_MAX);
    steps[n] = 0;
    vector<int> next_num(n + 1, -1);

    for (int i = n; i > 1; --i) {
        int s = steps[i] + 1;
        // 3 * x
        if (i % 3 == 0 && steps[i / 3] > s) {
            steps[i / 3] = s;
            next_num[i / 3] = i;
        }
        // 2 * x
        if (i % 2 == 0 && steps[i / 2] > s) {
            steps[i / 2] = s;
            next_num[i / 2] = i;
        }
        // x + 1
        if (steps[i - 1] > s) {
            steps[i - 1] = s;
            next_num[i - 1] = i;
        }
    }

    cout << steps[1] << endl;
    for (int i = 1; i != -1; i = next_num[i]) {
        cout << i << ' ';
    }
    cout << endl;
}