#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long trailing_zeros = 0;
    for (long long i = 5; n / i >= 1; i *= 5) {
        trailing_zeros += n / i;
    }
    cout << trailing_zeros << endl;
}