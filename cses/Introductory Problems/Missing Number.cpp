#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long expected_sum = n * (n + 1) / 2; // Sum of the first n natural numbers
    long long actual_sum = 0;
    int num;

    for (int i = 0; i < n - 1; ++i) {
        cin >> num;
        actual_sum += num;
    }
    
    cout << expected_sum - actual_sum << endl;
}