class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1, mid;
        bool found = false;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            int n = matrix[mid].size();
            if(target >= matrix[mid][0] && target <= matrix[mid][n - 1])
            {
                found = true;
                break;
            }

            if(target < matrix[mid][0])
            {
                high = mid - 1;
            }

            else if(target > matrix[mid][n - 1])
            {
                low = mid + 1;
            }
        }

        if(found == true)
        {
            return binary_search(matrix[mid].begin(), matrix[mid].end(), target);
        }
        return false;
    }
};
