#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    string n1, m1;
    cin >> n1 >> m1;
    int n = n1.size(), m = m1.size();
    vector <vector <int>> dp(n+1, vector <int> (m+1, 0));

    for(int i=1; i<=n; i++) dp[i][0] = i;
    for(int j=1; j<=m; j++) dp[0][j] = j;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(n1[i-1] == m1[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        }
    }

    cout << dp[n][m] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}