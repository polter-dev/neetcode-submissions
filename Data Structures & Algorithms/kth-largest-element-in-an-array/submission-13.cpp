class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        //although you can just sort and return .at(.size()-k)
        // "Follow-up: Can you solve it without sorting?"
        // so this is that attempt.
        
        priority_queue<int> max;

        for (int num : nums)
        {
            max.push(num);
        }

        for (int i =0; i < k-1; i++)
            max.pop();
        return max.top();
    }
};
