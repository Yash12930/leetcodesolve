#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//CODE BY YASH1290 BRUH
const ll MAX = 1e17 + 7;
const ll mod = 1e9+7;

vector<vector<int>>dp;

void calc(int i, int m, int mask, int next_mask, vector<int>& next){
  if(i == m) {
    next.push_back(next_mask);
    return;
  }
  
  int x = (mask>>i)&1;
  int y = (mask>>(i+1))&1;
  
  if(x == 0){
    // horizontal block placement
    calc(i+1, m, mask, next_mask|(1<<i), next);
    
    // vertical block placement
    if(y == 0 && i+1 < m) calc(i+2, m, mask, next_mask, next);
  }
  else calc(i+1, m, mask, next_mask, next);
}

int solve(int col, int mask, int m, int n){
  if(col == n) return (mask == 0);
  
  if(dp[col][mask] != -1) return dp[col][mask];
  
  vector<int>next;
  calc(0, m, mask, 0, next);
  
  int ans = 0;
  
  for(auto next_mask: next) ans = (ans + solve(col+1, next_mask, m, n))%mod;
  return  dp[col][mask] = ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n; cin>>m>>n;
    dp.resize(n, vector<int>(pow(2, m), -1));
 
    int ans = solve(0, 0, m, n);
    cout<<ans<<endl;
}