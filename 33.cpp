class Solution {
public:
    int find_rotate_index(int left, int right, vector<int> &nums) {
        if (nums[left] < nums[right])
          return 0;

        while (left <= right) {
          int pivot = (left + right) / 2;
          if (nums[pivot] > nums[pivot + 1])
            return pivot + 1;
          else {
            if (nums[pivot] < nums[left])
              right = pivot - 1;
            else
              left = pivot + 1;
          }
        }
        return 0;
    }
    int searchUtil(vector<int> &nums, int lo, int hi, int target) {
        if (lo > hi)
            return -1;
        
        int mid = (lo+hi)/2;

        if (nums[mid] == target)
            return mid;
        else if (nums[mid] > target)
            return searchUtil(nums, lo, mid-1, target);
        else
            return searchUtil(nums, mid+1, hi, target);
    }

    
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return (nums[0] == target) ? 0 : -1;
        
        int pivot = find_rotate_index(0, nums.size()-1, nums);
        
        int res = -1;
        if (target == nums[pivot])
            return pivot;
        else if (pivot == 0)
            res = searchUtil(nums, 0, nums.size()-1, target);
        else if (target < nums[0])
            res = searchUtil(nums, pivot+1, nums.size()-1, target);
        else
            res = searchUtil(nums, 0, pivot-1, target);
        
        return res;
    }       
};