class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        // Search in the range [0, rows * cols - 1]
        int low = 0;
        int high = rows * cols - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            // Convert 1D index into 2D coordinates
            int row = mid / cols;
            int col = mid % cols;

            int value = matrix[row][col];

            if (value == target)
                return true;

            if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return false;
    }
};