#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7;
const int maxN = 1000;
//CODE BY YASH1290 BRUH

void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    vector <vector <int>> dp(n, vector <int>(m+1, 0));

    if(a[0] == 0) fill(dp[0].begin(), dp[0].end(), 1);
    else dp[0][a[0]] = 1;

    for(int i=1; i<n; i++){
        if(a[i] == 0){
            for(int j=1; j<=m; j++){
                for(int k: {j-1, j, j+1}){
                    if(k>=1 && k<=m) dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
                }
            }
        }else{
            int j = a[i];
            for(int k: {j-1, j, j+1}){
                if(k>=1 && k<=m) dp[i][j] = (dp[i][j] + dp[i-1][k])%MOD;
            }
        }
    }
    int result = 0;
    for(int j=1; j<=m; j++) result = (result + dp[n-1][j])%MOD;
    cout << result << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}