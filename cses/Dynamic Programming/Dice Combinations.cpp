#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
//CODE BY YASH1290 BRUH

void solve(){
    int n;
    cin >> n;
    vector <int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=6 && i-j >=0; j++){
            dp[i] = (dp[i] + dp[i-j])%MOD;
        }
    }
    cout << dp[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}