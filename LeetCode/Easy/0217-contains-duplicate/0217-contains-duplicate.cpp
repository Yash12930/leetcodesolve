class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size(); 
        unordered_set<int> number(n);
        for(int num : nums){
            if(number.find(num) != number.end()) return true;
            number.insert(num);
        }
        return false;
    }
};