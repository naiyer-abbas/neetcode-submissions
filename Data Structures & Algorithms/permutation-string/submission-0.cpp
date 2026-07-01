class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector <int> freq1(26, 0);
        vector <int> freq2(26, 0);
        int n = s1.size();
        int m = s2.size();

        for(auto &e: s1)
            freq1[e - 'a'] ++;
        int start = 0;
        bool ans = false;
        if(m < n)    return false;
        int i = start + (n - 1);
        int j = 0;
        for(j = start; j <= i; j ++)
        {
            freq2[s2[j] - 'a'] ++;
        }
        j --;
        while(j < m)
        {
            if(freq1 == freq2)
                return true;
            freq2[s2[start] - 'a'] --;
            start ++;
            j ++;
            freq2[s2[j] - 'a'] ++;
        }
        if(freq1 == freq2)
            return true;
        return false;

    }
};
