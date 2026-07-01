class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int mx = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = i + 1; j < n; j ++)
            {
                int water = min(heights[i], heights[j]) * (j - i);
                mx = max(mx, water);
            }
        }
        return mx;
    }
};
