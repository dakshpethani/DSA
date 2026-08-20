class Solution {
public:
    bool isValid(string s) {
        stack<int>stack;
        for(char current_char : s)
        {
            if(current_char=='(' || current_char=='{' || current_char=='[')
            {
                stack.push(current_char);
            }
            else if (stack.empty() || !isMatchingPair(stack.top(),current_char))
            {
                return false;
            }
            else
            {
                stack.pop();
            }
            
        }
        return stack.empty();
        
    }
private : 
    bool isMatchingPair(char left , char right)
    {
        return (left=='(' && right==')') || (left=='{' && right=='}') || (left =='[' && right==']');
    }
};
