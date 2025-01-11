//print all the subsets of an array of the elements using with recoursion solution
#include <bits/stdc++.h>
using namespace std;

void F(int ar[], int i, int n, vector<int> ss, vector<int>MaxSubset, int MaxSum) {
	if (i > n - 1) {
		cout << "(";
		for (int k = 0; k < ss.size(); k++) {
			cout << ss[k];
			if (k != ss.size() - 1)
				cout << " ";
		}
		cout << ")" << endl;
		int sum = 0;
		for (int num : ss) {
			sum += num;
		}


		if (sum > MaxSum) {
			MaxSum = sum;
			MaxSubset[i] = ss;
		}

		return;
	}

	ss.push_back(ar[i]);
	F(ar, i + 1, n, ss, MaxSubset, MaxSum);

	ss.erase(ss.begin() + (ss.size() - 1));
	F(ar, i + 1, n, ss, MaxSubset, MaxSum);
}


int main() {
	freopen("C:/Users/User/Downloads/Algorithm/subset_recursion.txt", "r", stdin);
	int n;
	cout << "Enter the number of elements: ";
	cin >> n;

	int arr[n];
	cout << "Enter the elements of the array: ";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int>ss;
	vector<int> maxSubset;
	int maxSum = INT_MIN;

	cout << "All subsets:" << endl;
	F(arr, 0, n, ss, maxSubset, maxSum);

	cout << "\nMaximum subset: (";
	for (int j = 0; j < maxSubset.size(); j++) {
		cout << maxSubset[j];
		if (j != maxSubset.size() - 1) cout << " ";
	}
	cout << ")" << endl;
	cout << "Maximum sum: " << maxSum << endl;

	return 0;
}
