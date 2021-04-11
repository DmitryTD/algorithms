/*
https://www.youtube.com/watch?v=TD62dEeN2Yo&ab_channel=IlyaZimin

*/
#include <iostream>
#include <vector>

using namespace std;

int kol = 0;
vector <int> result;

void Merge(vector <int>& arr, int left, int right) {
	int i = left;
	int k = 0;
	int mid = left + (right - left) / 2;
	int j = mid + 1;


	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			result[k] = arr[i];
			i++;
		}
		else {

			kol = kol + (mid - i);
			result[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		result[k] = arr[i];
		kol = kol + (mid - i);
		i++;
		k++;
	}
	while (j <= right) {
		result[k] = arr[j];
		j++;
		k++;
	}
	for (i = 0; i < k; i++) {
		arr[left + i] = result[i];
	}
}

void MergeSort(vector <int>& start, int left, int right) {
	if (left < right) {
		if (right - left == 1) {
			if (start[left] > start[right]) {
				swap(start[left], start[right]);
				kol++;
			}
		}
		else {
			MergeSort(start, left, left + (right - left) / 2);
			MergeSort(start, left + (right - left) / 2 + 1, right);
			Merge(start, left, right);
		}
	}
}

int main() {
	int n, temp;

	cin >> n;
	vector <int> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	result.resize(n);
	MergeSort(a, 0, n - 1);

	cout << kol << endl;

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}