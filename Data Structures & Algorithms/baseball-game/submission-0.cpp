class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>stack;
        int result=0;
        for (const string & op :operations)
        {
            if(op=="+")
            {
                int top = stack.top();
                stack.pop();
                int newTop = top+stack.top();
                stack.push(top);
                stack.push(newTop);
                result+=newTop;
            }
            else if (op=="D")
            {
                stack.push(2*stack.top());
                result+=stack.top();
            }
            else if (op=="C")
            {
                result-=stack.top();
                stack.pop();
            }
            else
            {
                stack.push(stoi(op));
                result+=stack.top();
            }

        }
        return result;
        
    }
};