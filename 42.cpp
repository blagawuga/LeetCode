class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;
        // find minima  point
        vector<int> minimaPoints;
        for (int i=1; i<height.size()-1; i++) {
            if (height[i-1] > height[i] && height[i+1] >= height[i])
                minimaPoints.push_back(i);
        }
        
        int totalWater = 0;
        
        
        for (int i=0; i<minimaPoints.size(); i++) {
            // Expand left pivot 
            int leftMax = minimaPoints[i] - 1;
            int rightMax = minimaPoints[i] + 1;
            
            while (leftMax-1 >= 0 && height[leftMax] <= height[leftMax - 1])
                leftMax--;
            
            while (rightMax+1 < height.size() && height[rightMax] <= height[rightMax + 1])
                rightMax++;
            
            int maxHeight = min(height[leftMax], height[rightMax]);
            for (int j=leftMax; j<=rightMax; j++) {
                if (maxHeight > height[j])  {
                    int rem = (maxHeight - height[j]);
                    totalWater += rem;
                    height[j] += rem;
                }
                    
            }
        }
        
        return totalWater;
    }
};