class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int m = nums1.size(), n = nums2.size();
        int imin = 0, imax = m, half = (m + n + 1) / 2;
        while(imin <= imax){
            int i = (imin + imax)/2;
            int j = half - i;
            int aleft = (i==0) ? INT_MIN : nums1[i-1];
            int aright = (i == m) ? INT_MAX : nums1[i];
            int bleft = (j==0) ? INT_MIN : nums2[j-1];
            int bright = (j==n) ? INT_MAX : nums2[j];

            if(aleft <= bright && bleft <= aright){
                if((m+n)%2 == 0) return(max(aleft, bleft) + min(aright, bright))/2.0;
                else return max(aleft, bleft);
            }else if(aleft > bright) imax = i-1;
            else if(aright < bleft) imin = i+1;
        }
        return 0.0;
    }
};