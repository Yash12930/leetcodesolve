#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
//CODE BY YASH1290 BRUH

void solve(){
    int n;
    cin >> n;
    vector <int> dp(n+1, MOD);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        int num = i;
        while(num>0){
            int digit = num%10;
            num /=10;
            if(digit > 0) dp[i] = min(dp[i], dp[i-digit] + 1);
        }
    }
    cout << dp[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}