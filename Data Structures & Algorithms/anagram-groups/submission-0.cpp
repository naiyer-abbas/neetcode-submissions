class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int m = strs.size();
        map<vector<int>, vector<int>> um;
        for(int i = 0; i < m; i ++)
        {
            vector<int> v(26, 0);
            int n = strs[i].size();
            for(auto &e: strs[i])
            {
                v[e - 'a']++;
            }
            um[v].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto &e: um)
        {
            vector<string> temp;
            for(auto &j: e.second)
            {
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
