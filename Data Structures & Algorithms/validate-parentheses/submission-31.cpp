class Solution {
public:
    bool isValid(string s) 
    {
        int x = s.length();

        if (x <= 1) return false;

        stack<char> tracker;

        for (int i = 0; i < x; i++)
            if (s[i] == '(' || s[i] == '{' || s[i] == '[' )
                tracker.push(s[i]);
            else
            {
                if (tracker.size() == 0) {return false;}
                if (s[i] == ')')
                {
                    if (tracker.top() != '(') {return false;}
                }
                else if (s[i] == ']')
                {
                    if (tracker.top() != '[') {return false;}
                }
                else if (s[i] == '}')
                {
                    if (tracker.top() != '{') {return false;}
                }
                tracker.pop();
            }
        
        if (tracker.size() == 0)
            return true;
        return false;
    }

};
