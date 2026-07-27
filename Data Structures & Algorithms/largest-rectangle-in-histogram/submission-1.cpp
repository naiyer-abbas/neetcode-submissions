class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> st;
        int n = heights.size();
        vector <int> small_prev(n, -1);
        vector <int> small_next(n, n);
        for(int i = n - 1; i >= 0; i --)
        {
            while(!st.empty() && heights[st.top()] > heights[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                small_next[i] = st.top();
            }
            st.push(i);
        }

        st = stack <int>(); // clearing the stack

        for(int i = 0; i < n; i ++)
        {
            while(!st.empty() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }

            if(!st.empty())
            {
                small_prev[i] = st.top();
            }
            st.push(i);
        }

        int mx = 0;

        for(int i = 0; i < n; i ++)
        {
            int right = small_next[i];
            int left = small_prev[i];
            int width = right - left - 1;
            int ans = width * heights[i];
            mx = max(ans, mx);
        }
        return mx;
    }
};
