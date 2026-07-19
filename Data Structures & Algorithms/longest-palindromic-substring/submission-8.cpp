class Solution {
public:
    void expand(string &s, int low, int high, int &start, int &mx)
    {
        int n = s.size();
        while(low >= 0 && high < n && s[low] == s[high])
        {
            int len = (high - low) + 1;
            if(mx < len)
            {
                mx = len;
                start = low;
            }
            low --;
            high ++;
        }
    }

    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int mx = 1;
        for(int i = 1; i < n; i ++)
        {
            // odd case
            expand(s, i, i, start, mx);
            // even case
            expand(s, i - 1, i, start, mx);
        }
        return s.substr(start, mx);
    }
};
