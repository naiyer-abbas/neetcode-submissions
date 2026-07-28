class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int n = heights.size();
        int mx = 0;
        for(int i = 0; i < n; i ++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                int top = st.top();
                st.pop();
                int right = i;
                int left = -1;
                if(!st.empty())
                    left = st.top();
                int ans = heights[top] * (right - left - 1);
                mx = max(ans, mx); 
            }
            st.push(i);
        }

        int right = n;
        int left = -1;

        while(!st.empty())
        {
            int top = st.top();
            st.pop();
            if(!st.empty())
                left = st.top();
            else 
                left = -1;
            int ans = heights[top] * (right - left - 1);
            mx = max(mx, ans);
            //right = top;
        }
        return mx;
    }
};
