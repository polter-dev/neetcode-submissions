class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        int len = nums.size();
        std::unordered_map<int, int> vals;

        for (int i = 0; i < len; i++) {
            int search = target - nums[i];
            
            if (vals.find(search) == vals.end()) {
                vals[nums[i]] = i;  
            } else {
                ret.push_back(vals[search]);
                ret.push_back(i);
                return ret;
            }
        }

        return ret;
    }
};
