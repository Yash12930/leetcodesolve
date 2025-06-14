#include<bits/stdc++.h>
#define rep(i, a, b) for(auto i = a; i < b; i++)
#define bep(i, a, b) for(auto i = a; i > b; i--)
#define all(x) x.begin(), x.end()
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
typedef long long ll;
using namespace std;
const ll mod = 1e9+7;
const int MAX_N = 200005;
const ll INF = 1e18;
//CODE BY nger8028 BRUH

ll mpow(ll base, ll exp);
bool isPrime(ll n);

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    rep(i, 0, n) cin >> grid[i];

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            for (int c = 'A'; c <= 'D'; c++) {
                bool fail = false;
                if (grid[y][x] == c) fail = true;
                if (y > 0 && grid[y - 1][x] == c) fail = true;
                if (x > 0 && grid[y][x - 1] == c) fail = true;
                if (!fail) {
                    grid[y][x] = c;
                    break;
                }
            }
            cout << grid[y][x];
        }
        cout << "\n";
    }
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
    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0) return false;
    return true;
}
