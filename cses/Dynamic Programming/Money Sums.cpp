#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];

    int maxsum = accumulate(a.begin(), a.end(), 0);
    vector <bool> dp(maxsum + 1, false);
    dp[0] = true;
    for(int coin : a){
        for(int i=maxsum; i>=coin; i--){
            if(dp[i-coin]) dp[i] = true;
        }
    }

    vector <int> possum;
    for(int i=1; i<=maxsum; i++){
        if(dp[i]) possum.push_back(i);
    }

    cout << possum.size() << endl;
    for(int sum: possum) cout << sum << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}