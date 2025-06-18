class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];

            if(slow == fast) break;
        }
        int slowag = nums[0];
        while(slow != slowag){
            slow = nums[slow];
            slowag = nums[slowag];
        }
        return slow;
    }
};