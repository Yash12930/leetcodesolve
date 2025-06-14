#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    int a, b;
    cin >> a >> b;
    vector < vector <int>> dp(a+1, vector <int> (b+1, INT_MAX));

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            if(i == j) dp[i][j] = 0;
        }
    }
    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j] + 1);
            for(int k=1; k<j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k] + 1);
        }
    }
    cout << dp[a][b] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}