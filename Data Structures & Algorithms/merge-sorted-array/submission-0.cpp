class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        vector<int> change;
        int low1 = 0;
        int low2 = 0;

        while (low1 <= m-1 && low2 <= n-1)
        {
            if (nums1[low1] < nums2[low2])
            {
                change.push_back(nums1[low1]);
                low1++;
            }
            else
            {
                change.push_back(nums2[low2]);
                low2++;
            }
        }

        while (low1 <= m-1)
            change.push_back(nums1[low1++]);
        while (low2 <= n-1)
            change.push_back(nums2[low2++]);
        
        nums1 = change;
    }
};