class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = 1000000000, ans = 1000000000;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            int res = 0;
            for(int i = 0; i < piles.size(); i ++)
            {
                res += (piles[i] + ( mid - 1))/ mid;
            }
            if(res <= h)
            {
                ans = mid;
                high = mid - 1;
            }

            else
                low = mid + 1;      
        }
        return ans;
    }
};
