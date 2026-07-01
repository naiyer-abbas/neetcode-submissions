class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int mx = 0;
        int i = 0, j = n - 1;
        while(i < j)
        {
            int water = min(heights[i], heights[j]) * (j - i);
            mx = max(mx, water);
            if(heights[i] < heights[j])
                i ++;
            else
                j --;
        }
        return mx;
    }
};
