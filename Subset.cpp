//print all the subsets of an array of the elements using with iterative solution
#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("C:/Users/User/Downloads/Algorithm/subset_iteration.txt", "r", stdin);
	int n, sum = 0;
	cout << "Enter the number of elements: ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int N = pow(2, n);
	vector<int> maxSubset;
	int maxSum = INT_MIN;

	cout << "Subsets are:\n";
	for (int number = 0; number < N ; number++) {
		vector<int> subset;
		int Sum = 0;

		cout << "(";
		bool first = true;
		for (int i = 0; i < n; i++) {
			if (number & (1 << i)) {
				if (!first) cout << " ";
				cout << arr[i];
				subset.push_back(arr[i]);
				Sum += arr[i];
				first = false;
			}
		}
		cout << ")" << endl;
		if (Sum > maxSum) {
			maxSum = Sum;
			maxSubset = subset;
		}
	}

	cout << "\nMaximum subset: (";
	for (int i = 0; i < maxSubset.size(); i++) {
		cout << maxSubset[i];
		if (i != maxSubset.size() - 1) cout << " ";
	}
	cout << ")" << endl;
	cout << "Maximum sum: " << maxSum << endl;

	return 0;
}
