class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // calculate n!
        int n = nums.size();
        vector<int> output(n, 0);
        
        vector<int> a(n, 0);
        vector<int> b(n, 0);
        
        a[0] = 1;
        b[n-1] = 1;
        
        // Fill a
        for (int i=1; i<n; ++i) {
            a[i] = a[i-1]*nums[i-1];
        }
        
        // Fill b
        for (int i=1; i<n; ++i) {
            b[n-i-1] = b[n-i]*nums[n-i];
        }
        
        // fill output by multiplying a and b
        for (int i=0; i<n; ++i) {
            output[i] = a[i]*b[i];
        }
        
        return output;
    }
};