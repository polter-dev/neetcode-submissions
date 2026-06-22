class Solution {
public:
    int floodFill(vector<vector<int>>&grid, vector<vector<int>> &visited, int x, int y, int rows, int cols)
    {
        //base cases
        if (x < 0 || y < 0 || x >= rows || y >= cols) return 0;
        if (grid[x][y] == 0 || visited[x][y] == 1) return 0;

        visited[x][y] = 1;

        return 1 + floodFill(grid, visited, x+1, y, rows, cols) + floodFill(grid, visited, x-1, y, rows, cols)
                 + floodFill(grid, visited, x, y+1, rows, cols) + floodFill(grid, visited, x, y-1, rows, cols);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int count = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    int cur = floodFill(grid, visited, i, j, rows, cols);
                    if (cur > count) count = cur;
                }

        return count;
    }   
};
