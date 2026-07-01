class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int trap = 0;
        while(left < right)
        {
            if(height[left] <= height[right])
            {
                trap += max(0, leftMax - height[left]);
                leftMax = max(leftMax, height[left]);
                left ++;
            }

            else
            {
                trap += max(0, rightMax - height[right]);
                rightMax = max(rightMax, height[right]);
                right --;
            }
        }
        return trap;
    }
};
