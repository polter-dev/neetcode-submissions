class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        //although you can just sort and return .at(.size()-k)
        // "Follow-up: Can you solve it without sorting?"
        // so this is that attempt.
        
        std::priority_queue<int, std::vector<int>, std::greater<int>> max;

        for (int num : nums)
        {
            max.push(num);
            if (max.size() > k)
                max.pop();
        }

        return max.top();
    }
};
