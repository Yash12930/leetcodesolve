#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
//CODE BY YASH1290 BRUH

void solve(){
    int n, x;
    cin >> n >> x;
    vector <int> dp(x+1, -1);
    vector <int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    dp[0] = 0;
    for(int i=1; i<=x; i++){
        for(int coins:a){
            if(coins <=i && dp[i-coins]!=-1){
                if(dp[i]==-1) dp[i] = dp[i-coins] + 1;
                else dp[i] = min(dp[i-coins] + 1, dp[i]);
            }
        }
    }
    cout << dp[x] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}