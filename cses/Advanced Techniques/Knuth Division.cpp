#include<bits/stdc++.h>
#define REP(i, a, b) for(int i = a; i < b; i++)
#define BEP(i, a, b) for(int i = a; i > b; i--)
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
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node);
void bfs(vector<vector<int>>& adj, vector<bool>& vis, int start);

void solve(){
    int n;
    cin >> n;
    vector<int> x(n);
    REP(i, 0, n) cin >> x[i];
    
    vector<ll> prefix(n+1, 0);
    REP(i, 0, n) prefix[i+1] = prefix[i] + x[i];

    vector<vector<ll>> dp(n, vector<ll> (n, 0));
    vector<vector<ll>> opt(n, vector<ll> (n, 0));
    REP(i, 0, n) opt[i][i] = i;
    REP(len, 2, n+1){
        REP(i, 0, n-len+1){
            int j = len-1+i;
            dp[i][j] = LLONG_MAX;
            ll sum = prefix[j+1] - prefix[i];

            int l = opt[i][j-1];
            int r = opt[i+1][j];
            if(r==0) r = j-1;
            REP(k, l, r+1) if(k<j){
                ll cost = dp[i][k] + dp[k+1][j] + sum;
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                    opt[i][j] = k;
                }
            }
        }
    }
    cout << dp[0][n-1] << "\n";
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

void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node) {
    vis[node] = true;
    cout << node << " ";
    
    for(int neighbor : adj[node]) {
        if(!vis[neighbor]) {
            dfs(adj, vis, neighbor);
        }
    }
}

void bfs(vector<vector<int>>& adj, vector<bool>& vis, int start) {
    queue<int> q;
    vis[start] = true;
    q.push(start);
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        cout << node << " ";
        
        for(int neighbor : adj[node]) {
            if(!vis[neighbor]) {
                vis[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}
