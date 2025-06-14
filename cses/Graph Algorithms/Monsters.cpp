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
void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node);
void bfs(vector<vector<int>>& adj, vector<bool>& vis, int start);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    REP(i, 0, n) cin >> grid[i];

    queue <pair<int, int>> monster;
    int startx = -1, starty = -1;

    REP(i, 0, n){
        REP(j, 0, m){
            if(grid[i][j] == 'M') monster.push({i, j});
            if(grid[i][j] == 'A'){
                startx = i;
                starty = j;
            }
        }
    }

    vector<vector<int>> monsterdist(n, vector<int> (m, INT_MAX));
    queue<pair<int, int>> temp = monster;
    while(!temp.empty()){
        pair<int, int> pos = temp.front();
        temp.pop();
        monsterdist[pos.first][pos.second] = 0;
    }
    while(!monster.empty()){
        auto [x, y] = monster.front();
        monster.pop();

        REP(d, 0, 4){
            int nx = x+dx[d];
            int ny = y+dy[d];
            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && monsterdist[nx][ny]== INT_MAX){
                monsterdist[nx][ny] = monsterdist[x][y] + 1;
                monster.push({nx, ny});
            }
        }
    }

    vector<vector<int>> dist(n, vector<int> (m, -1));
    vector<vector<pair<int,int>>> parent(n, vector<pair<int,int>>(m, {-1,-1}));
    queue<pair<int,int>> q;

    q.push({startx, starty});
    dist[startx][starty] = 0;

    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();

        if(x == 0 || y == 0 || x == n-1 || y == m-1){
            cout << "YES\n";
            string path = "";
            int cx = x, cy = y;
            while(parent[cx][cy].first != -1){
                int px = parent[cx][cy].first;
                int py = parent[cx][cy].second;

                REP(d, 0, 4){
                    if(px+dx[d] == cx && py+dy[d] == cy){
                        path+=dir[d];
                        break;
                    }
                }
                cx = px;
                cy = py;
            }
            reverse(all(path));
            cout << path.length() << "\n" << path << "\n";
            return;
        }

        REP(d, 0, 4){
            int nx = x+dx[d];
            int ny = y+dy[d];

            if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]!='#' && dist[nx][ny]==-1 && dist[x][y]+1 < monsterdist[nx][ny]){
                dist[nx][ny] = dist[x][y]+1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
    cout << "NO\n";
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
