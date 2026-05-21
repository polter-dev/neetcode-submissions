class Solution {
public:
    bool isAnagram(string s, string t) {
        int freqS[26] = { 0 };
        int freqT[26] = { 0 };
        int size = s.length();
        int m = t.length();

        if (size != m)
            return false;

        for (int i = 0; i < size; i++) { 
            freqS[s[i] - 'a']++;
            freqT[t[i] - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (freqS[i] != freqT[i])
                return false;
        }
            
        
        return true;
    }
};
