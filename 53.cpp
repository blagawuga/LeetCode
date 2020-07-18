class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //  Let L[i] denote the largest sum till ith index (including the ith element)

        for (int i=1; i<nums.size(); i++) {
            if (nums[i] + nums[i-1] > nums[i])
                nums[i] = nums[i] + nums[i-1];
        }
        
        return *max_element(nums.begin(), nums.end());
    }
};