#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int maxN = 1000;
//CODE BY YASH1290 BRUH

char c[maxN][maxN];
ll dp[maxN][maxN];

void solve() {
    int n;
    cin >> n;
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    dp[0][0] = (c[0][0] == '.') ? 1 : 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] == '.') {
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }

    cout << dp[n - 1][n - 1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}