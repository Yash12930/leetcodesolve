#include <bits/stdc++.h>
using namespace std;

void decToGrayCode(long long n, int bits){
    long long grayNum = n ^ (n >> 1);
    cout << bitset<64>(grayNum).to_string().substr(64 - bits) << endl;
}

int main(){
    long long n;
    cin >> n;
    long long a = pow(2, n);
    for(int i=0; i<a; i++){
        decToGrayCode(i, n);
    }
}