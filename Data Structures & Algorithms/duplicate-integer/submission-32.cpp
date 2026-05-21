class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> vals;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            int num = nums.back();
            if (vals.contains(num)){
                return true;   
            } else {
                nums.pop_back();
                vals.insert(num);
            }
        }
        return false;
    }
};