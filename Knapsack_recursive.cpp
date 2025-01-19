#include <bits/stdc++.h>
using namespace std;

int KnapSack(int weight[], int price[], int n, int wc) {

    if (n == 0 || wc == 0)
        return 0;

    if (weight[n] > wc) {
        return KnapSack(weight, price, n - 1, wc);
    }
    else {
        int include_profit = price[n] + KnapSack(weight, price, n - 1, wc - weight[n]);
        int exclude_profit = KnapSack(weight, price, n - 1, wc);
        return max(include_profit, exclude_profit);
    }
}

int main() {
    int n, wc;
    cout << "Input the number of items and the weight capacity:\n";
    cin >> n >> wc;

    int weight[n + 1];
    int price[n + 1];

    cout << "Input weights and prices of items :\n";
    for (int i = 1; i <= n; i++) {
        cin >> weight[i] >> price[i];
    }

    int ans = KnapSack(weight, price, n, wc);
    cout << "Maximum profit : " << ans << endl;

    return 0;
}
