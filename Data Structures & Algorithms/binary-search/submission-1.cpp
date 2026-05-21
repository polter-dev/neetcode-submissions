class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len = nums.size();
        int high = len;
        
        int low = 0;

        while(true)
        {
            int mid = (high+low)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (mid == low ||  mid == high)
            {
                return -1;
            }
            if (nums[mid] < target)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }
    }
};
