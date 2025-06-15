typedef long long ll;

class Solution {
private:
    const int MOD = 1e9+7;
    
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        int maxval = 0;
        
        maxval = *max_element(nums.begin(), nums.end());
        
        vector<ll> left(maxval + 1), right(maxval + 1);
        
        for (int x : nums) right[x]++;
        
        ll ans = 0;
        for (int j = 0; j < n; j++) {
            
            int v = nums[j];
            right[v]--;
            int val = v * 2;
            
            if (val <= maxval) {
                ans = (ans + left[val] * right[val]) % MOD;
            }
            left[v]++;
        }
        return ans;
    }
};