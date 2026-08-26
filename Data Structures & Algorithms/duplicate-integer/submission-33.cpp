class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        map<int, int> t;
        for (int n : nums)
        {
            try {
                int g = t.at(n);
                return true;
            } catch (const std::out_of_range &e){
                t[n] = 1;
            }
            
        }
        return false;
    }
};