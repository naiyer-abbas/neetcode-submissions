#define pii pair<int, int>
class Solution {
public:
    double dfo(int x, int y)
    {
        return (double)sqrt((x * x) + (y * y));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pii> pq; // max heap
        for(int i = 0; i < points.size(); i ++)
        {
            int dfo_10 = dfo(points[i][0], points[i][1]) * 10;
            if(pq.size() >= k)
            {
                if(dfo_10 < pq.top().first)
                {
                    pq.pop();
                    pq.push({dfo_10, i}); 
                }     
            }
            else
                pq.push({dfo_10, i});
        }
        while(!pq.empty())
        {
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(points[idx]);
        }
        return ans;
    }
};
