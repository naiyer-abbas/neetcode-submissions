class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector <vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i < n - 2; i ++)
        {
            int target = - nums[i];
            int left = i + 1, right = n - 1;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            while(left < right)
            {
                if(nums[left] + nums[right] == target)
                {
                    vector<int> v = {nums[i], nums[left], nums[right]};
                    ans.push_back(v);
                    do
                    {
                        left ++;
                    } while(left > 0 && nums[left] == nums[left - 1]);

                    do
                    {
                        right --;
                    } while(right < n - 1 && nums[right + 1] == nums[right]);
                        
                    continue;
                }

                else if(nums[left] + nums[right] < target)
                    do
                    {
                        left ++;
                    }
                    while(left > 0 && nums[left] == nums[left - 1]);
                        
                else
                    do
                    {
                        right --;
                    }
                    while(right < n - 1 && nums[right + 1] == nums[right]);
                        
            }
        }
        return ans;
    }
};
