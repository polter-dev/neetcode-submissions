class Solution {
public:
    void reverseString(vector<char>& s) 
    {
        int ptr1 = 0;
        int ptr2 = s.size() - 1;    

        while (ptr1 < ptr2)
        {
            char t = s[ptr1];
            s[ptr1] = s[ptr2];
            s[ptr2] = t;

            ptr1++; ptr2--;
        }
    }
};