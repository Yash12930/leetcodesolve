#include <bits/stdc++.h>
using namespace std;
long long solve(int n, long long *arr){
    long long ans = 0;
     for (long long i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            ans += (arr[i - 1] - arr[i]);
            arr[i] = arr[i - 1];
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    long long m[n];
    for(int i=0; i<n; i++){
        cin >> m[i];
    }
    cout << solve(n,m) << endl;;
}