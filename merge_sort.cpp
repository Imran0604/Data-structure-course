//Merge Sort

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {

	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<int>L(n1);
	vector<int>R(n2);

	for (int i = 0; i < n1; i++)
		L[i] = arr[left + i];

	for (int j = 0; j < n2; j++)
		R[j] = arr[mid + 1 + j];

	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if (l < r) {
		int m = l + (r - l) / 2;

		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << '\n';
}


int main() {
	int number;
	cout << "Enter the array size:\n";
	cin >> number;
	int a[number + 1];

	for (int i = 0; i < number; i++)
		cin >> a[i];

	mergeSort(a, 0, number - 1);
	cout << "Sorted array: \n";
	printArray(a, number);
	return 0;

}
