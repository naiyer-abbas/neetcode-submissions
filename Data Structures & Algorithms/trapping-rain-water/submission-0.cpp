class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector <int> prefix(n, 0);
        vector <int> suffix(n, 0);
        int mx = prefix[0] = height[0];
        for(int i = 1; i < n; i ++)
        {
            mx = max(mx, height[i]);
            prefix[i] = mx;
            //cout << prefix[i] << " ";
        }
        //cout << endl;

        mx = suffix[n - 1] = height[n - 1];

        for(int i = n - 2; i >= 0; i --)
        {
            mx = max(mx, height[i]);
            suffix[i] = mx;
            //cout << suffix[i] << " ";
        }

        int trap = 0;

        for(int i = 1; i < n - 1; i++)
        {
            trap += max(min(prefix[i - 1], suffix[i + 1]) - height[i], 0);
        }
        return trap;
    }
};
