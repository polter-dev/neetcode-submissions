class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        //although you can just sort and return .at(.size()-k)
        // "Follow-up: Can you solve it without sorting?"
        // so this is that attempt.
        
 priority_queue<int, vector<int>, greater<int>> heap;
        for(int num : nums){
            heap.push(num);
            if(heap.size() > k) heap.pop();
        }
        return heap.top();
    
    }
};
