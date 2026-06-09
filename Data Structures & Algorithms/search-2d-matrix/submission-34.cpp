class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        
        int lo = 0; int hi = rows-1;
        //stop index i in the row it belongs
        int i = 0;
        while (lo < hi) 
        {
            int mid = (lo + hi+1) / 2;
            if (matrix[mid][0] <= target) lo = mid;
            else hi = mid - 1;
        }
        i = lo;


        int low = 0; int high = cols-1;
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
