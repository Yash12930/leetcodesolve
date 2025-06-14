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

class DSU {
public:
    vector<int> parent, rank;
    int components;
    
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        components = n;
        REP(i, 1, n+1){
            parent[i] = i;
        }
    }
    
    int find(int x) {
        if(parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if(px == py) return false;
        
        if(rank[px] < rank[py]) swap(px, py);
        parent[py] = px;
        if(rank[px] == rank[py]) rank[px]++;
        
        components--;
        return true;
    }
};

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> edges(m);
    set<pair<int, int>> edgeset;

    REP(i, 0, m){
        cin >> edges[i].first >> edges[i].second;
        edgeset.insert({min(edges[i].first, edges[i].second), max(edges[i].first, edges[i].second)});
    }
    vector<pair<int, int>> breakdown(k);
    REP(i, 0, k){
        cin >> breakdown[i].first >> breakdown[i].second;
        edgeset.erase({min(breakdown[i].first, breakdown[i].second), max(breakdown[i].first, breakdown[i].second)});
    }

    DSU dsu(n);
    for(auto edge : edgeset) dsu.unite(edge.first, edge.second);

    vector<int> result;
    result.push_back(dsu.components);

    BEP(i, k-1, 0){
        dsu.unite(breakdown[i].first, breakdown[i].second);
        result.push_back(dsu.components);
    }

    BEP(i, result.size()-1, -1) cout << result[i] << " ";
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
