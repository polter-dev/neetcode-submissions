class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0, high = cols-1;

        //stop index i in the row it belongs
        int i = 0;
        while (i < rows-1)
            if (matrix[i+1][0] <= target) i++;
            else break;
        
        //binary search
        while (low < high)
         {
            int mid = (high + low) / 2;
            if (matrix[i][mid] == target)
                return true;
            if (target < matrix[i][mid])
                high = mid-1;
            else
                low = mid+1;
        }
        if (low == high)
            if (matrix[i][low] == target) return true;
        
        return false;
    }
};
