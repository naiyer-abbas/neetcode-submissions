class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, mx = 0, n = s.size();
        unordered_set<int> hashSet;
        int left = 0;
        for(int i = 0; i < n; i ++)
        {
            while(hashSet.find(s[i]) != hashSet.end())
            {
                hashSet.erase(s[left ++]);
                ans --;
            }
            hashSet.insert(s[i]);
            ans ++;
            mx = max(ans, mx);
        }
        return mx;
    }
};
