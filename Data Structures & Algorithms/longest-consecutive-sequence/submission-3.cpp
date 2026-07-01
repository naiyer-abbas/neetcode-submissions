class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash;
        for(auto &e: nums)
        {
            hash.insert(e);
        }

        int mx = 0;
        int length = 0;
        for(auto &e: hash)
        {
            if(hash.find(e - 1) == hash.end())
            {
                length = 1;
                while(hash.find(e + length) != hash.end())
                {
                    length ++;
                }
            }
            mx = max(mx, length);
        }
        return mx;
    }
};
