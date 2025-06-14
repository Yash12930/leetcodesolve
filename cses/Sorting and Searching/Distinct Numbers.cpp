#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    set <int> arr;
    int j=0;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        arr.insert(x);
    }
    cout << arr.size() << endl;
}