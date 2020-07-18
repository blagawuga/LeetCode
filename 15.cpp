class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
    
        if (nums.size() == 0 || nums.size() == 1 || nums.size() == 2)
            return result;        
        
        // Sort the numbers    
        sort(nums.begin(), nums.end());
        
        
        
        for (int i=0; i<nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i-1]) {
                int lo = i+1;
                int hi = nums.size() - 1;
                while (lo < hi) {
                    int sum = nums[lo] + nums[hi] + nums[i];
                    if (sum > 0) {
                        hi--;
                    }
                    if (sum < 0) {
                        lo++;
                    }
                    else if (sum == 0) {
                        result.push_back({ nums[i], nums[lo++], nums[hi--]});
                    }
                    
                }
            }
            
        }
        
        // Uniquing and resizing
        vector<vector<int>>::iterator ip = unique(result.begin(), result.end());
        result.resize(distance(result.begin(), ip));
        return result;
    }
};