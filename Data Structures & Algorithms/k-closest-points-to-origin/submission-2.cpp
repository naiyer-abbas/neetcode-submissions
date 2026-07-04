#define pii pair<int, int>
class Solution {
public:
    double dfo(int x, int y)
    {
        return (x * x) + (y * y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<pii> pq; // max heap
        for(int i = 0; i < points.size(); i ++)
        {
            int distance = dfo(points[i][0], points[i][1]);
            if(pq.size() >= k)
            {
                if(distance < pq.top().first)
                {
                    pq.pop();
                    pq.push({distance, i}); 
                }     
            }
            else
                pq.push({distance, i});
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
