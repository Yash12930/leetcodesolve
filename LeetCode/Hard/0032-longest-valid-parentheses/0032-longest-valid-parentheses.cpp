class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, maxlen = 0, n = s.length();

        for(int i=0; i<n; i++){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) maxlen = max(maxlen, 2*close);
            else if(close > open) open = close = 0;
        }

        close = open = 0;
        for(int i=n-1; i>-1; i--){
            if(s[i] == '(') open++;
            else close++;
            if(open == close) maxlen = max(maxlen, 2*close);
            else if(close < open) open = close = 0;
        }

        return maxlen;
    }
};