class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mx = 0;
        int idx = 0;
        for(int i = 1; i < n; i ++)
        {
            int ans = prices[i] - prices[idx];
            mx = max(mx, ans);
            if(prices[i] < prices[idx])
                idx = i;
        }
        return mx;
    }
};
