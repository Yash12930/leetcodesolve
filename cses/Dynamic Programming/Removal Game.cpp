#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    int n;
    cin >> n;
    vector <ll> scores(n);
    ll totsum = 0;
    for(int i=0; i<n; i++){
        cin >> scores[i];
        totsum += scores[i];
    }

    vector <vector <ll>> dp(n, vector <ll> (n, 0));

    for(int i=0; i<n; i++) dp[i][i] = scores[i];

    for(int len=2; len<=n; len++){
        for(int i=0; i<=n-len; i++){
            int j = i+len-1;
            dp[i][j] = max(scores[i] - dp[i+1][j], scores[j] - dp[i][j-1]);
        }
    }
    ll score = (totsum + dp[0][n-1])/2;
    cout << score << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}