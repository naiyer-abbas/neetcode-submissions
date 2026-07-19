class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int mx = 1;
        for(int i = 1; i < n; i ++)
        {
            // odd case
            for(int j = 1; i - j >= 0 && i + j < n; j ++)
            {
                int len = 2 * j + 1;
                if(s[i - j] == s[i + j])
                {
                    if(mx < len)
                    {
                        mx = len;
                        start = i - j;
                    }
                }

                else
                    break;
            }

            // even case
            int low = i - 1, high = i;
            int len;
            while(low >= 0 && high < n && s[low] == s[high])
            {
                len = (high - low) + 1;
                if(mx < len)
                {
                    mx = len;
                    start = low;
                }
                low --;
                high ++;
            }
        }
        return s.substr(start, mx);
    }
};
