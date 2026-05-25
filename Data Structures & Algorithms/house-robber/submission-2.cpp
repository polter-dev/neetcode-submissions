class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int max = 0;
        int one = 0; int two = 0;
        for (int num : nums)
        {
            int current = (one > two + num) ? one : two + num;
            two = one;
            one = current;
        }    

        return one;
    }
};
