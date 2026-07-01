class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        vector<int> ans;
        int n = nums.size();
        vector<vector<int>> bucket(n + 1);
        for(auto &e: nums)
        {
            um[e] ++;
        }
        for(auto &e: um)
        {
            bucket[e.second].push_back(e.first);
        }
        int i = n;
        while(k)
        {
            if(bucket[i].size() > 0)
            {
                for(auto &e: bucket[i])
                {
                    ans.push_back(e);
                    k --;
                    if(k <= 0)
                        break;
                }
            }
            i --;
        }
        return ans;
    }
};
