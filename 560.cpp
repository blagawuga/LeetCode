class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 1)
            return (nums[0] == k) ? 1 : 0;
        
        map<int, int> sum_map;
        
        int count = 0;
        int sum = 0;
        sum_map[0] = 1;
        
        
        for (int i=0; i<nums.size(); ++i) {
            sum += nums[i];
            if (sum_map.find(sum - k) != sum_map.end()) {
                count += sum_map[sum - k];
            }
            
            if (sum_map.find(sum) != sum_map.end()) {
                sum_map[sum]++;
            } else {
                sum_map[sum] = 1;
            } 
        }
        
        return count;
    }
};