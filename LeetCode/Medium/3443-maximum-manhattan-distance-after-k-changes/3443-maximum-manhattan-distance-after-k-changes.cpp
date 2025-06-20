class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.length();
        
        vector<vector<int>> counts(n + 1, vector<int>(4, 0));
        for (int i = 0; i < n; ++i) {
            counts[i + 1] = counts[i];
            if (s[i] == 'N') counts[i + 1][0]++;
            else if (s[i] == 'S') counts[i + 1][1]++;
            else if (s[i] == 'E') counts[i + 1][2]++;
            else if (s[i] == 'W') counts[i + 1][3]++;
        }

        int maxdisttot = 0;

        for (int i = 1; i <= n; ++i) {
            int cN = counts[i][0];
            int cS = counts[i][1];
            int cE = counts[i][2];
            int cW = counts[i][3];

            int vpair = min(cN, cS);
            int hpair = min(cE, cW);
            int totpair = vpair + hpair;
            int unfix = max(0, totpair - k);
            int maxdist = i - 2 * unfix;
            maxdisttot = max(maxdisttot, maxdist);
        }

        return maxdisttot;
    }
};