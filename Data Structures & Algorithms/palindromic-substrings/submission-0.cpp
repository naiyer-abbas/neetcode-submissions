class Solution {
public:
    int ans = 0;
    void expand(string &s, int low, int high)
    {
        int n = s.size();
        while(low >= 0 && high < n && s[low] == s[high])
        {
            ans ++;
            low --;
            high ++;
        }
        return;
    }

    int countSubstrings(string s) {
        int n = s.size();
        for(int i = 0; i < n; i ++)
        {
            // odd case
            int low , high;
            low = high = i;
            expand(s, low, high);

            // even case
            if(i  > 0)
            {
                low = i - 1;
                high = i;
                expand(s, low, high);
            }
        }
        return ans;
    }
};
