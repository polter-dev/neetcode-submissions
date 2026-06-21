class Solution {
public:
    void floodFill(vector<vector<char>>& grid, vector<vector<int>> &visited, int x, int y, int rows, int cols)
    {
        //bounds check
        if (x >= rows || y >= cols || x < 0 || y < 0) return;
        if (visited[x][y] == 1) return;
        if (grid[x][y] == '0') return;

        visited[x][y] = 1;

        floodFill(grid, visited, x+1, y, rows, cols);
        floodFill(grid, visited, x-1, y, rows, cols);
        floodFill(grid, visited, x, y+1, rows, cols);
        floodFill(grid, visited, x, y-1, rows, cols);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        int count = 0;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    floodFill(grid, visited, i, j, rows, cols);
                    count++;
                }
            }
        
        return count;
    }
};
