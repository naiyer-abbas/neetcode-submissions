class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

           
            if (nums[mid] <= nums[high]) { // if right half is sorted
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return nums[low];
    }
};