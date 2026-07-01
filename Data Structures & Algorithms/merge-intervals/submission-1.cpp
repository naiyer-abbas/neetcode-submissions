class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector <vector<int>> merged;
        for(int i = 0; i < intervals.size(); i ++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            // check for overlap
            while(i + 1 < intervals.size() && r >= intervals[i + 1][0])
            {
                if(r < intervals[i + 1][1])
                    r = intervals[i + 1][1];
                i ++;
            }
            merged.push_back({l, r});
        }
        return merged;
    }
};
