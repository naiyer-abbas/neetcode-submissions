// The core rule of Kadane's algorithm is much simpler: You should only start a new subarray at the
// current element if the current element itself is greater than the running sum plus the current
// element. Here is the standard, cleanest way to write it in C++:

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = nums[0];
        int mx = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currentSum = max(nums[i], currentSum + nums[i]);
            mx = max(mx, currentSum);
        }
        return mx;
    }
};
