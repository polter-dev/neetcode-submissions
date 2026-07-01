class Solution {
public:
    bool check3x3(vector<vector<char>>&board, char hand, int curRow, int curCol)
    {
        //get to beginning indicies for the cell
        int startRow = (curRow / 3) * 3;
        int startCol = (curCol / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++)
            for (int j = startCol; j < startCol + 3; j++)
                if (curRow != i || curCol != j)
                    if (board[i][j] == hand) return false;
        return true;
    }

    bool checkRC(vector<vector<char>>&board, char hand, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            if ((board[row][i] == hand && col !=i) || 
                (board[i][col] == hand && row !=i)) return false;
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                char hand = board[i][j];
                if (hand != '.')
                {
                    bool t;
                    //check 3x3 matrix
                    t = check3x3(board, hand, i, j);
                    if (!t) return false;
                    //check rows and cols
                    t = checkRC(board, hand, i, j);
                    if (!t) return false;
                }
            }

        return true;    
    }
};
