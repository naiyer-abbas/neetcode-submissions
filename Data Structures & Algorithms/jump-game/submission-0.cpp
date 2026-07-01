class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int goal = n - 1;
        bool ans = true;
        for(int i = n - 2; i >= 0; i --)
        {
            if(goal - i <= nums[i])
                goal = i;
        }
        if(goal != 0)
            return false;
        return true;
    }
};
