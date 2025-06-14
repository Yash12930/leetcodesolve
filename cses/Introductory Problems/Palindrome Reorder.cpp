#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    unordered_map<char, int> freq;
    for (char c : s){
        freq[c]++;
    }
    int odd_count = 0;
    char odd_char = '\0';
    for (auto &entry : freq){
        if (entry.second % 2 != 0) {
            odd_count++;
            odd_char = entry.first;
        }
    }
    if (odd_count > 1){
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    string half = "";
    for (auto &entry : freq){
        half += string(entry.second / 2, entry.first);
    }
    string palindrome = half;
    if (odd_count == 1){
        palindrome += odd_char;
    }
    reverse(half.begin(), half.end());
    palindrome += half;
    cout << palindrome << endl;
}