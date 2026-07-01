class Solution {
public:
    bool isSubset(unordered_map<int, int> freq1, unordered_map<int, int> freq2)
    {
        for(auto &e: freq1)
        {
            if(freq1[e.first] > freq2[e.first])
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<int, int> freq1;
        unordered_map<int, int> freq2;
        int ans = INT_MAX;

        for(auto &e: t)
            freq1[e] ++;
        int m = s.size();
        int n = t.size();
        if(m < n)
            return "";
        int left = 0, right = 0;
        int start = 0, end = 0;
        while(right < m && left <= right)
        {
            freq2[s[right]] ++;
            //cout << "left : " << left << "   right : " << right << endl;
            while(left <= right && isSubset(freq1, freq2))
            {
                //cout << "PASS  " << "  ans  :  " << ans << "    left  :  " << left << "  right: " << right << endl;
                if((right - left) + 1 < ans)
                {
                    start = left;
                    end = right;
                    ans = (right - left) + 1;
                }
                freq2[s[left]] --;
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
