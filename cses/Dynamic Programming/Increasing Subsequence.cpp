#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

void solve(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector <int> dp;
    for(int x: arr){
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) dp.push_back(x);
        else *it = x;
    }
    cout << dp.size() << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}