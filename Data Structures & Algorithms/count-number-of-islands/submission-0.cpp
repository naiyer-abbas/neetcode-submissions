class Solution {
public:
    int dir[4][2] = {{0,1},{1,0}, {-1, 0}, {0, -1}}; 
    void dfs(vector<vector<char>>& grid, vector<vector<bool>> &visited, int row, int col)
    {
        if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || visited[row][col] || grid[row][col] == '0')
            return;
        visited[row][col] = true;
        for(int i = 0; i < 4; i ++)
        {
            dfs(grid, visited, row + dir[i][0], col + dir[i][1]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        int islands = 0;
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < m; j ++)
            {
                if(grid[i][j] == '1' && !visited[i][j])
                {
                    islands ++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return islands;
    }
};
