class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int one = 0;
        int two = numbers.size() - 1;
        vector<int> ret;

        while(one != two)
        {
            if (numbers[two] + numbers[one] == target)
            {
                ret.push_back(one+1);
                ret.push_back(two+1);
                break;
            }

            if (numbers[two] + numbers[one] > target)
                two--;
            else
                one++;
        }
        return ret;
    }
};
