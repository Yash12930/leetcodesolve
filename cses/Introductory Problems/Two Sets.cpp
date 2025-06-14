#include <bits/stdc++.h>
using namespace std;

void display(vector<int> &v) {
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void output(int n){
    vector <int> a, b;
    if(n%4 == 0){
        cout << "YES" << endl;
        for(int i=1; i<=n; i++){
            if(i <= n/4){
                a.push_back(i);
            }else if(i > 3*n/4){
                a.push_back(i);
            }else{
                b.push_back(i);
            }
        }
        cout << a.size() << endl;
        display(a);

        cout << b.size() << endl;
        display(b);
    }else if(n%4 == 3){
        cout <<  "YES" << endl;
        for(int i=1; i<=n; i++){
            if(i <= (n+1)/4){
                a.push_back(i);
            }else if(i == (n+1)/2){
                a.push_back(i);
            }else if(i > 3*(n+1)/4){
                a.push_back(i);
            }else{
                b.push_back(i);
            }
        }
        cout << a.size() << endl;
        display(a);

        cout << b.size() << endl;
        display(b);
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int n;
    cin >> n;
    output(n);
}