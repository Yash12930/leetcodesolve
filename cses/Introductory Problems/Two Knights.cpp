#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> results(n + 1, 0);
    for (int k = 1; k <= n; ++k){
        long long k2 = static_cast<long long>(k) * k;
        long long total_ways = k2 * (k2 - 1) / 2;
        long long attacking_ways = 0;
        if (k > 2){
            attacking_ways = 4 * (k - 1) * (k - 2);
        }
        results[k] = total_ways - attacking_ways;
    }
    for (int k = 1; k <= n; ++k){
        cout << results[k] << endl;
    }
}