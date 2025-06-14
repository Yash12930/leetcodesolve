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

vector<int> topsort(int n, vector<vector<int>>& adj, vector<int>& indeg){
    queue<int> q;
    vector<int> ans;

    REP(i, 0, n){
        if(indeg[i] == 0) q.push(i);
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();

        ans.push_back(node);
        for(int child : adj[node]){
            indeg[child]--;
            if(indeg[child] == 0) q.push(child);
        }
    }
    return ans;
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge(m);
    vector<vector<int>> adj(n);
    vector<int> indeg(n);
    REP(i, 0, m){
        cin >> edge[i].first >> edge[i].second;
        edge[i].first--;
        edge[i].second--;
    }

    REP(i, 0, m){
        int u = edge[i].first;
        int v = edge[i].second;
        adj[u].push_back(v);
        indeg[v]++;
    }

    vector<int> ans = topsort(n, adj, indeg);
    if((int)ans.size()!=n) cout << "IMPOSSIBLE" << "\n";
    else for(int x:ans) cout << x+1 << " ";
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