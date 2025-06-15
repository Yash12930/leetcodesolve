class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string maxs = s;
        char tomax = 0;
        for(char c : s){
            if(c != '9'){
                tomax = c;
                break;
            }
        }

        if(tomax){
            for(char& c:maxs) if(c == tomax) c = '9';
        }
        int maxn = stoi(maxs);

        string mins = s;
        if (s[0] != '1') {
            char tomin = s[0];
            for(char& c:mins) if(c == tomin) c = '1';
        } else {
            char tomin = 0;
            for(int i = 1; i < s.size(); ++i){
                if(s[i] != '0' && s[i] != '1'){
                    tomin = s[i];
                    break;
                }
            }
            if(tomin){
                for(int i = 1; i < mins.size(); ++i){
                    if(mins[i] == tomin) mins[i] = '0';
                }
            }
        }
        int minn = stoi(mins);

        return maxn - minn;
    }
};