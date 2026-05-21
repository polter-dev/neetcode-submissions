class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int>tracker;
        for (string val : tokens)
        {
            if (val == "+" || val == "-" || val == "/" || val == "*")
            {
                int two = tracker.top(); tracker.pop();
                int one = tracker.top(); tracker.pop();
                if (val == "+") tracker.push(one + two);
                else if(val == "-") tracker.push(one - two);
                else if (val == "/") tracker.push(one / two);
                else tracker.push(one * two);
            }
            else
            {
                tracker.push(std::stoi(val));
            }
        }
        return tracker.top();
    }
};
