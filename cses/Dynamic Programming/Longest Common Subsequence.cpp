#include<bits/stdc++.h>
#define REP(i, a, b) for(auto i = a; i < b; i++)
#define BEP(i, a, b) for(auto i = a; i > b; i--)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
const int MAX_N = 100005;
//CODE BY YASH1290 BRUH

ll mpow(ll base, ll exp);
bool isPrime(ll n);

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> a1(n), a2(m);
    for(int i=0; i<n; i++) cin >> a1[i];
    for(int i=0; i<m; i++) cin >> a2[i];

    vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
    vector<int> res;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a1[i-1] == a2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout << dp[n][m] <<"\n";
    
    int i = n, j = m;
    while(i > 0 && j > 0){
        if(a1[i-1] == a2[j-1]){
            res.push_back(a1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }

    reverse(res.begin(), res.end());
    for(int x: res) cout << x << " ";
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solve();
}

ll mpow(ll base, ll exp){
    ll result = 1;

    base %= mod;
    while(exp > 0){
        if(exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    

    return result;
}

bool isPrime(ll n){
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (ll i = 5; i * i <= n; i += 6) if (n % i == 0 || n % (i + 2) == 0) return false;

    return true;
}