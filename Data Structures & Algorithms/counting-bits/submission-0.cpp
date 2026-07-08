class Solution {
public:
    vector<int> countBits(int n) {
        vector <int> ans(n + 1);
        ans[0] = 0;
        if(n == 0)
            return ans;
        ans[1] = 1;
        int msb = 2;
        for(int i = 2; i <= n; i ++)
        {
            if(i == msb * 2)
                msb *= 2;
            ans[i] = 1 + ans[i - msb]; // 00 01 10 11
        }
        return ans;
    }
};
