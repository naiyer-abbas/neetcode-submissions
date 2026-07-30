class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int, int> mp;
        int n = position.size();
        for(int i = 0; i < n; i ++)
        {
            mp[position[i]] = speed[i];
        }

        double arrival = -1.0;
        int fleet = 0;
        for(auto it = mp.rbegin(); it != mp.rend(); it ++)
        {
            int start = it -> first;
            int sp = it -> second;
            int distance = target - start;
            double time = (double)(target - start) / sp;
            if(time > arrival)
            {
                fleet ++;
                arrival = time;
            }
        }
        return fleet;
    }
};
