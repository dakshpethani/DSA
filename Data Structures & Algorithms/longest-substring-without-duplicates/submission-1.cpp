class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>charSet;
        int left = 0;
        int result=0;
        for(int right =0;right<n;right++)
        {
            if(charSet.find(s[right])!=charSet.end())
            {
                left = max(charSet[s[right]]+1,left);
            }
            charSet[s[right]]=right;
            result = max(result, right-left+1);
        }
        return result;
        
        
    }
};
