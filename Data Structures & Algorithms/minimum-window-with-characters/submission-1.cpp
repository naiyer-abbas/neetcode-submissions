class Solution {
public:
    
    string minWindow(string s, string t) {
        vector <int> need(128, 0);
        int ans = INT_MAX;

        for(char &e: t)
            need[e] ++;
        int m = s.size();
        int n = t.size();
        if(m < n)
            return "";
        int left = 0, right = 0;
        int start = 0, end = 0;
        int count = t.size();
        while(right < m)
        {
            if(need[s[right]] > 0)
                count --;
            need[s[right]] --;
            while(count == 0)
            {
                if((right - left) + 1 < ans)
                {
                    start = left;
                    end = right;
                    ans = (right - left) + 1;
                }
                need[s[left]] ++;
                if(need[s[left]] > 0)
                    count ++;
                left ++;
            }
            right ++;
        }
        if(ans == INT_MAX)
            return "";
        string  res = s.substr(start, (end - start) + 1);
        return res;
    }
};
