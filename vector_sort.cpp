#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first < b.second.first) {
		return 1;
	}
	else if (a.second.first == b.second.first) {
		if (a.second.second < b.second.second) return 1;
		else return 0;
	}
	else return 0;
}

int main() {
	freopen("C:/Users/User/Downloads/Algorithm/test_input1.txt", "r", stdin);

	vector<pair<int, pair<int, int>>> ar;
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		ar.push_back(make_pair(x, make_pair(y, z)));
	}

	cout << "before sorting: " << '\n';

	for (int i = 0; i < n; i++) {
		cout << ar[i].first << " " << ar[i].second.first << " " << ar[i].second.second << '\n';
	}
	sort(ar.begin(), ar.end(), compare);

	cout << "after sorting: " << '\n';

	for (int i = 0; i < n; i++) {
		cout << ar[i].first << " " << ar[i].second.first << " " << ar[i].second.second << '\n';
	}

}
