#include <bits/stdc++.h>
using namespace std;

int main(){
    string c;
    cin >> c;
    char current;
    int count = 0, answer = 0;
    for(int i=0; i<c.size(); i++){
        if (c[i] != current) {
            current = c[i];
            count = 0;
        }
        if(c[i] == current){
            count++;
        }
        answer = max(answer, count);
    }
    cout << answer << endl;
}