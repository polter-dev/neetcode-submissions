class Solution {
public:
    //dfs with only horizontal or vertical movement
    bool dfs(const char *word, int k, int r, int c, vector<vector<char>>& board, vector<vector<int>>& visited)
    {
        if (word[k] == '\0') return true;

        int rows = board.size(), cols = board[0].size();
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) continue;
            if (visited[nr][nc] || board[nr][nc] != word[k]) continue;

            visited[nr][nc] = 1;
            if (dfs(word, k + 1, nr, nc, board, visited)) return true;
            visited[nr][nc] = 0;
        }
        return false;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        vector<string>ret;
        int rows = board.size();

        //check each word, in the entire grid
        //use the first character for navigating through the grid
        //if none of the next letters are near in each index then the word does not exist
        for (string word : words)
        {
            for (int i = 0; i < rows; i++)
            {
                bool flag = false;
                int cols = board[i].size();
                vector<vector<int>>visited(rows, vector<int>(cols, 0));
                for (int j = 0; j < cols; j++)
                {
                    //grab inital letter
                    char c = word[0];
                    
                    //start search until found
                    if (board[i][j] == c)
                    {  
                        //length can be one, if its in the board then it exists, otherwise start searching
                        if(word.length() == 1)
                        {
                            visited[i][j] = 1;
                            if (find(ret.begin(), ret.end(), word) == ret.end())
                                ret.push_back(word);
                            flag = true;
                        }
                        else
                        {
                            visited[i][j] = 1;
                            bool found = dfs(word.c_str(), 1, i, j, board, visited);
                            if (found)
                            {
                                if (find(ret.begin(), ret.end(), word) == ret.end())
                                    ret.push_back(word);
                                flag = true;
                                break;
                            }
                            else
                            {
                                visited[i][j] = 0;
                            }
                        }
                    }
                }
                if (flag) break; // done with the specific word.
            }
        }
        return ret;
    }
};
