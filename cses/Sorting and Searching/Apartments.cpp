#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n); 
    vector<int> b(m); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int applicantIndex = 0;
    int apartmentIndex = 0;
    int matchedApplicants = 0;

    while(applicantIndex < n && apartmentIndex < m){
        if(b[apartmentIndex] < a[applicantIndex] - k){
            apartmentIndex++;
        }else if(b[apartmentIndex] > a[applicantIndex] + k){
            applicantIndex++;
        }else{
            matchedApplicants++;
            applicantIndex++;
            apartmentIndex++;
        }
    }
    cout << matchedApplicants << endl;
}
