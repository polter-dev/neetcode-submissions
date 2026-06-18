class Solution {
public:
    void generate(vector<vector<int>>&ret, vector<int>&nums, int k, int *used, int *cur, int n)
    {
        if (k == n)
        {
            //store perms
            vector<int>store;
            for (int i = 0; i < n; i++)
                store.push_back(nums[cur[i]]);
            ret.push_back(store);
            return;
        }

        for (int i = 0; i < n; i++)
            if(!used[i])
            {
                used[i] = 1;
                cur[i] = k;
                generate(ret,nums, k+1, used, cur, n);
                used[i] = 0;
            }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> r;
        int n = nums.size();
        int *used = (int*)calloc(n, sizeof(int));
        int *cur = (int*)malloc(sizeof(int) * n);
        generate(r, nums, 0, used, cur, n);
        return r;
    }
};
