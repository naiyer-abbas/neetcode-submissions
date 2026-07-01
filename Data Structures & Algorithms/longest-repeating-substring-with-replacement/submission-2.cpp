class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int start = 0;
        int ans = 0;
        unordered_map <int, int> um;
        for(int i = 0; i < n; i ++)
        {
            um[s[i]] ++;
            int mx = 0;
            for(auto &e: um)
            {
                mx = max(mx, e.second);
            }
            int len = (i - start) + 1;
            int replace = len - mx;
            //cout << "i : " << i << "       start : " << start << "     mx: " <<  mx  <<    "         len" << len << "      ans :    " << ans << endl; 
            if(replace <= k)
                ans = max(ans, len);
            else
            {
                um[s[start]] --;
                um[s[i]] --;
                start ++;
                i --;
            }
            
        }
        return ans;
    }
};
