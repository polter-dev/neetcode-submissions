class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ret;
        for (int i = 0; i <= n; i++)
        {
            int count = 0;
            {
                uint32_t bits = i;
            }
            int j = i;
            while (j)
            {
                if (j & 1)
                    count++;
                j >>= 1;
            }
            ret.push_back(count);
        }
        return ret;
    }
};
