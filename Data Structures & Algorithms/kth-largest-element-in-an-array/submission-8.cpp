class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        //although you can just sort and return .at(.size()-k)
        // "Follow-up: Can you solve it without sorting?"
        // so this is that attempt.

        make_heap(nums.begin(), nums.end()); 
        int val = 0;
        while(k)
        {
            pop_heap(nums.begin(), nums.end());
            val = nums.back();
            nums.pop_back();
            k--;
        }

        return val;
    }
};
