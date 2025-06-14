class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            int a2 = target - nums[i];
            if(mp.count(a2)) return {mp[a2], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};