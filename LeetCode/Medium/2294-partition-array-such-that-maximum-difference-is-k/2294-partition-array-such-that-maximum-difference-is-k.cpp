class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count = 1;
        int currel = nums[0];

        for(int i=1; i<n; i++){
            if(nums[i] > currel + k){
                currel = nums[i];
                count++;
            }
        }
        return count;
    }
};