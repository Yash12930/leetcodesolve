#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//CODE BY YASH1290 BRUH
const ll MAX = 1e17 + 7;
const ll mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector <int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    pair <int, int> dp[1<<n];
    dp[0] = {1,0};

    for(int i=1; i<(1<<n); i++){
        dp[i] = {21, 0};
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                pair <int, int> cna = dp[i^(1<<j)];
                if(cna.second + a[j] <= x){
                    cna.second += a[j];
                }else{
                    cna.first++;
                    cna.second = a[j];
                }
                dp[i] = min(dp[i], cna);
            }
        }
    }
    cout << dp[(1<<n)-1].first << endl;
}
