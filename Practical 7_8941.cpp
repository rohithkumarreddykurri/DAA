#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, amount;

    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter total amount: ";
    cin >> amount;

    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    cout << "Minimum coins = " << dp[amount] << endl;

    return 0;
}