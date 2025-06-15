class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long result = LLONG_MIN;
        long long maxl = nums[0], minl = nums[0];
        int left = 0;
        
        for (int j = m-1; j < n; ++j) {
            while (left < j - (m - 1)) {
                left++;
                maxl = max(maxl, (long long)nums[left]);
                minl = min(minl, (long long)nums[left]);
            }
            result = max(result, maxl * nums[j]);
            result = max(result, minl * nums[j]);
        }
        return result;
    }
};