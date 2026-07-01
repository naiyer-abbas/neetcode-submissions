class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        int ans = 0, mx = 0;
        unordered_map <int, int> um;
        for(int i = 0; i < n; i ++)
        {
            um[s[i]] ++;
            mx = max(mx, um[s[i]]);
            int len = (i - start) + 1;
            int replace = len - mx;
            if(replace <= k)
                ans = max(ans, len);
            else
            {
                um[s[start]] --;
                start ++;
            }
            
        }
        return ans;
    }
};
