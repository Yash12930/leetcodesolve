#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    ll n;
    cin >> n;
    ll totsum = (1ll*n*(n+1))/2;
    if(totsum%2 != 0) cout << 0 << endl;
    ll target = totsum/2;
    vector <ll> dp(target+1, 0);
    dp[0] = 1;
    for(ll i=1; i<n; i++){
        for(ll j=target; j>=i; j--){
            dp[j] += dp[j-i];
            dp[j] %= MOD;
        }
    }
    if(totsum%2 == 0) cout << dp[target] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}