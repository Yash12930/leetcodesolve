#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
const ll maxN = 1e6;
//CODE BY YASH1290 BRUH

struct project{
    int start, end, reward;
};

bool compareProjects(const project& a, const project& b){
    return a.end < b.end;
}

void solve(){
    int n;
    cin >> n;
    vector <project> projects(n);
    for(int i=0; i<n; i++) cin >> projects[i].start >> projects[i].end >> projects[i].reward;

    sort(projects.begin(), projects.end(), compareProjects);

    vector <ll> dp(n+1, 0);
    vector <ll> endt(n);
    for (int i=0; i<n; i++) endt[i] = projects[i].end;
    
    for(int i=1; i<=n; i++){
        ll curr = projects[i-1].start;
        int j = upper_bound(endt.begin(), endt.begin()+i-1, curr-1) - endt.begin();
        dp[i] = max(dp[i-1], projects[i-1].reward + dp[j]);
    }
    cout << dp[n] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}