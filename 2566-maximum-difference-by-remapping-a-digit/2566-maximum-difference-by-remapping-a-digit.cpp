class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        char nignig = s[0];

        //we just want the msb to be 0 and 9, in cases where its already 9, go to the next msb which is not 9
        string maxs = s;
        char replacement = 0;
        for(char c: s) if(c != '9'){
            replacement = c;
            break;
        }
        for(char& c:maxs) if(c == replacement) c = '9';
        int maxn = stoi(maxs);

        string mins = s;
        for(char& c:mins) if(c == nignig) c = '0';
        int minn = stoi(mins);

        return maxn - minn;
    }
};