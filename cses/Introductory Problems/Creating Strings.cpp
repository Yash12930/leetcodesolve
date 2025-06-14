#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    sort(str.begin(), str.end());
    vector<string> res;
    do {res.push_back(str);}
    while(next_permutation(str.begin(), str.end()));
    cout << res.size() << '\n';
    for (auto &x : res) cout << x << '\n';
}