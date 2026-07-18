class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        //vector<vector<int>> matrix(rows, vector<int>(cols, 1));
        vector <vector<bool>> dp(n, vector<bool>(n));
        if(n == 1) return s;
        int start = 0;
        int mx = 1;
    
        for(int i = 0; i < n; i ++)
        {
            dp[i][i] = true;
            if(i < n - 1 && (s[i] == s[i + 1]))
            {
                dp[i][i + 1] = true;
                mx = 2;
                start = i;
            }
        }

        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = true;
                    if(mx < len)
                    {
                        start = i;
                        mx = len;
                    }
                }
            }
        }
        return s.substr(start, mx); 
    }
};
