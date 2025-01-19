#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int WC = 100;
int table[N + 1][WC + 1];

int KnapSack(int weight[], int price[], int n, int wc) {
    if (table[n][wc] != -1)
        return table[n][wc];

    if (weight[n] > wc)
        return table[n][wc] = KnapSack(weight, price, n - 1, wc);
    else {
        int include_profit = price[n] + KnapSack(weight, price, n - 1, wc - weight[n]);
        int exclude_profit = KnapSack(weight, price, n - 1, wc);
        return table[n][wc] = max(include_profit, exclude_profit);
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

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= wc; w++) {
            if (i == 0 || w == 0)
                table[i][w] = 0;
            else
                table[i][w] = -1;
        }
    }
    int ans = KnapSack(weight, price, n, wc);
    cout << "Maximum Profit: " << ans << endl;

    return 0;
}
