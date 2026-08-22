class Solution {
public:
    /**
 * Decodes an encoded string containing patterns like "k[encoded_string]"
 * where k is the repeat count and encoded_string is the pattern to repeat
 * @param s - The encoded string to decode
 * @return The decoded string
 */
string decodeString(string s) {
   
    string currentString = "";
    stack<pair<string, int>> stk;
    int repeatCount = 0;

    for (char c : s) {
        if (isdigit(c)) {
            repeatCount = repeatCount * 10 + (c - '0');
        } else if (isalpha(c)) {
            currentString += c;
        } else if (c == '[') {

            stk.push({currentString, repeatCount});
            currentString = "";
            repeatCount = 0;
        } else if (c == ']') {
           
            auto [previousString, previousRepeatCount] = stk.top();
            stk.pop();
            string repeatedString = "";
            for (int i = 0; i < previousRepeatCount; i++) {
                repeatedString += currentString;
            }
            currentString = previousString + repeatedString;
        }
    }
  
    return currentString;
}

};