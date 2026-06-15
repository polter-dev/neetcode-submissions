class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++)
        {
            uint32_t bit = (n & (1<<i)); //extract right most bits first
            if (bit) bit = 1;
            res += (bit << (31-i)); //place bit on left side
        }    
        return res;
    }
};
